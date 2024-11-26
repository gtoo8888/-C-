#include "XVPlayer.h"
#include <thread>
#include <QThread>
#include "Utils.h"

XVPlayer::XVPlayer(QObject *parent) : QObject(parent)
{
    // 初始化SDL子系统
    if(SDL_Init(SDL_INIT_AUDIO)){
        // 返回值不是0,就代表失败
        qDebug() << "SDL_Init error" << SDL_GetError();
        emit signalPlayFailed(this);
        return;
    }

    maPktList = new std::list<AVPacket>();
    mvPktList = new std::list<AVPacket>();
    maMutex = new CondMutex();
    mvMutex = new CondMutex();
}

XVPlayer::~XVPlayer()
{
    delete maPktList;
    delete mvPktList;
    delete maMutex;
    delete mvMutex;

    SDL_Quit();
}
#pragma mark - 公共方法
void XVPlayer::play(){
    if(mState == Playing)
        return;
    //状态可能是:暂停、停止、正常完毕
    // 解封装、解码、播放，音视频同步
    // 多线程的知识
    // 创建子线程去解码
    // 解码后的格式不一定是我们播放器想要的?
    //PCM格式不是SDL支持的 S16 44100/ YUV -> RGB

    if(mState == Stopped){
        std::thread([this](){
            readFile();
        }).detach();
    }

    setState(Playing);
}

void XVPlayer::pause(){
    if(mState != Playing)
        return;
    setState(Pause);
}

void XVPlayer::stop(){
    if(mState == Stopped)
        return;
    setState(Stopped);

    freeAll();
}

bool XVPlayer::isPlaying(){
    return mState == Playing;
}

XVPlayer::State XVPlayer::getState(){
    return mState;
}

#pragma mark - 私有方法
void XVPlayer::setVideoFileName(const char *filename){
    mFileName = filename;
}


int XVPlayer::initDecoder(AVCodecContext **decodeCtx, AVStream **stream, AVMediaType type)
{
    // 根据type寻找最合适的流信息
    // 返回值是流索引
    int ret = av_find_best_stream(mFmtCtx,type,-1,-1,nullptr,0);
    RET(av_find_best_stream);

    // 检验流
    int streamIdx = ret;
    *stream = mFmtCtx->streams[streamIdx];
    if (!stream){
        myDebug() << "stream is empty";
        return -1;
    }

    // 为当前流找到合适的解码器
    const AVCodec *decoder = avcodec_find_decoder((*stream)->codecpar->codec_id);
    if(!decoder){
        myDebug() << "decoder is empty" << (*stream)->codecpar->codec_id;
        return -1;
    }

    // 初始化解码上下文
    *decodeCtx = avcodec_alloc_context3(decoder);
    if(!decoder){
        myDebug() << "avcodec_alloc_context3 error";
        return -1;
    }

    // 从流中拷贝参数到解码上下文中
    ret = avcodec_parameters_to_context(*decodeCtx, (*stream)->codecpar);
    RET(ret);

    // 打开解码器
    ret = avcodec_open2(*decodeCtx, decoder, nullptr);
    RET(ret);

    return 0;
}

void XVPlayer::setState(XVPlayer::State state){
    if(state == mState)
        return;
    mState = state;
    emit signalStateUpdate(this);
}

void XVPlayer::readFile()
{
    qDebug() << "readFile" << QThread::currentThread();
    int ret = 0;

    // 创建解封装上下文、打开文件
    ret = avformat_open_input(&mFmtCtx, mFileName, nullptr, nullptr);
    END(avformat_open_input);

    // 检索流信息
    ret = avformat_find_stream_info(mFmtCtx,nullptr);
    END(avformat_find_stream_info);

    // 打印流信息到控制台
    av_dump_format(mFmtCtx,0,mFileName,0);
    fflush(stderr);

    // 初始化音频信息
//    bool hasAudio = false;
    bool hasAudio = initAudioInfo() >= 0;
    // 初始化视频信息
    bool hasVideo = initVideoInfo() >= 0;
    // 音频和视频都没有，严重错误
    if(!hasAudio && !hasVideo){
        fateError();
        return;
    }

    emit signalInitFinished(this);
    // 从输入文件中读取数据
    while(mState != Stopped){ // 暂停了也可以继续读取

        AVPacket pkt;// 这个放在循环外也可以，因为addAudioPkt里面是拷贝构造函数，会将值复制新一份存起来
        ret = av_read_frame(mFmtCtx, &pkt);
        if(ret == 0){
            if(pkt.stream_index == maStream->index){ // 读取到的是音频数据
//                addAudioPkt(pkt);
            }else if(pkt.stream_index == mvStream->index){ // 读取到的是视频数据
                addVideoPkt(pkt);
            }
        }else if(ret == AVERROR_EOF){ // 读取到文件尾部，停止了
            qDebug() << "已经读取到文件尾部了";
            break;
        }else{
            ERROR_BUF;
            qDebug() << "av_read_frame error" << errbuf;
            continue; // 如果读取失败，跳过这次读取
        }
    }

end:
    avcodec_free_context(&maDecodeCtx);
    avcodec_free_context(&mvDecodeCtx);
    avformat_close_input(&mFmtCtx);
}

int64_t XVPlayer::getDuration()
{
    if(mFmtCtx == nullptr)
        return 0;
    return mFmtCtx->duration;
}

void XVPlayer::freeAll()
{
    avformat_close_input(&mFmtCtx);

    freeAudio();
    freeVideo();
}

void XVPlayer::fateError()
{
    setState(Stopped);
    emit signalPlayFailed(this);
    freeAll();
}


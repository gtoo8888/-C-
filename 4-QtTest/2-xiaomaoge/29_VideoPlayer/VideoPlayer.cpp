#include "VideoPlayer.h"
#include <thread>
#include <QThread>
#include "Utils.h"

VideoPlayer::VideoPlayer(QObject *parent) : QObject(parent)
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

VideoPlayer::~VideoPlayer()
{
    delete maPktList;
    delete mvPktList;
    delete maMutex;
    delete mvMutex;

    SDL_Quit();
}
#pragma mark - 公共方法
void VideoPlayer::play(){
    if(mState == Playing)
        return;
    //状态可能是:暂停、停止、正常完毕
    // 解封装、解码、播放，音视频同步
    // 多线程的知识
    // 创建子线程去解码
    // 解码后的格式不一定是我们播放器想要的?
    //PCM格式不是SDL支持的 S16 44100/ YUV -> RGB

    std::thread([this](){
        readFile();
    }).detach();
    setState(Playing);
}

void VideoPlayer::pause(){
    if(mState != Playing)
        return;
    setState(Pause);
}

void VideoPlayer::stop(){
    if(mState == Stopped)
        return;
    setState(Stopped);
}

bool VideoPlayer::isPlaying(){
    return mState == Playing;
}

VideoPlayer::State VideoPlayer::getState(){
    return mState;
}

#pragma mark - 私有方法
void VideoPlayer::setVideoFileName(const char *filename){
    mFileName = filename;
}


int VideoPlayer::initDecoder(AVCodecContext **decodeCtx, AVStream **stream, AVMediaType type)
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

void VideoPlayer::setState(VideoPlayer::State state){
    if(state == mState)
        return;
    mState = state;
    emit signalStateUpdate(this);
}

void VideoPlayer::readFile()
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
    if(initAudioInfo() < 0){
        goto end;
    }

    // 初始化视频信息
    if(initVideoInfo() < 0){
        goto end;
    }

    emit signalInitFinished(this);
    // 从输入文件中读取数据
    while(true){
        AVPacket pkt;
        ret = av_read_frame(mFmtCtx, &pkt);
        if(ret == 0){
            if(pkt.stream_index == maStream->index){ // 读取到的是音频数据
                addAudioPkt(pkt);
            }else if(pkt.stream_index == mvStream->index){ // 读取到的是视频数据
                addVideoPkt(pkt);
            }
        }else{
            continue; // 如果读取失败，跳过这次读取
        }
    }

end:
    avcodec_free_context(&maDecodeCtx);
    avcodec_free_context(&mvDecodeCtx);
    avformat_close_input(&mFmtCtx);
}

int64_t VideoPlayer::getDuration()
{
    if(mFmtCtx == nullptr)
        return 0;
    return mFmtCtx->duration;
}

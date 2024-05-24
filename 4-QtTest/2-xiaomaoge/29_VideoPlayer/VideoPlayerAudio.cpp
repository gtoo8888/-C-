#include "VideoPlayer.h"
#include "Utils.h"
#include <SDL2/SDL.h>
int VideoPlayer::initAudioInfo()
{
    // 初始化解码器
    int ret = initDecoder(&maDecodeCtx, &maStream, AVMEDIA_TYPE_AUDIO);
    RET(initDecoder);

    // 初始化SDL
    ret = initSwr();
    RET(initSwr);

    // 初始化SDL
    ret = initSDL();
    RET(initSDL);

    return ret;
}

int VideoPlayer::initSwr()
{
    // 重采样输入参数
    maSwrInSpec.sampleRate = maDecodeCtx->sample_rate;
    maSwrInSpec.sampleFmt = maDecodeCtx->sample_fmt;
    maSwrInSpec.chLayout = maDecodeCtx->channel_layout;
    maSwrInSpec.chs = maDecodeCtx->channels;

    // 重采样输出参数
    maSwrOutSpec.sampleRate = 44100;
    maSwrOutSpec.sampleFmt = AV_SAMPLE_FMT_S16;
    maSwrOutSpec.chLayout = AV_CH_LAYOUT_STEREO;
    maSwrOutSpec.chs = av_get_channel_layout_nb_channels(maSwrOutSpec.chLayout);
    // 声道数*每个样本的大小
    maSwrOutSpec.bytesPerSampleFrame = maSwrOutSpec.chs
                                        *av_get_bytes_per_sample(maSwrOutSpec.sampleFmt);

    maSwrCtx = swr_alloc_set_opts(nullptr,
                                  // 输出参数
                                  maSwrOutSpec.chLayout,
                                  maSwrOutSpec.sampleFmt,
                                  maSwrOutSpec.sampleRate,
                                  // 输入参数
                                  maSwrInSpec.chLayout,
                                  maSwrInSpec.sampleFmt,
                                  maSwrInSpec.sampleRate,
                                  0,nullptr);
    if(!maSwrCtx){
        qDebug() << "swr_alloc_set_opts error";
        return -1;
    }

    int ret = swr_init(maSwrCtx);
    RET(swr_init);

    // 初始化采样前的输入Frame
    maSwrInFrame = av_frame_alloc();
    if(!maSwrInFrame){
        qDebug() << "av_frame_alloc error";
        return -1;
    }

    // 初始化重采样后的输出Frame
    maSwrOutFrame = av_frame_alloc();
    if(!maSwrOutFrame){
        qDebug() << "av_frame_alloc error";
        return -1;
    }

    // 初始化重采样的输出frame的date[0]空间
    // 初始化4096的大小，让函数自己算
//    qDebug() << maSwrOutFrame->data[0];
    ret = av_samples_alloc(maSwrOutFrame->data,
                           maSwrOutFrame->linesize,
                           maSwrOutSpec.chs,
                           4096,maSwrOutSpec.sampleFmt,1);
    RET(av_samples_alloc);
//    qDebug() << maSwrOutFrame->data[0]; // 用来测试data[0]是否真的被赋值了
    return 0;
}

uint64_t count = 0;
void VideoPlayer::sdlAudioCallbackFunc(void *userdata, Uint8 *stream, int len)
{
//    qDebug() << "count" << count++ << "len" << len;
    VideoPlayer* player = (VideoPlayer*)userdata;
    player->sdlAudioCallback(stream,len);
}

int VideoPlayer::initSDL()
{
    // 之后做重采样的处理
    // 音频参数
    SDL_AudioSpec spec;
    // 采样率
    spec.freq = 44100;
    // 采样格式(s16le)
    spec.format= AUDIO_S16LSB;
    //声道数
    spec.channels = 2;
    //音频缓冲区的样本数量(这个值必须是2的幂)
    spec.samples = 512;
    //回调
    spec.callback = sdlAudioCallbackFunc;
    //传递给回调的参数
    spec.userdata = this; // 直接传递整个类，传递就去后再转化

    //打开音频设备
    if(SDL_OpenAudio(&spec, nullptr)){
        qDebug() << "SDL_OpenAudio error" << SDL_GetError();
        // 清除所有初始化的子系统
        SDL_Quit();
        return -1;
    }

    // 开始播放
    SDL_PauseAudio(0);
    return 0;
}



void VideoPlayer::sdlAudioCallback(Uint8 *stream, int len)
{
    SDL_memset(stream, 0, len);
    // len:SDL音频缓冲区剩余的大小(还未填充的大小)
    while(len > 0){
        if(mState == Stopped)
            break;

        if(maSwrOutIdx >= maSwrOutSize){
            maSwrOutSize = decodeAudio(); // 音频解码
//            qDebug() << maSwrOutSize;
            if(maSwrOutSize <= 0){
                memset(maSwrOutFrame->data[0],0,maSwrOutSize = 1024);
            }
            maSwrOutIdx = 0;
        }
        int srcLen = maSwrOutSize - maSwrOutIdx;
        srcLen = std::min(srcLen, len);
//        qDebug() << srcLen;
//        memset(maSwrOutFrame->data[0],50,1024);
        //将一个pkt包解码后的pcm数据填充到SDL的音频缓冲区
        // 以前只需要填写一次就行了，现在需要解码pkt，根据pkt大小来填充
        SDL_MixAudio(stream,maSwrOutFrame->data[0] + maSwrOutIdx ,srcLen,SDL_MIX_MAXVOLUME);

        // 移动偏移量
        len -= srcLen;
        stream += srcLen;
        maSwrOutIdx += srcLen;
    }
}

int VideoPlayer::decodeAudio()
{
    maMutex->lock();
//    while(maPktList->empty()){
//        maMutex->wait(); // 可能会被操作系统假唤醒，比较复杂，之后再写
//    }
    if(maPktList->empty() || mState == Stopped){
        maMutex->unlock(); // 如果没东西，直接不等了，解锁退出
        return 0;
    }

    //取出头部的数据包
    AVPacket pkt = maPktList->front(); // 不能使用引用，因为后面还会被用到
    //从头部中删除
    maPktList->pop_front();
    // 使用完队列，需要解锁
    maMutex->unlock();


    //发送压缩数据到解码器
    int ret = avcodec_send_packet(maDecodeCtx, &pkt);
    //释放pkt
    av_packet_unref(&pkt);
    RET(avcodec_send_packet);

    //获取解码后的数据
    ret = avcodec_receive_frame(maDecodeCtx, maSwrInFrame);
    if(ret == AVERROR(EAGAIN) || ret == AVERROR_EOF){
        return 0;
    }else RET(avcodec_receive_frame);

//    qDebug() << maSwrInFrame->sample_rate // 采样率
//             << maSwrInFrame->channels // 通道数
//             << av_get_sample_fmt_name((AVSampleFormat)maSwrInFrame->format);

    // 重采样输出的样本
    int outSamples = av_rescale_rnd(maSwrOutSpec.sampleRate,
                                    maSwrInFrame->nb_samples,
                                    maSwrInSpec.sampleRate, AV_ROUND_UP);

    //由于解码出来的PCM。跟SDL要求的PCM格式可能不一致
    //需要进行重采样
    // ret表示真正转换成功的样本，所以需要返回ret
    ret = swr_convert(maSwrCtx,
                      maSwrOutFrame->data, // 最终获得的数据
                      // 如果没有初始化的话，数组是存在的，但是里面的内容没有指向任何东西
                      outSamples,
                      (const uint8_t **)maSwrInFrame->data,
                      maSwrInFrame->nb_samples);
    RET(swr_convert);


    return ret * maSwrOutSpec.bytesPerSampleFrame;
}



// AVPacket &pkt增加引用是为了防止再次产生拷贝构造函数的
void VideoPlayer::addAudioPkt(AVPacket &pkt)
{
    maMutex->lock();
    maPktList->push_back(pkt);
    maMutex->signal();
    maMutex->unlock();
}

void VideoPlayer::clearAudioPktList()
{
    maMutex->lock();
    for(AVPacket &pkt : *maPktList){
        av_packet_unref(&pkt);
    }
    maPktList->clear();
    maMutex->unlock();
}

void VideoPlayer::freeAudio()
{
    maSwrOutIdx = 0;
    maSwrOutSize = 0;

    clearAudioPktList();
    avcodec_free_context(&maDecodeCtx); // 只要传地址，都会自动成为空指针，ffmpeg控制的
    swr_free(&maSwrCtx);
    av_frame_free(&maSwrInFrame);
    if(maSwrOutFrame){
        av_freep(&maSwrOutFrame->data[0]);
        av_frame_free(&maSwrOutFrame);
    }

    SDL_PauseAudio(1);
    SDL_CloseAudio();
}


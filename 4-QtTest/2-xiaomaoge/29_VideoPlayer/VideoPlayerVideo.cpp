#include "VideoPlayer.h"
#include "Utils.h"
#include <thread>

extern "C" {
#include <libavutil/imgutils.h>
}


int VideoPlayer::initVideoInfo()
{
    // 初始化解码器
    int ret = initDecoder(&mvDecodeCtx, &mvStream, AVMEDIA_TYPE_VIDEO);
    RET(initDecoder);

    // 初始化视频像素格式转换
    ret = initSws();
    RET(initSws);


    // 开启新的线程去解码视频数据,主动去解码视频数据
    // 音频是SDL来要音频数据
    std::thread([this](){
        decodeVideo();
    }).detach();

    return 0;
}

int VideoPlayer::initSws()
{
    mvSwsOutSpec.widght = mvDecodeCtx->width;
    mvSwsOutSpec.height = mvDecodeCtx->width;
    mvSwsOutSpec.pixFmt = AV_PIX_FMT_RGB24;

    // 初始化视频像素格式转换上下文
    mvSwsCtx = sws_getContext(mvDecodeCtx->width,
                              mvDecodeCtx->height,
                              mvDecodeCtx->pix_fmt,
                              mvSwsOutSpec.widght,
                              mvSwsOutSpec.height,
                              mvSwsOutSpec.pixFmt,
                              SWS_BILINEAR,nullptr,nullptr,nullptr);


    // 初始化视频像素格式转换的输入Frame
    mvSwsInFrame = av_frame_alloc();
    if(!mvSwsInFrame){
        qDebug() << "av_frame_alloc error";
        return -1;
    }
    // 初始化视频像素格式转换的输出Frame
    mvSwsOutFrame = av_frame_alloc();
    if(!mvSwsOutFrame){
        qDebug() << "av_frame_alloc error";
        return -1;
    }

    // mvSwsOutFrame的date[0]指向的空间
    // 视频每次解码出来只有一帧，所以每次初始化一帧就可以了
    int ret = av_image_alloc(mvSwsOutFrame->data,
                            mvSwsOutFrame->linesize,
                            mvSwsOutSpec.widght,
                            mvSwsOutSpec.height,
                            mvSwsOutSpec.pixFmt,
                            1); // 表示对齐
    RET(av_image_alloc);

    return 0;
}

void VideoPlayer::addVideoPkt(AVPacket &pkt)
{
    mvMutex->lock();
    mvPktList->push_back(pkt);
    mvMutex->signal();
    mvMutex->unlock();
}

void VideoPlayer::clearVideoPktList()
{
    mvMutex->lock();
    for(AVPacket &pkt : *mvPktList){
        av_packet_unref(&pkt);
    }
    mvPktList->clear();
    mvMutex->unlock();
}

void VideoPlayer::decodeVideo()
{
    while(true){
        mvMutex->lock();

        if(mvPktList->empty()){
            mvMutex->unlock();
            continue;
        }

        // 取出头部视频包
        AVPacket pkt = mvPktList->front();
        mvPktList->pop_front();
        mvMutex->unlock();

        //发送压缩数据到解码器
        int ret = avcodec_send_packet(mvDecodeCtx, &pkt);
        // 释放pkt
        av_packet_unref(&pkt);
        CONTINUE(avcodec_send_packet);

        while(true){
            //获取解码后的数据
            ret = avcodec_receive_frame(mvDecodeCtx, mvSwsInFrame);
            if(ret == AVERROR(EAGAIN) || ret == AVERROR_EOF){
                break; // 跳过这一帧，解码下一帧
            }else BREAK(avcodec_receive_frame);

            // TODO
            SDL_Delay(33);

            // 像素格式的转换 mvSwsInFrame -> mvSwsOutFrame(yuv420->rgb24)
            sws_scale(mvSwsCtx,
                      mvSwsInFrame->data, mvSwsInFrame->linesize,
                      0,mvDecodeCtx->height,
                      mvSwsOutFrame->data, mvSwsOutFrame->linesize);

//            qDebug() << mvSwsOutFrame->data;
            // 发出信号
            emit signalFrameDecoded(this,mvSwsOutFrame->data[0],mvSwsOutSpec);

        }
    }
}

void VideoPlayer::freeVideo()
{

}

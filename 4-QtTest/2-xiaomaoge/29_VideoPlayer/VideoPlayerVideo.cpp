#include "VideoPlayer.h"
#include "Utils.h"

int VideoPlayer::initVideoInfo()
{
    int ret = initDecoder(&mvDecodeCtx, &mvStream, AVMEDIA_TYPE_VIDEO);
    RET(initDecoder);
    return ret;
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

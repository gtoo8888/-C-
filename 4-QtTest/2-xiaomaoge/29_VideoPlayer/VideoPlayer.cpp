#include "VideoPlayer.h"
#include <thread>
#include <QDebug>
#include <QThread>

VideoPlayer::VideoPlayer(QObject *parent) : QObject(parent)
{

}

VideoPlayer::~VideoPlayer()
{

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

void VideoPlayer::setState(VideoPlayer::State state){
    if(state == mState)
        return;
    mState = state;
    emit stateUpdate(this);
}

void VideoPlayer::readFile()
{
    qDebug() << "readFile" << QThread::currentThread();
}

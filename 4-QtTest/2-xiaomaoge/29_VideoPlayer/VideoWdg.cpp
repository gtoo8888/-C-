#include "VideoWdg.h"

VideoWdg::VideoWdg(QWidget *parent) : QWidget(parent)
{

}

VideoWdg::~VideoWdg(void)
{
    if(!mImage){
        delete mImage;
        mImage = nullptr;
    }
}

void VideoWdg::slotPlayerFrameDecoded(VideoPlayer *player, uint8_t *data, VideoPlayer::VideoSwsSpec spec)
{
    qDebug() << "slotPlayerFrameDecoded";
    // 释放之前的图片
    if(!mImage){
        delete mImage;
        mImage = nullptr;
    }

    // 创建新的图片

    if(data != nullptr){
            qDebug() << data[0];
        mImage = new QImage((uchar *) data,
                            spec.widght,
                            spec.height,
                            QImage::Format_RGB888);
    }
}

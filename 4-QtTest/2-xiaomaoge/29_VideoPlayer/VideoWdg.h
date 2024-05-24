#ifndef VIDEOWDG_H
#define VIDEOWDG_H

#include <QWidget>
#include "VideoPlayer.h"
#include <QImage>
#include "Utils.h"


/**
 * @brief 显示 (渲染) 视频数据
 */

class VideoWdg : public QWidget
{
    Q_OBJECT
public:
    explicit VideoWdg(QWidget *parent = nullptr);
    ~VideoWdg(void);

public slots:
    void slotPlayerFrameDecoded(VideoPlayer* player,
                                uint8_t* data,
                                VideoPlayer::VideoSwsSpec spec);
signals:

private:
    QImage *mImage = nullptr;
};

#endif // VIDEOWDG_H

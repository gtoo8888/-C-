#ifndef VIDEOWDG_H
#define VIDEOWDG_H

#include <QImage>
#include <QWidget>
#include "Utils.h"
#include "XVPlayer.h"

/**
 * @brief 显示 (渲染) 视频数据
 */

class VideoWdg : public QWidget {
    Q_OBJECT
public:
    explicit VideoWdg(QWidget* parent = nullptr);
    ~VideoWdg(void);

public slots:
    void slotPlayerFrameDecoded(XVPlayer* player, uint8_t* data, XVPlayer::VideoSwsSpec spec);
signals:

private:
    QImage* mImage = nullptr;
};

#endif  // VIDEOWDG_H

#ifndef VIDEOWDG_H
#define VIDEOWDG_H

#include <QWidget>

/**
 * @brief 显示 (渲染) 视频数据
 */

class VideoWdg : public QWidget
{
    Q_OBJECT
public:
    explicit VideoWdg(QWidget *parent = nullptr);

signals:

};

#endif // VIDEOWDG_H

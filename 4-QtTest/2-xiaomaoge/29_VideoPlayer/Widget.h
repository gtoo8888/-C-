#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "VideoPlayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnOpenFile_clicked();
    void slotPlayerStateUpdate(VideoPlayer* player);
    void slotPlayerInitFinish(VideoPlayer* player);
    void slotPlayerFailed(VideoPlayer* player);

    void on_btnPlayer_clicked();
    void on_btnStop_clicked();
    void on_sliderVoice_valueChanged(int value);
    void on_sliderTime_valueChanged(int value);

private:
    Ui::Widget *ui;
    VideoPlayer* mVideoPlayer = nullptr;

    QString getDiratonText(int64_t millisecond);
};
#endif // WIDGET_H

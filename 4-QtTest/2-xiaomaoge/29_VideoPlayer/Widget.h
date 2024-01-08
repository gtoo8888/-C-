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

    void on_btnPlayer_clicked();

    void on_btnStop_clicked();

    void on_sliderVoice_valueChanged(int value);

private:
    Ui::Widget *ui;
    VideoPlayer* mVideoPlayer = nullptr;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "XVPlayer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class XVPlayerWidget;
}
QT_END_NAMESPACE

class XVPlayerWidget : public QWidget {
    Q_OBJECT

public:
    XVPlayerWidget(QWidget* parent = nullptr);
    ~XVPlayerWidget();

private slots:
    void on_btnOpenFile_clicked();
    void slotPlayerStateUpdate(XVPlayer* player);
    void slotPlayerInitFinish(XVPlayer* player);
    void slotPlayerFailed(XVPlayer* player);

    void on_btnPlayer_clicked();
    void on_btnStop_clicked();
    void on_sliderVoice_valueChanged(int value);
    void on_sliderTime_valueChanged(int value);

private:
    Ui::XVPlayerWidget* ui;
    XVPlayer* mVideoPlayer = nullptr;

    QString getDiratonText(int64_t millisecond);
};
#endif  // WIDGET_H

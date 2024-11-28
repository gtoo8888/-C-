#ifndef STOPWATCHCLOCKWDG_H
#define STOPWATCHCLOCKWDG_H

#include <QWidget>

namespace Ui {
class StopwatchClockWdg;
}

class StopwatchClockWdg : public QWidget
{
    Q_OBJECT

public:
    explicit StopwatchClockWdg(QWidget *parent = nullptr);
    ~StopwatchClockWdg();

private:
    Ui::StopwatchClockWdg *ui;
};

#endif // STOPWATCHCLOCKWDG_H

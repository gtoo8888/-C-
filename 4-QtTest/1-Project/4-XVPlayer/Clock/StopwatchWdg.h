#ifndef STOPWATCHWDG_H
#define STOPWATCHWDG_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "StopwatchClockWdg.h"

namespace Ui {
class StopwatchWdg;
}

class StopwatchWdg : public QWidget
{
    Q_OBJECT

public:
    explicit StopwatchWdg(QWidget *parent = nullptr);
    ~StopwatchWdg();

private slots:

    void slotBtnNewClock(void);

private:
    Ui::StopwatchWdg *ui;

    QVBoxLayout *vlayout;


    QVector<StopwatchClockWdg*>  clockWdgVec;


};

#endif // STOPWATCHWDG_H

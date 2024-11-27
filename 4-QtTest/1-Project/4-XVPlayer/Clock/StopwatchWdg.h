#ifndef STOPWATCHWDG_H
#define STOPWATCHWDG_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>

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
    void updateDisplay(void);
    void on_btnClockStart_clicked();

private:
    Ui::StopwatchWdg *ui;

    QTimer* nowTime;
    QTime baseTime;

    QString timeStr;
    QString initTimeStr = QString("00:00:00.000");


};

#endif // STOPWATCHWDG_H

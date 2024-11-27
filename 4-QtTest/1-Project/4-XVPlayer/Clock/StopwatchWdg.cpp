#include "StopwatchWdg.h"
#include "ui_StopwatchWdg.h"
#include <QDebug>

StopwatchWdg::StopwatchWdg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StopwatchWdg)
{
    ui->setupUi(this);
    ui->labShowTime->setText(initTimeStr);

    this->nowTime = new QTimer;

    connect(this->nowTime,&QTimer::timeout,this,&StopwatchWdg::updateDisplay);
}

StopwatchWdg::~StopwatchWdg()
{
    delete ui;
}

void StopwatchWdg::updateDisplay()
{
    /*
     * 1.点击开始后获取到当前的时间并且赋值给baseTime
     * 2.启动定时器,间隔1s
     * 3.槽函数中再次获取当前的时间currTime
     * 4.计算两个时间的差值t
     * 5.声明一个showTime对象给他加上t的差值
     * 6.格式化后设置显示
     */
    QTime currTime = QTime::currentTime();
    int t = this->baseTime.msecsTo(currTime);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    this->timeStr = showTime.toString("hh:mm:ss:zzz");
    ui->labShowTime->setText(timeStr);
}

void StopwatchWdg::on_btnClockStart_clicked()
{
    if(ui->btnClockStart->text() == "开始"){
        this->baseTime = this->baseTime.currentTime();
        this->nowTime->start(1);
        ui->btnClockStart->setText("停止");
    }else if(ui->btnClockStart->text() == "停止"){
        ui->btnClockStart->setText("开始");
        this->nowTime->stop();
    }
}

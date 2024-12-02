#include "StopwatchClockWdg.h"
#include "ui_StopwatchClockWdg.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

StopwatchClockWdg::StopwatchClockWdg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StopwatchClockWdg),
    clockNowStatus(stop),
    nameModifyStatus(lock),
    clockIndex(-1),
    nowClockCount(0),
    initTimeStr(QString("00:00:00.000")),
    stopwatchClockName(QString("Stopwatch"))
{
    ui->setupUi(this);
    this->nowTime = new QTimer;

    initUi();
    initConnect();
}

void StopwatchClockWdg::initUi()
{
    ui->labShowTime->setText(initTimeStr);
//    ui->tableWdgTimeCount->setCurrentIndex(0);
    cleanTableWdg();
    ui->tableWdgTimeCount->verticalHeader()->setVisible(false);
    ui->tableWdgTimeCount->setSelectionBehavior(QAbstractItemView::SelectRows); // 可以选中一行
    ui->tableWdgTimeCount->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->leClockName->setEchoMode(QLineEdit::Normal);
    ui->leClockName->setEnabled(false); // 不可修改
    ui->leClockName->setText(stopwatchClockName);
}

void StopwatchClockWdg::initConnect()
{
    connect(ui->btnStart,&QPushButton::clicked,this,&StopwatchClockWdg::slotBtnStart);
    connect(ui->btnReset,&QPushButton::clicked,this,&StopwatchClockWdg::slotBtnReset);
    connect(ui->btnDownload,&QPushButton::clicked,this,&StopwatchClockWdg::slotBtnDownload);
    connect(ui->btnTimeCount,&QPushButton::clicked,this,&StopwatchClockWdg::slotBtnTimeCount);
    connect(ui->btnNameModify,&QPushButton::clicked,this,&StopwatchClockWdg::slotBtnNameModify);
    connect(this->nowTime,&QTimer::timeout,this,&StopwatchClockWdg::slotUpdateDisplay);
}

void StopwatchClockWdg::cleanTableWdg()
{
    ui->tableWdgTimeCount->clear();
    while (ui->tableWdgTimeCount->rowCount() > 0) {
        ui->tableWdgTimeCount->removeRow(0);
    }
    ui->tableWdgTimeCount->setHorizontalHeaderLabels(QStringList() <<"序号"<<"计次");
}

StopwatchClockWdg::~StopwatchClockWdg()
{
    delete ui;
}

void StopwatchClockWdg::setClockIndex(uint8_t idx)
{
    this->clockIndex = idx;
    ui->labClockNum->setText(QString("秒表%1").arg(clockIndex));
}

void StopwatchClockWdg::slotUpdateDisplay()
{
//     1.点击开始后获取到当前的时间并且赋值给baseTime
//     2.启动定时器,间隔1s
//     3.槽函数中再次获取当前的时间currTime
//     4.计算两个时间的差值t
//     5.声明一个showTime对象给他加上t的差值
//     6.格式化后设置显示
    QTime currTime = QTime::currentTime();
    int t = this->baseTime.msecsTo(currTime);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    this->timeStr = showTime.toString("hh:mm:ss.zzz");
    ui->labShowTime->setText(timeStr);
}



void StopwatchClockWdg::slotBtnStart()
{
    if(clockNowStatus == ClockStatus::stop){
        clockNowStatus = ClockStatus::run;
        this->baseTime = this->baseTime.currentTime();
        this->nowTime->start(1);
        ui->btnStart->setText("暂停");
    }else if(clockNowStatus == ClockStatus::pause){
        clockNowStatus = ClockStatus::run;
        this->nowTime->start(1);
        ui->btnStart->setText("暂停");
    }else if(clockNowStatus == ClockStatus::run){
        clockNowStatus = ClockStatus::pause;
        ui->btnStart->setText("开始");
        this->nowTime->stop();
    }
}

void StopwatchClockWdg::slotBtnReset()
{
    clockNowStatus = ClockStatus::stop;
    ui->btnStart->setText("开始");
    this->nowTime->stop();
    ui->labShowTime->setText(initTimeStr);
    nowClockCount = 0;
    cleanTableWdg();
}

void StopwatchClockWdg::slotBtnDownload()
{
    uint8_t nowCout = ui->tableWdgTimeCount->rowCount();
    if(nowCout == 0){
        QMessageBox::warning(this,"警告","警告！保存内容不能为空!");
        return;
    }

    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString dateTimeStr = dateTime.toString("yyyyMMddhhmm");//格式化时间
    QString saveFileName = QString("%1_%2").arg(stopwatchClockName).arg(dateTimeStr);
    QString filename= QFileDialog::getSaveFileName(this,"保存秒表记录",saveFileName,"(*.csv)");

    if(filename.isEmpty())
        return;

    QString outStr = QString("idx,time count\n");
    for(int i = 0;i < nowCout;i++){
        QString outStrLine = QString("%1,%2\n").arg(vTimeCount[i].index).arg(vTimeCount[i].nowTime);
        outStr += outStrLine;
    }


    QFile file(filename);
    file.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream stream(&file);
    stream << outStr;
    file.close();

}

void StopwatchClockWdg::slotBtnTimeCount()
{
    nowClockCount += 1;
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(baseTime.msecsTo(QTime::currentTime()));
    QString nowTimeStr = showTime.toString("hh:mm:ss.zzz");

    qDebug() << QString("idx:%1 time:%2").arg(nowClockCount).arg(nowTimeStr);


    TimeCountInfo nowInfo{
        .index = nowClockCount,
        .nowTime = nowTimeStr
    };

    vTimeCount.push_back(nowInfo);

    uint8_t tableWdgIdx = ui->tableWdgTimeCount->rowCount();
    ui->tableWdgTimeCount->setRowCount(tableWdgIdx+1); // 一定要设置行数以后才能显示
    ui->tableWdgTimeCount->setItem(tableWdgIdx,0,new QTableWidgetItem(QString::number(nowInfo.index)));
    ui->tableWdgTimeCount->setItem(tableWdgIdx,1,new QTableWidgetItem(nowInfo.nowTime));
}

void StopwatchClockWdg::slotBtnNameModify()
{
    if (nameModifyStatus == NameModifyStatus::lock){
        nameModifyStatus = NameModifyStatus::modify;
        ui->leClockName->setEnabled(true);
        ui->btnNameModify->setText("确定");
    }else if (nameModifyStatus == NameModifyStatus::modify){
        nameModifyStatus = NameModifyStatus::lock;
        ui->leClockName->setEnabled(false);
        stopwatchClockName = ui->leClockName->text();
        ui->btnNameModify->setText("修改");
        qDebug() << stopwatchClockName;
    }
}

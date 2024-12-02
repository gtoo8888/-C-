#include "StopwatchWdg.h"
#include "ui_StopwatchWdg.h"
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

StopwatchWdg::StopwatchWdg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StopwatchWdg)
{
    ui->setupUi(this);
    vlayout = new QVBoxLayout(this);
    ui->clockShowWdg->setLayout(vlayout);

    connect(ui->btnNewClock,&QPushButton::clicked,this,&StopwatchWdg::slotBtnNewClock);
}

StopwatchWdg::~StopwatchWdg()
{
    delete ui;
}

void StopwatchWdg::slotBtnNewClock(void)
{
    int nowClockNum = clockWdgVec.size();
    if (nowClockNum < 3){
        StopwatchClockWdg* stopwatchClockWdg = new StopwatchClockWdg(ui->clockShowWdg);
        clockWdgVec.push_back(stopwatchClockWdg);
        vlayout->addWidget(stopwatchClockWdg);
        stopwatchClockWdg->setClockIndex(clockWdgVec.size());
        stopwatchClockWdg->show();
    }else{
        QMessageBox box(QMessageBox::Warning, QString("警告"),QString("当前秒表达到最大%1个").arg(nowClockNum));
        box.exec();
    }
}



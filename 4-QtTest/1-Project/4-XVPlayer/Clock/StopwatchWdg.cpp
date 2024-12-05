#include "StopwatchWdg.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include "StopwatchSetWdg.h"
#include "ui_StopwatchWdg.h"

StopwatchWdg::StopwatchWdg(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::StopwatchWdg),
      maxClockNum(6),
      updateTimer(new QTimer) {
    ui->setupUi(this);
    vlayout = new QVBoxLayout(this);
    ui->clockShowWdg->setLayout(vlayout);
    ui->labIcon->installEventFilter(this);

    connect(ui->btnNewClock, &QPushButton::clicked, this, &StopwatchWdg::slotBtnNewClock);
    connect(ui->btnCleanClock, &QPushButton::clicked, this, &StopwatchWdg::slotBtnCleanClock);
    connect(this->updateTimer, &QTimer::timeout, this, &StopwatchWdg::slotupdateNowTime);

    updateTimer->start();

    LOG_INF("  ");
    LOG_INF("init StopwatchWdg");
}

StopwatchWdg::~StopwatchWdg() {
    delete ui;
}

void StopwatchWdg::slotBtnNewClock(void) {
    int nowClockNum = clockWdgVec.size();
    if (nowClockNum < maxClockNum) {
        StopwatchClockWdg* stopwatchClockWdg = new StopwatchClockWdg(ui->clockShowWdg);
        clockWdgVec.push_back(stopwatchClockWdg);
        vlayout->addWidget(stopwatchClockWdg);
        stopwatchClockWdg->setClockIndex(clockWdgVec.size());
        connect(stopwatchClockWdg, &StopwatchClockWdg::sigClockCloseWnd, this, &StopwatchWdg::slotClockClose);
        stopwatchClockWdg->show();
    } else {
        QMessageBox box(QMessageBox::Warning, QString("警告"), QString("当前秒表达到最大%1个").arg(nowClockNum));
        box.exec();
    }
}

void StopwatchWdg::slotBtnCleanClock() {
    for (auto it = clockWdgVec.begin(); it != clockWdgVec.end(); it++) {
        StopwatchClockWdg* deleteClock = *it;
        delete deleteClock;
    }
    clockWdgVec.clear();
}

void StopwatchWdg::slotClockClose(int clockIndex) {
    StopwatchClockWdg* nowClockClose = clockWdgVec[clockIndex - 1];
    delete nowClockClose;
    clockWdgVec.erase(clockWdgVec.begin() + clockIndex - 1);

    for (int idx = 0; idx < clockWdgVec.size(); idx++) {
        clockWdgVec[idx]->setClockIndex(idx + 1);
    }
}

void StopwatchWdg::slotupdateNowTime(void) {
    ui->labShowTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

bool StopwatchWdg::eventFilter(QObject* watched, QEvent* event) {
    if (watched == ui->labIcon) {
        if (QEvent::MouseButtonDblClick == event->type()) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                LOG_INF("LeftDbButton");
                slotEventLabSettingClock();
                return true;
            } else if (mouseEvent->button() == Qt::RightButton) {
                LOG_INF("RightDbButton");
                return true;
            }
        }
    }
    return false;
}

void StopwatchWdg::slotEventLabSettingClock() {
    StopwatchSetWdg* stopwatchSetWdg = new StopwatchSetWdg();
    stopwatchSetWdg->show();
}

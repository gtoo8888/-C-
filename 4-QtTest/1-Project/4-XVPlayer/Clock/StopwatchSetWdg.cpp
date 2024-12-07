#include "StopwatchSetWdg.h"
#include "ui_StopwatchSetWdg.h"

StopwatchSetWdg::StopwatchSetWdg(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::StopwatchSetWdg) {
    ui->setupUi(this);

    initUi();
}

StopwatchSetWdg::~StopwatchSetWdg() {
    delete ui;
}

void StopwatchSetWdg::initUi()
{
    this->resize(600, 400);
    this->setMinimumSize(QSize(600, 400));
    this->setMaximumSize(QSize(600, 400));


    ui->tabWidget->setTabText(0, QString("设置"));
    ui->tabWidget->setTabText(1, QString("快捷键"));
    ui->tabWidget->setTabText(2, QString("关于"));
    ui->tabWidget->setCurrentIndex(0);
}

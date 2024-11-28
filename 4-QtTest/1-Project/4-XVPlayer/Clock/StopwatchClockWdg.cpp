#include "StopwatchClockWdg.h"
#include "ui_StopwatchClockWdg.h"

StopwatchClockWdg::StopwatchClockWdg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StopwatchClockWdg)
{
    ui->setupUi(this);
}

StopwatchClockWdg::~StopwatchClockWdg()
{
    delete ui;
}

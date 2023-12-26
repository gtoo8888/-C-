#include "ChatWindows.h"
#include "ui_Chatwindows.h"

ChatWindows::ChatWindows(QWidget *parent,QString userName) :
    QWidget(parent),
    ui(new Ui::ChatWindows)
{
    ui->setupUi(this);
}

void ChatWindows::closeEvent(QCloseEvent *event){
    emit this->closeChatWnd();
    QWidget::closeEvent(event);
}

ChatWindows::~ChatWindows()
{
    delete ui;
}

#include "Login.h"
#include "StuManage.h"
#include "ui_Login.h"
#include "Utils.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    initConnect();
}

Login::~Login()
{
    delete ui;
}


void Login::initConnect()
{
    connect(ui->btnLoign,&QPushButton::clicked,this,&Login::slotOpenStuManage);
    connect(ui->btnExit,&QPushButton::clicked,this,&Login::slotExitLogin);

    enterAction->setShortcut(Qt::Key_Enter);
    connect(enterAction, &QAction::triggered, this, &Login::slotOpenStuManage);
}

void Login::keyPressEvent(QKeyEvent *event)
{
    int keyType = event->key();
    switch(keyType){
    case Qt::Key_Enter:
    case Qt::Key_Return:
        myDebug() << "Key_Enter";
        slotOpenStuManage();
        break;
    case Qt::Key::Key_F7:
        myDebug() << "Key_F7";
        break;
    }
}

void Login::slotOpenStuManage()
{
    StuManage* stuManage = new StuManage(this);
    stuManage->show();
}

void Login::slotExitLogin()
{
    close();
}




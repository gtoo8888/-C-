#include "Login.h"
#include "StuManage.h"
#include "ui_Login.h"
#include "Utils.h"
#include "DlgUserModify.h"
#include "DlgForgetPwd.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    mpSql = StuSql::getInstance();

    initUi();
    initConnect();
}

Login::~Login()
{
    delete ui;
}

void Login::initUi()
{
    ui->labelAddUser->installEventFilter(this); // label没有clicked事件，只能使用事件过滤器处理
    ui->labelForgetPwd->installEventFilter(this);
}


void Login::initConnect()
{
    connect(ui->btnLoign,&QPushButton::clicked,this,&Login::slotOpenStuManage);
    connect(ui->btnExit,&QPushButton::clicked,this,&Login::slotExitLogin);
    connect(ui->btnExit,&QPushButton::clicked,this,&Login::slotExitLogin);


//    enterAction->setShortcut(Qt::Key_Enter); // 没用
//    connect(enterAction, &QAction::triggered, this, &Login::slotOpenStuManage);
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
    case Qt::Key::Key_Escape:
        slotExitLogin();
        break;
    }
}

void Login::slotOpenStuManage(){
    QString userName = ui->lineEditUserName->text();
    QString password = ui->lineEditPassword->text();

    UserInfo userInfo = mpSql->getUserInfofromName(userName);

    QString userAuth("");
    if(userInfo.id == -1){
        QMessageBox::warning(this,"警告","用户不存在");
    }else{
        if(userInfo.password == password){
            myDebug() << "密码正确";
            mpStuManage = new StuManage(userInfo);
            mpStuManage->show();
            connect(mpStuManage,&StuManage::signalsCloseWnd,this,&Login::slotReShowLogin);
            this->hide();
            return;
        }else{
            QMessageBox::warning(this,"警告","密码错误");
            return;
        }
    }
}

void Login::slotExitLogin()
{
    close();
}

void Login::slotReShowLogin(void)
{
    this->show();
    mpStuManage->deleteLater();
}

void Login::slotlabelAddUser()
{
    DlgUserModify* dlgUserModify = new DlgUserModify();
    dlgUserModify->exec();
}

void Login::slotForgetPwd()
{
    DlgForgetPwd* dlgForgetPwd = new DlgForgetPwd();
    dlgForgetPwd->exec();
}

bool Login::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->labelAddUser){
         if(QEvent::MouseButtonPress == event->type()){
             QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
             if(mouseEvent->button() == Qt::LeftButton){
                 myDebug()<<"LeftButton";
                 slotlabelAddUser();
                 return true;
             }else if(mouseEvent->button() == Qt::RightButton){
                 myDebug()<<"RightButton";
                 return true;
             }
         }
    }else if(watched == ui->labelForgetPwd){
        if(QEvent::MouseButtonPress == event->type()){
            slotForgetPwd();
        }
    }
    return false;
}





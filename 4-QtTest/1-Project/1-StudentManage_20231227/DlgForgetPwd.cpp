#include "DlgForgetPwd.h"
#include "ui_DlgForgetPwd.h"
#include "Utils.h"


DlgForgetPwd::DlgForgetPwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgForgetPwd)
{
    ui->setupUi(this);
    initUi();
    initConnect();
}

DlgForgetPwd::~DlgForgetPwd()
{
    delete ui;
}

void DlgForgetPwd::initUi()
{

}

void DlgForgetPwd::initConnect()
{
    connect(ui->btnSave,&QPushButton::clicked,this,&DlgForgetPwd::slotBtnSave);
    connect(ui->btnCancel,&QPushButton::clicked,this,&DlgForgetPwd::slotBtnCancel);
    connect(ui->btnExitUserName,&QPushButton::clicked,this,&DlgForgetPwd::slotBtnExitUserName);
}

void DlgForgetPwd::slotBtnExitUserName()
{
    sql = StuSql::getInstance();
    QString userName = ui->leUserName->text();
    if(sql->isExit(userName)){
        QMessageBox::information(this,"信息","用户存在");
    }else{
        QMessageBox::warning(this,"警告","用户不存在,请注册");
        this->reject();
    }
}

void DlgForgetPwd::slotBtnCancel()
{
    myDebug() << "Cancel";
    this->reject();
}

void DlgForgetPwd::slotBtnSave()
{
    myDebug() << "Save";
    sql = StuSql::getInstance();
    QString userName = ui->leUserName->text();
    QString password = ui->leNewPwd->text();

    if(password.isEmpty()){
        QMessageBox::warning(this,"警告","新密码不能为空");
        return;
    }

    UserInfo oldUserInfo = sql->getUserInfofromName(userName);
    oldUserInfo.password = password;
    sql->updateUserPwd(oldUserInfo);
    QMessageBox::information(this,"信息","修改密码成功");
    this->accept();
}


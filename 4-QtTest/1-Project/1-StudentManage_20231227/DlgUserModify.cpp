#include "DlgUserModify.h"
#include "ui_DlgUserModify.h"
#include "StuSql.h"
#include "Utils.h"

DlgUserModify::DlgUserModify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUserModify)
{
    ui->setupUi(this);
    initUi();
    initConnect();
}

DlgUserModify::~DlgUserModify()
{
    delete ui;
}

void DlgUserModify::initUi()
{

}

void DlgUserModify::initConnect()
{
    connect(ui->btnCancel,&QPushButton::clicked,this,&DlgUserModify::slotBtnCancel);
    connect(ui->btnSave,&QPushButton::clicked,this,&DlgUserModify::slotBtnSave);
}

void DlgUserModify::slotBtnCancel()
{
    this->reject();
}

void DlgUserModify::slotBtnSave()
{
    UserInfo info;
    StuSql* sql = StuSql::getInstance();
    info.userName = ui->leUserName->text();
    info.password = ui->lePassword->text();
    QString authStr = ui->comboBoxAuthType->currentText();
    if(QString("教师") == authStr)
        info.auth = UserInfo::AuthType::Teacher;
    else if(QString("学生") == authStr)
        info.auth = UserInfo::AuthType::Student;
    sql->addUser(info);
    QMessageBox::information(this,"信息","添加成功");

    this->accept(); // 回车直接执行
}



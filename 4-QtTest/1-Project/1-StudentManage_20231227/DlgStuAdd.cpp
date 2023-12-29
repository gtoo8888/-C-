#include "DlgStuAdd.h"
#include "ui_DlgStuAdd.h"
#include "Utils.h"

DlgStuAdd::DlgStuAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgStuAdd)
{
    ui->setupUi(this);
    initConnect();
}

DlgStuAdd::~DlgStuAdd()
{
    delete ui;
}

void DlgStuAdd::setType(DlgStuAdd::ModType type, StuInfo *info)
{
    mType = type;
    mStuInfo = info;
    if(ModType::Add == mType){

    }else if(ModType::Update == mType){
        ui->leName->setText(info->name);
        ui->spinBoxAge->setValue(info->age);
        ui->leGrade->setText(QString::number(info->score));
        ui->leClassNum->setText(QString::number(info->classNum));
        ui->leStudentId->setText(QString::number(info->studentId));
        ui->lePhone->setText(info->phone);
    }
}

void DlgStuAdd::initConnect()
{
    connect(ui->btnSave,&QPushButton::clicked,this,&DlgStuAdd::slotBtnSave);
    connect(ui->btnCancel,&QPushButton::clicked,this,&DlgStuAdd::slotBtnCancel);
}

// TODO：处理非法输入
// 学生被开除了
// 姓和名分开
// 成绩管理
void DlgStuAdd::slotBtnSave()
{
    StuInfo info;
    StuSql* sql = StuSql::getInstance();
    info.name = ui->leName->text();
    info.age = ui->spinBoxAge->text().toUInt();
    info.score = ui->leGrade->text().toUInt();
    info.classNum = ui->leClassNum->text().toUInt();
    info.studentId = ui->leStudentId->text().toUInt();
    info.phone = ui->lePhone->text();
    if(ModType::Add == mType){
        if(sql->addStu(info)){
            QMessageBox::information(this,"信息","添加成功");
        }
    }else if(ModType::Update == mType){
        info.id = mStuInfo->id;
        if(sql->updateStuInfo(info)){
            QMessageBox::information(this,"信息","修改成功");
        }
    }
    this->accept(); // 回车直接执行
}

void DlgStuAdd::slotBtnCancel()
{
    this->reject();
}





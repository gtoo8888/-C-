#include "StuManage.h"
#include "ui_StuManage.h"
#include "Utils.h"
#include <QFile>
#include <QTimer>

StuManage::StuManage(UserInfo userInfo, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mpStuSql(nullptr)
    , dlgStuAdd(new DlgStuAdd(this))
{
    ui->setupUi(this);
    mpStuSql = StuSql::getInstance();

    mUserInfo = userInfo;
    initUi();
    initConnect();
}

StuManage::~StuManage()
{
    delete ui;
    delete mpStuSql;
}

void StuManage::initUi(void)
{
    tmpExample = ui->menubar->addMenu("example");
    tmpSimulationData = tmpExample->addAction("模拟数据");
    tmpClearStuData = tmpExample->addAction("清空数据");

    ui->labelUserName->setText(QString("欢迎您,%1!").arg(mUserInfo.userName));
    // TODO： 换成图标
    if(mUserInfo.auth == UserInfo::AuthType::Admin){
        ui->tbUserType->setText(QString("A"));
    }else if(mUserInfo.auth == UserInfo::AuthType::Teacher){
        ui->tbUserType->setText(QString("T"));
    }else if(mUserInfo.auth == UserInfo::AuthType::Student){
        ui->tbUserType->setText(QString("S"));
    }
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 可以选中一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    updateTable();
}

void StuManage::initConnect()
{
    connect(tmpSimulationData,&QAction::triggered,this,&StuManage::slotTmpSimulationData);
    connect(tmpClearStuData,&QAction::triggered,this,&StuManage::slotTmpClearStu);
    connect(ui->btnStuSearch,&QPushButton::clicked,this,&StuManage::slotbtnSearchStu);
    connect(ui->btnStuAdd,&QPushButton::clicked,this,&StuManage::slotbtnAddStu);
    connect(ui->btnStuUpdate,&QPushButton::clicked,this,&StuManage::slotbtnUpdateStu);
    connect(ui->btnStuDel,&QPushButton::clicked,this,&StuManage::slotbtnDelStu);
    connect(ui->btnExit,&QPushButton::clicked,this,&StuManage::close);
}

void StuManage::updateTable()
{
    quint32 cnt = mpStuSql->getStuCnt();
    QList<StuInfo> listStu = mpStuSql->getPageStu(0,cnt); // 获取到所有数据

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"序号"<<"名称"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话");
    ui->tableWidget->setRowCount(cnt);
    for(int i = 0;i < listStu.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(listStu[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(listStu[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(listStu[i].age)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(listStu[i].score)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(listStu[i].classNum)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(listStu[i].studentId)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(listStu[i].phone));
    }

    ui->statusbar->showMessage(QString("班级人数: %1").arg(cnt));
}

void StuManage::keyPressEvent(QKeyEvent *event)
{
    int keyType = event->key();
    switch(keyType){
    case Qt::Key::Key_F6:
        myDebug() << "F6";
        QFile file;
        file.setFileName("://StuManage.qss");
        file.open(QIODevice::ReadOnly);
        QString strQss = file.readAll();
//        myDebug() << strQss;
//        this->setStyleSheet(strQss);
        break;
    }
}

void StuManage::slotTmpSimulationData()
{
    myDebug() << "slotSimulationData";
    for(int i = 1;i <= 100;i++){
        StuInfo stuInfo;
        stuInfo.age = 10+i;
        stuInfo.name = QString("测试%1").arg(i);
        stuInfo.score = 2+i;
        stuInfo.classNum = 3+i;
        stuInfo.studentId = 4+i;
        stuInfo.phone =  QString("%1%2%3").arg(i).arg(i).arg(i);
        mpStuSql->addStu(stuInfo);
    }
    updateTable();
}

void StuManage::slotTmpClearStu()
{
    mpStuSql->clearStuTable();
    updateTable();
}

void StuManage::slotbtnAddStu()
{
    dlgStuAdd->setType(DlgStuAdd::ModType::Add);
    dlgStuAdd->exec();
    updateTable();
}

void StuManage::slotbtnUpdateStu()
{
    int idx = ui->tableWidget->currentRow();
    if(-1 == idx){
        QMessageBox::warning(this,"警告","未选中目标");
    }else{
        StuInfo* info = new StuInfo;
        info->id = ui->tableWidget->item(idx,0)->text().toUInt();
        info->name = ui->tableWidget->item(idx,1)->text();
        info->age = ui->tableWidget->item(idx,2)->text().toUInt();
        info->score = ui->tableWidget->item(idx,3)->text().toUInt();
        info->classNum = ui->tableWidget->item(idx,4)->text().toUInt();
        info->studentId = ui->tableWidget->item(idx,5)->text().toUInt();
        info->phone = ui->tableWidget->item(idx,6)->text();
        dlgStuAdd->setType(DlgStuAdd::ModType::Update, info);
        dlgStuAdd->exec();
        updateTable();
    }



}

void StuManage::slotbtnDelStu()
{
    int idx = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(idx,1)->text().toUInt();
    mpStuSql->delStu(id);
    updateTable();
}

void StuManage::slotbtnSearchStu()
{
    quint32 cnt = mpStuSql->getStuCnt();
    QList<StuInfo> listStu = mpStuSql->getPageStu(0,cnt); // 获取到所有数据

    QString strFilter = ui->lineEdit->text();
    QList<StuInfo> filterStu;
    for(int i = 0;i < listStu.size();i++){
        if(listStu[i].name.contains(strFilter)){
            filterStu.push_back(listStu[i]);
        }
    }

    int filterStuNum = filterStu.size();

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"序号"<<"名称"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话");
    ui->tableWidget->setRowCount(filterStuNum);
    for(int i = 0;i < filterStuNum;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(filterStu[i].id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(filterStu[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(filterStu[i].age)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(filterStu[i].score)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(filterStu[i].classNum)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(filterStu[i].studentId)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(filterStu[i].phone));
    }

    ui->statusbar->showMessage(QString("筛选后人数: %1").arg(filterStuNum));
}

void StuManage::slotbtnExit()
{
    emit signalsCloseWnd();
    QTimer::singleShot(100, this, [this]() {
        this->hide();
    });

}







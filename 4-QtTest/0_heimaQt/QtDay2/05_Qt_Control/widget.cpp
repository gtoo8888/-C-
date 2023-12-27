#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮男默认选中
    ui->rBtnMan->setChecked(true);

    //选中女后打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug() << "选中了女的";
    });

    //多选按钮z是选中0是未选中
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用listwidget写诗
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //将一行诗放入到listwidget控件中
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter);

//    QStringList QList<QString>  相同
    QStringList list;
    list <<"锄禾日当午"<<"旱地和下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

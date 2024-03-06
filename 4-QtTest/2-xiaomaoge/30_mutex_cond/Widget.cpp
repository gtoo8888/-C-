#include "Widget.h"
#include "ui_Widget.h"


// 生产者，消费者模型
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_testBtn1_clicked()
{
    form1 = new Form1();
    form1->show();
}

void Widget::on_testBtn2_clicked()
{
    form2 = new Form2();
    form2->show();
}

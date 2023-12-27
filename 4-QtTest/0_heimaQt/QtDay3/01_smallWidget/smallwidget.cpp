#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QspinBox移动Qslider跟着移动
    void(QSpinBox:: * spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);

    //Qslider滑动QspinBox数字跟着改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

int SmallWidget::getNum(){
    ui->spinBox->value();
}

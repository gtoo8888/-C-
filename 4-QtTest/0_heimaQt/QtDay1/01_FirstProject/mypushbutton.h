#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = 0);

    ~myPushButton();//想要显示它的构造和析构内容
    //在.h中定义类的形式，在.cpp中写具体的类的内容
signals:

public slots:

};

#endif // MYPUSHBUTTON_H

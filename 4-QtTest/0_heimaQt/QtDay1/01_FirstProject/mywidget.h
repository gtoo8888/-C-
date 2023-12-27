#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>//包含头文件qwidget窗口类


class myWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = 0);//构造函数
    ~myWidget();
};

#endif // MYWIDGET_H

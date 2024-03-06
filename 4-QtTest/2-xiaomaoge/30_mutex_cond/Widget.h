#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Form1.h"
#include "Form2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_testBtn1_clicked();

    void on_testBtn2_clicked();

private:
    Ui::Widget *ui;
    Form1 *form1;
    Form2 *form2;
};
#endif // WIDGET_H

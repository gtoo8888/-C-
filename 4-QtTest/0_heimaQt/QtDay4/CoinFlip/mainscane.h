#ifndef MAINSCANE_H
#define MAINSCANE_H

#include <QMainWindow>
#include "chooselevescane.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScane; }
QT_END_NAMESPACE

class MainScane : public QMainWindow
{
    Q_OBJECT

public:
    MainScane(QWidget *parent = nullptr);
    ~MainScane();

    void paintEvent(QPaintEvent *);

    ChooseLeveScane *chooseScane = NULL;

private:
    Ui::MainScane *ui;
};
#endif // MAINSCANE_H

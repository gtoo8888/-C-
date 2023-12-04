#pragma once

#include <QObject>
#include "ui_about.h"

class About  : public QWidget
{
    Q_OBJECT

public:
    About(QWidget *parent);
    ~About();

    void closeCurrentWindow();

private:
    Ui::About* ui;
};

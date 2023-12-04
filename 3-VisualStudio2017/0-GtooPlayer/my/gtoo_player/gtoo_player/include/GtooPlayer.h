#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GtooPlayer.h"

class GtooPlayer : public QMainWindow
{
    Q_OBJECT

public:
    GtooPlayer(QWidget *parent = nullptr);
    void initConnect(void);
    void initUi(void);
    ~GtooPlayer();


    QPushButton* openSecond1;
    QPushButton* openFileButton;

public slots:
    void openAbout(void);
    void openFile(void);

private:
    Ui::GtooPlayerClass* ui;
};

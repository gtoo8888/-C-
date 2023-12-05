#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GtooPlayer.h"
#include "ReadThread.h"

class GtooPlayer : public QMainWindow
{
    Q_OBJECT

public:
    GtooPlayer(QWidget *parent = nullptr);
    ~GtooPlayer();

    QPushButton* buttonOccupy;
    QMenu* tmpExampleMenu; // TODE 临时demo
    QAction* tmpExampleMenuOpen;  // TODE 临时demo

public slots:
    void openAbout(void);
    void openFile(void);
    void openExample(void);

    void pauseVideo(void);
    void startVideo(void);

private:
    void initUtils(void);
    void initConnect(void);
    void initUi(void);
    void onPlayState(ReadThread::PlayState state);

private:
    Ui::GtooPlayerClass* ui;
    QString mPlayerTitile = QString("我的播放器-GtooPlay");
    ReadThread* mReadThread = nullptr;
};

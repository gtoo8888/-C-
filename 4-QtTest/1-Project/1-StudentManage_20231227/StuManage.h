#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StuSql.h"
#include "DlgStuAdd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class StuManage : public QMainWindow
{
    Q_OBJECT
public:
    StuManage(UserInfo userInfo,QWidget *parent = nullptr);
    ~StuManage();
    virtual void keyPressEvent(QKeyEvent *event);


signals:
    void signalsCloseWnd(void);

public slots:
    void slotTmpSimulationData(void);
    void slotTmpClearStu(void);
    void slotbtnAddStu(void);
    void slotbtnUpdateStu(void);
    void slotbtnDelStu(void);
    void slotbtnSearchStu(void);
    void slotbtnExit(void);


private:
    void initUi(void);
    void initConnect(void);
    void updateTable(void);
    QMenu* tmpExample; // TODE 临时demo
    QAction* tmpSimulationData;
    QAction* tmpClearStuData;

    StuSql* mpStuSql;
    UserInfo mUserInfo;
    DlgStuAdd* dlgStuAdd = new DlgStuAdd();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

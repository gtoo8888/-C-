#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class StuManage : public QMainWindow
{
    Q_OBJECT
public:
    StuManage(QWidget *parent = nullptr);
    ~StuManage();
    virtual void keyPressEvent(QKeyEvent *event);

private:
    void initUi(void);
    void initConnect(void);
    QMenu* tmpExample; // TODE 临时demo
    QAction* tmpSimulationData;  // TODE 临时demo

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

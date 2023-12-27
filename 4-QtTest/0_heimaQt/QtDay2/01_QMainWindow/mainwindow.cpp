#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);//重置窗口大小

    //菜单栏―只能最多有一个
    QMenuBar *bar = menuBar();//菜单栏创建
    setMenuBar(bar);//将菜单栏放入到窗口中
    QMenu *fileMenu = bar ->addMenu("文件");//创建菜单
    QMenu *editMenu = bar ->addMenu("编辑");

    QAction *newAction = fileMenu ->addAction("新建");//创建菜单项
    fileMenu ->addSeparator();//添加分割线
    QAction *openAction = fileMenu ->addAction("打开");

    //工具栏可以有多个
    QToolBar *toolBar = new QToolBar(this);//工具栏创建
    addToolBar(Qt::LeftToolBarArea,toolBar);//将工具栏放入到窗口中，设置默认停靠区域
    //QT中的所有枚举值都用Qt::来开头
    toolBar ->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//后期设置只允许左右停靠
    toolBar ->setFloatable(false);//设置禁止浮动
    toolBar ->setMovable(false);//设置移动(总开关)

    toolBar ->addAction(newAction);//工具栏中可以设置内容，将上面菜单中的内容一模一样复制过来了
    toolBar ->addSeparator();//添加分割线
    toolBar ->addAction(openAction);

    QPushButton *btn = new QPushButton("aa",this);//工具栏中添加控件
    toolBar ->addWidget(btn);

    //状态栏最多有一个
    QStatusBar *stBar = statusBar();//状态栏创建
    setStatusBar(stBar);//设置到窗口中
    QLabel *label = new QLabel("提示信息",this);//放标签控件
    stBar ->addWidget(label);
    QLabel *label2 = new QLabel("右侧提示信息",this);
    stBar ->addPermanentWidget(label2);

    //铆接部件（浮动窗口）可以有多个
    QDockWidget *dockWidget = new QDockWidget("浮动",this);//浮动窗口创建
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);//设置到窗口中
    dockWidget ->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);//设置后期停靠区域，只允许上下

    //设置核心部件，只能有一个
    QTextEdit *edit = new QTextEdit(this);//核心部件创建
    setCentralWidget(edit);//设置到窗口中

}

MainWindow::~MainWindow()
{

}

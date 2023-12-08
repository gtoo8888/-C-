#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QTextCodec>

#include "GtooPlayer.h"
#include "About.h"
#include "VideoCtrl.h"

///由于我们建立的是C++的工程
///编译的时候使用的C++的编译器编译
///而FFMPEG是C的库
///因此这里需要加上extern "C"
///否则会提示各种未定义
extern "C"
{
#include "libavcodec/avcodec.h"
}

void test(void) {
    printf("%s\n", avcodec_configuration());
}


GtooPlayer::GtooPlayer(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GtooPlayer),
    mReadThread(new ReadThread)
{    
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); // 没有用
    //qDebug() << QString::fromLocal8Bit("中文");
    qDebug() << "中文";

    ui->setupUi(this);
    initUtils();
    initUi();
    initConnect();
}


void testLog(void) {
    LOG_INFO("中文");
    LOG_TRACE("trace");
    LOG_DEBUG("debug");
    LOG_INFO("info");
    LOG_WARN("warn");
    LOG_ERROR("error");
    LOG_CRITICAL("critical");

    LOG_INFO("PID:[{:08d}] {:08d} ", 123, 123);
    LOG_INFO("str:{}", "test");
    QString qstr("qstr");
    LOG_INFO("qstr:{}", qstr.toStdString()); // 不能直接输出QString
}

void GtooPlayer::initUtils(void) {
    testLog();
}

void GtooPlayer::initUi(void) {
    // 保留一下添加toolbar的方式
    //buttonOccupy = new QPushButton(QString::fromLocal8Bit("about"));
    //ui->ToolBar->addWidget(buttonOccupy);


    tmpExampleMenu = ui->menuBar->addMenu("example"); // 创建例子
    tmpExampleMenu2PlayList = tmpExampleMenu->addAction("playlist");

    //ui->play_list->setEditable(true); // QComboBox需要开启才能编辑

    ui->progressBar->setMinimum(mProgressBarMin);
    ui->progressBar->setMaximum(mProgressBarMax);
    ui->progressBar->setValue(mProgressBarMin);
}

void GtooPlayer::initConnect(void) {
    this->setWindowTitle(mPlayerTitile);
    connect(ui->actionAbout, &QAction::triggered, this, &GtooPlayer::openAbout);
    connect(tmpExampleMenu2PlayList, &QAction::triggered, this, &GtooPlayer::openExample2PlayList);
    connect(ui->actionVideoCtrl, &QAction::triggered, this, &GtooPlayer::showVideoCtrl);


    connect(ui->actionOpen, &QAction::triggered, this, &GtooPlayer::openFile);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &GtooPlayer::startVideo);
    connect(ui->pushButtonPause, &QPushButton::clicked, this, &GtooPlayer::pauseVideo);
    connect(ui->pushButtonPrevious, &QPushButton::clicked, this, &GtooPlayer::pauseVideo);
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &GtooPlayer::pauseVideo);

    //ui->play_list->currentText()
    connect(ui->playListWidget, &PlayList::SigPlay, this, &GtooPlayer::startVideoPlayList);

    // 它表示当信号被触发时，槽函数会立即在发射信号的线程上被调用。这意味着信号和槽之间的通信是直接的、同步的，不涉及事件循环的调度
    // 这是不同线程中的触发
    connect(mReadThread, &ReadThread::updateImage, ui->playImageWidget, &PlayImage::updateImage, Qt::DirectConnection);
    connect(mReadThread, &ReadThread::playState, this, &GtooPlayer::onPlayState);
    connect(mReadThread, &ReadThread::updateTime, this, &GtooPlayer::updateTime);
}

void GtooPlayer::openAbout(void) {
    About* aboutWindow = new About();
    // QWidget作为单独的显示窗口，初始化时候不能使用this
    // 如果初始化中继承了this，新建的窗口就和主窗口是同一个，拖不开了
    //About* aboutWindow = new About(this);   
    aboutWindow->show();
}

void GtooPlayer::openExample2PlayList(void) {
    PlayList* exampleWindow = new PlayList();
    exampleWindow->show();
    //exampleWindow->showFullScreen();
}


void GtooPlayer::openFile(void) {
    LOG_DEBUG("openFile");
    QString filePath = QFileDialog::getOpenFileName(this, "选择播放视频~！",
        "E:/Desktop/languguetest/Cplusplustest/3-VisualStudio2017/0-GtooPlayer/test_video",
        "视频 (*.mp4 *.m4v *.mov *.avi *.flv);; 其它(*)");
    qDebug() << filePath;
    QFileInfo info(filePath);
}

void GtooPlayer::showVideoCtrl(void) {
    VideoCtrl* videoCtrlWidget = new VideoCtrl();
    videoCtrlWidget->show();
}

void GtooPlayer::startVideo(void) {
    LOG_DEBUG("startVideo");
    if (ui->pushButtonStart->text() == "开始") {
        mReadThread->open(nowPlayFilePath);
    }
    else {
        mReadThread->close();
    }
}

void GtooPlayer::startVideoPlayList(QString playFilePath) {
    LOG_DEBUG("startVideoPlayList");
    nowPlayFilePath = playFilePath;
    if (ui->pushButtonStart->text() == "开始") {
        mReadThread->open(nowPlayFilePath);
    }
    else {
        mReadThread->close();
    }
}


void GtooPlayer::pauseVideo(void) {
    LOG_DEBUG("pauseVideo");
}


void GtooPlayer::onPlayState(ReadThread::PlayState state) {
    if (state == ReadThread::play) {
        //this->setWindowTitle(QString("正在播放： %1").arg(mReadThread->url())); // 需要解决文件名太长的问题
        this->setWindowTitle(QString("正在播放： %1").arg("test"));
        ui->pushButtonStart->setText("停止");
    }
    else if (state == ReadThread::end) {
        ui->pushButtonStart->setText("开始");
        this->setWindowTitle(mPlayerTitile);
    }
}


void GtooPlayer::updateTime(QString nowTime, QString totalTime,qreal progressValue) {
    ui->labelNowTime->setText(nowTime);
    ui->labelTotalTime->setText(totalTime);

    qreal nowProgress = progressValue * (mProgressBarMax - mProgressBarMin);
    ui->progressBar->setValue(int(nowProgress));
    ui->progressBar->setFormat(QString("%1%").arg(QString::number(nowProgress, 'f', 2)));
}


GtooPlayer::~GtooPlayer(){
}

#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QTextCodec>


#include "GtooPlayer.h"
#include "About.h"
#include "Example.h"
extern "C"
{
#include "libavcodec/avcodec.h"
}

///�������ǽ�������C++�Ĺ���
///�����ʱ��ʹ�õ�C++�ı���������
///��FFMPEG��C�Ŀ�
///���������Ҫ����extern "C"
///�������ʾ����δ����

void test(void) {
    printf("%s\n", avcodec_configuration());
}


GtooPlayer::GtooPlayer(QWidget *parent):
    ui(new Ui::GtooPlayerClass),
    QMainWindow(parent)
{    
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); // û����
    qDebug() << QString::fromLocal8Bit("����");

    ui->setupUi(this);
    initUi();
    initConnect();
}

void GtooPlayer::initUi(void) {
    openSecond1 = new QPushButton(QString::fromLocal8Bit("����"));
    //openSecond1 = new QPushButton("about1");
    ui->ToolBar->addWidget(openSecond1);

    openFileButton = new QPushButton("open file");
    ui->ToolBar->addWidget(openFileButton);

    openExampleButton = new QPushButton("example");
    ui->ToolBar->addWidget(openExampleButton);

}

void GtooPlayer::initConnect(void) {
    connect(openSecond1, &QPushButton::clicked, this, &GtooPlayer::openAbout);
    connect(openFileButton, &QPushButton::clicked, this, &GtooPlayer::openFile);
    connect(openExampleButton, &QPushButton::clicked, this, &GtooPlayer::openExample);


    connect(ui->pushButton_1_pause, &QPushButton::clicked, this, &GtooPlayer::pauseVideo);
    connect(ui->pushButton_2_start, &QPushButton::clicked, this, &GtooPlayer::startVideo);
    connect(ui->pushButton_3_previous, &QPushButton::clicked, this, &GtooPlayer::startVideo);
    connect(ui->pushButton_4_next, &QPushButton::clicked, this, &GtooPlayer::startVideo);
}

void GtooPlayer::openAbout(void) {
    About* aboutWindow = new About(this);
    aboutWindow->show();
}

void GtooPlayer::openExample(void) {
    Example* exampleWindow = new Example(this);
    exampleWindow->show();
}


void GtooPlayer::openFile(void) {
    QString filePath = QFileDialog::getOpenFileName(this, "test", "E:\\Desktop\\tool\\player_test\\test_video");
    QFileInfo info(filePath);
    qDebug() << filePath;

    //is = stream_open(filePath);
    av_log(NULL, AV_LOG_INFO, "Failed to initialize VideoState!\n");
}

void GtooPlayer::pauseVideo(void) {
    qDebug() << "pauseVideo";

}

void GtooPlayer::startVideo(void) {
    qDebug() << "startVideo";

}


GtooPlayer::~GtooPlayer()
{}

#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QTextCodec>


#include "GtooPlayer.h"
#include "About.h"
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

}

void GtooPlayer::initConnect(void) {
    connect(ui->pushButton, &QPushButton::clicked, this, &test);

    connect(openSecond1, &QPushButton::clicked, this, &GtooPlayer::openAbout);
    connect(openFileButton, &QPushButton::clicked, this, &GtooPlayer::openFile);
}

void GtooPlayer::openAbout(void) {
    About* aboutWindow = new About(this);
    aboutWindow->show();
}

void GtooPlayer::openFile(void) {
    QString filePath = QFileDialog::getOpenFileName(this, "test", "E:\\Desktop\\tool\\player_test\\test_video");
    QFileInfo info(filePath);
    qDebug() << filePath;

    //is = stream_open(filePath);
    av_log(NULL, AV_LOG_INFO, "Failed to initialize VideoState!\n");
}


GtooPlayer::~GtooPlayer()
{}

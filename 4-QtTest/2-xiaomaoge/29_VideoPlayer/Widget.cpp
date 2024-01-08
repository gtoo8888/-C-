#include "Widget.h"
#include "ui_Widget.h"
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    mVideoPlayer = new VideoPlayer();
    connect(mVideoPlayer,&VideoPlayer::stateUpdate,this,&Widget::slotPlayerStateUpdate);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    "选择多媒体文件",
                                                    "E:/Desktop/languguetest/Cplusplustest/3-VisualStudio2017/0-GtooPlayer/test_video",
                                                    "视频文件(*.mp4 *.avi *.mkv);;音频文件(*.mp3 *.acc)");
    if(fileName.isEmpty()){
        qDebug() << "没有打开文件";
        return;
    }
    qDebug() << fileName;
    mVideoPlayer->setVideoFileName(fileName.toUtf8().data());
    mVideoPlayer->play();
}

void Widget::slotPlayerStateUpdate(VideoPlayer *player){
    VideoPlayer::State state = player->getState();
    if(state == VideoPlayer::Playing){
        ui->btnPlayer->setText("暂停");
    }else{
        ui->btnPlayer->setText("播放");
    }


    if(state == VideoPlayer::Stopped){
        ui->btnPlayer->setEnabled(false);
        ui->btnStop->setEnabled(false);
        ui->btnSilence->setEnabled(false);
        ui->sliderTime->setEnabled(false);

        ui->sliderTime->setValue(0);
        ui->sliderTime->setValue(ui->sliderTime->minimum());
        ui->labelCurrentTime->setText(QString("00:00:00"));
        ui->lableDurationTime->setText(QString("00:00:00"));
        ui->stackedWidget->setCurrentWidget(ui->pageOpenFile);
    }else{
        ui->btnPlayer->setEnabled(true);
        ui->btnStop->setEnabled(true);
        ui->btnSilence->setEnabled(true);
        ui->sliderTime->setEnabled(true);
        ui->stackedWidget->setCurrentWidget(ui->pagePlayWdg);
    }
}

void Widget::on_btnPlayer_clicked()
{
    VideoPlayer::State state = mVideoPlayer->getState();
    if(state == VideoPlayer::Playing){
        mVideoPlayer->pause();
    }else{
        mVideoPlayer->play();
    }
}

void Widget::on_btnStop_clicked()
{
    mVideoPlayer->stop();
}

void Widget::on_sliderVoice_valueChanged(int value)
{
    ui->labelVoice->setText(QString("%1").arg(value));
}

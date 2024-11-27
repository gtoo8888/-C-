#include "XVPlayerWidget.h"
#include "ui_XVPlayerWidget.h"
#include <QFileDialog>
#include <QTime>

#include "Utils.h"

XVPlayerWidget::XVPlayerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XVPlayerWidget)
{
    ui->setupUi(this);

    qDebug("version: %d", avcodec_version());

    // 注册信号的参数类型，保证能够发出信号
    qRegisterMetaType<XVPlayer::VideoSwsSpec>("VideoSwsSpec");

    ui->stackedWidget->setCurrentIndex(0);
    mVideoPlayer = new XVPlayer();
    connect(mVideoPlayer,&XVPlayer::signalStateUpdate,this,&XVPlayerWidget::slotPlayerStateUpdate);
    connect(mVideoPlayer,&XVPlayer::signalInitFinished,this,&XVPlayerWidget::slotPlayerInitFinish);
    connect(mVideoPlayer,&XVPlayer::signalPlayFailed,this,&XVPlayerWidget::slotPlayerFailed);
    connect(mVideoPlayer,&XVPlayer::signalFrameDecoded,ui->videoWidget,&VideoWdg::slotPlayerFrameDecoded);
}

XVPlayerWidget::~XVPlayerWidget()
{
    delete ui;
}


void XVPlayerWidget::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    "选择多媒体文件",
                                                    "E:/Desktop/languguetest/Cplusplustest/3-VisualStudio2017/0-GtooPlayer/test_video",
                                                    "多媒体文件(*.mp4 *.avi *.mkv *.mp3 *.acc)");
    if(fileName.isEmpty()){
        qDebug() << "没有打开文件";
        return;
    }
    qDebug() << fileName;
    mVideoPlayer->setVideoFileName(fileName.toStdString().data());
    mVideoPlayer->play();
}

void XVPlayerWidget::slotPlayerStateUpdate(XVPlayer *player){
    XVPlayer::State state = player->getState();
    if(state == XVPlayer::Playing){
        ui->btnPlayer->setText("暂停");
    }else{
        ui->btnPlayer->setText("播放");
    }


    if(state == XVPlayer::Stopped){
        ui->btnPlayer->setEnabled(false);
        ui->btnStop->setEnabled(false);
        ui->btnSilence->setEnabled(false);
        ui->sliderTime->setEnabled(false);

        ui->sliderTime->setValue(0);
        ui->sliderTime->setValue(ui->sliderTime->minimum());
        ui->labelCurrentTime->setText(getDiratonText(0));
        ui->lableDurationTime->setText(getDiratonText(0));
        ui->stackedWidget->setCurrentWidget(ui->pageOpenFile);
    }else{
        ui->btnPlayer->setEnabled(true);
        ui->btnStop->setEnabled(true);
        ui->btnSilence->setEnabled(true);
        ui->sliderTime->setEnabled(true);
        ui->stackedWidget->setCurrentWidget(ui->pagePlayWdg);
    }
}

void XVPlayerWidget::slotPlayerInitFinish(XVPlayer *player)
{
    int64_t duration = player->getDuration()/1000000; // 微秒
    // 设置进度条范围
    ui->sliderTime->setRange(0,duration);
    // 设置播放时间
    ui->lableDurationTime->setText(getDiratonText(duration));
}

void XVPlayerWidget::slotPlayerFailed(XVPlayer *player)
{
    QMessageBox::critical(nullptr, "警告", "播放失败");
}

void XVPlayerWidget::on_btnPlayer_clicked()
{
    XVPlayer::State state = mVideoPlayer->getState();
    if(state == XVPlayer::Playing){
        mVideoPlayer->pause();
    }else{
        mVideoPlayer->play();
    }
}

void XVPlayerWidget::on_btnStop_clicked()
{
    mVideoPlayer->stop();
}

void XVPlayerWidget::on_sliderTime_valueChanged(int value)
{
    ui->labelCurrentTime->setText(getDiratonText(value));
}

void XVPlayerWidget::on_sliderVoice_valueChanged(int value)
{
    ui->labelVoice->setText(QString("%1").arg(value));
}

QString XVPlayerWidget::getDiratonText(int64_t millisecond)
{
    // 方法1：
    int64_t seconds = millisecond;
    QString hour = QString("0%1").arg(seconds/3600).right(2);
    QString minute = QString("0%1").arg((seconds/60)%60).right(2);
    QString second = QString("0%1").arg(seconds%60).right(2);
    QString durationTime = QString("%1:%2:%3").arg(hour).arg(minute).arg(second);
//    myDebug() << microsecond ;
//    myDebug() << seconds ;
//    myDebug() << hour << " " << minute << " " << second ;

    // 方法2：
//    int64_t seconds = millisecond;
//    QString durationTime = QString("%1:%2:%3")
//            .arg(seconds/3600,2,10,QLatin1Char('0'))
//            .arg((seconds/60)%60,2,10,QLatin1Char('0'))
//            .arg(seconds%60,2,10,QLatin1Char('0'));
    // 方法3：
//    int64_t millisecond = microsecond/1000;
//    QString durationTime = QTime::fromMSecsSinceStartOfDay(int(millisecond)).toString("HH:mm:ss");
    return durationTime;
}



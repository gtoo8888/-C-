#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStringList>

#define myDebug() qDebug() << QString("[%1]:%2 %3").arg(__FILE__).arg(__LINE__).arg(__FUNCTION__)

#define test 1
#define ERROR_BUF      \
    char errbuf[1024]; \
    av_strerror(ret, errbuf, sizeof(errbuf));

#define CODE(func, code)                         \
    if (ret < 0) {                               \
        ERROR_BUF;                               \
        myDebug() << #func << "error" << errbuf; \
        code;                                    \
    }

#define END(func) CODE(func, fateError(); return;)
#define RET(func) CODE(func, return ret;)
#define CONTINUE(func) CODE(func, continue;)
#define BREAK(func) CODE(func, break;)

extern "C" {
#include <libavcodec/avcodec.h>    //avcodec:编解码(最重要的库)
#include <libavdevice/avdevice.h>  //avdevice:各种设备的输入输出
#include <libavformat/avformat.h>  //avformat:封装格式处理
#include <libavutil/avutil.h>      //avutil:工具库（大部分库都需要这个库的支持）
#include <libswscale/swscale.h>    //swscale:视频像素数据格式转换
}

#endif                             // UTILS_H

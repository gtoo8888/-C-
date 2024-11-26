#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <list>
#include "CondMutex.h"

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h>
}

/**
* @brief 预处理视频数据(解析文件、解码视频流\音频流)
*/
class XVPlayer : public QObject
{
    Q_OBJECT
public:
    // 播放器状态
    typedef enum{
        Stopped = 0,
        Playing,
        Pause
    } State;

    typedef enum{
        Min = 0,
        Max = 100
    } Volum;

    // 视频Frame的参数信息
    typedef struct{
        int widght;
        int height;
        AVPixelFormat pixFmt;
    } VideoSwsSpec;

    explicit XVPlayer(QObject *parent = nullptr);
    ~XVPlayer();

    void play(void);
    void pause(void);
    void stop(void);
    bool isPlaying(void);
    // 获取当前播放状态
    State getState(void);
    void setVideoFileName(const char* filename);
    // 获取总时长,单位是1us,1s=10^3ms=10^6us
    int64_t getDuration(void);
    // 设置音量
    void setVolumn(int volume);


signals:
    void signalStateUpdate(XVPlayer* videoPlayer);
    void signalInitFinished(XVPlayer* videoPlayer);
    void signalPlayFailed(XVPlayer* videoPlayer);
    void signalFrameDecoded(XVPlayer* videoPlayer,uint8_t *data,VideoSwsSpec spec);

private:
    typedef struct{
        int sampleRate; // 采样率
        AVSampleFormat sampleFmt; // 采样格式
        uint64_t chLayout; // 通道格式类型，单通道，双通道
        int chs; // 通道数
        int bytesPerSampleFrame; // 每个样本帧的大小
    } AudioSwrSpec;

    /**************************音频相关************************************/
    AVCodecContext *maDecodeCtx = nullptr;  // 解码上下文
    AVStream *maStream = nullptr;// 流
    AVFrame *maSwrInFrame = nullptr,*maSwrOutFrame = nullptr;    // 存放解码后的数据
    std::list<AVPacket> *maPktList = nullptr; // 存放音频包的列表
    CondMutex *maMutex = nullptr; // 音频包列表的锁
    SwrContext *maSwrCtx = nullptr; // 音频重采样上下文
    AudioSwrSpec maSwrInSpec, maSwrOutSpec; // 音频重采样输入/输出参数
    int maSwrOutIdx = 0; // 音频重采样输出PCM的索引，从哪个位置取出PCM数据填充到SDL的音频缓冲区
    int maSwrOutSize = 0; // 音频重采样输出PCM的大小


    // 初始化音频信息
    int initAudioInfo(void);
    // 初始化音频重采样
    int initSwr(void);
    // 初始化SDL
    int initSDL(void);
    // 添加数据包到音频列表中
    void addAudioPkt(AVPacket& pkt);
    // 清空音频包列表
    void clearAudioPktList(void);
    // SDL填充缓冲区的回调函数
    static void sdlAudioCallbackFunc(void *userdata, Uint8 *stream, int len);
    // 实际回调函数
    void sdlAudioCallback(Uint8 *stream, int len);
    // 音频解码,解码出来多大
    int decodeAudio(void);
    // 释放音频资源
    void freeAudio(void);




    /**************************视频相关************************************/


    AVCodecContext *mvDecodeCtx = nullptr;// 解码上下文
    AVStream *mvStream = nullptr;// 流
    AVFrame *mvSwsInFrame = nullptr, *mvSwsOutFrame = nullptr; // 视频像素格式转换的输入输出frame
    SwsContext *mvSwsCtx; // 像素格式转换的上下文
    VideoSwsSpec mvSwsOutSpec;   // 像素格式转换的输出的Frame参数
    std::list<AVPacket> *mvPktList = nullptr; // 存放音频包的列表
    CondMutex *mvMutex; // 视频包列表的锁


    // 初始化视频信息
    int initVideoInfo(void);
    // 初始化视频像素格式转换
    int initSws(void);
    // 添加数据包到音频列表中
    void addVideoPkt(AVPacket& pkt);
    // 清空视频包列表
    void clearVideoPktList(void);
    // 解码视频
    void decodeVideo(void);
    // 释放视频资源
    void freeVideo(void);


    /**************************其他************************************/
    // 当前状态
    State mState = Stopped;
    // 音频/视频文件名
    const char* mFileName;
    // 解封装上下文
    AVFormatContext *mFmtCtx = nullptr;
    // 音量
    int mVolume = Volum::Max;
    // 初始化解码器和解码上下文
    int initDecoder(AVCodecContext **decodeCtx, AVStream **stream, AVMediaType type);
    // 设置状态
    void setState(State state);
    // 读取文件
    void readFile(void);
    // 释放所有资源
    void freeAll(void);


    // 出现致命错误
    void fateError(void);

};

#endif // VIDEOPLAYER_H

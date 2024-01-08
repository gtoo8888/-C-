#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>


/**
* @brief 预处理视频数据(解析文件、解码视频流\音频流)
*/
class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    // 播放器状态
    typedef enum{
        Stopped = 0,
        Playing,
        Pause
    } State;

    explicit VideoPlayer(QObject *parent = nullptr);
    ~VideoPlayer();

    void play(void);
    void pause(void);
    void stop(void);
    bool isPlaying(void);
    // 获取当前播放状态
    State getState(void);
    void setVideoFileName(const char* filename);
signals:
    void stateUpdate(VideoPlayer* videoPlayer);
private:
    // 当前状态
    State mState = Stopped;
    const char* mFileName;
    // 设置状态
    void setState(State state);
    void readFile(void);
};

#endif // VIDEOPLAYER_H

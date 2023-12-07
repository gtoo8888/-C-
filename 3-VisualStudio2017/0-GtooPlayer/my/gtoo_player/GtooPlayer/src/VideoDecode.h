/******************************************************************************
 * @�ļ���     videodecode.h
 * @����       ��Ƶ�����࣬��������е���ffmpeg����Ƶ���н���
 *
 * @������     mhf
 * @����       1603291350@qq.com
 * @ʱ��       2022/09/15
 * @��ע
 *****************************************************************************/
#ifndef VIDEODECODE_H
#define VIDEODECODE_H

#include <QString>
#include <QSize>

struct AVFormatContext;
struct AVCodecContext;
struct AVRational;
struct AVPacket;
struct AVFrame;
struct SwsContext;
struct AVBufferRef;
class QImage;

class VideoDecode
{
public:
    VideoDecode();
    ~VideoDecode();

    bool open(const QString& url = QString());    // ��ý���ļ���������ý��rtmp��strp��http
    QImage read();                               // ��ȡ��Ƶͼ��
    void close();                                 // �ر�
    bool isEnd();                                 // �Ƿ��ȡ���
    const qint64& pts();                          // ��ȡ��ǰ֡��ʾʱ��

private:
    void initFFmpeg();                            // ��ʼ��ffmpeg�⣨����������ֻ�����һ�Σ�
    void showError(int err);                      // ��ʾffmpegִ�д���ʱ�Ĵ�����Ϣ
    qreal rationalToDouble(AVRational* rational); // ��AVRationalת��Ϊdouble
    void clear();                                 // ��ն�ȡ����
    void free();                                  // �ͷ�

private:
    AVFormatContext* m_formatContext = nullptr;   // ���װ������
    AVCodecContext*  m_codecContext = nullptr;   // ������������
    SwsContext*      m_swsContext = nullptr;   // ͼ��ת��������
    AVPacket* m_packet = nullptr;                 // ���ݰ�
    AVFrame*  m_frame = nullptr;                 // ��������Ƶ֡
    int    m_videoIndex = 0;                    // ��Ƶ������
    qint64 m_totalTime = 0;                    // ��Ƶ��ʱ��
    qint64 m_totalFrames = 0;                    // ��Ƶ��֡��
    qint64 m_obtainFrames = 0;                    // ��Ƶ��ǰ��ȡ����֡��
    qint64 m_pts = 0;                    // ͼ��֡����ʾʱ��
    qreal  m_frameRate = 0;                    // ��Ƶ֡��
    QSize  m_size;                                // ��Ƶ�ֱ��ʴ�С
    char*  m_error = nullptr;                     // �����쳣��Ϣ
    bool   m_end = false;                         // ��Ƶ��ȡ���
    uchar* m_buffer = nullptr;                    // YUVͼ����Ҫת��λRGBAͼ�����ﱣ��ת�����ͼ������
};

#endif // VIDEODECODE_H

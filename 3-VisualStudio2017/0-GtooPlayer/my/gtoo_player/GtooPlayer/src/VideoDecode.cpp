#include "videodecode.h"
#include <QDebug>
#include <QImage>
#include <QMutex>
#include <qdatetime.h>


extern "C" {        // ��C�������ָ���Ĵ���
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libswscale/swscale.h"
#include "libavutil/imgutils.h"

#include "libavutil/time.h"

}

#define ERROR_LEN 1024  // �쳣��Ϣ���鳤��
#define PRINT_LOG 1

VideoDecode::VideoDecode()
{
    //    initFFmpeg();      // 5.1.2�汾����Ҫ������

    m_error = new char[ERROR_LEN];
}

VideoDecode::~VideoDecode()
{
    close();
}

/**
 * @brief ��ʼ��ffmpeg�⣨����������ֻ�����һ�Σ�
 *        �ɰ汾��ffmpeg��Ҫע������ļ���ʽ���⸴����������������ȫ�ֳ�ʼ����
 *        ���°汾��ffmpeg�з׷������ˣ�����Ҫע����
 */
void VideoDecode::initFFmpeg()
{
    static bool isFirst = true;
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    if (isFirst)
    {
        //        av_register_all();         // �Ѿ���Դ����ɾ��
        /**
         * ��ʼ�������,���ڴ�������ý�壬�˺��������ڽ����GnuTLS��OpenSSL����̰߳�ȫ���⡣
         * һ��ɾ���Ծ�GnuTLS��OpenSSL���֧�֣��˺����������ã����Ҵ˺����������κ���;��
         */
        avformat_network_init();
        isFirst = false;
    }
}

/**
 * @brief      ��ý���ļ���������ý�壬����rtmp��strp��http
 * @param url  ��Ƶ��ַ
 * @return     true���ɹ�  false��ʧ��
 */
bool VideoDecode::open(const QString &url)
{
    if (url.isNull()) return false;

    AVDictionary* dict = nullptr;
    av_dict_set(&dict, "rtsp_transport", "tcp", 0);      // ����rtsp��ʹ��tcp�򿪣������ʧ�ܴ�����ϢΪ��Error number -135 occurred�������л���UDP��tcp��udp_multicast��http��������vlc��������Ҫʹ��udp��
    av_dict_set(&dict, "max_delay", "3", 0);             // ��������û�⸴���ӳ٣���΢��Ϊ��λ������ͨ����UDP�� ��������ʱ���⸴������������������յ������ݰ�����Ϊ���ǿ������򵽴�������ݰ�������ȫ��ʧ���������ͨ�������⸴���ӳ�����Ϊ�㣨ͨ��max_delayAVFormatContext �ֶΣ������á�
    av_dict_set(&dict, "timeout", "1000000", 0);         // ��΢��Ϊ��λ�����׽��� TCP I/O ��ʱ������ȴ�ʱ����̣�Ҳ���ܻỹû���Ӿͷ����ˡ�

    // �������������ؽ��װ������
    int ret = avformat_open_input(&m_formatContext,          // ���ؽ��װ������
        url.toStdString().data(),  // ����Ƶ��ַ
        nullptr,                   // �����null���˲���ǿ��ʹ���ض��������ʽ���Զ�ѡ����װ�����ļ���ʽ��
        &dict);                    // ��������
// �ͷŲ����ֵ�
    if (dict)
    {
        av_dict_free(&dict);
    }
    // ����Ƶʧ��
    if (ret < 0)
    {
        showError(ret);
        free();
        return false;
    }

    // ��ȡý���ļ������ݰ��Ի�ȡ����Ϣ��
    ret = avformat_find_stream_info(m_formatContext, nullptr);
    if (ret < 0)
    {
        showError(ret);
        free();
        return false;
    }
    m_totalTime = m_formatContext->duration / (AV_TIME_BASE / 1000); // ������Ƶ��ʱ�������룩
#if PRINT_LOG
    qDebug() << QString::fromLocal8Bit("��Ƶ��ʱ����%1 ms��[%2]").arg(m_totalTime).arg(QTime::fromMSecsSinceStartOfDay(int(m_totalTime)).toString("HH:mm:ss zzz"));
#endif

    // ͨ��AVMediaTypeö�ٲ�ѯ��Ƶ��ID��Ҳ����ͨ���������ң������һ����������
    m_videoIndex = av_find_best_stream(m_formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
    if (m_videoIndex < 0)
    {
        showError(m_videoIndex);
        free();
        return false;
    }

    AVStream* videoStream = m_formatContext->streams[m_videoIndex];  // ͨ����ѯ����������ȡ��Ƶ��

    // ��ȡ��Ƶͼ��ֱ��ʣ�AVStream�е�AVCodecContext���°汾�����ã���Ϊʹ��AVCodecParameters��
    m_size.setWidth(videoStream->codecpar->width);
    m_size.setHeight(videoStream->codecpar->height);
    m_frameRate = rationalToDouble(&videoStream->avg_frame_rate);  // ��Ƶ֡��

    // ͨ��������ID��ȡ��Ƶ���������°汾����ֵ����ʹ��const��
    const AVCodec* codec = avcodec_find_decoder(videoStream->codecpar->codec_id);
    m_totalFrames = videoStream->nb_frames;


#if PRINT_LOG
    qDebug() << QString::fromLocal8Bit("�ֱ��ʣ�[w:%1,h:%2] ֡�ʣ�%3  ��֡����%4  ��������%5")
        .arg(m_size.width()).arg(m_size.height()).arg(m_frameRate).arg(m_totalFrames).arg(codec->name);
#endif

    // ����AVCodecContext�������ֶ�����ΪĬ��ֵ��
    m_codecContext = avcodec_alloc_context3(codec);
    if (!m_codecContext)
    {
#if PRINT_LOG
        qWarning() << "������Ƶ������������ʧ�ܣ�";
#endif
        free();
        return false;
    }

    // ʹ����Ƶ����codecparΪ�����������ĸ�ֵ
    ret = avcodec_parameters_to_context(m_codecContext, videoStream->codecpar);
    if (ret < 0)
    {
        showError(ret);
        free();
        return false;
    }

    m_codecContext->flags2 |= AV_CODEC_FLAG2_FAST;    // �������Ϲ淶�ļ��ټ��ɡ�
    m_codecContext->thread_count = 8;                 // ʹ��8�߳̽���

    // ��ʼ�������������ģ����֮ǰavcodec_alloc_context3�����˽���������������NULL�Ϳ���
    ret = avcodec_open2(m_codecContext, nullptr, nullptr);
    if (ret < 0)
    {
        showError(ret);
        free();
        return false;
    }

    // ����AVPacket�������ֶ�����ΪĬ��ֵ��
    m_packet = av_packet_alloc();
    if (!m_packet)
    {
#if PRINT_LOG
        qWarning() << "av_packet_alloc() Error��";
#endif
        free();
        return false;
    }
    // ����AVFrame�������ֶ�����ΪĬ��ֵ��
    m_frame = av_frame_alloc();
    if (!m_frame)
    {
#if PRINT_LOG
        qWarning() << "av_frame_alloc() Error��";
#endif
        free();
        return false;
    }

    // ����ͼ��ռ�
    int size = av_image_get_buffer_size(AV_PIX_FMT_RGBA, m_size.width(), m_size.height(), 4);
    /**
     * ��ע�⣺��������Զ����һЩ���������ֻ�ǰ�װsize���䣬�󲿷���Ƶͼ�����ݿ���û�����⣬
     *         �����ٲ�����Ƶͼ����ʹ��sws_scale()����ʱ�ᳬ�����鳤�ȣ���ʹ��ʹ��msvc debugģʽʱdelete[] m_buffer�ᱨ��HEAP CORRUPTION DETECTED: after Normal block(#32215) at 0x000001AC442830370.CRT delected that the application wrote to memory after end of heap buffer��
     *         �ر��������Ƶ��http://vfx.mtime.cn/Video/2019/02/04/mp4/190204084208765161.mp4
     */
    m_buffer = new uchar[size + 1000];    // ��������1000���ֽھͻ���������ֿ�������������ˣ�������ȱ����ڴ�
//    m_image = new QImage(m_buffer, m_size.width(), m_size.height(), QImage::Format_RGBA8888);  // ���ַ�ʽ�����ڴ�󲿷������Ҳ���ԣ�������Ϊ���ڿ�����������������deleteʱҲ�ᱨ��
    m_end = false;
    return true;
}

/**
 * @brief
 * @return
 */
QImage VideoDecode::read()
{
    // ���û�д��򷵻�
    if (!m_formatContext)
    {
        return QImage();
    }

    // ��ȡ��һ֡����
    int readRet = av_read_frame(m_formatContext, m_packet);
    if (readRet < 0)
    {
        avcodec_send_packet(m_codecContext, m_packet); // ��ȡ��ɺ���������д����AVPacket�������޷���ȡ�����֡
    }
    else
    {
        if (m_packet->stream_index == m_videoIndex)     // �����ͼ����������н���
        {
            AVRational time_base = m_formatContext->streams[m_videoIndex]->time_base;
            // ���㵱ǰ֡ʱ�䣨���룩
#if 1       // ����һ�����������г��������Ǵ���һ�����
            m_packet->pts = qRound64(m_packet->pts * (1000 * rationalToDouble(&time_base)));
            m_packet->dts = qRound64(m_packet->dts * (1000 * rationalToDouble(&time_base)));

#else       // �������������ڲ��ű�����Ƶ�ļ�������ÿһ֡ʱ���׼����������������Ƶ���޷���ȡ��֡���������޷�����
            m_obtainFrames++;
            m_packet->pts = qRound64(m_obtainFrames * (qreal(m_totalTime) / m_totalFrames));
#endif
            
            
            //int64_t timestamp = av_rescale_q(m_packet->pts, time_base, AV_TIME_BASE_Q);
            //int64_t timestamp = av_frame_get_best_effort_timestamp(frame);
            //av_frame_get_best_effort_timestamp()


            // ����ȡ����ԭʼ���ݰ����������
            int ret = avcodec_send_packet(m_codecContext, m_packet);
            if (ret < 0)
            {
                showError(ret);
            }
        }
    }
    av_packet_unref(m_packet);  // �ͷ����ݰ������ü���-1��Ϊ0ʱ�ͷſռ�

    int ret = avcodec_receive_frame(m_codecContext, m_frame);
    if (ret < 0)
    {
        av_frame_unref(m_frame);
        if (readRet < 0)
        {
            m_end = true;     // ���޷���ȡ��AVPacket���ҽ�������Ҳû������ʱ��ʾ��ȡ���
        }
        return QImage();
    }

    int64_t timestamp = m_frame->best_effort_timestamp;
    int64_t timestamp_change = timestamp / (AV_TIME_BASE / 1000);
    int64_t all_time = m_formatContext->duration / (AV_TIME_BASE / 1000);
    qDebug() << QString("%1 %2:%3").arg(timestamp).arg(timestamp_change).arg(all_time);

    m_pts = m_frame->pts;

    // Ϊʲôͼ��ת��������Ҫ���������ʼ���أ�����Ϊm_frame->format�����ʹ��Ӳ�����룬���������ͼ���ʽ��m_codecContext->pix_fmt��ͼ���ʽ��һ�����ͻᵼ���޷�ת��ΪQImage
    if (!m_swsContext)
    {
        // ��ȡ�����ͼ��ת�������ġ�����У������Ƿ�һ�£����У�鲻ͨ�����ͷ���Դ��Ȼ���ж��������Ƿ���ڣ��������ֱ�Ӹ��ã��粻���ڽ��з��䡢��ʼ������
        m_swsContext = sws_getCachedContext(m_swsContext,
            m_frame->width,                     // ����ͼ��Ŀ��
            m_frame->height,                    // ����ͼ��ĸ߶�
            (AVPixelFormat)m_frame->format,     // ����ͼ������ظ�ʽ
            m_size.width(),                     // ���ͼ��Ŀ��
            m_size.height(),                    // ���ͼ��ĸ߶�
            AV_PIX_FMT_RGBA,                    // ���ͼ������ظ�ʽ
            SWS_BILINEAR,                       // ѡ�������㷨(ֻ�е��������ͼ���С��ͬʱ��Ч),һ��ѡ��SWS_FAST_BILINEAR
            nullptr,                            // ����ͼ����˲�����Ϣ, ������Ҫ��NULL
            nullptr,                            // ���ͼ����˲�����Ϣ, ������Ҫ��NULL
            nullptr);                          // �ض������㷨��Ҫ�Ĳ���(?)��Ĭ��ΪNULL
        if (!m_swsContext)
        {
#if PRINT_LOG
            qWarning() << "sws_getCachedContext() Error��";
#endif
            free();
            return QImage();
        }
    }

    // AVFrameתQImage
    uchar* data[] = { m_buffer };
    int    lines[4];
    av_image_fill_linesizes(lines, AV_PIX_FMT_RGBA, m_frame->width);  // ʹ�����ظ�ʽpix_fmt�Ϳ�����ͼ���ƽ��������С��
    ret = sws_scale(m_swsContext,             // ����������
        m_frame->data,            // ԭͼ������
        m_frame->linesize,        // ����Դͼ��ÿ��ƽ�沽��������
        0,                        // ��ʼλ��
        m_frame->height,          // ����
        data,                     // Ŀ��ͼ������
        lines);                   // ����Ŀ��ͼ��ÿ��ƽ��Ĳ���������
    QImage image(m_buffer, m_frame->width, m_frame->height, QImage::Format_RGBA8888);
    av_frame_unref(m_frame);

    return image;
}

/**
 * @brief �ر���Ƶ���Ų��ͷ��ڴ�
 */
void VideoDecode::close()
{
    clear();
    free();

    m_totalTime = 0;
    m_videoIndex = 0;
    m_totalFrames = 0;
    m_obtainFrames = 0;
    m_pts = 0;
    m_frameRate = 0;
    m_size = QSize(0, 0);
}

/**
 * @brief  ��Ƶ�Ƿ��ȡ���
 * @return
 */
bool VideoDecode::isEnd()
{
    return m_end;
}

/**
 * @brief    ���ص�ǰ֡ͼ�񲥷�ʱ��
 * @return
 */
const qint64 &VideoDecode::pts()
{
    return m_pts;
}

/**
 * @brief        ��ʾffmpeg���������쳣��Ϣ
 * @param err
 */
void VideoDecode::showError(int err)
{
#if PRINT_LOG
    memset(m_error, 0, ERROR_LEN);        // ����������
    av_strerror(err, m_error, ERROR_LEN);
    qWarning() << "DecodeVideo Error��" << m_error;
#else
    Q_UNUSED(err)
#endif
}

/**
 * @brief          ��AVRationalת��Ϊdouble�����ڼ���֡��
 * @param rational
 * @return
 */
qreal VideoDecode::rationalToDouble(AVRational* rational)
{
    qreal frameRate = (rational->den == 0) ? 0 : (qreal(rational->num) / rational->den);
    return frameRate;
}

/**
 * @brief ��ն�ȡ����
 */
void VideoDecode::clear()
{
    // ��Ϊavformat_flush����ˢ��AVIOContext (s->pb)������б�Ҫ���ڵ��ô˺���֮ǰ����avio_flush(s->pb)��
    if (m_formatContext && m_formatContext->pb)
    {
        avio_flush(m_formatContext->pb);
    }
    if (m_formatContext)
    {
        avformat_flush(m_formatContext);   // �����ȡ����
    }
}

void VideoDecode::free()
{
    // �ͷ�������swsContext��
    if (m_swsContext)
    {
        sws_freeContext(m_swsContext);
        m_swsContext = nullptr;             // sws_freeContext�������������NULL
    }
    // �ͷű�����������ĺ���֮��ص��������ݣ�����NULLд���ṩ��ָ��
    if (m_codecContext)
    {
        avcodec_free_context(&m_codecContext);
    }
    // �رղ�ʧ��m_formatContext������ָ����Ϊnull
    if (m_formatContext)
    {
        avformat_close_input(&m_formatContext);
    }
    if (m_packet)
    {
        av_packet_free(&m_packet);
    }
    if (m_frame)
    {
        av_frame_free(&m_frame);
    }
    if (m_buffer)
    {
        delete[] m_buffer;
        m_buffer = nullptr;
    }
}

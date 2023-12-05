#include "readthread.h"
#include "videodecode.h"

#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <qimage.h>

ReadThread::ReadThread(QObject *parent) : QThread(parent)
{
    m_videoDecode = new VideoDecode();

    qRegisterMetaType<PlayState>("PlayState");    // ע���Զ���ö�����ͣ������źŲ��޷�����
}

ReadThread::~ReadThread()
{
    if (m_videoDecode)
    {
        delete m_videoDecode;
    }
}

/**
 * @brief      ���벥�ŵ���Ƶ��ַ�������߳�
 * @param url
 */
void ReadThread::open(const QString &url)
{
    if (!this->isRunning())
    {
        m_url = url;
        emit this->start(); // QThread�������źţ�
    }
}

/**
 * @brief       ������ͣ������
 * @param flag  true����ͣ  fasle������
 */
void ReadThread::pause(bool flag)
{
    m_pause = flag;
}

/**
 * @brief �رղ���
 */
void ReadThread::close()
{
    m_play = false;
    m_pause = false;
}

/**
 * @brief    ���ص�ǰ���ŵĵ�ַ
 * @return
 */
const QString &ReadThread::url()
{
    return m_url;
}

/**
 * @brief      ��������ʱ
 * @param msec ��ʱ����
 */
void  sleepMsec(int msec)
{
    if (msec <= 0) return;
    QEventLoop loop;		//����һ���µ��¼�ѭ��
    QTimer::singleShot(msec, &loop, SLOT(quit()));//�������ζ�ʱ�����ۺ���Ϊ�¼�ѭ�����˳�����
    loop.exec();			//�¼�ѭ����ʼִ�У�����Ῠ�����ֱ����ʱʱ�䵽����ѭ�����˳�
}

void ReadThread::run()
{
    bool ret = m_videoDecode->open(m_url);         // ��������ʱ��Ƚ���������ŵ�Ui�̻߳Ῠ
    if (ret)
    {
        m_play = true;
        m_etime1.start();
        m_etime2.start();
        emit playState(play);
    }
    else
    {
        qWarning() << "��ʧ�ܣ�";
    }
    // ѭ����ȡ��Ƶͼ��
    while (m_play)
    {
        // ��ͣ
        while (m_pause)
        {
            sleepMsec(200);
        }

        QImage image = m_videoDecode->read();  // ��ȡ��Ƶͼ��
        if (!image.isNull())
        {
            // 1���ٲ���
#if 0
            sleepMsec(int(m_decodeVideo->pts() - m_etime1.elapsed()));         // ��֧�ֺ���
#else
            sleepMsec(int(m_videoDecode->pts() - m_etime2.elapsed()));         // ֧�ֺ��ˣ�����ܶ�ȡ����Ƶ����һֱ����ʾ���԰���һ�д���ע�����ԣ�
#endif
            emit updateImage(image);
        }
        else
        {
            // ��ǰ��ȡ����Чͼ��ʱ�ж��Ƿ��ȡ���
            if (m_videoDecode->isEnd())
            {
                break;
            }
            sleepMsec(1);   // ���ﲻ��ʹ��QThread::msleep()��ʱ�������ܲ��ȶ�
        }
    }

    qDebug() << "���Ž�����";
    m_videoDecode->close();
    emit playState(end);
}

/******************************************************************************
 * @�ļ���     readthread.h
 * @����       ��ȡ��Ƶͼ�������̣߳����߳��н�����Ƶ
 *
 * @������     mhf
 * @����       1603291350@qq.com
 * @ʱ��       2022/09/15
 * @��ע
 *****************************************************************************/
#ifndef READTHREAD_H
#define READTHREAD_H

#include <QElapsedTimer>
#include <QThread>
#include <QTime>

class VideoDecode;

class ReadThread : public QThread
{
    Q_OBJECT
public:
    enum PlayState      // ��Ƶ����״̬
    {
        play,
        end
    };
public:
    explicit ReadThread(QObject *parent = nullptr);
    ~ReadThread() override;

    void open(const QString& url = QString());  // ����Ƶ
    void pause(bool flag);                      // ��ͣ��Ƶ
    void close();                               // �ر���Ƶ
    const QString& url();                       // ��ȡ�򿪵���Ƶ��ַ

protected:
    void run() override;

signals:
    void updateImage(const QImage& image);      // ����ȡ������Ƶͼ���ͳ�ȥ
    void playState(PlayState state);            // ��Ƶ����״̬���͸ı�ʱ����

private:
    VideoDecode* m_videoDecode = nullptr;       // ��Ƶ������
    QString m_url;                              // �򿪵���Ƶ��ַ
    bool m_play = false;                      // ���ſ���
    bool m_pause = false;                      // ��ͣ����
    QElapsedTimer m_etime1;                     // ������Ƶ�����ٶȣ�����ȷ������֧����Ƶ���ˣ�
    QTime         m_etime2;                     // ������Ƶ�����ٶȣ�֧����Ƶ���ˣ�
};

#endif // READTHREAD_H

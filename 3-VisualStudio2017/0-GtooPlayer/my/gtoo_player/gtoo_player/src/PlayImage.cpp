#include "playimage.h"

#include <QPainter>

PlayImage::PlayImage(QWidget *parent) : QWidget(parent)
{
    // ���õ�ɫ�����ñ���ɫ
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);   //���ñ�����ɫ
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

/**
 * @brief        ����QimageͼƬ��ʾ
 * @param image
 */
void PlayImage::updateImage(const QImage& image)
{
    updatePixmap(QPixmap::fromImage(image));
}

/**
 * @brief        ����QPixmapͼƬ
 * @param pixmap
 */
void PlayImage::updatePixmap(const QPixmap &pixmap)
{
    m_mutex.lock();
    m_pixmap = pixmap;
    m_mutex.unlock();
    update();
}

/**
 * @brief        ʹ��Qpainter��ʾͼƬ
 * @param event
 */
void PlayImage::paintEvent(QPaintEvent *event)
{
    if (!m_pixmap.isNull())
    {
        QPainter painter(this);
#if 0
        // �������Բ��ԣ�QImage�����ź�תΪQPixmap�ķ�ʽ��ͼ��Ƚ�Сʱ��ʱ�٣�ͼƬԽ���ʱԽ��
        QPixmap pixmap = QPixmap::fromImage(m_image.scaled(this->size(), Qt::KeepAspectRatio));
        // �Ƚ�QImageת��ΪQPixmap�ٽ����������ʱ�Ƚ��٣������ȶ���������Ϊ����ͼƬ��С������̫��Ӱ��
        QPixmap pixmap1 = QPixmap::fromImage(m_image).scaled(this->size(), Qt::KeepAspectRatio);
#endif
        m_mutex.lock();
        QPixmap pixmap = m_pixmap.scaled(this->size(), Qt::KeepAspectRatio);
        m_mutex.unlock();
        int x = (this->width() - pixmap.width()) / 2;
        int y = (this->height() - pixmap.height()) / 2;
        painter.drawPixmap(x, y, pixmap);
    }
    QWidget::paintEvent(event);
}

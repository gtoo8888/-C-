#include "VideoSlider.h"
#include <QMouseEvent>
#include <QStyle>
VideoSlider::VideoSlider(QWidget *parent) : QSlider(parent)
{

}

void VideoSlider::mousePressEvent(QMouseEvent *ev)
{
    // 根据点击位置的x值，计算出对应的value
    // 方法1:
//    int range = maximum()- minimum();
//    double nowPos = ev->pos().x() * 1.0 / width();
//    int value = minimum() + nowPos * range;
    // 方法2:
    int value = QStyle::sliderValueFromPosition(minimum(),maximum(),
                                    ev->pos().x(),width());
    setValue(value);
    //保持拖动事件依然可用
    QSlider::mousePressEvent(ev);
}

#ifndef VIDEOSLIDER_H
#define VIDEOSLIDER_H

#include <QSlider>

class VideoSlider : public QSlider {
    Q_OBJECT
public:
    explicit VideoSlider(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev) override;
signals:
};

#endif  // VIDEOSLIDER_H

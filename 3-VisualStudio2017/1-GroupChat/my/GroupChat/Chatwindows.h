#ifndef CHATWINDOWS_H
#define CHATWINDOWS_H

#include <QWidget>

namespace Ui {
class ChatWindows;
}

class ChatWindows : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindows(QWidget *parent = nullptr,QString userName = QString(""));
    void closeEvent(QCloseEvent *event);
    ~ChatWindows();

signals:
    void closeChatWnd();

private:
    Ui::ChatWindows *ui;
};

#endif // CHATWINDOWS_H

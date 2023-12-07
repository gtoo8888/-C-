#pragma once

#include <QWidget>
#include "ui_WidgetExample.h"
#include "ReadThread.h"

class Example : public QWidget
{
    Q_OBJECT

public:
    Example(QWidget *parent = nullptr);
    ~Example();

private slots:
    void on_but_file_clicked();

    void on_but_open_clicked();

    void on_but_pause_clicked();

    void on_playState(ReadThread::PlayState state);


private:
    Ui::ExampleClass *ui;

    ReadThread* m_readThread = nullptr;
};

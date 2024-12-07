#ifndef STOPWATCHSETWDG_H
#define STOPWATCHSETWDG_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class StopwatchSetWdg;
}

class StopwatchSetWdg : public QWidget {
    Q_OBJECT

public:
    explicit StopwatchSetWdg(QWidget *parent = nullptr);
    ~StopwatchSetWdg();

private:
    Ui::StopwatchSetWdg *ui;

    void initUi(void);
};

#endif  // STOPWATCHSETWDG_H

#include "About.h"

About::About(QWidget *parent):
    ui(new Ui::About),
    QWidget(parent)
{
    ui->setupUi(this);

    connect(ui->ClosePushButton, &QPushButton::clicked, this, &About::closeCurrentWindow);
}

void About::closeCurrentWindow(void) {
    this->close();
}

About::~About()
{
    delete ui;
}

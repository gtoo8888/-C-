#include "MainWindow.h"
#include "Clock/ClockWdg.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnClock_clicked() {
    ClockWdg* clockwdg = new ClockWdg;
    clockwdg->show();
}

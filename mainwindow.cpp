#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->check1, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Hello", "You clicked the button!");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

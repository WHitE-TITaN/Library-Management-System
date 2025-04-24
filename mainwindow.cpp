#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerdialog.h"

#include <QMessageBox>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->check1, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Hello", "Check Was SuccessFull procide with Process\n"
                                                   "✅✅✅!");
    });

    connect(ui->registerUserButton, &QPushButton::clicked, this, [this](){
        registerdialog dialog(this); // parent set to main window
        if (dialog.exec() == QDialog::Accepted) {
            QMessageBox::information(this, "Success", "User has been registered successfully!");
        } else {
            QMessageBox::information(this, "Cancelled", "Registration was cancelled.");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

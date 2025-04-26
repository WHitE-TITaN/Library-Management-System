#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "issuebook.h"
#include "registerdialog.h"
#include "additionofbook.h"
#include "allissuers.h"

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

    connect(ui->registerBookButton, &QPushButton::clicked, this, [this](){
        AdditionOfBook dialog(this);
        if(dialog.exec() == QDialog::Accepted){
            QMessageBox::information(this, "Success", "book has been registered successfully!");
        } else {
            QMessageBox::information(this, "Cancelled", "Registration was cancelled.");
        }
    });

    connect(ui->BookIssueButton, &QPushButton::clicked, this, [this](){
        IssueBook dialog(this);
        if(dialog.exec() == QDialog::Accepted){
            QMessageBox::information(this, "Success", "issued Book");
        }
        else{
            QMessageBox::information(this, "Cancelled", "Cant Issue book");
        }
    });

    connect(ui->ShowBookDetails, &QPushButton::clicked, this, [this](){
        allIssuers dialog(this);
        dialog.exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "registerdialog.h"
#include "ui_registerdialog.h"

#include "members.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QPushButton>

registerdialog::registerdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerdialog)
{
    ui->setupUi(this);

    connect(ui->registerBtn, &QDialogButtonBox::accepted, this, [this](){
        QString name = ui->nameEdit->text();
        QString address = ui->AddressEdit->text();
        QString contect = ui->ContactEdit->text();

        if(name.isEmpty() || address.isEmpty() || contect.isEmpty()){
            QMessageBox::warning(this, "Input Error","All fields Need to be Filled");
            return;
        }

        long long contactNumeber = contect.toLongLong();
        if(contactNumeber == 0 || contactNumeber / 1 == 0){
            QMessageBox::warning(this, "Error Input", "Wrong Contact Number");
            this->reject();
            return;
        }

        members newMember;
        int userId = newMember.registerUser(name.toStdString(), address.toStdString(), contactNumeber);

        QString summary = QString::fromStdString(newMember.getUserSummary(userId));
        QMessageBox::information(this, "User Registered!", summary);

        this->accept();
    });


    connect(ui->registerBtn, &QDialogButtonBox::rejected, this, [this](){
        this->reject();
        return;
    });
}

registerdialog::~registerdialog()
{
    delete ui;
}

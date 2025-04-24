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
        members newMember;
        bool isSuccessFull = newMember.registerUser(name.toStdString(), address.toStdString(), contactNumeber);

        if(isSuccessFull){
            time_t currectTime = time(0);
            tm validTill = *localtime(&currectTime);
            validTill.tm_mon += 1;
            mktime(&validTill);

            char expry[100];
            strftime(expry, sizeof(expry), "%d/%m/%Y", &validTill);

            QString summary = QString("🎉Registration Successful!🎉\n\n"
                                      "Name: %1\n"
                                      "Address: %2\n"
                                      "contect: %3\n"
                                      "Expiry: %4\n");
        }
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

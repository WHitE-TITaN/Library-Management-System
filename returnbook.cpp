#include "returnbook.h"
#include "ui_returnbook.h"

#include <QDialogButtonBox>
#include "informationWareHouse.h"
#include <QMessageBox>

returnBook::returnBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::returnBook)
{
    ui->setupUi(this);

    this->connect(ui->submmitBox, &QDialogButtonBox::accepted, this, [this](){
        QString name = ui->nameEdit->text();
        QString id = ui->nameEdit->text();

        if(name.isEmpty() || id.isEmpty()){
            QMessageBox::warning(this, "Input Error", "all fields Requires to be filed");
        }

        int userId = id.toInt();
        string bookName = name.toStdString();
        informationWareHouse returning;

        int fine = returning.returningBook(bookName, userId);
        if( fine == -1){
            QMessageBox::warning(this, "Input Error", "all fields Requires to be filed Correctly !");
            this->rejected();
            return;
        }
        else if(fine == 0){
            QMessageBox::information(this, "return successFull", "ThankYou hope you liked the service");
            this->accepted();
            return;
        }
        else{
            QString summary = QString("Due to Late return you have a \nfine - %1\need to clear the amount or the subScription will be revoked")
                                  .arg(fine);
            QMessageBox::warning(this, "Late retrun", summary);
            this->accepted();
            return;
        }
    });
}

returnBook::~returnBook()
{
    delete ui;
}

#include "additionofbook.h"
#include "ui_additionofbook.h"

#include "informationWareHouse.h"
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QDialog>

AdditionOfBook::AdditionOfBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdditionOfBook)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, [this](){
        QString bookName = ui->bookNameEdit->text();
        QString count = ui->lineEdit->text();

        if(bookName.isEmpty() || count.isEmpty()){
            QMessageBox::warning(this, "Input Error", "Please Fill all the Nessary Details");
        }

        int actualCount = count.toInt();
        if(actualCount == 0 || actualCount / 1 == 0){
            QMessageBox::warning(this, "Error Input", "Book Count is not Valid");
            this->reject();
            return;
        }

        informationWareHouse newBook;
        bool operationStat = newBook.addBook(bookName.toStdString(), actualCount);
        if(operationStat){
            QString summary = QString("Name - %1\n"
                                      "Total count - %2")
                                  .arg(bookName)
                                  .arg(count);
            QMessageBox::information(this, "Successfull addition", summary);
            this->accepted();
        }
    });

    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, [this](){
        this->reject();
        return;
    });
}

AdditionOfBook::~AdditionOfBook()
{
    delete ui;
}

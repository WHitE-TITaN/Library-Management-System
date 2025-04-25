#include "issuebook.h"
#include "ui_issuebook.h"

#include "informationWareHouse.h"

#include <QMessageBox>
#include <QDialogButtonBox>
#include <QDialog>

IssueBook::IssueBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IssueBook)
{
    ui->setupUi(this);

    connect(ui->applyToIssue, &QDialogButtonBox::accepted, this, [this](){
        QString userId = ui->idEdit->text();
        QString BookName = ui->nameEdit->text();

        if(userId.isEmpty() || BookName.isEmpty()){
            QMessageBox::warning(this, "Input Error", "All fields requires to be filled");
            this->rejected();
            return;
        }

        int id = userId.toInt();
        if(id == 0){
            QMessageBox::warning(this, "Input Error","Wrong Id");
            this->rejected();
            return;
        }

        informationWareHouse issueing;
        if(issueing.issueBook(BookName.toStdString(), id)){
            QMessageBox::information(this, "successfull", "book Issded to user for 15 days");
            this->accepted();
        }
    });
}

IssueBook::~IssueBook()
{
    delete ui;
}

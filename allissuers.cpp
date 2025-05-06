#include "allissuers.h"
#include "ui_allissuers.h"

#include <QDialogButtonBox>
#include "informationWareHouse.h"
#include <QMessageBox>

allIssuers::allIssuers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::allIssuers)
{
    ui->setupUi(this);

    connect(ui->submmitButtonBox, &QDialogButtonBox::accepted, this, [this](){
        QString bookName = ui->nameEdit_2->text();

        if(bookName.trimmed().isEmpty()){
            QMessageBox::warning(this, "Input Error", "All Field required to be filled");
            this->rejected();
            return;
        }

        informationWareHouse bookDetails;
        string allDetails = bookDetails.allIssuers(bookName.toStdString());

        QString allDetailsStr = QString::fromStdString(allDetails);
        if (allDetailsStr.trimmed().isEmpty()) {
            QMessageBox::information(this, "Issuers", "No issuers found for this book.");
        } else {
            QMessageBox::information(this, "Issuers", allDetailsStr);
        }
        QMessageBox::information(this, "Issuers", QString::fromStdString(allDetails));
    });
}

allIssuers::~allIssuers()
{
    delete ui;
}

#include "additionofbook.h"
#include "ui_additionofbook.h"

AdditionOfBook::AdditionOfBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdditionOfBook)
{
    ui->setupUi(this);
}

AdditionOfBook::~AdditionOfBook()
{
    delete ui;
}

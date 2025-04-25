#ifndef ADDITIONOFBOOK_H
#define ADDITIONOFBOOK_H

#include <QDialog>

namespace Ui {
class AdditionOfBook;
}

class AdditionOfBook : public QDialog
{
    Q_OBJECT

public:
    explicit AdditionOfBook(QWidget *parent = nullptr);
    ~AdditionOfBook();

private:
    Ui::AdditionOfBook *ui;
};

#endif // ADDITIONOFBOOK_H

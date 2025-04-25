#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QDialog>

namespace Ui {
class IssueBook;
}

class IssueBook : public QDialog
{
    Q_OBJECT

public:
    explicit IssueBook(QWidget *parent = nullptr);
    ~IssueBook();

private:
    Ui::IssueBook *ui;
};

#endif // ISSUEBOOK_H

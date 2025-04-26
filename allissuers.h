#ifndef ALLISSUERS_H
#define ALLISSUERS_H

#include <QDialog>

namespace Ui {
class allIssuers;
}

class allIssuers : public QDialog
{
    Q_OBJECT

public:
    explicit allIssuers(QWidget *parent = nullptr);
    ~allIssuers();

private:
    Ui::allIssuers *ui;
};

#endif // ALLISSUERS_H

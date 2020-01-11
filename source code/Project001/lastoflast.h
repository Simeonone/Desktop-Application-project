#ifndef LASTOFLAST_H
#define LASTOFLAST_H

#include <QDialog>
#include "admin.h"
namespace Ui {
class lastoflast;
}

class lastoflast : public QDialog
{
    Q_OBJECT

public:
    explicit lastoflast(QWidget *parent = nullptr);
    ~lastoflast();

private:
    Ui::lastoflast *ui;
};

#endif // LASTOFLAST_H

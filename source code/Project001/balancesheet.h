#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <QDialog>
#include "admin.h"
namespace Ui {
class balancesheet;
}

class balancesheet : public QDialog
{
    Q_OBJECT

public:

    explicit balancesheet(QWidget *parent = nullptr);
    ~balancesheet();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_loadtable_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::balancesheet *ui;
};

#endif // BALANCESHEET_H

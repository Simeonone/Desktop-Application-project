#ifndef CASHFLOWS2_H
#define CASHFLOWS2_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include "admin.h"

namespace Ui {
class cashflows2;
}

class cashflows2 : public QDialog
{
    Q_OBJECT

public:
    explicit cashflows2(QWidget *parent = nullptr);
    ~cashflows2();

private slots:
    void on_pushButton_3_loadtable_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::cashflows2 *ui;
};

#endif // CASHFLOWS2_H

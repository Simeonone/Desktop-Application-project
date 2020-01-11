#ifndef INCOMESTATEMENT_H
#define INCOMESTATEMENT_H

#include <QDialog>
#include "admin.h"
namespace Ui {
class incomestatement;
}

class incomestatement : public QDialog
{
    Q_OBJECT

public:
    explicit incomestatement(QWidget *parent = nullptr);
    ~incomestatement();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_loadtable_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::incomestatement *ui;
};

#endif // INCOMESTATEMENT_H

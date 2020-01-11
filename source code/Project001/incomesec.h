#ifndef INCOMESEC_H
#define INCOMESEC_H

#include <QDialog>

namespace Ui {
class incomesec;
}

class incomesec : public QDialog
{
    Q_OBJECT

public:
    explicit incomesec(QWidget *parent = nullptr);
    ~incomesec();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::incomesec *ui;
};

#endif // INCOMESEC_H

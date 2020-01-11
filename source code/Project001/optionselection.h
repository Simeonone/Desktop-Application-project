#ifndef OPTIONSELECTION_H
#define OPTIONSELECTION_H

#include <QDialog>


//#include "cashflowsmainwindow.h" //
namespace Ui {
class optionselection;
}

class optionselection : public QDialog
{
    Q_OBJECT
//public slots: //
   // void cashflowsmainwindow(); //
public:
    explicit optionselection(QWidget *parent = nullptr);
    ~optionselection();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
   // cashflowsmainwindow mMynewwindow; //
    Ui::optionselection *ui;
};

#endif // OPTIONSELECTION_H

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

namespace Ui {
class calculator;
} //I wanna use the standard UI namespace which is going to be tied to our calclator.ui file

class calculator : public QDialog
{
    Q_OBJECT
//Q_OBJECT: I wanna declare my class as a qobject which is the base class for all our qt objects.
    //also takes care of my event handling for me, my signals and slots
public:
    explicit calculator(QWidget *parent = nullptr);  //nullptr=this widget has no parent
    ~calculator();

private:
    Ui::calculator *ui;
    //now let me define my slots
private slots:
    void NumPressed();
    void MathButtonPressed();
   void EqualButtonPressed();
   void ChangeNumberSign();
};

#endif // CALCULATOR_H

#include "calculator.h"
#include "ui_calculator.h"
double calcVal=0.0; //tracks current value for our calculations
bool divTrigger=false;//tracks last mathbutton that was clicked on
bool multTrigger=false;//tracks last mathbutton that was clicked on
bool addTrigger=false;//tracks last mathbutton that was clicked on
bool subTrigger=false;//tracks last mathbutton that was clicked on
calculator::calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculator) //creates a ui class and assigns it to the ui member that we have
{
    ui->setupUi(this); //sets up my ui
    ui->display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];//create an array that will hold my qpushbuttons
    //now i want to cycle thro each and assign our signal and slot
    for (int i=0;i<10;i++) {
        QString butName = "Button" + QString::number(i);
        //get buttons by name
        numButtons[i] = calculator::findChild<QPushButton *>(butName); //seraches for a widget by providing the name
        //now, lets get to when a button is released
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
    connect(ui->add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->equal, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));
    connect(ui->changesign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));
}

calculator::~calculator() //destructor
{
    delete ui;
}
void calculator::NumPressed() //this function puts the numbers in the display
{
    QPushButton *button = (QPushButton *)sender();
    //below gets the number that was clicked on the button
    QString butVal = button->text();
    //below gets the value in our display
    QString displayVal = ui->display->text(); //check if display is capital D or not
    if((displayVal.toDouble()== 0)||(displayVal.toDouble()== 0.0)){
        ui->display->setText(butVal);
    }
    else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        //below the code handles a maximum of 16 digits before it handles exponents
        ui->display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void calculator::MathButtonPressed() // tracks which math button was clicked on last
{
    divTrigger=false;
    multTrigger=false;
    addTrigger=false;
    subTrigger=false;
    //store the current value inside display
    QString displayVal = ui->display->text();
    //below stores this
    calcVal = displayVal.toDouble(); //we're converting to double cause thats what were going to be storing everything as
    //below finds out what math button was actually clicked on
    QPushButton *button=(QPushButton *)sender();//the sender that sent us to this function
    //below gets the math symbol from the button
    QString butVal = button->text();
    //below checks out which math button was actually clicked on
    if(QString::compare(butVal, "/" , Qt::CaseInsensitive) == 0)//if its equal to 0 it means i have a match
    {
        divTrigger=true;
    } else if(QString::compare(butVal, "*" , Qt::CaseInsensitive) == 0)//if its equal to 0 it means i have a match
    {
        multTrigger=true;
    } else if(QString::compare(butVal, "+" , Qt::CaseInsensitive) == 0)//if its equal to 0 it means i have a match
    {
        addTrigger=true;
    } else {
        subTrigger = true;
    }
    //then we clear our display when we're entering a new number
    ui->display->setText("");
}
void calculator::EqualButtonPressed(){
    double solution = 0.0;
    //below gets the value in the display to perform set calculation
    QString displayVal = ui->display->text();
    //now lets convert to double so that we can perform our calculations
    double dblDisplayVal = displayVal.toDouble();
    //now were making sure math button was indeed pressed
    if(addTrigger || subTrigger || multTrigger || divTrigger)
    {
        //below eg. if the last one that was clicked was called addtrigger
        if(addTrigger)
        {
            solution= calcVal + dblDisplayVal;
        } else if(subTrigger)
        {
            solution= calcVal - dblDisplayVal;
        } else if(multTrigger)
        {
            solution= calcVal * dblDisplayVal;
        } else
        {
            solution= calcVal / dblDisplayVal;
        }
    }
    ui->display->setText(QString::number(solution));
}
void calculator::ChangeNumberSign()
{
    QString displayVal = ui->display->text();
    //below is a regular expression check to verify that what's inside the display is actually a number
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal))
    {
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->display->setText(QString::number(dblDisplayValSign));
    }
}

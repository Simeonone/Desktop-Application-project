#include "mainpage.h"
#include "ui_mainpage.h"
#include <QDesktopServices>
#include "optionselection.h"
mainpage::mainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/project/Project001/simeon1.png");
    ui->label_2->setPixmap(pix);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_pushButton_clicked()
{
    hide();
    optionselection optionselection;
    optionselection.setModal(true);
    optionselection.exec();
}

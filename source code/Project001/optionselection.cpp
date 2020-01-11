#include "optionselection.h"
#include "ui_optionselection.h"
#include "cashflows2.h"
#include "balancesheet.h"
#include "incomestatement.h"
#include "login.h"
#include<QDesktopServices>
#include<QUrl>
optionselection::optionselection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionselection)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/xampp/htdocs/project/TPA-Service-Accounting.jpg");
    ui->label_4->setPixmap(pix);
    ui->pushButton->setToolTip("<font color='blue'><b>Use SmartAccountant to manage</b> your company’s"
                               "<ul>"
                               "<li>revenue</li>"
                               "<li>costs</li>"
                               "<li>gross profit</li>"
                               "<li>selling and administrative expenses</li>"
                               "<li>Other expenses and income</li>"
                               "<li>taxes paid</li>"
                               "<li>net profit</li></font>"
                               "</ul>");
    ui->pushButton_2->setToolTip("<font color='blue'><b>Use SmartAccountant to manage</b> your company's"
                                 "<ul>"
                                 "<li>assets</li>"
                                 "<li>liabilities</li>"
                                 "<li>capital of a business or other organization at a particular point in time, detailing the balance of income and expenditure over the preceding period.</li></font>"
                                 "</ul");
    ui->pushButton_3->setToolTip("<font color='blue'><b>Use SmartAccountant to Manage</b> your company's"
                                 "<ul>"
                                 "<li>amount of cash (currency) that is generated or consumed in a given time period<li></font>");
    ui->pushButton_5->setToolTip("<font color='blue'<b>Have any questions, queries, or are you new to SmartAccountant? Click here to contact us, know about SmartAccountant and even more!</b></font>");
    //my database is called cash
    QSqlDatabase cash= QSqlDatabase::addDatabase("QSQLITE");
    cash.setDatabaseName("C:/Users/home/Desktop/project/Database001/simeondatabase.db");

    if(!cash.open())
    {
        ui->label_3->setText("Failed to connect to database");
    }
    else{
        ui->label_3->setText("Connected...");
    }
}

optionselection::~optionselection()
{
    delete ui;
}

void optionselection::on_pushButton_3_clicked()
{
    cashflows2 cashflows2;
    cashflows2.setModal(true);
    cashflows2.exec();
}



void optionselection::on_pushButton_5_clicked()
{
    QString link="http://localhost/project/index.html";
    QDesktopServices::openUrl(QUrl(link));
}

void optionselection::on_pushButton_2_clicked()
{
    balancesheet balancesheet;
    balancesheet.setModal(true);
    balancesheet.exec();
}

void optionselection::on_pushButton_clicked()
{
    incomestatement incomestatement;
    incomestatement.setModal(true);
    incomestatement.exec();
}

void optionselection::on_pushButton_4_clicked()
{
    hide();
    login login;
    login.setModal(true);
    login.exec();
}

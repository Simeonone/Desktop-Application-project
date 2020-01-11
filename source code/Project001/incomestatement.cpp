#include "incomestatement.h"
#include "ui_incomestatement.h"
#include<QMessageBox>
#include <QUrl>
#include<QtWidgets>
#include<QDesktopServices>
#include "calculator.h"
#include "incomesec.h"
#include "last.h"
incomestatement::incomestatement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incomestatement)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/xampp/htdocs/project/ManagementLeadership.jpg");
    ui->label_5->setPixmap(pix);
    ui->pushButton_2->setToolTip("<font color='red'><b>Insert particulars only!!</b></font>");
    admin conn;
    if(!conn.connOpen())
        ui->label_4->setText("Failed to connect to database");
    else {
        ui->label_4->setText("Connected");
    }
}

incomestatement::~incomestatement()
{
    delete ui;
}

void incomestatement::on_pushButton_clicked()
{
    admin conn;
    QString brought, carried, particular;
    particular=ui->lineEdit->text();
    brought=ui->lineEdit_2->text();
    carried=ui->lineEdit_3->text();
    if((ui->lineEdit->text().isEmpty())||(ui->lineEdit_2->text().isEmpty())||(ui->lineEdit_3->text().isEmpty()))
    {
         QMessageBox::information(this,tr("Fail!"),tr("Insert all fields to save"));

    }
    else{
    if(!conn.connOpen()) //checks whether database is still open or not
    {
       qDebug()<<"Failed to open the database";
       return;
    }
    conn.connOpen();
    //the query is called qryb
    QSqlQuery qryb;
    qryb.prepare("insert into incomestatement (particular,balance_carried_forward,balance_brought_forward) values ('"+particular+"','"+brought+"','"+carried+"')");
    if(qryb.exec())
    {
        QMessageBox::information(this,tr("SUCCESS!!"),tr("MESSAGE SAVED SUCCESSFULLY"));
        conn.connClose();
    }
    else{
         QMessageBox::critical(this,tr("error"),qryb.lastError().text());
    }
    }
}

void incomestatement::on_pushButton_3_loadtable_clicked()
{
    admin conn;
    //pointer is called modal
    QSqlQueryModel * modal = new QSqlQueryModel;
    conn.connOpen();//connopen is the function that opens the connection with the sqlite database
    //lets prepare a query
    QSqlQuery* qry=new QSqlQuery(conn.mydb);
    qry->prepare("select particular, balance_carried_forward, balance_brought_forward from incomestatement");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void incomestatement::on_pushButton_2_clicked()
{
    admin conn;
    QString newusername;
    newusername=ui->lineEdit->text();
    //changepassword=ui->lineEdit_password->text();
    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;

    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from incomestatement where particular='"+newusername+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("SUCCESS!"),tr("Deleted successfully"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}

void incomestatement::on_pushButton_3_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File. SmartAccountant © 2019 Incomestatement"),
                "C:/Users/home/Desktop/project/Database001",
                "All files (*.*);;Text file (*.txt)"
                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}

void incomestatement::on_pushButton_4_clicked()
{
    calculator calculator;
    calculator.setModal(true);
    calculator.exec();
}

void incomestatement::on_pushButton_5_clicked()
{
    incomesec incomesec;
    incomesec.setModal(true);
    incomesec.exec();
}

void incomestatement::on_pushButton_6_clicked()
{
    last last;
    last.setModal(true);
    last.exec();
}

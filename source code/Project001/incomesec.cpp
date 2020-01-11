#include "incomesec.h"
#include "ui_incomesec.h"
#include <QSqlQuery>
#include "admin.h"
#include <QMessageBox>
incomesec::incomesec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incomesec)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/xampp/htdocs/project/accounting-bookkeeping-linson.jpg");
    ui->label->setPixmap(pix);
   // this->setCentralWidget(ui->tableView);
}

incomesec::~incomesec()
{
    delete ui;
}

void incomesec::on_pushButton_3_clicked()
{
    admin conn;
    //pointer is called modal
    QSqlQueryModel * modal = new QSqlQueryModel;
    conn.connOpen();//connopen is the function that opens the connection with the sqlite database
    //lets prepare a query
    QSqlQuery* qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from incomestatement");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());

}

void incomesec::on_pushButton_2_clicked()
{

       admin conn;
        conn.connOpen();
        QSqlQuery qryyy34;
        qryyy34.prepare("UPDATE incomestatement SET ANALYSIS = 'Liabilities are incresing from previous financial year' WHERE TOTAL<0 ");
        if(qryyy34.exec())
       {
            QMessageBox::information(this,tr("SUCCESS!"),tr("Added successfully"));
            conn.connClose();
        }
        conn.connClose();


}


void incomesec::on_pushButton_clicked()
{

    admin conn;
     conn.connOpen();
     QSqlQuery qryyy34;
     qryyy34.prepare("UPDATE incomestatement SET ANALYSIS = 'Liabilities are incresing from previous financial year' WHERE TOTAL>0 ");
     if(qryyy34.exec())
    {
         QMessageBox::information(this,tr("SUCCESS!"),tr("Added successfully"));
         conn.connClose();
     }
     conn.connClose();

}

void incomesec::on_pushButton_4_clicked()
{
    admin conn;
   // QString csfinal;
   // csfinal=ui->lineEdit->text();
    //changepassword=ui->lineEdit_password->text();
    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry55;
    qry55.prepare("UPDATE incomestatement SET TOTAL= (balance_brought_forward-balance_carried_forward)");
    if(qry55.exec())
   {
        QMessageBox::information(this,tr("SUCCESS!"),tr("Operation completed"));
        conn.connClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error"),qry55.lastError().text());
    }
}


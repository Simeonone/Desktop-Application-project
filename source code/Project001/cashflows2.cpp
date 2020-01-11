#include "cashflows2.h"
#include "ui_cashflows2.h"
#include<QMessageBox>
#include"calculator.h"
#include <QFileDialog>
#include<QDesktopServices>
#include<QUrl>
#include<QtWidgets>
cashflows2::cashflows2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cashflows2)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/xampp/htdocs/project/photodune-7212896-for-business-l.jpg");
    ui->label_5->setPixmap(pix);
    ui->pushButton_2->setToolTip("<font color='red'><b>Insert Particulars Only!!</b></font>");
    admin conn;
    if(!conn.connOpen())
        ui->label_4->setText("Failed to connect to database");
    else {
        ui->label_4->setText("Connected");
    }

}

cashflows2::~cashflows2()
{
    delete ui;
}

void cashflows2::on_pushButton_3_loadtable_clicked()
{
    admin conn;
    //pointer is called modal
    QSqlQueryModel * modal = new QSqlQueryModel;
    conn.connOpen();//connopen is the function that opens the connection with the sqlite database
    //lets prepare a query
    QSqlQuery* qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from cashflows");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    QSqlQueryModel * modal2 = new QSqlQueryModel;
    QSqlQuery* qry2=new QSqlQuery(conn.mydb);
    qry2->prepare("select particular from incomestatement");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->comboBox->setModel(modal2);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void cashflows2::on_pushButton_clicked()
{
    admin conn;
    QString brought, carried, particular,retry;
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
    qryb.prepare("insert into cashflows (particulars,balance_carried_forward,balance_brought_forward) values ('"+particular+"','"+brought+"','"+carried+"')");

    // UPDATE cashflows SET TOTAL= (balance_brought_forward+balance_carried_forward)
    if(qryb.exec())
    {
        QMessageBox::information(this,tr("SUCCESS!!"),tr("MESSAGE SAVED SUCCESSFULLY"));
        conn.connClose();
    }
    else{
         QMessageBox::critical(this,tr("error"),qryb.lastError().text());
    }
  //  QSqlQuery qryc;
    //qryc.prepare("update cashflows set total= ('"+brought+"'+'"+carried+"')");
    }
}

void cashflows2::on_pushButton_2_clicked()
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
    qry.prepare("Delete from cashflows where particulars='"+newusername+"'");
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

void cashflows2::on_pushButton_3_clicked()
{
    calculator calculator;
    calculator.setModal(true);
    calculator.exec();
}

void cashflows2::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File. SmartAccountant © 2019 Cashflows"),
                "C:/Users/home/Desktop/project/Database001",
                "All files (*.*);;Text file (*.txt)"
                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
   // QMessageBox::information(this,tr("File Name. SmartAccountant © 2019 Balancesheet"),filename);
}


void cashflows2::on_pushButton_5_clicked()
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
    qry55.prepare("UPDATE cashflows SET TOTAL= (balance_brought_forward-balance_carried_forward)");
    if(qry55.exec())
   {
        QMessageBox::information(this,tr("SUCCESS!"),tr("Added successfully"));
        conn.connClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error"),qry55.lastError().text());
    }
}

//void cashflows2::on_pushButton_6_clicked()
//{
//    admin conn;
//    conn.connOpen();
//    QSqlQuery qryyy;
//    qryyy.prepare("UPDATE cashflows SET ANALYSIS = 'Liabilities are incresing from previous financial year' WHERE TOTAL<0 ");
//    if(qryyy.exec())
//   {
//        QMessageBox::information(this,tr("SUCCESS!"),tr("Added successfully"));
//        conn.connClose();
//    }
//    conn.connClose();
//}

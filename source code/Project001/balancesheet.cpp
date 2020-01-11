#include "balancesheet.h"
#include "ui_balancesheet.h"
#include <QMessageBox>
#include "calculator.h"
#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>
//#include <QRegExpValidator>
#include "cashflowsfinals.h"
balancesheet::balancesheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balancesheet)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/xampp/htdocs/project/photo-1524821695732-717b25a38974.jpeg");
    ui->label_4->setPixmap(pix);
    ui->pushButton_2->setToolTip("<font color='red'><b>Insert Particulars Only!!</b></font>");
        admin conn;
            if(!conn.connOpen())
                ui->label_tutor_status->setText("Couldn't connect to database");
            else
              ui->label_tutor_status->setText("Connected...");
}

balancesheet::~balancesheet()
{
    delete ui;
}

void balancesheet::on_pushButton_clicked()
{
    admin conn; //creating a new object with admin class
    QString newusername, newpassword, newnew, daters;
    newusername=ui->lineEdit_particular->text();
    newpassword=ui->lineEdit_balancecf->text();
    newnew=ui->lineEdit_balancebf->text();
    daters=ui->lineEdit_balancebf_2->text();
//    QRegExp regex("^(2[0-3]|[01]?[0-9]):([0-5]?[0-9])$");
//    QValidator *validator = new QRegularExpressionValidator(regex,this);
//    QLineEdit *edit = new QLineEdit(this)
    if((ui->lineEdit_particular->text().isEmpty())||(ui->lineEdit_balancebf->text().isEmpty())||(ui->lineEdit_balancecf->text().isEmpty())||(ui->lineEdit_balancebf_2->text().isEmpty()))
    {
         QMessageBox::information(this,tr("Fail!"),tr("Insert all fields to save"));

    }
\

    else{
    if(!conn.connOpen()) //checks whether database is still open or not
    {
       qDebug()<<"Failed to open the database";
       return;
    }
    //the query is called qryt
    conn.connOpen(); //this function will open the connection
    QSqlQuery qryt;
    qryt.prepare("insert into balancesheet (particulars,balance_carried_forward,balance_brought_forward,time) values ('"+newusername+"','"+newpassword+"','"+newnew+"','"+daters+"')");
    //sqlite database can't have multiple open connections simulatneously
    if(qryt.exec())//not that whenever you're done with a query, you need to close it cause the database is using the query
    {
     //now i want to show, if my query executes that my data is saved
     //there up there's an include qmessagebox
     //now i want to show the message in the messagebox
        QMessageBox::information(this,tr("SUCCESS!!"),tr("Data saved successfully"));
        //the code above executes if the query is successful
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error"),qryt.lastError().text());
    }
    }
    }


void balancesheet::on_pushButton_3_loadtable_clicked()
{
    admin conn;
    //pointer is called modal
    QSqlQueryModel * modal = new QSqlQueryModel;
    conn.connOpen();//connopen is the function that opens the connection with the sqlite database
    //lets prepare a query
    QSqlQuery* qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from balancesheet");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
   // conn.connClose();
  //  qDebug() <<(modal->rowCount());
    QSqlQueryModel * modal3 = new QSqlQueryModel;
    QSqlQuery* qry2=new QSqlQuery(conn.mydb);
    qry2->prepare("select particular from incomestatement");
    qry2->exec();
    modal3->setQuery(*qry2);
    ui->comboBox->setModel(modal3);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void balancesheet::on_pushButton_2_clicked()
{
    admin conn;
    QString newusername;
    newusername=ui->lineEdit_particular->text();
    //changepassword=ui->lineEdit_password->text();
    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from balancesheet where particulars='"+newusername+"'");
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

void balancesheet::on_pushButton_5_clicked()
{
    calculator calculator;
    calculator.setModal(true);
    calculator.exec();
}

void balancesheet::on_pushButton_3_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File. SmartAccountant © 2019 Balancesheet"),
                "C:/Users/home/Desktop/project/Database001",
                "All files (*.*);;Text file (*.txt)"
                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}

void balancesheet::on_pushButton_4_clicked()
{
    cashflowsfinals cashflowsfinals;
    cashflowsfinals.setModal(true);
    cashflowsfinals.exec();
}

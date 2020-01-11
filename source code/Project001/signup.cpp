#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include "login.h"
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->pushButton_delete->setToolTip("<font color='red'<b>Insert Username Only!!</b></font>");
    ui->pushButton->setToolTip("<font color='black'><b>Verify User credentials before signup!</b></font>");
    QPixmap pix("C:/Users/home/Desktop/project/Project001/7765.jpg_wh1200.jpg");
    ui->label->setPixmap(pix);
    admin conn;
            if(!conn.connOpen())
                ui->label_sec_status->setText("Couldn't connect to database");
            else
              ui->label_sec_status->setText("Connected...");

}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    admin conn; //creating a new object with admin class
    QString newusername, newpassword;
    newusername=ui->lineEdit_username->text();
    newpassword=ui->lineEdit_password->text();
    if((ui->lineEdit_password->text().isEmpty())||(ui->lineEdit_username->text().isEmpty()))
    {
         QMessageBox::critical(this,tr("Fail!"),tr("Operation unsuccessful"));

    }
    else {
    if(!conn.connOpen()) //checks whether database is still open or not
    {
       qDebug()<<"Failed to open the database";
       return;
    }
    //the query is called qryt
    conn.connOpen(); //this function will open the connection
    QSqlQuery qryt;
    qryt.prepare("insert into logininfo (Username,Password) values ('"+newusername+"','"+newpassword+"')");
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

void signup::on_pushButton_delete_clicked()
{
    admin conn;
    QString newusername, newpassword;
    newusername=ui->lineEdit_username->text();
    //changepassword=ui->lineEdit_password->text();
    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from logininfo where Username='"+newusername+"'");
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

void signup::on_pushButton_2_clicked()
{
    admin conn;
    //pointer is called modal
    QSqlQueryModel * modal = new QSqlQueryModel;
    conn.connOpen();//connopen is the function that opens the connection with the sqlite database
    //lets prepare a query
    QSqlQuery* qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from logininfo");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void signup::on_pushButton_3_clicked()
{
    hide(); //closes the window once successful
    login login;
    login.setModal(true);
    login.exec();
}

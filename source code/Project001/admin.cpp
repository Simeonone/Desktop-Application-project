#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/project/Project001/images (2).jpeg");
    ui->label_4->setPixmap(pix);
    if(!connOpen())
        ui->label_3->setText("Couldn't connect to database");
    else
      ui->label_3->setText("Connected...");
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if(username=="Admin" && password == "123456789")
    {
       // QMessageBox::information(this,"Reminder!","Remember to verify user details before assigning user with login credentials");
         hide();
         signup signup; //this is a new window code. before opening the new window the old one should be closed
         signup.setModal(true);
         signup.exec();
    }
    else{
        QMessageBox::warning(this,"Error!!", "Login Fail!");
    }
//    QString usernamet, passwordt;
//    usernamet=ui->lineEdit->text();
//    passwordt=ui->lineEdit_2->text();
//    if(!connOpen()) //checks whether database is still open or not
//    {
//       qDebug()<<"Failed to open the database";
//       return;
//    }
    //.the query is called qry
//    connOpen(); //this function will open the connection
//    QSqlQuery qryt;
//    qryt.prepare("select * from logininfo where Username ='"+usernamet+ "' and Password = '" +passwordt+ "'");
    //sqlite database can't have multiple open connections simulatneously
//    if(qryt.exec())//not that whenever you're done with a query, you need to close it cause the database is using the query
//    {
//        int count=0; //counts the number of times the query is executed
//        while(qryt.next())
//        {
//            count++;
//        }
//        if(count==1){
//            ui->label_3->setText("Username and password is correct");
//            connClose();// this closes the connection with the database and opens the new window
//            QMessageBox::information(this,"Reminder!","Remember to verify user details before assigning user with login credentials");
//            hide();
//            this->hide();
//            signup signup; //this is a new window code. before opening the new window the old one should be closed
//            signup.setModal(true);
//            signup.exec();
//        }
//        if(count>1)
//            ui->label_3->setText("Duplicate username and password");
//        if(count<1)
//            ui->label_3->setText("Username and password is not correct");
//}
}

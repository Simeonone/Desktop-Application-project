#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/project/Project001/accounting.jpg");
    ui->label_4->setPixmap(pix);
    //database name is mydb
    admin conn;
    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/home/Desktop/project/Database001/simeondatabase.db");
    if(!conn.connOpen())
        ui->label->setText("Couldn't connect to database");
    else
      ui->label->setText("Connected...");

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    admin conn;
    QString username, password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();
    if(!conn.connOpen()) //checks whether database is still open or not
    {
       qDebug()<<"Failed to open the database";
       return;
    }
    conn.connOpen();
    //the query is called qry
    QSqlQuery qry;
    if(qry.exec("select * from logininfo where Username ='"+username+ "' and password = '" +password+ "'"))
    {
        int count=0; //counts the number of times the query is executed
        while(qry.next())
        {
            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is correct");
            conn.connClose();
            this->hide();
            hide(); //closes the window once successful
            mainpage mainpage;
            mainpage.setModal(true);
            mainpage.exec();
        }
        if(count>1)
            ui->label->setText("Duplicate username and password");
        if(count<1)
            ui->label->setText("Username and password is not correct");
    }
}

void login::on_pushButton_2_clicked()
{
    admin admin;
    admin.setModal(true);
    admin.exec();
}

void login::on_pushButton_3_clicked()
{
    admin admin;
    admin.setModal(true);
    admin.exec();
}

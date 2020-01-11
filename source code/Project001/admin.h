#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include"signup.h"
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
        //what's done is the database is close and removed if any connection is there, or default connection is there. conclose funtion does this
    }
    bool connOpen()
    {
        //note that we don't want to use labels in the header files, instead it will be shown in the application output
        mydb= QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/home/Desktop/project/Database001/simeondatabase.db");
        if(!mydb.open())
        {
            qDebug()<<("Couldn't connect to database");
            return false;
        }
        else{
          qDebug()<<("Connected...");
          return true;
        }
    }

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_clicked();


private:
    Ui::admin *ui;

};

#endif // ADMIN_H

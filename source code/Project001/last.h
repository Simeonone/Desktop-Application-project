#ifndef LAST_H
#define LAST_H

#include <QDialog>
#include <QtSql>
#include<QPainter>
namespace Ui {
class last;
}

class last : public QDialog
{
    Q_OBJECT
    QSqlDatabase mydb;

           void connClose()
           {mydb.close();
               mydb.removeDatabase(QSqlDatabase::defaultConnection);

           }

           bool connOpen()
           {
               mydb=QSqlDatabase::addDatabase("QSQLITE");
              mydb.setDatabaseName("C:/Users/home/Desktop/project/Database001/simeondatabase.db");//path of your database file
              if(!mydb.open())
                 {
              return false;}
              else
                 {
              return true;}
           }

public:
    explicit last(QWidget *parent = nullptr);
    ~last();

private:
    Ui::last *ui;
    int a;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // LAST_H

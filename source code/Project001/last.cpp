#include "last.h"
#include "ui_last.h"
#include <QtSql>
#include <QPainter>
//#include<QRectF>

last::last(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::last)
{

    ui->setupUi(this);

}

last::~last()
{
    delete ui;
}

void last::paintEvent(QPaintEvent *)
{
    connOpen(); //accesses your database
    QPainter Painter(this);
    QRectF size=QRectF(ui->label->geometry());
    Painter.setBrush(Qt::black);
    QString r1="select * from test";
    QString r2="select * from test where name= 'Paed'";
    QString r3="select * from test where name= 'Inf'";
    QString r4="select * from test where name= 'me'";
    QSqlQuery q1,q2,q3,q4;
    q1.exec(r1); //we execute the string
    q2.exec(r2);
    q3.exec(r3);
    q4.exec(r4);
    int tot=0, bg=0, bs=0, rfn=0, sim=0;
    while(q1.next())
    {
        tot++; //counting how many lines we got after the execution of the query
    }
    while(q2.next())
    {
        bg++;
    }
    while(q3.next())
    {
        bs++;
    }
    while(q4.next())
    {
        sim++;
    }
    bg=(((bg*100)/tot)*360)/100;
    bs=(((bs*100)/tot)*360)/100;
    sim=(((sim*100)/tot)*360)/100;
    rfn=360-(bs+bg+sim);
    Painter.drawPie(size,0,bg*16);
    Painter.setBrush(Qt::green);
    Painter.drawPie(size,bg*16,bs*16);
    Painter.setBrush(Qt::yellow);
    Painter.drawPie(size,bg*16+bs*16,sim*16);
    Painter.setBrush(Qt::black);
    Painter.drawPie(size,bg*16+bs*16+sim*16,rfn*16);
}

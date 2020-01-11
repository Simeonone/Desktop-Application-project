#include "cashflowsfinals.h"
#include "ui_cashflowsfinals.h"
#include <QSqlTableModel>
#include "admin.h"
cashflowsfinals::cashflowsfinals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cashflowsfinals)
{
    ui->setupUi(this);
    cashflowsfinals::makePlot();
}

cashflowsfinals::~cashflowsfinals()
{
    delete ui;
}
void cashflowsfinals::makePlot()
{
    // generate some data:
    QVector<double> x(100000), y(100000); // initialize with entries 0..100
  // for (int i=0; i<100000; ++i)
  //  {
  //    x[i] = i/50.0 - 1; // x goes from -1 to 1
 //     y[i] = x[i]*x[i]; // let's plot a quadratic function
 //   }
    // create graph and assign data to it:
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(x, y);
    // give the axes some labels:
   // ui->customplot->xAxis->setLabel("Time");
   // ui->customplot->yAxis->setLabel("Balance brought forward");
    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(-500, 15000);
    ui->customplot->yAxis->setRange(-500, 15000);
    //ui->customplot->replot();

    QSqlTableModel *model=new QSqlTableModel;
    model->setTable("balancesheet");
    model->select();
    ui->tableView->setModel(model);

    ui->customplot->xAxis->setLabel("time");
    ui->customplot->yAxis->setLabel("balance_brought_forward");
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm");
    ui->customplot->xAxis->setTicker(dateTicker);

    QVector<QCPGraphData> timeData(model->rowCount());

    for(int i=0; i< model->rowCount(); ++i){
        timeData[i].key = QDateTime(QDate::currentDate(), model->index(i, model->fieldIndex("time")).data().toTime()).toTime_t();
        timeData[i].value = model->index(i, model->fieldIndex("balance_brought_forward")).data().toDouble();
    }

    double Tmin = (*std::min_element(timeData.begin(), timeData.end(),
                                    [](const QCPGraphData& x, const QCPGraphData& y)
    {  return x.key < y.key; })).key;
    double Tmax = (*std::max_element(timeData.begin(), timeData.end(),
                                    [](const QCPGraphData& x, const QCPGraphData& y)
    {  return x.key < y.key; })).key;

    double Ymin = (*std::min_element(timeData.begin(), timeData.end(),
                                    [](const QCPGraphData& x, const QCPGraphData& y)
    {  return x.value < y.value; })).value;

    double Ymax = (*std::max_element(timeData.begin(), timeData.end(),
                                    [](const QCPGraphData& x, const QCPGraphData& y)
    {  return x.value < y.value; })).value;
    ui->customplot->xAxis->setRange(Tmin, Tmax);
    ui->customplot->yAxis->setRange(Ymin, Ymax);
    ui->customplot->graph(0)->data()->set(timeData);
    ui->customplot->replot();
}

void cashflowsfinals::on_pushButton_clicked()
{
    admin conn;
       QSqlQueryModel * modal=new QSqlQueryModel();
       conn.connOpen();
       QSqlQuery* qry=new QSqlQuery(conn.mydb);
       qry->prepare("select particulars, balance_brought_forward, time from balancesheet");
       qry->exec();
       modal->setQuery(*qry);
       ui->tableView->setModel(modal);
       conn.connClose();
       qDebug() <<(modal->rowCount());
}

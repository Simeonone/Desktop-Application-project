#ifndef CASHFLOWSFINALS_H
#define CASHFLOWSFINALS_H

#include <QDialog>
namespace Ui {
class cashflowsfinals;
}

class cashflowsfinals : public QDialog
{
    Q_OBJECT

public:
    explicit cashflowsfinals(QWidget *parent = nullptr);
    ~cashflowsfinals();
private slots:
    void makePlot();
    void on_pushButton_clicked();

private:
    Ui::cashflowsfinals *ui;
};

#endif // CASHFLOWSFINALS_H

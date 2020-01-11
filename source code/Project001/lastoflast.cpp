#include "lastoflast.h"
#include "ui_lastoflast.h"

lastoflast::lastoflast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lastoflast)
{
    ui->setupUi(this);
}

lastoflast::~lastoflast()
{
    delete ui;
}

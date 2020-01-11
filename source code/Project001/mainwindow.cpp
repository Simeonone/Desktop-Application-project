#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include"admin.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/home/Desktop/project/Project001/accounting.jpg");//named pix
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    login login;
    login.setModal(true);
    login.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    admin admin;
    admin.setModal(true);
    admin.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    admin admin;
    admin.setModal(true);
    admin.exec();
}

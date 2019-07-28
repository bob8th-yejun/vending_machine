#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeMoney(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMoney(int n) {
    money += n;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setDisabled(false);
    ui->pbTea->setDisabled(false);
    ui->pbGongCha->setDisabled(false);
    ui->pbReturn->setDisabled(false);
    if (money <= 0)
        ui->pbReturn->setDisabled(true);
    if (money < 100)
        ui->pbCoffee->setDisabled(true);
    if (money < 150)
        ui->pbTea->setDisabled(true);
    if (money < 200)
        ui->pbGongCha->setDisabled(true);
}

void MainWindow::on_pb10_clicked()
{
    changeMoney(10);
}

void MainWindow::on_pb50_clicked()
{
    changeMoney(50);
}

void MainWindow::on_pb100_clicked()
{
    changeMoney(100);
}

void MainWindow::on_pb500_clicked()
{
    changeMoney(500);
}

void MainWindow::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void MainWindow::on_pbTea_clicked()
{
    changeMoney(-150);
}

void MainWindow::on_pbGongCha_clicked()
{
    changeMoney(-200);
}

void MainWindow::on_pbReturn_clicked()
{
    int m = money;
    int c500 = m / 500;
    m %= 500;
    int c100 = m / 100;
    m %= 100;
    int c50 = m / 50;
    m %= 50;
    int c10 = m / 10;

    char str[100];
    sprintf(str, "500Won = %d\n100Won = %d\n50Won = %d\n10Won = %d", c500, c100, c50, c10);

    QMessageBox msg;
    msg.information(nullptr, "return", str);

    changeMoney(-money);
}

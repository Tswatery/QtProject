#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnect.h"
#include <string>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::acceptSignal()
{
    this->show();
}

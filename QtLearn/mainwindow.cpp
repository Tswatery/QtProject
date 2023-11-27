#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnect.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setDatabaseName("menu");
    db.setUserName("root");
    db.setPassword("123456");
    QSqlQuery query;
    query.exec("set names 'GBK'");
    // 建立数据库连接并设置中文不乱码
    ui->menu->setCurrentIndex(0);
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList() << "菜名" << "价格" << "菜系");
    ui->mainview->setModel(model);
    ui->mainview->horizontalHeader()->setStyleSheet(
      "QHeaderView::section{"
      "border-top:0px solid #E5E5E5;"
      "border-left:0px solid #E5E5E5;"
      "border-right:0.5px solid #E5E5E5;"
      "border-bottom: 0.5px solid #E5E5E5;"
      "background-color:white;"
      "padding:4px;"
      "}"
    ); // 给列表添加样式表

    int row = 0;
    if(query.exec("select dishName, price, cuisine from menu")){
        while(query.next()){
            QString dishName = query.value("dishName").toString(),
                    cuisine = query.value("cuisine").toString();
            QString price = QString::number(query.value("price").toDouble());
            model->setItem(row, 0, new QStandardItem(dishName));
            model->setItem(row, 1, new QStandardItem(cuisine));
            model->setItem(row, 2, new QStandardItem(price));
            row ++;
            qDebug() << dishName << cuisine << price;
        }
    }else {
        qDebug() << "database menu connect error";
    }
    // 添加元素
}

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
#include <QCheckBox>
#include <QHBoxLayout>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMenu();
    init();
    tableId = 2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu()
{
    DataBaseInit();
    modelDrink = new QStandardItemModel();
    modelMenu = new QStandardItemModel();
    modelOrder = new QStandardItemModel();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    // 建立数据库连接并设置中文不乱码
    int row = 0;
    if(query.exec("select id, dishName, price, cuisine from menu")){
        while(query.next()){
            QString id = query.value("id").toString(),
                    dishName = query.value("dishName").toString(),
                    price = query.value("price").toString(),
                    cuisine = query.value("cuisine").toString();
            modelMenu->setItem(row, 0, new QStandardItem(id));
            modelMenu->setItem(row, 1, new QStandardItem(dishName));
            modelMenu->setItem(row, 2, new QStandardItem(price));
            modelMenu->setItem(row, 3, new QStandardItem(cuisine));
            modelMenu->item(row, 0)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 1)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 2)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 3)->setTextAlignment(Qt::AlignCenter);
            row ++;
            qDebug() << dishName << cuisine << price;
        }
    }else {
        qDebug() << "database menu connect error";
    }
    db.close();
}

void MainWindow::init()
{
    ui->menu->setCurrentIndex(0);
    modelMenu->setHorizontalHeaderLabels(QStringList() << "序号"<< "菜名" << "价格" << "菜系");
    ui->mainview->setModel(modelMenu);
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

    modelOrder->setHorizontalHeaderLabels(QStringList() << "菜名" << "价格" << "份数" << "备注");
    ui->Order->setModel(modelOrder);
    ui->Order->horizontalHeader()->setStyleSheet(
      "QHeaderView::section{"
      "border-top:0px solid #E5E5E5;"
      "border-left:0px solid #E5E5E5;"
      "border-right:0.5px solid #E5E5E5;"
      "border-bottom: 0.5px solid #E5E5E5;"
      "background-color:white;"
      "padding:4px;"
      "}"
    ); // 给列表添加样式表

}

void MainWindow::DataBaseInit()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setDatabaseName("myqt_project");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
}

/*
    对于添加的菜品 应该给每一桌都新建一张表 这样就方便查询和删除

*/

void MainWindow::on_ShowCommentBtn_2_clicked()
{
    DataBaseInit(); // 打开数据库
    QString MenuId = ui->MenuId->text();
    QString quantity = ui->MenuNum->text(); // 获取两种信息
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    QString qstr = QString("select dishName, price, cuisine from menu where id = %1").arg(MenuId);
    query.exec(qstr);
    query.first();
    QString dishName = query.value("dishName").toString(),
            price = query.value("price").toString(),
            cuisine = query.value("cuisine").toString();
    // 查询对应的数据


    qstr = QString("insert into orders (TableNumber, DishName, Price, Quantity, MenuId) "
                   "values(%1, '%2', %3, %4, %5)")
                    .arg(tableId).arg(dishName).arg(price).arg(quantity).arg(MenuId);
    query.exec(qstr);
    // 向数据库中插入数据

    qstr = QString("select DishName, Price, Quantity from orders where TableNumber = %1").arg(tableId);
    query.exec(qstr);
    int row = 0;
    double SumPrice = 0;
    while(query.next()) {
        QString DishName = query.value("DishName").toString(),
                Price = query.value("Price").toString(),
                Quantity = query.value("Quantity").toString();
        SumPrice += Price.toDouble() * Quantity.toDouble();
        modelOrder->setItem(row, 0, new QStandardItem(DishName));
        modelOrder->setItem(row, 1, new QStandardItem(Price));
        modelOrder->setItem(row, 2, new QStandardItem(Quantity));
        modelOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        row ++;
        qDebug() << DishName << Price << Quantity;
    }
    QString SumPriceString = QString::number(SumPrice) + "元";
    ui->Sum->setText(SumPriceString);
    db.close();
}

void MainWindow::on_ShowCommentBtn_3_clicked()
{
    DataBaseInit();
    ui->MenuNum->clear();
    QString MenuId = ui->MenuId->text();
    QSqlQuery query(db);
    QString qstr = QString("select sum(Price * Quantity) from orders where MenuId = %1").arg(MenuId);
    query.exec(qstr);
    query.first();
    QString SumPrice = query.value(0).toString();
    QString prePrice = ui->Sum->text();
    prePrice.chop(1);
    qDebug() << prePrice;
    QString SumPriceString = QString::number(prePrice.toDouble() - SumPrice.toDouble()) + "元";
    ui->Sum->setText(SumPriceString);
    qstr = QString("delete from orders where Table_name = %1").arg(MenuId);
    query.exec(qstr);
    db.close();
}

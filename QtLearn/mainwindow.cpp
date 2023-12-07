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
    DataBaseInit();
    QString MenuId = ui->MenuId->text();
    QString quantity = ui->MenuNum->text();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    QString qstr = QString("select dishName, price, cuisine from menu where id = %1").arg(MenuId);
    query.exec(qstr);
    query.first();
    QString dishName = query.value("dishName").toString(),
            price = query.value("price").toString(),
            cuisine = query.value("cuisine").toString();



    qstr = QString("insert into orders (TableNumber, DishName, Price, Quantity) "
                   "values(%1, '%2', %3, %4)")
                    .arg(tableId).arg(dishName).arg(price).arg(quantity);
    query.exec(qstr);

    qstr = QString("select DishName, Price, Quantity from orders where TableNumber = %1").arg(tableId);
    bool flag = query.exec(qstr);
    qDebug() << qstr << flag << query.lastError();

    int row = 0;
    while(query.next()) {
        QString DishName = query.value("DishName").toString(),
                Price = query.value("Price").toString(),
                Quantity = query.value("Quantity").toString();
        modelOrder->setItem(row, 0, new QStandardItem(DishName));
        modelOrder->setItem(row, 1, new QStandardItem(Price));
        modelOrder->setItem(row, 2, new QStandardItem(Quantity));
        modelOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        row ++;
        qDebug() << DishName << Price << Quantity;
    }
    db.close();
}

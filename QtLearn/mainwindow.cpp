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
    ui->mainview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    model->setHorizontalHeaderLabels(QStringList() << "菜名" << "价格"   << "点餐（份数）" << "虎扑评分"  <<  "点餐确认"<< "查看评价");
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
            model->setItem(row, 1, new QStandardItem(price));
            model->setItem(row, 2, new QStandardItem(""));
            model->item(row, 0)->setTextAlignment(Qt::AlignCenter);
            model->item(row, 1)->setTextAlignment(Qt::AlignCenter);
            model->item(row, 2)->setTextAlignment(Qt::AlignCenter);


            // 下面的代码是给TableView设置checkbox选择框
            QWidget* widget5 = new QWidget();
            QCheckBox* checkBox5 = new QCheckBox();
            QHBoxLayout* hLayout5 = new QHBoxLayout();
            hLayout5->addWidget(checkBox5);
            hLayout5->setMargin(0);
            hLayout5->setAlignment(checkBox5, Qt::AlignCenter);
            widget5->setLayout(hLayout5);
            ui->mainview->setIndexWidget(ui->mainview->model()->index(row, 5), widget5);
            // 给第4列也装上checkbox
            QWidget* widget4 = new QWidget();
            QCheckBox* checkBox4 = new QCheckBox("√");
            QHBoxLayout* hLayout4 = new QHBoxLayout();
            hLayout4->addWidget(checkBox4);
            hLayout4->setMargin(0);
            hLayout4->setAlignment(checkBox4, Qt::AlignCenter);
            widget4->setLayout(hLayout4);
            ui->mainview->setIndexWidget(ui->mainview->model()->index(row, 4), widget4);
//            connect(checkBox4, &); // 发送者 信号 接收者 处理的槽函数
            row ++;
            qDebug() << dishName << cuisine << price;
        }
    }else {
        qDebug() << "database menu connect error";
    }
    // 添加元素
}

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
#include <paybill.h>
#include <QMessageBox>

MainWindow::MainWindow(std::string& username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->name = username;
    getVipLevel();
    showMenu();
    init();
    tableId = 2;
    showRecentOrder();
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
    modelComment = new QStandardItemModel();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    // 建立数据库连接并设置中文不乱码
    int row = 0;
    if(query.exec("select id, dishName, price, cuisine, rating from menu order by rating desc")){ // 降序
        while(query.next()){
            QString id = query.value("id").toString(),
                    dishName = query.value("dishName").toString(),
                    price = query.value("price").toString(),
                    cuisine = query.value("cuisine").toString(),
                    rating = query.value("rating").toString();
            modelMenu->setItem(row, 0, new QStandardItem(id));
            modelMenu->setItem(row, 1, new QStandardItem(dishName));
            modelMenu->setItem(row, 2, new QStandardItem(price));
            modelMenu->setItem(row, 3, new QStandardItem(cuisine));
            modelMenu->setItem(row, 4, new QStandardItem(rating));
            modelMenu->item(row, 0)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 1)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 2)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 3)->setTextAlignment(Qt::AlignCenter);
            modelMenu->item(row, 4)->setTextAlignment(Qt::AlignCenter);
            row ++;
        }
    }else {
        qDebug() << "database menu connect error";
    }
    for(int i = 0; i < 5; ++ i)
        modelMenu->item(i, 1)->setForeground(QBrush(QColor(255, 99, 71)));
    db.close();
}

void MainWindow::init()
{  
    ui->menu->setCurrentIndex(0);
    modelMenu->setHorizontalHeaderLabels(QStringList() << "序号"<< "菜名" << "价格" << "菜系" << "评分");
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


// 在vipLevel中添加等级 并更新
void MainWindow::getVipLevel()
{
    updateVipLevel();
    DataBaseInit();
    QString qname = QString::fromStdString(this->name);
    QString qstr = QString("select vip_level from users where username = '%1'").arg(qname);
    QSqlQuery query(db);
    query.exec(qstr);
    query.first();
    QString vipLevel = query.value("vip_level").toString();
    ui->vipLevel->setText(QString("vip ") + vipLevel);
    db.close();
}

void MainWindow::updateVipLevel()
{
    DataBaseInit();
    QSqlQuery query(db);
    QString qstr = QString("update users set vip_level = "
                           "case "
                           "when costmoney <= 1000 then 1 "
                           "when costmoney <= 5000 then 2 "
                           "when costmoney <= 10000 then 3 "
                           "else 4 "
                           "end "
                           "WHERE role != 'admin';");
    qDebug() << qstr;
    bool flag = query.exec(qstr);
    qDebug() << "更新vip等级 " << flag;
    db.close();
}


/*
 * 点餐记忆 找到最近一次该用户的order
 * 有两种情况：
 * 1. status为0的话 就说明该用户还有订单没有支付 就把这次的订单全部展示出来
 * 2. status为1的话 就说明该用户是再次消费 因此可以提供点餐记忆 快速生成上次的订单
*/
void MainWindow::showRecentOrder(){
    DataBaseInit();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    QString qstr = "select PaymentStatus from orders order by OrderTime desc";
    bool flag = query.exec(qstr);
    query.first();
    QString PaymentStatus = query.value("PaymentStatus").toString();
        qDebug() << "点餐记忆获取paymentstatus " << flag << PaymentStatus;
    if(! QString::compare(PaymentStatus, "0")) {
        // 如果没有付款 此时付款状态为0 表示未付款
        qstr = QString("select DishName, Price, Quantity, CustomerNote from orders where customername = '%1' and PaymentStatus = 0").arg(QString::fromStdString(this->name));
        bool flag = query.exec(qstr);
        qDebug() << "点餐记忆未付款 " << flag << qstr;
        int row = 0;
        double SumPrice = 0;
        while(query.next()) {
            QString DishName = query.value("DishName").toString(),
                    Price = query.value("Price").toString(),
                    Quantity = query.value("Quantity").toString(),
                    CustomerNote = query.value("CustomerNote").toString();
            SumPrice += Price.toDouble() * Quantity.toDouble();
            modelOrder->setItem(row, 0, new QStandardItem(DishName));
            modelOrder->setItem(row, 1, new QStandardItem(Price));
            modelOrder->setItem(row, 2, new QStandardItem(Quantity));
            modelOrder->setItem(row, 3, new QStandardItem(CustomerNote));
            modelOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
            modelOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
            modelOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
            modelOrder->item(row, 3)->setTextAlignment(Qt::AlignCenter);
            row ++;
        }
        QString SumPriceString = QString::number(SumPrice) + "元";
        ui->Sum->setText(SumPriceString);
    }else {
        // 此时付款状态为1 表示已付款
        QMessageBox::StandardButton reply = QMessageBox::question(
                    nullptr, "上次点单", "系统检测到您上次点了本店的招牌菜, 本次是否还需要尝尝?",
                    QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            qDebug() << "点餐记忆 yes";
            // 获取最近一次点单
            qstr = QString("select TableNumber, DishName, Price, Quantity, CustomerNote from orders where customername = '%1' and PaymentStatus = 0").arg(QString::fromStdString(this->name));
            bool flag = query.exec(qstr);
            int row = 0;
            double SumPrice = 0;
            QString lastTableNumber;
            qDebug() << "需要点餐记忆 " << flag << qstr;
            while(query.next()) {
                QString DishName = query.value("DishName").toString(),
                        Price = query.value("Price").toString(),
                        Quantity = query.value("Quantity").toString(),
                        CustomerNote = query.value("CustomerNote").toString(),
                        TableNumber = query.value("TableNumber").toString();
                if(lastTableNumber.isEmpty() || QString::compare(lastTableNumber, TableNumber) == 0) {
                    // 如果 lastTableNumber是空的 说明是第一次查 要更新 如果不是空的就说明lastTableNumber与TableNumber相等
                    lastTableNumber = TableNumber;
                }else break;
                SumPrice += Price.toDouble() * Quantity.toDouble();
                modelOrder->setItem(row, 0, new QStandardItem(DishName));
                modelOrder->setItem(row, 1, new QStandardItem(Price));
                modelOrder->setItem(row, 2, new QStandardItem(Quantity));
                modelOrder->setItem(row, 3, new QStandardItem(CustomerNote));
                modelOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
                modelOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
                modelOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
                modelOrder->item(row, 3)->setTextAlignment(Qt::AlignCenter);
                row ++;
                qDebug() << DishName << Price << Quantity;
            }
            QString SumPriceString = QString::number(SumPrice) + "元";
            ui->Sum->setText(SumPriceString);
            // 将付款状态改为0 以及时间戳改成最近的时间
            qstr = QString("update orders set PatmentStatus = 0, OrderTime = NOW() where TableNumber = %1").arg(lastTableNumber);
        }
    }
    db.close();
}


/*
    对于添加的菜品 应该给每一桌都新建一张表 这样就方便查询和删除
*/
void MainWindow::on_ShowCommentBtn_2_clicked()
{
    DataBaseInit(); // 打开数据库
    QString MenuId = ui->MenuId->text();
    QString quantity = ui->MenuNum->text(); // 获取两种信息
    QString CommentContent = ui->MenuPS->text();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    QString qstr = QString("select dishName, price from menu where id = %1").arg(MenuId);
    query.exec(qstr);
    query.first();
    QString dishName = query.value("dishName").toString(),
            price = query.value("price").toString();
    // 查询对应的数据


    qstr = QString("insert into orders (TableNumber, DishName, Price, Quantity, MenuId, CustomerNote, customername) "
                   "values(%1, '%2', %3, %4, %5, '%6', '%7')")
                    .arg(tableId).arg(dishName).arg(price).arg(quantity).arg(MenuId).arg(CommentContent).arg(QString::fromStdString(this->name));
    bool flag = query.exec(qstr);
    // 向数据库中插入数据
    qDebug() << "向数据库中插入数据 " << flag << qstr;

    qstr = QString("select DishName, Price, Quantity, CustomerNote from orders where customername = '%1' and PaymentStatus = 0").arg(QString::fromStdString(this->name));
    flag = query.exec(qstr);
    qDebug() << "插入后查询数据 " << flag << qstr;
    int row = 0;
    double SumPrice = 0;
    while(query.next()) {
        QString DishName = query.value("DishName").toString(),
                Price = query.value("Price").toString(),
                Quantity = query.value("Quantity").toString(),
                CustomerNote = query.value("CustomerNote").toString();
        SumPrice += Price.toDouble() * Quantity.toDouble();
        modelOrder->setItem(row, 0, new QStandardItem(DishName));
        modelOrder->setItem(row, 1, new QStandardItem(Price));
        modelOrder->setItem(row, 2, new QStandardItem(Quantity));
        modelOrder->setItem(row, 3, new QStandardItem(CustomerNote));
        modelOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        modelOrder->item(row, 3)->setTextAlignment(Qt::AlignCenter);
        row ++;
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


// 点餐评价
void MainWindow::on_ShowCommentBtn_clicked()
{
    modelComment->clear();
    modelComment->setHorizontalHeaderLabels(QStringList() << "评价人" << "评价" << "等级" << "评价时间");
    ui->Comment->setModel(modelComment);
    ui->Comment->setColumnWidth(1, 285);
    ui->Comment->setColumnWidth(3, 185);
    ui->Comment->horizontalHeader()->setStyleSheet(
      "QHeaderView::section{"
      "border-top:0px solid #E5E5E5;"
      "border-left:0px solid #E5E5E5;"
      "border-right:0.5px solid #E5E5E5;"
      "border-bottom: 0.5px solid #E5E5E5;"
      "background-color:white;"
      "padding:4px;"
      "}"
    ); // 给列表添加样式表
    DataBaseInit();
    QString Menuid = ui->CommentId->text();
    int option = ui->SortCombine->currentIndex();
    QSqlQuery query(db);
    QString qstr = QString(
                "select CommentName, CommentContent, Rating, CommentDate from MenuComments where MenuId = %1 "
                ).arg(Menuid);
    QString opRating = "order by Rating", opDate = "order by CommentDate";
    switch (option) {
    case 0:
        qstr += opRating + " asc";
        break;
    case 1:
        qstr += opRating + " desc";
        break;
    case 2:
        qstr += opDate + " asc";
        break;
    case 3:
        qstr += opDate + " desc";
        break;
    default:
        break;
    }

    qDebug() << QString("展示评论") << qstr << option << query.lastError() ;
    query.exec("set names 'GBK'");
    query.exec(qstr);
    int row = 0;
    while(query.next()) {
        QString CommentDate = query.value("CommentDate").toString(),
                CommentName = query.value("CommentName").toString(),
                CommentContent = query.value("CommentContent").toString(),
                Rating = query.value("Rating").toString();
        modelComment->setItem(row, 3, new QStandardItem(CommentDate));
        modelComment->setItem(row, 0, new QStandardItem(CommentName));
        modelComment->setItem(row, 1, new QStandardItem(CommentContent));
        modelComment->setItem(row, 2, new QStandardItem(Rating));
        modelComment->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelComment->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelComment->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        modelComment->item(row, 3)->setTextAlignment(Qt::AlignCenter);
        row ++;
    }
    db.close();
}


// 结账  vip1 1000元以内 95折 vip2 5000元以内 88折 vip3 10000元以内 8折 vip4 75折
void MainWindow::on_Pay_clicked(){
    int vipLevel = ui->vipLevel->text().toStdString().back() - '0';
    payBill* paybill = new payBill(this->name, vipLevel);
    paybill->show();
    this->close();
}

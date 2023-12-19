#include "paybill.h"
#include "ui_paybill.h"
#include <QSqlQuery>
#include <QStandardItem>
#include <QMessageBox>
#include <QDebug>
#include <comment.h>

payBill::payBill(std::__cxx11::string username, int viplevel, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payBill),
    username(username),
    viplevel(viplevel)
{
    ui->setupUi(this);
    modelShowOrder = new QStandardItemModel();
    this->sumPrice = 0;
    this->finalPrice = 0;
    showorder();
}

payBill::~payBill()
{
    delete ui;
}

void payBill::showorder()
{
    DataBaseInit();
    modelShowOrder->setHorizontalHeaderLabels(QStringList() << "菜名" << "价格" << "份数" << "备注");
    ui->Order->setModel(modelShowOrder);
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

    QSqlQuery query(db);
    query.exec("set names 'GBK'");
    int row = 0;
    QString qstr = QString("select DishName, Price, Quantity, CustomerNote from orders where customername = '%1' and PaymentStatus = 0").arg(QString::fromStdString(this->username));
    query.exec(qstr);
    while(query.next()) {
        QString dishName = query.value("DishName").toString(),
                Quantity = query.value("Quantity").toString(),
                Price = query.value("Price").toString(),
                CustomerNote = query.value("CustomerNote").toString();
        modelShowOrder->setItem(row, 0, new QStandardItem(dishName));
        modelShowOrder->setItem(row, 1, new QStandardItem(Price));
        modelShowOrder->setItem(row, 2, new QStandardItem(Quantity));
        modelShowOrder->setItem(row, 3, new QStandardItem(CustomerNote));
        modelShowOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 3)->setTextAlignment(Qt::AlignCenter);
        row += 1;
        this->sumPrice += Price.toDouble() * Quantity.toInt();
//        qDebug() << Price.toDouble() << Quantity.toInt();
    }
    double discount;
    switch (viplevel) {
    case 1:
        discount = 0.95;
        break;
    case 2:
        discount = 0.88;
        break;
    case 3:
        discount = 0.8;
        break;
    default:
        discount = 0.75;
        break;
    }
    this->finalPrice = discount * this->sumPrice;
    qDebug() << this->finalPrice << discount << this->sumPrice;
    QString showMsg = QString("您好，您消费的菜单如上，请确认无误后付款。\n您本次消费金额为 %1元, 由于您是vip %2, 可以打%3折 , 实际消费金额为 %4元").arg(this->sumPrice)
            .arg(QString::number(this->viplevel)).arg(QString::number(discount)).arg(QString::number(this->finalPrice));
    ui->Check->setText(showMsg);
}

void payBill::DataBaseInit()
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

void payBill::on_pushButton_clicked()
{
    QString TimeStamp;
    QMessageBox::StandardButton reply = QMessageBox::question(
                nullptr, "付款", "确定付款？",
                QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QMessageBox::information(nullptr, "付款成功", "尊敬的顾客您已付款成功！");
        // 1 将顾客消费的金额更新
        DataBaseInit();
        QSqlQuery query(db);
        QString qstr = QString("update users set costmoney = costmoney + %1 where username = '%2'")
                .arg(this->finalPrice).arg(QString::fromStdString(username));
        query.exec("set names 'GBK'");
        bool flag = query.exec(qstr);
        qDebug() << "更新付款金额 " << flag;

        // 2 找到最近订单的时间戳
        qstr = QString("select OrderTime from orders where PaymentStatus = 1 and customername = '%1'").arg(QString::fromStdString(this->username));
        flag = query.exec(qstr);
        qDebug() << "查找时间戳 " << flag << qstr;
        query.first();
        TimeStamp = query.value("OrderTime").toString();

        // 3 将订单中的paymentstatus改成1 即true 已付款
        qstr = QString("update orders set PaymentStatus = 1 where customername = '%1'").arg(QString::fromStdString(this->username));
        flag = query.exec(qstr);
        qDebug() << "更新付款状态 " << flag;

        db.close();
    }else {
        QMessageBox::warning(nullptr, "未确定", "请联系服务员进一步确认！");
    }

    Comment* commentWindow = new Comment(this->username, TimeStamp);
    commentWindow->show();

    this->close();
}

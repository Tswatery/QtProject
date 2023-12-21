#include "comment.h"
#include "ui_comment.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

Comment::Comment(std::string& username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Comment)
{
    ui->setupUi(this);
    this->name = QString::fromStdString(username);
    modelShowOrder = new QStandardItemModel();
    showOrder();
}

Comment::~Comment()
{
    delete ui;
}

void Comment::DataBaseInit()
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

void Comment::showOrder()
{
    DataBaseInit();
    modelShowOrder->setHorizontalHeaderLabels(QStringList() << "编号" << "菜名" << "价格" << "份数" << "备注");
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
    QString qstr = QString("select DishName, Price, Quantity, CustomerNote, MenuId from orders where customername = '%1' and PaymentStatus = 0").arg(this->name);
    bool flag = query.exec(qstr);
    qDebug() << "评论 " << flag << qstr;
    while(query.next()) {
        QString dishName = query.value("DishName").toString(),
                Quantity = query.value("Quantity").toString(),
                Price = query.value("Price").toString(),
                CustomerNote = query.value("CustomerNote").toString(),
                MenuId = query.value("MenuId").toString();
        modelShowOrder->setItem(row, 0, new QStandardItem(MenuId));
        modelShowOrder->setItem(row, 1, new QStandardItem(dishName));
        modelShowOrder->setItem(row, 2, new QStandardItem(Price));
        modelShowOrder->setItem(row, 3, new QStandardItem(Quantity));
        modelShowOrder->setItem(row, 4, new QStandardItem(CustomerNote));
        modelShowOrder->item(row, 0)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 1)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 2)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 3)->setTextAlignment(Qt::AlignCenter);
        modelShowOrder->item(row, 4)->setTextAlignment(Qt::AlignCenter);
        row += 1;
    }
    // 将订单中的paymentstatus改成1 即true 已付款
    qstr = QString("update orders set PaymentStatus = 1 where customername = '%1'").arg(this->name);
    flag = query.exec(qstr);
    qDebug() << "更新付款状态 " << flag;

    db.close();
}


void Comment::on_pushButton_clicked()
{
    QString MenuId = ui->MenuId->text(),
            Score = ui->Score->text(),
            comment = ui->CommentMsg->toPlainText();
    DataBaseInit();
    QSqlQuery query(db);
    query.exec("set names 'GBK'");

    QString qstr = QString("select dishName from menu where id = %1 ").arg(MenuId);
    bool flag = query.exec(qstr);
    qDebug() << "评论 " << flag;
    query.first();
    QString DishName = query.value("dishName").toString();

    qstr = QString("insert into menucomments(CommentName, MenuId, DishName, CommentContent, Rating) values "
                           "('%1', %2, '%3', '%4', %5)").arg(this->name).arg(MenuId).arg(DishName).arg(comment).arg(Score);


    flag = query.exec(qstr);
    if(flag) {
        QMessageBox::information(nullptr, "评价成功", "感谢您的评价！");
    }else {
        QMessageBox::warning(nullptr, "评价失败", "请输入正确的菜品号！");
    }
    qDebug() << "评论插入 " << flag << qstr << query.lastError();
    db.close();
}

#include "comment.h"
#include "ui_comment.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Comment::Comment(std::string& username, QString& timestamp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Comment)
{
    ui->setupUi(this);
    this->name = QString::fromStdString(username);
    this->TimeStamp = timestamp;
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
    QString qstr = QString("select DishName, Price, Quantity, CustomerNote from orders where customername = '%1' and OrderTime = '%2'").arg(this->name).arg(this->TimeStamp);
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
    }
    db.close();
}


void Comment::on_pushButton_clicked()
{
    QString MenuId = ui->MenuId->text(),
            Score = ui->Score->text(),
            comment = ui->CommentMsg->toPlainText();
    DataBaseInit();
    QSqlQuery query(db);

    QString qstr = QString("select dishName from menu where id = %1 ").arg(MenuId);
    bool flag = query.exec(qstr);
    qDebug() << "评论 " << flag;
    query.first();
    QString DishName = query.value("dishName").toString();

    qstr = QString("insert into menucomments(CommentName, MenuId, DishName, CommentContent, Rating) values "
                           "'%1', %2, '%3', '%4', %5").arg(this->name).arg(MenuId).arg(DishName).arg(comment).arg(Score);


    flag = query.exec(qstr);
    qDebug() << "评论插入 " << flag << qstr << query.lastError();
    db.close();
}

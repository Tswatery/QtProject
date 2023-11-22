#include "dbconnect.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <string>
#include <QString>
#include <QDebug>
#include <QSqlQuery>

bool DbConnect::connect(){
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName(QString::fromStdString(this->username));
    db.setDatabaseName(QString::fromStdString(this->dataBaseName));
    db.setPassword(QString::fromStdString(this->password));

    return (db.open() ? true : false);
}

bool DbConnect::query(std::string usr, std::string pwd){
    QString sql = "select username, password from users";
    QSqlQuery query;
    bool flag = query.exec(sql);
    while(query.next()){
        QString qusr = query.value("username").toString(), qpwd = query.value("password").toString();
        qDebug() << qusr << qpwd;
        if(qusr.toStdString() == usr
                && qpwd.toStdString() == pwd) return true;
    }
    return false;
}

void DbConnect::query1(std::string cuiSine){
    QSqlQuery query;


    // 设置mySQL输出不乱码
    query.exec("set names 'GBK'");


    QString sql = "select dishName, description, price, cuisine from menu";
    bool flag = query.exec(sql);

    (flag ? qDebug() << "成功执行" : qDebug() << "执行失败");
    while(query.next()) {
        QString dishName = query.value("dishName").toString(),
                desc = query.value("description").toString(),
                price = query.value("price").toString();
        std::string cuisine = query.value("cuisine").toString().toStdString();
        if(cuisine == cuiSine)
            qDebug() << dishName << desc << price;
    }
}

void DbConnect::close(){
    db.close();
}

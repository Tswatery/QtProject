#include "dbconnect.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <string>
#include<QString>
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
        qDebug() << query.value("username").toString()
                 << query.value("password").toString();

    }

}

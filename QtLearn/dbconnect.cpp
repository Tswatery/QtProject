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
    query.exec(sql);
    while(query.next()){
        QString qusr = query.value("username").toString(), qpwd = query.value("password").toString();
        qDebug() << qusr << qpwd;
        if(qusr.toStdString() == usr
                && qpwd.toStdString() == pwd) return true;
    }
    return false;
}
void DbConnect::close(){
    db.close();
}

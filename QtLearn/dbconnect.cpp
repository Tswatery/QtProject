#include "dbconnect.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <string>

void DbConnect::connect(){
    QStringList list = QSqlDatabase::drivers();
    qDebug() << list;

    this->getQsql().setHostName("127.0.0.1");
    this->getQsql().setPort(3306);
    this->getQsql().setUserName(this->getUserName());
    this->getQsql().setPassword(this->getPassWord());
    this->getQsql().setDatabaseName(this->getDataBaseName());

}

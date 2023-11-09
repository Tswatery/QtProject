#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <string>
#include <QSqlDatabase>

class DbConnect
{
private:
    std::string dataBaseName; // 表示要连接mysql中的哪一个数据库
    std::string username;
    std::string password;
    QSqlDatabase db;

public:
    DbConnect(const std::string& username,
              const std::string& dataBaseName,
              const std::string& password):
        dataBaseName(dataBaseName),
        username(username),
        password(password),
        db(QSqlDatabase::addDatabase("QMYSQL")) {} // 构造函数 避免写get和set函数


    bool connect(); // 连接数据库

    bool query(std::string usr, std::string pwd); // 输入用户名和密码 判断是否能登录

};

#endif // DBCONNECT_H

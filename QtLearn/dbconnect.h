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
    DbConnect();

    void setDataBaseName(std::string name) {
        this->dataBaseName = name;
    }

    void setUserName(std::string username) {
        this->username = username;
    }

    void setPassWord(std::string password) {
        this->password = password;
    }

    void setQsql() {
        this->db = QSqlDatabase::addDatabase("QMYSQL");
    }

    void connect();

    std::string getDataBaseName(){
        return this->dataBaseName;
    }

    std::string getUserName(){
        return this->username;
    }

    std::string getPassWord() {
        return this->password;
    }

    QSqlDatabase getQsql(){
        return this->db;
    }
};

#endif // DBCONNECT_H

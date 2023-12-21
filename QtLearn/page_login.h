#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include "dbconnect.h"
#include "mainwindow.h"
#include <QSqlDatabase>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = 0);
    ~Page_Login();
    void DataBaseInit();

signals:
    void loginSuccess();  // 登陆成功信号

private slots:
    void attemptLogin();  // 尝试登录槽函数

    void on_btn_signup_clicked();

private:
    Ui::Page_Login *ui;
    QSqlDatabase db;
};

#endif // PAGE_LOGIN_H

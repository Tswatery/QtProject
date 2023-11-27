#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include "dbconnect.h"
#include "mainwindow.h"

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = 0);
    ~Page_Login();

signals:
    void loginSuccess();  // 登陆成功信号

private slots:
    void attemptLogin();  // 尝试登录槽函数
    void on_btn_exit_clicked();

private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H

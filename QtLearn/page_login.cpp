#include "page_login.h"
#include "ui_page_login.h"
#include "dbconnect.h"
#include <QDebug>
#include <QSqlDatabase>

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);

}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked()
{
    //从line中获取用户名与密码

    // 数据库查找用户名与密码
    DbConnect* db = new DbConnect("root", "myqt_project", "123456");
    bool flag = db->connect();
    (flag) ? qDebug() << "连接成功" : qDebug() << "连接失败";
    bool flag = db->query();

    // 失败提示

    // 成功则进入主界面
    emit sendLoginSuccess();
}

void Page_Login::on_btn_exit_clicked()
{
    // 退出
    exit(0);
}

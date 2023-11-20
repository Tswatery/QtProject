#include "page_login.h"
#include "ui_page_login.h"
#include "dbconnect.h"
#include <QDebug>
#include <QSqlDatabase>
#include "mainwindow.h"
#include <QObject>
#include <QWidget>

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    mainWindowPtr = new MainWindow();
    ui->setupUi(this);
    connect(ui->btn_login, &Page_Login::sendLoginSuccess, mainWindowPtr, &MainWindow::acceptSignal);
}

Page_Login::~Page_Login()
{
    delete ui;
    delete mainWindowPtr;
}

void Page_Login::on_btn_login_clicked()
{
    //从line中获取用户名与密码
    QString pwd = ui->pwd->text();
    QString usr = ui->usr->text();
    // 数据库查找用户名与密码
    DbConnect* db = new DbConnect("root", "myqt_project", "123456");
    (db->connect()) ? qDebug() << "连接成功" : qDebug() << "连接失败"; // 打印日志是否正确连接
    std::string stdpwd = pwd.toStdString(), stdusr = usr.toStdString();
    if(db->query(stdusr, stdpwd)) {
        // 进入主界面
        qDebug() << "密码和用户名正确进入主界面";
        emit
    }else {
        qDebug() << "错误不能进入主界面";
    }

    db->close();
    delete db;
}

void Page_Login::on_btn_exit_clicked()
{
    // 退出
    qDebug() << "点击了提出按钮";
    exit(0);
}

#include "page_login.h"
#include "ui_page_login.h"
#include "dbconnect.h"
#include <QDebug>
#include <QSqlDatabase>
#include "mainwindow.h"
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);
    connect(ui->btn_login, &QPushButton::clicked, this, &Page_Login::attemptLogin);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::DataBaseInit()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setDatabaseName("myqt_project");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
}

void Page_Login::attemptLogin(){
    //从line中获取用户名与密码
    QString pwd = ui->pwd->text();
    QString usr = ui->usr->text();
    // 数据库查找用户名与密码
    DbConnect* db = new DbConnect("root", "myqt_project", "123456");
    (db->connect()) ? qDebug() << "连接成功" : qDebug() << "连接失败"; // 打印日志是否正确连接
    std::string stdpwd = pwd.toStdString(), stdusr = usr.toStdString(); // 从QString转变为std::string
    if(db->query(stdusr, stdpwd)) {
        // 登陆成功进入主界面
        qDebug() << "Login success";
        MainWindow* mainWindowPtr = new MainWindow(stdusr);
        mainWindowPtr->show();
        this->close();
    }else {
        // 登录失败
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
    }
    db->close();
    delete db; // 防止内存泄漏
}
void Page_Login::on_btn_signup_clicked()
{
    QString pwd = ui->pwd->text();
    QString usr = ui->usr->text();
    DataBaseInit();
    QSqlQuery query(db);
    QString qstr = QString("insert into users(username, password, role) values ('%1', '%2', 'customer')").arg(usr).arg(pwd);
    bool flag = query.exec(qstr);
    qDebug() << "注册 " << flag << qstr;
    if(flag ){
        QMessageBox::information(nullptr, "注册成功", "您已注册成功！");
    }
    db.close();
}

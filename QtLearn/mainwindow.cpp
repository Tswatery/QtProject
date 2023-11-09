#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnect.h"
#include <string>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dlgLogin.show();
//    auto f = [&] {
//        return this->show();
//    };
//    connect(&m_dlgLogin, &Page_Login::sendLoginSuccess, this, f);

//    ui->treeWidget->setColumnCount(1);

//    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget, QStringList("学生管理系统"));
//    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf, QStringList("学生管理"));
//    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf, QStringList("管理员管理"));
//    ui->treeWidget->addTopLevelItem(pf);
//    pf->addChild(p1);
//    pf->addChild(p2);

    DbConnect* db = new DbConnect("root", "myqt_project", "123456");
//    if(db->connect())
//        QMessageBox::information(this, "conn", "successful");
//    else
//        QMessageBox::information(this, "conn", "error");
//    db->query();

}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnect.h"
#include <QSqlQueryModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->MultiSelect,
            QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this,
            &MainWindow::handleCuisineSelected
            );
    QSqlQueryModel *menuModel = new QSqlQueryModel(this);
    ui->tableView->setModel(menuModel);
}

void MainWindow::handleCuisineSelected(const QString &cuisine) {
    DbConnect* db = new DbConnect("root", "myqt_project", "123456");
    std::string stdCuisine = cuisine.toStdString();
    (db->connect()) ? qDebug() << "连接成功" : qDebug() << "连接失败"; // 打印日志是否正确连接
    db->query1(stdCuisine); // 将对应cuisine的菜单输出
}

MainWindow::~MainWindow()
{
    delete ui;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showMenu();
    void init(); // 初始化界面

    void DataBaseInit();

private slots:
    void on_ShowCommentBtn_2_clicked();

    void on_ShowCommentBtn_3_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* modelOrder, *modelMenu, *modelDrink;
    int tableId;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H

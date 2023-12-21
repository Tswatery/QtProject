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
    explicit MainWindow(std::string& username, QWidget *parent = 0);
    ~MainWindow();

    void showMenu();
    void init(); // 初始化界面
    void DataBaseInit();
    void getVipLevel();
    void updateVipLevel();
    void showRecentOrder();
    void updateMenu();
    void getTableId();

private slots:
    void on_ShowCommentBtn_2_clicked();

    void on_ShowCommentBtn_3_clicked();

    void on_ShowCommentBtn_clicked();

    void on_Pay_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* modelOrder, *modelMenu, *modelDrink, *modelComment;
    int tableId;
    QSqlDatabase db;
    std::string name;
};

#endif // MAINWINDOW_H

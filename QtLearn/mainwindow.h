#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStandardItemModel>

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

private slots:
    void on_ShowCommentBtn_2_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* modelOrder, *modelMenu, *modelDrink;
};

#endif // MAINWINDOW_H

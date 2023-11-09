#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page_login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
};

#endif // MAINWINDOW_H

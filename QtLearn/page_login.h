#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include "dbconnect.h"

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = 0);
    ~Page_Login();

private slots:
    void on_btn_login_clicked();
    void on_btn_exit_clicked();

signals:
    void sendLoginSuccess();

private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H

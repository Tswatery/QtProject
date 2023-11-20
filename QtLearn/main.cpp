#include "mainwindow.h"
#include "page_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Page_Login* pageLoginPtr = new Page_Login();
    pageLoginPtr->show();
    return a.exec();
}

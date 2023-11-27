/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *Title;
    QTableView *AlreadyTable;
    QLabel *label;
    QPushButton *pushButton;
    QTabWidget *menu;
    QWidget *qmain;
    QTableView *mainview;
    QWidget *qdrink;
    QTableView *tableView;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(980, 525);
        Title = new QLabel(MainWindow);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(130, 60, 161, 51));
        Title->setStyleSheet(QString::fromUtf8("\n"
"font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        Title->setAlignment(Qt::AlignCenter);
        AlreadyTable = new QTableView(MainWindow);
        AlreadyTable->setObjectName(QStringLiteral("AlreadyTable"));
        AlreadyTable->setGeometry(QRect(600, 140, 361, 301));
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 100, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 390, 75, 23));
        menu = new QTabWidget(MainWindow);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(40, 120, 411, 351));
        qmain = new QWidget();
        qmain->setObjectName(QStringLiteral("qmain"));
        mainview = new QTableView(qmain);
        mainview->setObjectName(QStringLiteral("mainview"));
        mainview->setGeometry(QRect(10, 10, 391, 311));
        menu->addTab(qmain, QString());
        qdrink = new QWidget();
        qdrink->setObjectName(QStringLiteral("qdrink"));
        tableView = new QTableView(qdrink);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(5, 11, 391, 311));
        tableView->setStyleSheet(QStringLiteral(""));
        menu->addTab(qdrink, QString());

        retranslateUi(MainWindow);

        menu->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", Q_NULLPTR));
        Title->setText(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\347\202\271\351\244\220\345\223\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        menu->setTabText(menu->indexOf(qmain), QApplication::translate("MainWindow", "\344\270\273\351\244\220", Q_NULLPTR));
        menu->setTabText(menu->indexOf(qdrink), QApplication::translate("MainWindow", "\351\245\256\345\223\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QLineEdit>
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
    QTabWidget *menu;
    QWidget *qmain;
    QTableView *mainview;
    QWidget *qdrink;
    QTableView *tableView;
    QTableView *AlreadyTable_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(980, 525);
        Title = new QLabel(MainWindow);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(220, 10, 161, 51));
        Title->setStyleSheet(QString::fromUtf8("\n"
"font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        Title->setAlignment(Qt::AlignCenter);
        AlreadyTable = new QTableView(MainWindow);
        AlreadyTable->setObjectName(QStringLiteral("AlreadyTable"));
        AlreadyTable->setGeometry(QRect(600, 60, 361, 151));
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 20, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label->setAlignment(Qt::AlignCenter);
        menu = new QTabWidget(MainWindow);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(10, 40, 561, 481));
        qmain = new QWidget();
        qmain->setObjectName(QStringLiteral("qmain"));
        mainview = new QTableView(qmain);
        mainview->setObjectName(QStringLiteral("mainview"));
        mainview->setGeometry(QRect(10, 10, 531, 431));
        menu->addTab(qmain, QString());
        qdrink = new QWidget();
        qdrink->setObjectName(QStringLiteral("qdrink"));
        tableView = new QTableView(qdrink);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(5, 11, 541, 431));
        tableView->setStyleSheet(QStringLiteral(""));
        menu->addTab(qdrink, QString());
        AlreadyTable_2 = new QTableView(MainWindow);
        AlreadyTable_2->setObjectName(QStringLiteral("AlreadyTable_2"));
        AlreadyTable_2->setGeometry(QRect(600, 280, 361, 231));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 240, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(790, 220, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(MainWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(860, 220, 101, 20));

        retranslateUi(MainWindow);

        menu->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", Q_NULLPTR));
        Title->setText(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\347\202\271\351\244\220\345\223\201", Q_NULLPTR));
        menu->setTabText(menu->indexOf(qmain), QApplication::translate("MainWindow", "\344\270\273\351\244\220", Q_NULLPTR));
        menu->setTabText(menu->indexOf(qdrink), QApplication::translate("MainWindow", "\351\245\256\345\223\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\217\234\345\223\201\350\257\204\344\273\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\200\273\344\273\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

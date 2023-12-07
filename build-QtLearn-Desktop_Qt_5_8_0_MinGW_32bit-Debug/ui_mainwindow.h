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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *Title;
    QTableView *Order;
    QLabel *label;
    QTabWidget *menu;
    QWidget *qmain;
    QTableView *mainview;
    QWidget *qdrink;
    QTableView *tableView;
    QTableView *Comment;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *Sum;
    QPushButton *ShowCommentBtn;
    QLineEdit *CommentId;
    QLabel *label_4;
    QPushButton *ShowCommentBtn_2;
    QLineEdit *MenuId;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *MenuNum;
    QPushButton *ShowCommentBtn_3;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1136, 679);
        Title = new QLabel(MainWindow);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(220, 10, 161, 51));
        Title->setStyleSheet(QString::fromUtf8("\n"
"font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        Title->setAlignment(Qt::AlignCenter);
        Order = new QTableView(MainWindow);
        Order->setObjectName(QStringLiteral("Order"));
        Order->setGeometry(QRect(750, 70, 361, 521));
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(880, 20, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label->setAlignment(Qt::AlignCenter);
        menu = new QTabWidget(MainWindow);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(10, 40, 481, 281));
        qmain = new QWidget();
        qmain->setObjectName(QStringLiteral("qmain"));
        mainview = new QTableView(qmain);
        mainview->setObjectName(QStringLiteral("mainview"));
        mainview->setGeometry(QRect(10, 0, 461, 251));
        menu->addTab(qmain, QString());
        mainview->raise();
        qdrink = new QWidget();
        qdrink->setObjectName(QStringLiteral("qdrink"));
        tableView = new QTableView(qdrink);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(5, 11, 541, 431));
        tableView->setStyleSheet(QStringLiteral(""));
        menu->addTab(qdrink, QString());
        Comment = new QTableView(MainWindow);
        Comment->setObjectName(QStringLiteral("Comment"));
        Comment->setGeometry(QRect(30, 360, 691, 231));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 320, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(910, 600, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_3->setAlignment(Qt::AlignCenter);
        Sum = new QLineEdit(MainWindow);
        Sum->setObjectName(QStringLiteral("Sum"));
        Sum->setGeometry(QRect(1010, 600, 101, 20));
        ShowCommentBtn = new QPushButton(MainWindow);
        ShowCommentBtn->setObjectName(QStringLiteral("ShowCommentBtn"));
        ShowCommentBtn->setGeometry(QRect(280, 620, 75, 23));
        CommentId = new QLineEdit(MainWindow);
        CommentId->setObjectName(QStringLiteral("CommentId"));
        CommentId->setGeometry(QRect(110, 620, 101, 20));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 620, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_4->setAlignment(Qt::AlignCenter);
        ShowCommentBtn_2 = new QPushButton(MainWindow);
        ShowCommentBtn_2->setObjectName(QStringLiteral("ShowCommentBtn_2"));
        ShowCommentBtn_2->setGeometry(QRect(540, 280, 75, 23));
        MenuId = new QLineEdit(MainWindow);
        MenuId->setObjectName(QStringLiteral("MenuId"));
        MenuId->setGeometry(QRect(620, 100, 71, 20));
        label_5 = new QLabel(MainWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 100, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(MainWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 150, 91, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_6->setAlignment(Qt::AlignCenter);
        MenuNum = new QLineEdit(MainWindow);
        MenuNum->setObjectName(QStringLiteral("MenuNum"));
        MenuNum->setGeometry(QRect(620, 150, 71, 20));
        ShowCommentBtn_3 = new QPushButton(MainWindow);
        ShowCommentBtn_3->setObjectName(QStringLiteral("ShowCommentBtn_3"));
        ShowCommentBtn_3->setGeometry(QRect(620, 280, 75, 23));

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
        ShowCommentBtn->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\204\344\273\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\350\217\234\345\223\201\345\272\217\345\217\267", Q_NULLPTR));
        ShowCommentBtn_2->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\350\217\234\345\223\201\345\272\217\345\217\267", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\344\273\275\346\225\260", Q_NULLPTR));
        ShowCommentBtn_3->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

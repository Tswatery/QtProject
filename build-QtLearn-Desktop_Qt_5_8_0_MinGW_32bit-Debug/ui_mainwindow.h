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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *btn_exit;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(996, 633);
        MainWindow->setMinimumSize(QSize(800, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("QWidget#centralWidget{background-color: #001871;};"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(260, 90, 661, 441));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(65, 182, 230);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox = new QCheckBox(page);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_3->addWidget(checkBox, 0, 0, 1, 1);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 0, 5, 1, 1);

        tableWidget = new QTableWidget(page);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 1, 0, 1, 5);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 30, 731, 81));
        widget->setStyleSheet(QStringLiteral("color: white;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(231, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        btn_exit = new QPushButton(widget_2);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setStyleSheet(QLatin1String("color: rgb(170, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));

        gridLayout->addWidget(btn_exit, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(40, 91, 201, 441));
        treeWidget->setStyleSheet(QStringLiteral("background-color: #41b6e6;"));
        treeWidget->header()->setVisible(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 996, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232admin", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

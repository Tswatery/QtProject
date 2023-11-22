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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *Title;
    QComboBox *MultiSelect;
    QTableView *tableView;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(648, 525);
        Title = new QLabel(MainWindow);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(210, 60, 161, 51));
        Title->setStyleSheet(QStringLiteral("font: 16pt \"Arial\";"));
        Title->setAlignment(Qt::AlignCenter);
        MultiSelect = new QComboBox(MainWindow);
        MultiSelect->setObjectName(QStringLiteral("MultiSelect"));
        MultiSelect->setGeometry(QRect(420, 150, 69, 22));
        tableView = new QTableView(MainWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 140, 361, 301));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", Q_NULLPTR));
        Title->setText(QApplication::translate("MainWindow", "\347\202\271\345\215\225\347\263\273\347\273\237", Q_NULLPTR));
        MultiSelect->clear();
        MultiSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\276\275\350\217\234", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\235\350\217\234", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

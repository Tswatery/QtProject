/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_Login
{
public:
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_exit;
    QPushButton *btn_login;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *usr;
    QLabel *label_2;
    QLineEdit *pwd_2;

    void setupUi(QWidget *Page_Login)
    {
        if (Page_Login->objectName().isEmpty())
            Page_Login->setObjectName(QStringLiteral("Page_Login"));
        Page_Login->resize(400, 240);
        Page_Login->setMinimumSize(QSize(400, 240));
        Page_Login->setMaximumSize(QSize(400, 240));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Page_Login->setWindowIcon(icon);
        label_3 = new QLabel(Page_Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 20, 51, 60));
        label_3->setMinimumSize(QSize(0, 60));
        widget = new QWidget(Page_Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 150, 321, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        gridLayout->addWidget(btn_exit, 1, 1, 1, 1);

        btn_login = new QPushButton(widget);
        btn_login->setObjectName(QStringLiteral("btn_login"));

        gridLayout->addWidget(btn_login, 1, 0, 1, 1);

        widget_2 = new QWidget(Page_Login);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(100, 80, 193, 64));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        usr = new QLineEdit(widget_2);
        usr->setObjectName(QStringLiteral("usr"));

        gridLayout_2->addWidget(usr, 0, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        pwd_2 = new QLineEdit(widget_2);
        pwd_2->setObjectName(QStringLiteral("pwd_2"));

        gridLayout_2->addWidget(pwd_2, 1, 1, 1, 1);


        retranslateUi(Page_Login);

        QMetaObject::connectSlotsByName(Page_Login);
    } // setupUi

    void retranslateUi(QWidget *Page_Login)
    {
        Page_Login->setWindowTitle(QApplication::translate("Page_Login", "\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Page_Login->setToolTip(QApplication::translate("Page_Login", "\350\277\231\346\230\257\347\231\273\345\275\225\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Page_Login", "\347\202\271\345\215\225\347\263\273\347\273\237", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("Page_Login", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_login->setText(QApplication::translate("Page_Login", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("Page_Login", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Page_Login", "\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page_Login: public Ui_Page_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H

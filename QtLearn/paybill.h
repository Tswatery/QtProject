#ifndef PAYBILL_H
#define PAYBILL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QStandardItemModel>

namespace Ui {
class payBill;
}

class payBill : public QWidget
{
    Q_OBJECT

public:
    explicit payBill(std::string username, int viplevel, QWidget *parent = 0);
    ~payBill();
    void showorder();
    void DataBaseInit();
    void showRecentBill();

private slots:
    void on_pushButton_clicked();

private:
    Ui::payBill *ui;
    std::string username;
    QSqlDatabase db;
    QStandardItemModel* modelShowOrder;
    int viplevel;
    double sumPrice, finalPrice;
};

#endif // PAYBILL_H

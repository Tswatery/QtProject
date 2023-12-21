#ifndef COMMENT_H
#define COMMENT_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlDatabase>

namespace Ui {
class Comment;
}

class Comment : public QWidget
{
    Q_OBJECT

public:
    explicit Comment(std::string& name, QWidget *parent = 0);
    ~Comment();
    void DataBaseInit();
    void showOrder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Comment *ui;
    QSqlDatabase db;
    QString name, TimeStamp;
    QStandardItemModel* modelShowOrder;
};

#endif // COMMENT_H

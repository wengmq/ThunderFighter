#ifndef RANKINGWIDGET_H
#define RANKINGWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>//用于表格显示
#include <QSqlRecord>


#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QIcon>
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include<QPainter>
#include<QVariant>
namespace Ui {
    class rankingWidget;
}

class rankingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rankingWidget(QWidget *parent = 0);
    ~rankingWidget();
    //QVariant data(const QModelIndex &index, int role) const;
    void ui_init();
    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置

public slots:
    void on_pushButton_before_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::rankingWidget *ui;
    QPushButton *closeBtn;
    QLabel * bgLabel;
    QLabel *titleLabel;
    QSqlTableModel *tablemModel;

    QSqlQueryModel *queryModel;


};

#endif // RANKINGWIDGET_H

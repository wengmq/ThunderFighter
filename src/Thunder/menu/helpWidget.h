#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>
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
class helpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit helpWidget(QWidget *parent = 0);
    void  mousePressEvent(QMouseEvent *event);

    void  mouseMoveEvent(QMouseEvent *event);

  //  void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void paintEvent( QPaintEvent* ) ;

signals:
   // void backMenuSignal();

public slots:
   // void backBtn_clicked();

private:
    QPushButton *backBtn;
    QLabel * bgLabel;
    QPushButton *closeBtn;
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;

};

#endif // HELPWIDGET_H

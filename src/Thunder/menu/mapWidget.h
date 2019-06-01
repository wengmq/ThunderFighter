#ifndef MAPWIDGET_H
#define MAPWIDGET_H

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

class mapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mapWidget(QWidget *parent = 0);
    void  mousePressEvent(QMouseEvent *event);

    void  mouseMoveEvent(QMouseEvent *event);

  //  void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void paintEvent( QPaintEvent* ) ;

signals:

public slots:
    void map1Btn_clicked();
    void map2Btn_clicked();
    void map3Btn_clicked();
    void map4Btn_clicked();
private:

    QPushButton *closeBtn;
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;

    QPushButton *map1Btn;
    QPushButton *map2Btn;
    QPushButton *map3Btn;
    QPushButton *map4Btn;



};

#endif // MAPWIDGET_H

#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include<QPainter>
#include <QMessageBox>
#include <QWidget>
#include <QResizeEvent>
#include <QMouseEvent>
 #include <QTextCodec>
#include<QIcon>
#include<QPushButton>
class myMessageBox : public QMessageBox
{
    Q_OBJECT
public:
     myMessageBox(QString bgPic,QWidget *parent = 0);
    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QString bgPic;
     void setbgPix(QString bgPic);
public:
    void AutoSetSize(int width,int high);

protected:
    void resizeEvent(QResizeEvent*event);

private:
    int m_width;
    int m_high;
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置



signals:

public slots:

};

#endif // MYMESSAGEBOX_H

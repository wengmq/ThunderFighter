#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QIcon>
#include <QMessageBox>
#include "loginWidget.h"
#include <QDebug>
#include "registerWidget.h"
#include <QSound>
#include"../other/myMusic.h"
class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);
    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置

signals:

public slots:
    void loginBtn_clicked();
    void registerBtn_clicked();
    void loginBack();
    void regiterBack();
     void musicPlay();
      void closeBtn_click();
private:
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QPushButton *closeBtn;
    loginWidget *loginInterface;
    registerWidget *registerInterface;

    QLabel *labelPic1;
    QLabel *labelPic2;
    QLabel *labelPic3;
    QLabel *labelPic4;
    QLabel *labelPic5;
    QMovie *movie1;
    QMovie *movie2;
    QMovie *movie3;
    QMovie *movie4;
    QMovie *movie5;
    //QSound *music;
};

#endif // MAINWIDGET_H

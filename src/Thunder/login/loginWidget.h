#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

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
#include "../dataBase/myDatabase.h"
#include "../menu/menuWidget.h"
#include "forgetPwdWidget.h"
#include <QRegExpValidator>
#include<QRegExp>
class loginWidget : public QWidget
{
    Q_OBJECT

public:
    loginWidget(QWidget *parent = 0);
    ~loginWidget();
    int findName();
    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置

    void closeEvent(QCloseEvent *CloseEvent);

signals:
    void ReturnLoginSignal();


private:
    QLineEdit *NameLine;
    QLineEdit *PwdLine;
    QPushButton *sureBtn;
    QPushButton *backBtn;
    QPushButton *forgetPwdBtn;
    QPushButton *touristLoginBtn;
    QPushButton *closeBtn;
    menuWidget *menuInterface;
    forgetPwdWidget *forgetPwdInterface;

public slots:
    void sureBtn_clicked();
    void backBtn_clicked();
    void backLogin_slot();
    void forgetPwdLabel_clicked();
    void closeBtn_click();
};

#endif // LOGINWIDGET_H

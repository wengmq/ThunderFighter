#ifndef MODIFYPWDWIDGET_H
#define MODIFYPWDWIDGET_H

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
#include <QComboBox>
#include <QDebug>
#include <QMouseEvent>
#include<QPainter>
#include "../dataBase/myDatabase.h"
#include <QString>
class modifyPwdWidget : public QWidget
{
    Q_OBJECT
public:
    explicit modifyPwdWidget(QWidget *parent = 0);

    QString userName;
    void setuserName(QString name);

    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置
signals:

public slots:
    void sureBtn_clicked();

private:

    QLabel *nameLabel;
    QLabel *pwdLabel1;
    QLabel *pwdLabel2;

    QLineEdit *pwdLineEdit1;
    QLineEdit *pwdLineEdit2;
    QPushButton *closeBtn;
    QPushButton *sureBtn;


};

#endif // MODIFYPWDWIDGET_H

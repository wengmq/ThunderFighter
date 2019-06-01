#ifndef FORGETPWDWIDGET_H
#define FORGETPWDWIDGET_H

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
#include <QComboBox>
#include <QSqlQuery>
#include "../dataBase/myDatabase.h"
#include "modifyPwdWidget.h"

#include <QMouseEvent>
#include<QPainter>

class forgetPwdWidget : public QWidget
{
    Q_OBJECT
public:
    explicit forgetPwdWidget(QWidget *parent = 0);
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

    QLabel *questionLabel;
    QLabel *answerLabel;

    QComboBox *questionBox;
    QLineEdit *answerLineEdit;
    QPushButton *closeBtn;
    QPushButton *sureBtn;
    modifyPwdWidget  *modifyPwdWInterface;

};

#endif // FORGETPWDWIDGET_H

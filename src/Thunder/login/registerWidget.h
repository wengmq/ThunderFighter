#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

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
#include <QMouseEvent>
#include<QPainter>
#include <QDebug>
#include "../dataBase/myDatabase.h"
#include <QRegExpValidator>
#include<QRegExp>
#include<QValidator>
class registerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit registerWidget(QWidget *parent = 0);
    int registerReturn();
    int findName();

    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置

signals:
    void BackLoginSignal();

public slots:
        void backBtn_clicked();
        void sureBtn_clicked();
        void closeBtn_click();
private:
    QLabel *registerLabel;
    QLabel *nameLabel;
    QLabel *pwdLabel1;
    QLabel *pwdLabel2;
    QLabel *questionLabel;
    QLabel *answerLabel;

    QLineEdit *nameLineEdit;
    QLineEdit *pwdLineEdit1;
    QLineEdit *pwdLineEdit2;
    QComboBox *questionBox;
    QLineEdit *answerLineEdit;


    QPushButton *sureBtn;
    QPushButton *backBtn;
    QPushButton *closeBtn;

};

#endif // REGISTERWIDGET_H

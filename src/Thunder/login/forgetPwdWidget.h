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

     void  mousePressEvent(QMouseEvent *event);//����������¼�
     void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
     void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
     QPoint windowPos;     // ��ò�����ǰλ��
     QPoint mousePos;     // ������λ��
     QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��


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

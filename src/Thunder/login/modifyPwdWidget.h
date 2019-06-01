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
    QLabel *pwdLabel1;
    QLabel *pwdLabel2;

    QLineEdit *pwdLineEdit1;
    QLineEdit *pwdLineEdit2;
    QPushButton *closeBtn;
    QPushButton *sureBtn;


};

#endif // MODIFYPWDWIDGET_H

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
    void  mousePressEvent(QMouseEvent *event);//����������¼�
    void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
    void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��

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

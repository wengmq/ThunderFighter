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
    void  mousePressEvent(QMouseEvent *event);//����������¼�
    void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
    void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
    QString bgPic;
     void setbgPix(QString bgPic);
public:
    void AutoSetSize(int width,int high);

protected:
    void resizeEvent(QResizeEvent*event);

private:
    int m_width;
    int m_high;
    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��



signals:

public slots:

};

#endif // MYMESSAGEBOX_H

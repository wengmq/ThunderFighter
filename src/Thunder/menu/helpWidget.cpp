#include "helpWidget.h"

helpWidget::helpWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(450,450);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

   // this->setAutoFillBackground(false);  //��������õĻ��ͱ������
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
    this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

    //���ñ���ͼƬ
//    bgLabel =new QLabel(this) ;
//     bgLabel->setGeometry(0,0,450,450);
//    bgLabel->setStyleSheet("QLabel{border-image:url(MyPlane/images/widget/03_1.png);}");

//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/03_1.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,25,35,35);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(35,35));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

}
//void helpWidget::backBtn_clicked()
//{
//    qDebug()<<"���ǰ�����";
//    emit backMenuSignal();
//}

void helpWidget::mousePressEvent(QMouseEvent *event)
{

     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void helpWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}

void helpWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,450,450,QPixmap("MyPlane/images/widget/help11.png"));

}

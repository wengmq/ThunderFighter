#include "mapWidget.h"
extern int mapChooseFlag;
mapWidget::mapWidget(QWidget *parent) :
    QWidget(parent)
{

    this->setFixedSize(481,579);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

   // this->setAutoFillBackground(false);  //��������õĻ��ͱ������
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
    this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

    int x0 =145;
    int y0 = 135;
    int distance = 50;
    int btn_width = 200;
    int btn_height = 50;

    map1Btn = new QPushButton(this);
    map1Btn->setGeometry(x0,y0+(distance+btn_height)*0,btn_width,btn_height);
    map1Btn->setIcon(QIcon("MyPlane/images/btn/map1.png"));
    map1Btn->setIconSize(QSize(btn_width,btn_height));
    map1Btn->setFocusPolicy(Qt::NoFocus);
    map1Btn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    map1Btn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    map2Btn = new QPushButton(this);
    map2Btn->setGeometry(x0,y0+(distance+btn_height)*1,btn_width,btn_height);
    map2Btn->setIcon(QIcon("MyPlane/images/btn/map2.png"));
    map2Btn->setIconSize(QSize(btn_width,btn_height));
    map2Btn->setFocusPolicy(Qt::NoFocus);
    map2Btn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    map2Btn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    map3Btn = new QPushButton(this);
    map3Btn->setGeometry(x0,y0+(distance+btn_height)*2,btn_width,btn_height);
    map3Btn->setIcon(QIcon("MyPlane/images/btn/map3.png"));
    map3Btn->setIconSize(QSize(btn_width,btn_height));
    map3Btn->setFocusPolicy(Qt::NoFocus);
    map3Btn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    map3Btn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    map4Btn = new QPushButton(this);
    map4Btn->setGeometry(x0,y0+(distance+btn_height)*3,btn_width,btn_height);
    map4Btn->setIcon(QIcon("MyPlane/images/btn/map4.png"));
    map4Btn->setIconSize(QSize(btn_width,btn_height));
    map4Btn->setFocusPolicy(Qt::NoFocus);
    map4Btn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    map4Btn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");




    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,100,35,35);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(35,35));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));


    this->connect(map1Btn,SIGNAL(clicked()),this,SLOT(map1Btn_clicked()));
    this->connect(map2Btn,SIGNAL(clicked()),this,SLOT(map2Btn_clicked()));
    this->connect(map3Btn,SIGNAL(clicked()),this,SLOT(map3Btn_clicked()));
    this->connect(map4Btn,SIGNAL(clicked()),this,SLOT(map4Btn_clicked()));
}

void mapWidget::mousePressEvent(QMouseEvent *event)
{

     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void mapWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}

void mapWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,481,579,QPixmap("MyPlane/images/widget/01.png"));

}

void mapWidget::map1Btn_clicked()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�Ҫѡ���ͼ1��",QMessageBox::Yes|QMessageBox::No))
    {
        mapChooseFlag = 1;
       this->close();
    }
}

void mapWidget::map2Btn_clicked()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�Ҫѡ���ͼ2��",QMessageBox::Yes|QMessageBox::No))
    {
        mapChooseFlag = 2;
       this->close();
    }
}


void mapWidget::map3Btn_clicked()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�Ҫѡ���ͼ3��",QMessageBox::Yes|QMessageBox::No))
    {
        mapChooseFlag = 3;
       this->close();
    }
}


void mapWidget::map4Btn_clicked()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�Ҫѡ���ͼ4��",QMessageBox::Yes|QMessageBox::No))
    {
        mapChooseFlag = 4;
       this->close();
    }
}

#include "mainWidget.h"
#include<Phonon/VideoPlayer>

extern Phonon::VideoPlayer *musicPlayer;
extern myMusic *menuMusic ;
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent)
{
    loginInterface = new loginWidget();
    registerInterface = new registerWidget();

    this->setFixedSize(485,764);
    // this->setWindowTitle("��¼����");
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
    this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

      //���ñ�������    #include <QSound>
         //extern  QSound *music;

     musicPlay();
 //   menuMusic = new myMusic("MyPlane/music/bi.wav");
   // menuMusic->playAgain();
////    //���ñ���ͼƬ
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag4.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,10,40,30);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_click()));


    loginBtn = new QPushButton(this);
    loginBtn->setGeometry(60,460,160,60);
   //  loginBtn->setText("��¼");
    loginBtn->setIcon(QIcon("MyPlane/images/btn/login11.png"));
    loginBtn->setIconSize(QSize(160,60));
    loginBtn->setFocusPolicy(Qt::NoFocus);
    loginBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    loginBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");



    registerBtn = new QPushButton(this);
    registerBtn->setGeometry(250,460,160,60);
    //registerBtn->setText("ע��");
    registerBtn->setIcon(QIcon("MyPlane/images/btn/register11.png"));
    registerBtn->setIconSize(QSize(160,60));
    registerBtn->setFocusPolicy(Qt::NoFocus);
    registerBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    registerBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

//    //��ʾGIFͼ
//    labelPic1 =new QLabel(this);
//    movie1 = new QMovie("MyPlane/images/img/bat.gif");
//    labelPic1->setMovie(movie1);
//    movie1->start();
//    labelPic1->setGeometry(20,this->height()-250,94,131);
//    //ȥ�������ť����ֵİ�ɫ����
//    labelPic1->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    //��ʾGIFͼ
    labelPic2 =new QLabel(this);
    movie2 = new QMovie("MyPlane/images/img/alien.gif");
    labelPic2->setMovie(movie2);
    movie2->start();
    labelPic2->setGeometry(0,20,105,107);
    //ȥ�������ť����ֵİ�ɫ����
    labelPic2->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


        //��ʾGIFͼ
        labelPic3 =new QLabel(this);
        movie3 = new QMovie("MyPlane/images/img/plane.gif");
        labelPic3->setMovie(movie3);
        movie3->start();
        labelPic3->setGeometry(120,this->height()/2+30,55,49);
        //ȥ�������ť����ֵİ�ɫ����
        labelPic3->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


        //��ʾGIFͼ
        labelPic4 =new QLabel(this);
        movie4 = new QMovie("MyPlane/images/img/plane.gif");
        labelPic4->setMovie(movie4);
        movie4->start();
        labelPic4->setGeometry(this->width()-175,this->height()/2+30,55,49);
        //ȥ�������ť����ֵİ�ɫ����
        labelPic4->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


//        //��ʾGIFͼ
//        labelPic5 =new QLabel(this);
//        movie5 = new QMovie("MyPlane/images/img/elephant.gif");
//        labelPic5->setMovie(movie5);
//        movie5->start();
//        labelPic5->setGeometry(this->width()-230,this->height()-223,158,141);
//        //ȥ�������ť����ֵİ�ɫ����
//        labelPic5->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");




     connect(loginBtn,SIGNAL(clicked()),this,SLOT(loginBtn_clicked()));
     connect(registerBtn,SIGNAL(clicked()),this,SLOT(registerBtn_clicked()));


     connect( loginInterface,SIGNAL(ReturnLoginSignal()),this,SLOT(loginBack()));
     connect( registerInterface,SIGNAL(BackLoginSignal()),this,SLOT(regiterBack()));


}

void mainWidget::loginBtn_clicked()
{ 
    loginInterface->show();
    this->hide();
}

void mainWidget::registerBtn_clicked()
{
    registerInterface->show();

    this->hide();
}

void mainWidget::loginBack()
{
    loginInterface->hide();
    this->show();

}

void mainWidget::regiterBack()
{
    registerInterface->hide();
    this->show();
}



void mainWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void mainWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void mainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,485,764,QPixmap("MyPlane/images/widget/Bag4.png"));
}

void mainWidget::musicPlay()
{
    musicPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory);
    musicPlayer->load(Phonon::MediaSource("MyPlane/music/menubg.wav"));
    musicPlayer->play();
    connect(musicPlayer,SIGNAL(finished()),this,SLOT(musicPlay()));

}
void mainWidget::closeBtn_click()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�ȷ��Ҫ�˳���",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

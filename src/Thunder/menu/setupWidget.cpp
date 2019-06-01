#include "setupWidget.h"
#include<Phonon/VideoPlayer>
extern Phonon::VideoPlayer *musicPlayer;
extern QSound music;
extern bool isGuideOn;
extern int  difficultyRanking;
extern bool isMusicOn;

setupWidget::setupWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(450,450);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

    //this->setAutoFillBackground(false);  //这个不设置的话就背景变黑
     this->setWindowFlags(Qt::FramelessWindowHint);//去边框
    this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

    //设置背景图片
//    bgLabel =new QLabel(this) ;
//     bgLabel->setGeometry(0,0,673,661);
//    bgLabel->setStyleSheet("QLabel{border-image:url(MyPlane/images/widget/bc_rank.png);}");

//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg2.png")));
//    this->setPalette(palatte);


    musicBtn = new QPushButton(this);
    this->showMusicBtn();

    guideBtn = new QPushButton(this);
    this->showGuideBtn();

    difficultyBtn = new QPushButton(this);
    this->showDifficultyBtn();

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,10,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

    this->connect(musicBtn,SIGNAL(clicked()),this,SLOT(musicBtn_clicked()));
    this->connect(guideBtn,SIGNAL(clicked()),this,SLOT(guideBtn_clicked()));
    this->connect(difficultyBtn,SIGNAL(clicked()),this,SLOT(difficultyBtn_clicked()));

//    qDebug()<<"width:"<<this->parentWidget()->width();
//    qDebug()<<"height:"<<this->parentWidget()->height();
//    qDebug()<<"width:"<<this->width();
//    qDebug()<<"height:"<<this->height();
}

void setupWidget::showMusicBtn()
{

    if(isMusicOn)
    {
        musicBtn->setGeometry(140,75,150,45);
        musicBtn->setIcon(QIcon("MyPlane/images/btn/bgmusic1.png"));
        musicBtn->setIconSize(QSize(150,45));
        musicBtn->setFocusPolicy(Qt::NoFocus);
        musicBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        musicBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    }
    else
    {
        musicBtn->setGeometry(140,75,150,45);
        musicBtn->setIcon(QIcon("MyPlane/images/btn/bgmusic2.png"));
        musicBtn->setIconSize(QSize(150,45));
        musicBtn->setFocusPolicy(Qt::NoFocus);
        musicBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        musicBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    }

    qDebug()<<isMusicOn;
}

void setupWidget::showGuideBtn()
{


    if(isGuideOn)
    {



        guideBtn->setGeometry(140,175,150,45);
        guideBtn->setIcon(QIcon("MyPlane/images/btn/guide1.png"));
        guideBtn->setIconSize(QSize(150,45));
        guideBtn->setFocusPolicy(Qt::NoFocus);
        guideBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        guideBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    }
    else
    {
        guideBtn->setGeometry(140,175,150,45);
        guideBtn->setIcon(QIcon("MyPlane/images/btn/guide2.png"));
        guideBtn->setIconSize(QSize(150,45));
        guideBtn->setFocusPolicy(Qt::NoFocus);
        guideBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        guideBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    }

    qDebug()<<isGuideOn;
}

void setupWidget::showDifficultyBtn()
{

    switch(difficultyRanking)
    {
    case 1:
        difficultyBtn->setGeometry(140,275,150,45);
        difficultyBtn->setIcon(QIcon("MyPlane/images/btn/difficulty1.png"));
        difficultyBtn->setIconSize(QSize(150,45));
        difficultyBtn->setFocusPolicy(Qt::NoFocus);
        difficultyBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        difficultyBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        break;
    case 2:
        difficultyBtn->setGeometry(140,275,150,45);
        difficultyBtn->setIcon(QIcon("MyPlane/images/btn/difficulty2.png"));
        difficultyBtn->setIconSize(QSize(150,45));
        difficultyBtn->setFocusPolicy(Qt::NoFocus);
        difficultyBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        difficultyBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

        break;
    case 3:
        difficultyBtn->setGeometry(140,275,150,45);
        difficultyBtn->setIcon(QIcon("MyPlane/images/btn/difficulty3.png"));
        difficultyBtn->setIconSize(QSize(150,45));
        difficultyBtn->setFocusPolicy(Qt::NoFocus);
        difficultyBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        difficultyBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        break;
    }


    qDebug()<<difficultyRanking;
}

void setupWidget::musicBtn_clicked()
{

  isMusicOn = isMusicOn?false:true;
   this->showMusicBtn();

  if(isMusicOn)
  {
      //music.play();
      musicPlayer->play();
  }
  else
  {
      //music.stop();
      musicPlayer->stop();
  }

}

void setupWidget::guideBtn_clicked()
{

    isGuideOn = isGuideOn?false:true;
    this->showGuideBtn();

}

void setupWidget::difficultyBtn_clicked()
{


    difficultyRanking++;
    if(difficultyRanking>3)
        difficultyRanking= 1;

    this->showDifficultyBtn();

}



void setupWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void setupWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void setupWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap( 0, 0,450,450,QPixmap("MyPlane/images/widget/Bag_Bg2.png"));
}

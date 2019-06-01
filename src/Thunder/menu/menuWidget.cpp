#include "menuWidget.h"
extern int  planeChooseFlag;
menuWidget::menuWidget(QWidget *parent) :
    QWidget(parent)
{
    qDebug()<<"CCCCCC";
    helpInterface = new helpWidget();
     setupInterface = new setupWidget();
     rankingInterface = new rankingWidget();
     gameInterface = new  gameWidget();
     mapInterface = new mapWidget();

        this->setFixedSize(540,960);
        this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

        //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
        this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
        this->setWindowFlags(Qt::FramelessWindowHint);//去边框
       this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

        //设置背景图片
//        QPalette palatte;
//        palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg1.png")));
//        this->setPalette(palatte);


        closeBtn = new QPushButton(this);
        closeBtn->setGeometry(this->width()-60,15,30,30);
        closeBtn->setIcon(QIcon("MyPlane/images/btn/close111.png"));
        closeBtn->setIconSize(QSize(30,30));
        closeBtn->setFocusPolicy(Qt::NoFocus);
        closeBtn->setFlat(true);
        //去除点击按钮后出现的白色部分
        closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_click()));

        int x0 = 170;
        int y0 = 170;
        int width =150;
        int height = 45;
        int distance = 30;

        startBtn = new QPushButton(this);
        //startBtn->setGeometry(x0,y0+(distance+height)*0,width,height);
        startBtn->setGeometry((this->width()-403)/2,this->height()-120,403,116);
        startBtn->setIcon(QIcon("MyPlane/images/MainUI/MainUI_Btn_Bg5.png"));
        startBtn->setIconSize(QSize(403,116));
        startBtn->setFocusPolicy(Qt::NoFocus);
        startBtn->setFlat(true);

        RanKingBtn = new QPushButton(this);
        RanKingBtn->setGeometry(20,570,80,80);
        RanKingBtn->setIcon(QIcon("MyPlane/images/btn/menu_an241.png"));
        RanKingBtn->setIconSize(QSize(80,80));
        RanKingBtn->setFocusPolicy(Qt::NoFocus);
        RanKingBtn->setFlat(true);

        helpBtn = new QPushButton(this);
        helpBtn->setGeometry(this->width()-145,this->height()-215,151,142);
        helpBtn->setIcon(QIcon("MyPlane/images/MainUI/help11.png"));
        helpBtn->setIconSize(QSize(151,142));
        helpBtn->setFocusPolicy(Qt::NoFocus);
        helpBtn->setFlat(true);

        setupBtn = new QPushButton(this);
        //setupBtn->setGeometry(x0,y0+(distance+height)*3,width,height);
        setupBtn->setGeometry(this->width()-101,570,80,80);
        setupBtn->setIcon(QIcon("MyPlane/images/btn/menu_an31.png"));
        setupBtn->setIconSize(QSize(80,80));
        setupBtn->setFocusPolicy(Qt::NoFocus);
        setupBtn->setFlat(true);

        logoutBtn = new QPushButton(this);
        logoutBtn->setGeometry(25,15,170,59);
        logoutBtn->setIcon(QIcon("MyPlane/images/btn/login33.png"));
        logoutBtn->setIconSize(QSize(170,59));
        logoutBtn->setFocusPolicy(Qt::NoFocus);
        logoutBtn->setFlat(true);


        mapBtn = new QPushButton(this);
        mapBtn->setGeometry(-6,this->height()-215,151,142);
        mapBtn->setIcon(QIcon("MyPlane/images/MainUI/map11.png"));
        mapBtn->setIconSize(QSize(151,142));
        mapBtn->setFocusPolicy(Qt::NoFocus);
        mapBtn->setFlat(true);

        leftBtn = new QPushButton(this);
        leftBtn->setGeometry(30,this->height()/3,47,73);
        leftBtn->setIcon(QIcon("MyPlane/images/MainUI/MainUI_Arrow_L_Btn_Down.png"));
        leftBtn->setIconSize(QSize(47,73));
        leftBtn->setFocusPolicy(Qt::NoFocus);
        leftBtn->setFlat(true);


        rightBtn = new QPushButton(this);
        rightBtn->setGeometry(this->width()-77,this->height()/3,47,73);
        rightBtn->setIcon(QIcon("MyPlane/images/MainUI/MainUI_Arrow_R_Btn_Down.png"));
        rightBtn->setIconSize(QSize(47,73));
        rightBtn->setFocusPolicy(Qt::NoFocus);
        rightBtn->setFlat(true);


        planePic1 = new QLabel(this);
        QPixmap *pixMap1 = new QPixmap("MyPlane/images/PLAYER/Anim_Plane_01/3.png");
        planePic1->setPixmap(*pixMap1);
        planePic1->setGeometry((this->width()-pixMap1->width())/2,this->height()/3,pixMap1->width(),pixMap1->height());
        //去除点击按钮后出现的白色部分
        planePic1->setStyleSheet("QLabel{background-color:transparent;border:0px;color:white}");


        planePic2 = new QLabel(this);
        QPixmap *pixMap2 = new QPixmap("MyPlane/images/PLAYER/Anim_Plane_04/3.png");
        planePic2->setPixmap(*pixMap2);
        planePic2->setGeometry((this->width()-pixMap2->width())/2,this->height()/3,pixMap2->width(),pixMap2->height());
        //去除点击按钮后出现的白色部分
        planePic2->setStyleSheet("QLabel{background-color:transparent;border:0px;color:white}");
        planePic2->hide();


        planePic3 = new QLabel(this);
        QPixmap *pixMap3 = new QPixmap("MyPlane/images/PLAYER/Anim_Plane_05/3.png");
        planePic3->setPixmap(*pixMap3);
        planePic3->setGeometry((this->width()-pixMap3->width())/2,this->height()/3,pixMap3->width(),pixMap3->height());
        //去除点击按钮后出现的白色部分
        planePic3->setStyleSheet("QLabel{background-color:transparent;border:0px;color:white}");
        planePic3->hide();


        planePic4 = new QLabel(this);
        QPixmap *pixMap4 = new QPixmap("MyPlane/images/PLAYER/Anim_Plane_06/3.png");
        planePic4->setPixmap(*pixMap4);
        planePic4->setGeometry((this->width()-pixMap4->width())/2,this->height()/3,pixMap4->width(),pixMap4->height());
        //去除点击按钮后出现的白色部分
        planePic4->setStyleSheet("QLabel{background-color:transparent;border:0px;color:white}");
        planePic4->hide();



        //显示GIF图
        labelPic1 =new QLabel(this);
        movie1 = new QMovie("MyPlane/images/img/bat.gif");
        labelPic1->setMovie(movie1);
        movie1->start();
        labelPic1->setGeometry(this->width()-200,20,94,131);
        //去除点击按钮后出现的白色部分
        labelPic1->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

        //显示GIF图
        labelPic2 =new QLabel(this);
        movie2 = new QMovie("MyPlane/images/img/alien.gif");
        labelPic2->setMovie(movie2);
        movie2->start();
        labelPic2->setGeometry(0,70,105,107);
        //去除点击按钮后出现的白色部分
        labelPic1->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


        //显示GIF图
        labelPic3 =new QLabel(this);
        movie3 = new QMovie("MyPlane/images/img/boy2.gif");
        labelPic3->setMovie(movie3);
        movie3->start();
        labelPic3->setGeometry((this->width()-200)/2,this->height()-485,200,164);
        //去除点击按钮后出现的白色部分
        labelPic3->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");



        //去除点击按钮后出现的白色部分
        startBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        RanKingBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        helpBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        setupBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        logoutBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        mapBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

        //去除点击按钮后出现的白色部分
        leftBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
        //去除点击按钮后出现的白色部分
        rightBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

        //        this->vboxlayout = new QVBoxLayout(this);
        //        this->vboxlayout->setGeometry(QRect(100,70,150,300));
        //        this->vboxlayout->addWidget(startBtn);
        //        this->vboxlayout->addWidget(RanKingBtn);
        //        this->vboxlayout->addWidget(helpBtn);
        //        this->vboxlayout->addWidget(setupBtn);
        //        this->vboxlayout->addWidget(logoutBtn);



        this->connect(logoutBtn,SIGNAL(clicked()),this,SLOT(backLoginSlot()));
       // this->connect(helpInterface,SIGNAL(backMenuSignal()),this,SLOT(helpBackSlot()));
        this->connect(setupBtn,SIGNAL(clicked()),this,SLOT(setupBtn_click()));
        this->connect(helpBtn,SIGNAL(clicked()),this,SLOT(helpBtn_clicked()));
        this->connect(RanKingBtn,SIGNAL(clicked()),this,SLOT(RanKingBtn_clicked()));

        this->connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtn_clicked()));

        qDebug()<<"aaaaaaa";
        this->connect(gameInterface,SIGNAL(backHome_signal()),this,SLOT(gameBack_slot()));
        qDebug()<<"bbbbbbb";

        this->connect(leftBtn,SIGNAL(clicked()),this,SLOT(leftBtn_clicked()));
        this->connect(rightBtn,SIGNAL(clicked()),this,SLOT(rightBtn_clicked()));

        this->connect(mapBtn,SIGNAL(clicked()),this,SLOT(mapBtn_clicked()));
}



void menuWidget::mousePressEvent(QMouseEvent *event)
{
    QSound mclickSound("MyPlane/music/mclick.wav");
    mclickSound.play();
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void menuWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void menuWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,540,960,QPixmap("MyPlane/images/MainUI/MainUI_Bg2.png"));
}



void menuWidget::backLoginSlot()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"提示","您是否确认要注销您的账号？",QMessageBox::Yes|QMessageBox::No))
    {
        helpInterface->close();
        setupInterface->close();
        rankingInterface->close();
        emit backLoginSignal();
    }


}
//void menuWidget::helpBackSlot()
//{
//    helpInterface->hide();
//    //helpInterface.setWindowModality(Qt::ApplicationModal);
//    this->show();
//}

void menuWidget::helpBtn_clicked()
{
   // this->hide();

    //helpInterface是要显示的窗口名
//    Qt::WindowFlags flags = Qt::Dialog;
//     helpInterface->setWindowFlags(flags);

//    //弹出子窗口时禁用主窗口    //阻塞除当前窗体之外的所有的窗体
//    helpInterface->setWindowModality(Qt::ApplicationModal);



    //helpInterface->hide();

    helpInterface->show();
}
void menuWidget::setupBtn_click()
{

    setupInterface->showGuideBtn();

    //setupInterface->hide();
    setupInterface->show();

}

void menuWidget::RanKingBtn_clicked()
{
    //先刷新数据
    rankingInterface->on_pushButton_next_clicked();
    rankingInterface->on_pushButton_before_clicked();
    //rankingInterface->hide();
    rankingInterface->show();

}
void menuWidget::closeEvent(QCloseEvent *CloseEvent)
{
    helpInterface->close();
    setupInterface->close();
    rankingInterface->close();
}

void menuWidget::startBtn_clicked()
{


    gameInterface->setUserName(this->userName);
    gameInterface->gameStart();

    gameInterface->GamestartPlay();
    gameInterface->setBackground();

    gameInterface->show();
    this->hide();

}
void menuWidget::gameBack_slot()
{
    this->show();
    gameInterface->hide();
}
void menuWidget::leftBtn_clicked()
{
    qDebug()<<"leftBtn_clicked";
    planeChooseFlag--;
    if(planeChooseFlag <=0)
    {
        planeChooseFlag=4;
    }
    planePicShow();
}

void menuWidget::rightBtn_clicked()
{
     qDebug()<<"rightBtn_clicked";
    planeChooseFlag++;
    if(planeChooseFlag >=5)
    {
    planeChooseFlag=1;
    }
    planePicShow();
}

void menuWidget::planePicShow()
{
    qDebug()<<"0000000";
    switch(planeChooseFlag)
    {
     case 1:
        this->planePic1->show();
        this->planePic2->hide();
        this->planePic3->hide();
        this->planePic4->hide();
        break;
    case 2:
        qDebug()<<22222;
        this->planePic1->hide();
        this->planePic2->show();
        this->planePic3->hide();
        this->planePic4->hide();
       break;
    case 3:
        this->planePic1->hide();
        this->planePic2->hide();
        this->planePic3->show();
        this->planePic4->hide();
       break;
    case 4:
        qDebug()<<44444;
        this->planePic1->hide();
        this->planePic2->hide();
        this->planePic3->hide();
        this->planePic4->show();
       break;


    }

}

void menuWidget::closeBtn_click()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"提示","您是否确认要退出？",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

void menuWidget::mapBtn_clicked()
{
     //QMessageBox::information(this,"提示","该功能还未实现");
     mapInterface->show();
}

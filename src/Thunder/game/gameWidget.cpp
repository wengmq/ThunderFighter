#include "gameWidget.h"
int widget_w = 700;
int widget_h = 800;
extern bool isGuideOn;
extern Phonon::VideoPlayer *GamestartPlayer;
extern Phonon::VideoPlayer *musicPlayer;
extern int mapChooseFlag;
gameWidget::gameWidget(QWidget *parent) :
    QWidget(parent)
{


    this->resize(widget_w,widget_h);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
    this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

    this->gameStartFlag = false;
    this->labelChangeFlag = 0;

    mapFinal_str = "QLabel{border-image:url(MyPlane/images/Scene/Map_09.jpg);}";
    //����lab1��ͼƬ����ʽ
     lab1 = new QLabel(this);
    lab1->setGeometry(0,0,widget_w,widget_h);
    lab1->setStyleSheet(mapFinal_str);

    //����lab2��ͼƬ����ʽ
     lab2 = new QLabel(this);
    lab2->setGeometry(0,0,widget_w,widget_h);
    lab2->setStyleSheet(mapFinal_str);

//    //����lab3��ͼƬ����ʽ
//    QLabel *lab3 = new QLabel(this);
//    lab3->setGeometry(0,0,800,533);
//    lab3->setStyleSheet("QLabel{border-image:url(fish_image/seaworld1.png);}");

    //���ö���Animation1
    QPropertyAnimation *Animation1 = new QPropertyAnimation(lab1,"geometry",this);
    Animation1->setDuration(10000);//���������ʱ10��

    Animation1->setKeyValueAt(0,QRect(0,0,widget_w,widget_h));
    Animation1->setKeyValueAt(1,QRect(0,widget_h,widget_w,widget_h));


    //���ö���Animation2
    QPropertyAnimation *Animation2 = new QPropertyAnimation(lab2,"geometry",this);
    Animation2->setDuration(10000);//���������ʱ10��
    Animation2->setKeyValueAt(0,QRect(0,-widget_h,widget_w,widget_h));
    Animation2->setKeyValueAt(1,QRect(0,0,widget_w,widget_h));

//    //���ö���Animation3
//    QPropertyAnimation *Animation3 = new QPropertyAnimation(lab3,"geometry",this);
//    Animation3->setDuration(80000);//���������ʱ10��
//    Animation3->setKeyValueAt(0,QRect(1600,0,800,533));
//    Animation3->setKeyValueAt(1,QRect(0,0,800,533));



    //�Ѷ���Animation1�Ͷ���Animation1���붯����group
    QParallelAnimationGroup *group = new QParallelAnimationGroup();
    group->addAnimation(Animation1);
    group->addAnimation(Animation2);
//    group->addAnimation(Animation3);
    group->start();//�����鲥��
    group->setLoopCount(-1);//����ѭ������

//    QLabel *lab = new QLabel(this);
//    lab->setGeometry(0,0,100,50);
//    lab->setStyleSheet("QLabel{border-image:url(MyPlane/images/btn/again.png);}");


   //QCoreApplication::processEvents(QEventLoop::AllEvents, 100);



}


void gameWidget::setUserName(QString name)
{

    QFont ft;
    ft.setPointSize(18);


    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);


    this->UserName = name;


    QString str_sql1 = QString("select highScore from user where name = '%1'").arg( this->UserName);
    qDebug()<<str_sql1;
    QSqlQuery * query1 = myDatabase::Instance()->executeQuery(str_sql1);
    if(query1->next())
    {

        this->HighScore = query1->value(0).toString();
        qDebug()<<this->HighScore;
    }

    QString str_sql2 = QString("select newUserFlag from user where name = '%1'").arg( this->UserName);
    qDebug()<<str_sql2;
    QSqlQuery * query2 = myDatabase::Instance()->executeQuery(str_sql2);
    if(query2->next())
    {

        this->newUserFlag = query2->value(0).toInt();
        qDebug()<<this->newUserFlag;
    }

//    QString str_highScore = QString("������߷��ǣ� %1 ").arg(this->HighScore);
//    HighScoreLabel = new QLabel(str_highScore,this);
//    HighScoreLabel->setGeometry(0,0,this->width(),70);


//    HighScoreLabel->setFont(ft);
//    HighScoreLabel->setPalette(pa);

//    HighScoreLabel->hide();//����



}


void gameWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void gameWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}

//void gameWidget::closeBtn_clicked()
//{
//    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","����ǰ�ķ����ѱ����棬���Ƿ�ȷ���˳���",QMessageBox::Yes|QMessageBox::No))
//    {
//        exit(0);
//    }
//}


void gameWidget::backHome_slot()
{

//    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","����ǰ�ķ����ѱ����棬���Ƿ�ȷ���˳���",QMessageBox::Yes|QMessageBox::No))
//    {
       delete GameView;
        musicPlay();
        emit backHome_signal();
        qDebug()<<"���ز˵�����";
//    }



}

 void gameWidget::gameStart()
 {

     if(isGuideOn)
     {
         newUserGuide();
         //�޸ı�־Ϊ0
         QString str_sql = QString("update user set newUserFlag = %1 where name = '%2'").arg(0).arg( this->UserName);
         qDebug()<<str_sql;
         myDatabase::Instance()->executeSql(str_sql);

     }


     this->pixmap1.load("MyPlane/images/btn/count1.png");
     pixmap1 = pixmap1.scaled(pixmap1.width(),pixmap1.height());

     this->pixmap2.load("MyPlane/images/btn/count2.png");
     pixmap2 = pixmap2.scaled(pixmap2.width(),pixmap2.height());

     this->pixmap3.load("MyPlane/images/btn/count3.png");
     pixmap3 = pixmap3.scaled(pixmap3.width(),pixmap3.height());

     this->pixmap4.load("MyPlane/images/btn/countStart.png");
     pixmap4 = pixmap4.scaled(pixmap4.width(),pixmap4.height());

     time = new QTimer(this);

     count_down();
     this->connect(time,SIGNAL(timeout()),this,SLOT(count_down_slot()));


 }



 void gameWidget::count_down()
 {
     this->lightFlag = 0;

     labelPixmap = new QLabel(this);

     labelPixmap->setGeometry((this->width()-183)/2,(this->height()-183)/2,183,183);

     labelPixmap->show();

     time->start(1000);

 }

 void gameWidget::count_down_slot()
 {
     qDebug()<<"timeout";
     switch(this->lightFlag)
     {
     case 0:
         this->labelPixmap->setPixmap(pixmap3);
         break;
     case 1:
     {

         this->labelPixmap->setPixmap(pixmap2);
         break;
    }
     case 2:
     {
         QSound readygoSound("MyPlane/music/readygo.wav");
         readygoSound.play();
         this->labelPixmap->setPixmap(pixmap1);
         break;
}
     case 3:
     {

         this->labelPixmap->setPixmap(pixmap4);

         break;
        }
     case 4:
     {



        time->stop();


        labelPixmap->close();

        this->GameView = new gameView(this);
        //����gameview���ز˵����ź�
        this->connect(GameView,SIGNAL(backGameWidget_signal()),this,SLOT(backHome_slot()));
        GameView->userName = this->UserName;
        GameView->HighScore = this->HighScore;
        GameView->planeShow();
           qDebug()<<"GameView->userName"<<GameView->userName;
            qDebug()<<"this->UserName"<<this->UserName;
            qDebug()<<"GameView->HighScore"<<GameView->HighScore;
             qDebug()<<"this->HighScore"<<this->HighScore;

        GameView->show();

//        closeBtn = new QPushButton(this);
//        closeBtn->setGeometry(this->width()-22,2,20,20);
//        closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
//        closeBtn->setIconSize(QSize(20,20));
//        closeBtn->setFocusPolicy(Qt::NoFocus);
//        closeBtn->setFlat(true);
//        //ȥ�������ť����ֵİ�ɫ����
//        closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
//        this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_clicked()));

//        backHomeBtn = new QPushButton(this);
//        backHomeBtn->setGeometry(2,2,20,20);
//        backHomeBtn->setIcon(QIcon("MyPlane/images/btn/backHome11.png"));
//        backHomeBtn->setIconSize(QSize(20,20));
//        backHomeBtn->setFocusPolicy(Qt::NoFocus);
//        backHomeBtn->setFlat(true);
//        //ȥ�������ť����ֵİ�ɫ����
//        backHomeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
//        this->connect(backHomeBtn,SIGNAL(clicked()),this,SLOT(backHomeBtn_clicked()));





         break;

      }


     }
     this->lightFlag++;
 }


 void gameWidget::newUserGuide()
 {
      this->show();
       QString bgPic;
       bgPic = "MyPlane/images/widget/guide1.png";
       myMessageBox box1(bgPic,this);

       bgPic = "MyPlane/images/widget/guide2.png";
      myMessageBox box2(bgPic,this);

      bgPic = "MyPlane/images/widget/guide3.png";
      myMessageBox box3(bgPic,this);

 }
void gameWidget::labelChange_slot()
{
    labelChangeFlag++;
}

void gameWidget::GamestartPlay()
{

   qDebug()<<"GamestartPlay1";
    musicPlayer->pause();
    GamestartPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory);

    qDebug()<<"GamestartPlay2";
    GamestartPlayer->load(Phonon::MediaSource("MyPlane/music/bgm1.mp3"));
    GamestartPlayer->play();

    qDebug()<<"GamestartPlay3";
    connect(GamestartPlayer,SIGNAL(finished()),this,SLOT(GamestartPlay()));

    qDebug()<<"GamestartPlay4";




//    musicPlayer->stop();
//    delete musicPlayer;
//    GamestartPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory);
//    GamestartPlayer->load(Phonon::MediaSource("MyPlane/music/bgm1.mp3"));
//    GamestartPlayer->play();
//    connect(GamestartPlayer,SIGNAL(finished()),this,SLOT(GamestartPlay()));

}
void gameWidget::musicPlay()
{

//      qDebug()<<"musicPlayer1";
//    GamestartPlayer->stop();
//    delete GamestartPlayer;
//    musicPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory);
//    musicPlayer->load(Phonon::MediaSource("MyPlane/music/bi.wav"));
//    musicPlayer->play();
//    connect(musicPlayer,SIGNAL(finished()),this,SLOT(musicPlay()));




    GamestartPlayer->pause();
    GamestartPlayer->disconnect();
     delete GamestartPlayer;
    musicPlayer->play();

}

void gameWidget::setBackground()
{
    QString map1_str = "QLabel{border-image:url(MyPlane/images/Scene/Map_09.jpg);}";
    QString map2_str = "QLabel{border-image:url(MyPlane/images/Scene/Map_03.jpg);}";
    QString map3_str = "QLabel{border-image:url(MyPlane/images/Scene/Map_05.jpg);}";
    QString map4_str = "QLabel{border-image:url(MyPlane/images/Scene/Map_10.jpg);}";



    qDebug()<<mapChooseFlag;
    switch(mapChooseFlag)
    {

    case 1:
        mapFinal_str = map1_str;
        break;
    case 2:
        mapFinal_str = map2_str;
        break;
    case 3:
        mapFinal_str = map3_str;
        break;
    case 4:
        mapFinal_str = map4_str;
        break;


    }
    qDebug()<<"mapFinal_str"<<mapFinal_str;


    //����lab1��ͼƬ����ʽ
    lab1->setStyleSheet(mapFinal_str);

    //����lab2��ͼƬ����ʽ
    lab2->setStyleSheet(mapFinal_str);


}

#include "gameView.h"
extern int  planeChooseFlag;
extern int  difficultyRanking;
gameView::gameView(QWidget *parent) :
    QGraphicsView(parent)
{

    GameOver = new gameOver();
    GameOver->hide();
    this->widget_w = 700;
    this->widget_h = 800;
    qDebug()<<"gameView!!";
    this->stopGameFlag =false;
    //��ʼ��view
    this->resize(this->widget_w,this->widget_h);

    this->currentScore = 0;
    //���ñ��� �ޱ߿� ������ɫ
    this->setStyleSheet("QWidget{background-color:transparent;border:0px;color:red}");

    //��ʼ������
    scene = new QGraphicsScene();
    //���ó�����ԭ�㣬�ʹ�С����viewһ����
    scene->setSceneRect(0,0,this->widget_w,this->widget_h);
    //�ѳ�����ӵ���ͼ����
    this->setScene(scene);

    isMovingFlag = false;
    stopGameFlag = false;

    myPlane  = new myPlaneItem("MyPlane/images/PLAYER/Anim_Plane_01/3.png",scene);
    myPlane->setPos(this->width()/2-myPlane->pixMap.width()/2,this->height()-200);

    pProgressBar = new QProgressBar(this);
    pProgressBar->setOrientation(Qt::Horizontal);  // ˮƽ����
    pProgressBar->setMinimum(0);  // ��Сֵ
    pProgressBar->setMaximum(100);  // ���ֵ
    pProgressBar->setValue(100);  // ��ǰ����
    pProgressBar->setStyleSheet("{border:2px solid red;border-radius:5px;text-align:center;}");
    pProgressBar->setGeometry(0,this->height()-20,this->width(),20);

    my_bullet_launch_sound = new QSound("MyPlane/music/bi.wav");
    enemy_bullet_blast_sound = new QSound("MyPlane/music/bullet.wav");
     deathBlast_sound = new QSound("MyPlane/music/boom.wav");
     gameOver_sound = new QSound("MyPlane/music/58-0.wav");

    QFont ft;
    ft.setPointSize(18);


    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);

    QString str_currentScore = QString("��ǰ�÷֣� %1 ").arg(this->currentScore);
    currentScoreLabel = new QLabel(str_currentScore,this);
    currentScoreLabel->setGeometry(0,0,this->width(),70);
    currentScoreLabel->setFont(ft);
    currentScoreLabel->setPalette(pa);




    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-32,2,30,30);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(30,30));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_clicked()));

    backHomeBtn = new QPushButton(this);
    backHomeBtn->setGeometry(this->width()-64,2,30,30);
    backHomeBtn->setIcon(QIcon("MyPlane/images/btn/backHome11.png"));
    backHomeBtn->setIconSize(QSize(30,30));
    backHomeBtn->setFocusPolicy(Qt::NoFocus);
    backHomeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    backHomeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(backHomeBtn,SIGNAL(clicked()),this,SLOT(backHomeBtn_clicked()));
    this->connect(GameOver,SIGNAL(backGameView_signal()),this,SLOT(gameOver_slot()));

{

//            startGameBtn = new QPushButton(this);
//            startGameBtn->setGeometry(this->width()-90,2,20,20);
//            startGameBtn->setIcon(QIcon("MyPlane/images/btn/stop11.png"));
//            startGameBtn->setIconSize(QSize(20,20));
//            startGameBtn->setFocusPolicy(Qt::NoFocus);
//            startGameBtn->setFlat(true);
//            //ȥ�������ť����ֵİ�ɫ����
//            startGameBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
//            this->connect(startGameBtn,SIGNAL(clicked()),this,SLOT(startGameBtn_clicked));
//            startGameBtn->hide();

//            stopGameBtn = new QPushButton(this);
//            stopGameBtn->setGeometry(this->width()-67,2,20,20);
//            stopGameBtn->setIcon(QIcon("MyPlane/images/btn/start11.png"));
//            stopGameBtn->setIconSize(QSize(20,20));
//            stopGameBtn->setFocusPolicy(Qt::NoFocus);
//            stopGameBtn->setFlat(true);
//            //ȥ�������ť����ֵİ�ɫ����
//            stopGameBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
//            this->connect(stopGameBtn,SIGNAL(clicked()),this,SLOT(stopGameBtn_clicked));


    //     enemyPlane1 = new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_02.png",scene);
    //    enemyPlane1->setPos(50,60);

    //     enemyPlane2 = new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_10.png",scene);
    //    enemyPlane2->setPos(200,70);

    //     enemyPlane3 = new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_11.png",scene);
    //    enemyPlane3->setPos(450,80);

    //     enemyPlane4 = new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_18.png",scene);
    //    enemyPlane4->setPos(300,150);

 }


    QTime time;//���������
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);


    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(my_bullet_colliding()));
    timer1->start(25);//����������������ʱ������ʱ���Ϊ25���롣

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(my_bullet_move()));
    timer2->start(25);//����������������ʱ������ʱ���Ϊ25���롣

    timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(enemy_bullet_colliding()));
    timer3->start(25);//����������������ʱ������ʱ���Ϊ25���롣

    timer4 = new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(deathBlast_disappear()));
    timer4->start(500);//����������������ʱ������ʱ���Ϊ500���롣



    StopTimer = new QTimer(this);
    connect(StopTimer,SIGNAL(timeout()),this,SLOT(sleep()));
   // StopTimer->start(25);//����������������ʱ������ʱ���Ϊ100���롣

        ProgressBarTimer = new QTimer(this);
        connect(ProgressBarTimer,SIGNAL(timeout()),this,SLOT(enemy_planes_pProgressBar_slot()));
        ProgressBarTimer->start(25);//����������������ʱ������ʱ���Ϊ100���롣

    //��ʱ��
    //    advancedTimer = new QTimer(this);
    //    connect(advancedTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    //    advancedTimer->start(25);//����������������ʱ������ʱ���Ϊ100���롣
}


//void gameView::mouseMoveEvent(QMouseEvent *event)
//{
////myPlane->mapRectToScene;
//    //itemAt(myPlane->mapToScene(0,0).x(),myPlane->mapToScene(0,0).y());
//    qreal moveX = qreal(event->globalPos().x() - this->dPos.x());
//    qreal moveY = qreal(event->globalPos().y() - this->dPos.y());
//    //QPointF movePos = mapToScene(moveX,moveY);
//     //  myPlane->moveBy(moveX,moveY);
//       qDebug()<<"X:"<<myPlane->pos().x()<<",Y:"<<myPlane->pos().y();

//       myPlane->setPos(mapToScene(moveX,moveY));

//}
//void gameView::mousePressEvent(QMouseEvent *event)
//{
//    //mousePressFlag = true;
//    this->windowPos = this->pos();                // ��ò�����ǰλ��
//    this->mousePos = event->globalPos();     // ������λ��
//    this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
//}
//void gameView::mouseReleaseEvent(QMouseEvent *event)
//{
//   mousePressFlag = false;
//}

void gameView::keyPressEvent(QKeyEvent *event)
{
    int distance = 10;
    switch(event->key())
    {


    //�� ASDW��
    case Qt::Key_A:
        qDebug()<<"AAAAA";
        myPlane->setPos(mapToScene(myPlane->pos().x()-distance,myPlane->pos().y()));

        break;

    case Qt::Key_S:
        qDebug()<<"SSSSS";
        myPlane->setPos(mapToScene(myPlane->pos().x(),myPlane->pos().y()+distance));

        break;

    case Qt::Key_D:
        qDebug()<<"DDDDD";
        myPlane->setPos(mapToScene(myPlane->pos().x()+distance,myPlane->pos().y()));
        break;

    case Qt::Key_W:
        qDebug()<<"WWWW";
        myPlane->setPos(mapToScene(myPlane->pos().x(),myPlane->pos().y()-distance));
        break;




        //�������
    case Qt::Key_Left:
        qDebug()<<"left";
        myPlane->setPos(mapToScene(myPlane->pos().x()-distance,myPlane->pos().y()));

        break;

    case Qt::Key_Down:
        qDebug()<<"down";
        myPlane->setPos(mapToScene(myPlane->pos().x(),myPlane->pos().y()+distance));

        break;

    case Qt::Key_Right:
        qDebug()<<"right";
        myPlane->setPos(mapToScene(myPlane->pos().x()+distance,myPlane->pos().y()));
        break;

    case Qt::Key_Up:
        qDebug()<<"up";
        myPlane->setPos(mapToScene(myPlane->pos().x(),myPlane->pos().y()-distance));
        break;


    case Qt::Key_Space:
        qDebug()<<"Key_Space";
        my_bullet_launch_sound->play();
        my_bullets.append(new  myBulletItem("MyPlane/images/bullet/bullet-126.png",scene));
        my_bullets.back()->setPos(myPlane->x()+36,myPlane->y()-80);
        break;

    case Qt::Key_P:
           qDebug()<<"PPPPPP";
           stopAllTimer();
           //������Ϣ�򣬿��ó�������
            QMessageBox::information(this,"��ͣ","��ǰ��Ϸ����ͣ,���OK������Ϸ��");
            startAllTimer();

        break;



    }
}


void gameView::mousePressEvent(QMouseEvent *event)
{
    //    qreal PlaneX1 = myPlane->mapFromScene(0,0).x();
    //    qreal PlaneX2 = myPlane->mapFromScene(0,0).x()+myPlane->pixMap.width();
    //    qreal PlaneY1 = myPlane->mapFromScene(0,0).y();
    //    qreal PlaneY2 = myPlane->mapFromScene(0,0).y()+myPlane->pixMap.height();

    qreal PlaneX1 = myPlane->pos().x();
    qreal PlaneX2 = myPlane->pos().x()+myPlane->pixMap.width();
    qreal PlaneY1 = myPlane->pos().y();
    qreal PlaneY2 = myPlane->pos().y()+myPlane->pixMap.height();


    qDebug()<<"PlaneX1"<<PlaneX1;
    qDebug()<<"PlaneX2"<<PlaneX2;
    qDebug()<<"PlaneY1"<<PlaneY1;
    qDebug()<<"PlaneY2"<<PlaneY2;


    if(event->x() >= PlaneX1 && event->x() <= PlaneX2 && event->y() >= PlaneY1 && event->y() <= PlaneY2)
    {//ֻ����������ɻ������ǲſ���������ƶ��ɻ�
        this->setCursor(Qt::PointingHandCursor);
        isMovingFlag = true;
    }
    my_bullet_launch_sound->play();
    my_bullets.append(new  myBulletItem("MyPlane/images/bullet/bullet-126.png",scene));
    my_bullets.back()->setPos(myPlane->x()+36,myPlane->y()-80);
    ////    else
    ////    {
    //    myBulletItem *myBullet = new myBulletItem("MyPlane/images/bullet/Bullet_1.png",scene);

    //    myBullet->setPos(myPlane->pos().x()+myPlane->pixMap.width()/2-10,myPlane->pos().y()-myPlane->pixMap.height()*2);
    ////    }


    //    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/Bullet_1.png",scene));
    //    enemy_bullets.back()->setPos(myPlane->pos().x()+myPlane->pixMap.width()/2-10,myPlane->pos().y()-myPlane->pixMap.height()*2);

}

void gameView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    QPoint posNow;
    if(isMovingFlag)
    {
        //qDebug()<<"x:"<<pos.x()<<"y:"<<pos.y()<<"this->width:"<<this->width()<<"this->height:"<<this->height();
        if(pos.x()>this->width()-myPlane->pixMap.width()/2)//�����ұ߽�
        {
            posNow.rx() = this->width()-myPlane->pixMap.width()/2;
        }
        else if(pos.x()<myPlane->pixMap.width()/2)//������߽�
        {
            posNow.rx()=myPlane->pixMap.width()/2;
        }
        else
        {
            posNow.rx() = pos.x();
        }


        if(pos.y()>this->height()-myPlane->pixMap.height()/2)//�����±߽�
        {
            posNow.ry() = this->height()-myPlane->pixMap.height()/2;
        }
        else if(pos.y()<myPlane->pixMap.height()/2)//�����ϱ߽�
        {
            posNow.ry()=myPlane->pixMap.height()/2;
        }
        else
        {
            posNow.ry() = pos.y();
        }

        //       posNow.rx() = pos.x();
        //       posNow.ry() = pos.y();
        //myPlane->setPos(posNow.x(),posNow.y());

        myPlane->setPos(posNow.x()-myPlane->pixMap.width()/2,posNow.y()-myPlane->pixMap.height()/2);
    }
}

void gameView::mouseReleaseEvent(QMouseEvent *event)
{
    this->setCursor(Qt::ArrowCursor);
    isMovingFlag = false;
}

void gameView::enemy_plane_produce()//�����л�//�����л��ӵ�
{

    int planeTypeFlag = 0;
    int max_enemy_plane_num ;
    switch(difficultyRanking)
    {
    case 1:
        max_enemy_plane_num = 3;
        break;

    case 2:
        max_enemy_plane_num = 6;
        break;
    case 3:
        max_enemy_plane_num = 9;
        break;
    }

    planeTypeFlag = qrand()%6;

    //qDebug()<<enemy_planes.size();
    if(enemy_planes.size()<max_enemy_plane_num)
    {
        static int planeIndex = 1;
        QList<int> list_xx ;
        //�Զ������ֵ��ȡֵ��Χ
        list_xx<<-6<<-7<<-4<<-5<<-6<<6<<7<<4<<5<<6;
        QList<int> list_yy;
        list_yy<<0<<1<<2<<3<<4;
        int speed_xx = list_xx[qrand()%list_xx.size()];
        int speed_yy = list_yy[qrand()%list_yy.size()];

        qDebug()<<planeTypeFlag;
        switch(planeTypeFlag)//���������ͬ���͵ķɻ�
        {
        case PLANE_TYPE_0://С�� ����ֵ 600������60
            enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_02.png",scene,planeIndex++,600,60,speed_xx,speed_yy,PLANE_TYPE_0));
            enemy_planes.back()->setPos(qrand()%400,qrand()%20);
            break;

        case PLANE_TYPE_1:  //���� ����ֵ 2000������350
            enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_17.png",scene,planeIndex++,2000,350,speed_xx,speed_yy,PLANE_TYPE_1));
            enemy_planes.back()->setPos(qrand()%400,qrand()%20);
            break;
        case PLANE_TYPE_2://����  ����ֵ 1800������300
            enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_13.png",scene,planeIndex++,1800,200,speed_xx,speed_yy,PLANE_TYPE_2));
            enemy_planes.back()->setPos(qrand()%400,qrand()%20);
            break;
        case PLANE_TYPE_3://С�� ����ֵ 400������100
            enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_09.png",scene,planeIndex++,400,100,speed_xx,speed_yy,PLANE_TYPE_3));
            enemy_planes.back()->setPos(qrand()%400,qrand()%20);
            break;
        case PLANE_TYPE_4://С�� ����ֵ 500������800
            enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_10.png",scene,planeIndex++,500,80,speed_xx,speed_yy,PLANE_TYPE_4));
            enemy_planes.back()->setPos(qrand()%400,qrand()%20);
            break;



        }

//        enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_02.png",scene,planeIndex++,600,60,speed_xx,speed_yy));
//        enemy_planes.back()->setPos(qrand()%400,qrand()%20);
        // qDebug()<<"x ="<<enemy_planes.back()->pos().x()<<"y = "<<enemy_planes.back()->pos().y();
    }


    //�����л��ӵ�
    if(enemy_planes.size()>0)
    {
        for(int i = enemy_planes.size()-1;  i>-1;  i--)
        {
            if(enemy_planes[i]->cType == ENEMY_PLANE_TYPE)
            {
                //�ӵ�����ƶ��Ĺ켣
                QList<int> list_x ;
                list_x<<0<<-1<<-2<<-3<<-4<<-5<<1<<2<<3<<4<<5<<0<<-1<<0<<-1<<1<<1;
                QList<int> list_y;
                list_y<<16<<18<<20<<22<<24;
                int speed_x = list_x[qrand()%list_x.size()];
                int speed_y = list_y[qrand()%list_y.size()];
                //qDebug()<<"speed_x"<<speed_x;
                // qDebug()<<"speed_y"<<speed_y;

                switch(enemy_planes[i]->planeType)
                {

                case PLANE_TYPE_0://02��ɫ С�� ����ֵ 600������60
                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-026.png",scene,speed_x,speed_y));

                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);
                    break;

                case PLANE_TYPE_1:  //17��ɫ ���� ����ֵ 2000������350
                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-011-1.png",scene,0,speed_y));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+112,enemy_planes[i]->y()+180);

                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-011-1.png",scene,5,speed_y));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+112,enemy_planes[i]->y()+180);

                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-011-1.png",scene,-5,speed_y));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+112,enemy_planes[i]->y()+180);
                    break;
                case PLANE_TYPE_2:// 13��ɫ ����  ����ֵ 1800������300
                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-028.png",scene,0,speed_y*2));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+100-30,enemy_planes[i]->y()+130);

                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-028.png",scene,0,speed_y*2));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+100+30,enemy_planes[i]->y()+130);

                    break;
                case PLANE_TYPE_3:// 09��ɫ С�� ����ֵ 400������100
                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-025.png",scene,speed_x,speed_y));

                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);
                    break;
                case PLANE_TYPE_4:// 10��ɫ С�� ����ֵ 500������800
                    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/sucai-027.png",scene,speed_x,speed_y));
                    enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);
                    break;




                }

//                enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/bullet-101.png",scene,speed_x,speed_y));

//                enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);
            }
        }

    }


}

void gameView::enemy_plane_move()//�л��ƶ�
{
    //ѭ���ɻ�����
    //  qDebug()<<"enemy_planes.size():"<<enemy_planes.size();
    for(int i=0; i<enemy_planes.size(); i++)
    {
        if(enemy_planes[i]->cType == ENEMY_PLANE_TYPE)
        {
            //static int a=1;

            enemy_planes[i]->moveBy(enemy_planes[i]->xMove,enemy_planes[i]->yMove);


            if(enemy_planes[i]->x()<=0)//������߽磬�л�������
            {
                enemy_planes[i]->xMove  = -enemy_planes[i]->xMove ;//����ͬ���ٶ����������ƶ�
                enemy_planes[i]->yMove  = enemy_planes[i]->xMove%2?-enemy_planes[i]->xMove : enemy_planes[i]->xMove;
                // enemy_planes[i]->moveBy(2,1);
            }
            if(enemy_planes[i]->x()>widget_w-enemy_planes[i]->pixMap.width())//�����ұ߽磬�л�������
            {
                enemy_planes[i]->xMove  = -enemy_planes[i]->xMove ;//����ͬ���ٶ����������ƶ�
                enemy_planes[i]->yMove  = enemy_planes[i]->xMove%2?-enemy_planes[i]->xMove : enemy_planes[i]->xMove ;
                //enemy_planes[i]->yMove  = -1 ;
            }
            if(enemy_planes[i]->y()<=0)//�����ϱ߽磬�л�������
            {
                enemy_planes[i]->yMove  = -enemy_planes[i]->yMove ;//����ͬ���ٶ����������ƶ�

            }

            //            if(enemy_planes[i]->y()>10)
            //            {
            //               //enemy_planes[i]->xMove  = -2 ;
            //               enemy_planes[i]->yMove  = 1 ;
            //            }
            //            if(a==1)
            //            {
            //                qDebug()<<"a=1";
            //                enemy_planes[i]->moveBy(-2,-1);

            //            }
            //            else
            //            {
            //                 qDebug()<<"a!=1";
            //                enemy_planes[i]->moveBy(2,1);
            //            }

            if(enemy_planes[i]->y()>widget_h)
            {
                delete enemy_planes[i];
                //enemy_planes[i]->rremoveAt(i);
                enemy_planes.removeAt(i);

            }


            //�л�Ѫ����ʾ
            enemy_planes[i]->pProgressBar->setGeometry(100,100,100,5);

            //enemy_planes[i]->pProgressBar->setGeometry(enemy_planes[i]->x() +  enemy_planes[i]->pixMap.width()/4,enemy_planes[i]->y()+enemy_planes[i]->pixMap.height()+5,enemy_planes[i]->pixMap.width()/2,5);

            enemy_planes[i]->pProgressBar->setValue(100 *enemy_planes[i]->lifeValues/enemy_planes[i]->maxLifeValues);  // ��ǰ����
            if(enemy_planes[i]->lifeValues<=0)
            {
                enemy_planes[i]->pProgressBar->close();
            }




        }
    }

}


void gameView::my_bullet_produce()
{
    my_bullets.append(new  myBulletItem("MyPlane/images/bullet/bullet-126.png",scene));
    my_bullets.back()->setPos(myPlane->x()+36,myPlane->y()-80);
}
void gameView::deathBlast_produce(qreal x,qreal y)
 {

     death_Blasts.append(new deathBlastItem("MyPlane/images/DeathBlast/4.png",scene));
     death_Blasts.back()->setPos(x,y);
     deathBlast_sound->play();
 }
void gameView::deathBlast_disappear()
{

    for(int i = 0; i<death_Blasts.size(); ++i)
    {
        delete death_Blasts.at(i);
        death_Blasts.removeAt(i);
    }
}

void gameView::my_bullet_move()
{
    static int time = 0;
    time++;
    if(time==50)
    {
        enemy_plane_produce();
        time = 0;
    }
    enemy_plane_move();

    //�����ӵ�����
    for(int i = 0; i<my_bullets.size(); ++i)
    {
        // qDebug()<<my_bullets.size();
        my_bullets[i]->moveBy(0,-20);
    }
    if(my_bullets.size()>40)
    {
        if(my_bullets.at(1)->y()<0)
        {
            delete my_bullets.at(1);
            my_bullets.removeAt(1);
            //qDebug()<<"delete myBullet";
        }
    }


    //�л��ӵ����ƶ�
    for(int i= 0;i<enemy_bullets.size(); i++)
    {
        enemy_bullets[i]->moveBy(enemy_bullets[i]->x_speed,enemy_bullets[i]->y_speed);

    }

}

void gameView::my_bullet_colliding()
{

    int collidingFlag = 0;
    //�����ӵ�����
    for(int i = 0; i<my_bullets.size(); ++i)
    {
        if(my_bullets[i]->collidingItems().count()>0)
        {

            QList<QGraphicsItem *> list = my_bullets[i]->collidingItems();
            QList<QGraphicsItem *>::Iterator it;
            enemyPlaneItem *enemyPlane;
            it=list.begin();

            while(it!=list.end())//�����ҷ��ӵ�����ײ�б�
            {
                if(((PixmapItem *)(*it))->cType == ENEMY_PLANE_TYPE)
                {//����ײ�Ķ���Ϊ�з��ɻ�ʱ

                    enemyPlane= (enemyPlaneItem*)(*it);
                    //�����з��ɻ�����
                    for(int j = 0; j<enemy_planes.size(); ++j)
                    {
                        //�ж��ҵ���ײ�б�����ĵз��ɻ��ڵз��ɻ��б������λ�ã��ٽ���ɾ��
                        if(enemyPlane[j].plane_index == enemyPlane->plane_index)
                        {
                            enemyPlane->lifeValues -= myPlane->attackVlaue;//�л�����ֵ����
                            if(enemyPlane->lifeValues<=0)//�л�����ֵ����������
                            {

//                                deathBlast  = new deathBlastItem("MyPlane/images/DeathBlast/4.png",scene);
//                                deathBlast->setPos(enemyPlane->x(),enemyPlane->y());
//                                static int deathBlastCloseFlag =0;
//                                deathBlastCloseFlag++;
//                                if(deathBlastCloseFlag == 1000)
//                                {

//                                    delete deathBlast;
//                                    deathBlastCloseFlag= 0;
//                                }

                                deathBlast_produce(enemyPlane->x(),enemyPlane->y());
                                qDebug()<<"deathBlast new enemyPlane->x() , enemyPlane->x(),enemyPlane->y() "<<enemyPlane->x()<<enemyPlane->y();
                                delete enemy_planes.at(j);
                                enemy_planes.removeAt(j);
                                this->currentScore += enemyPlane->maxLifeValues/10;
                                //                              qDebug()<< " this->currentScore:"<<this->currentScore;
                                //                              qDebug()<< " enemyPlane->lifeValues:"<<enemyPlane->lifeValues;
                                QString str_currentScore = QString("��ǰ�÷֣� %1 ").arg(this->currentScore);
                                //                              qDebug()<<str_currentScore;
                                currentScoreLabel->setText(str_currentScore);
                                if(this->currentScore>this->HighScore.toInt())//��ǰ����������߷�
                                {qDebug()<<"��ǰ����������߷�";
                                    if(updateHighScore(this->userName,this->currentScore))
                                    {

                                        qDebug()<<"�޸����ݳɹ�";
                                    }

                                }

                                //delete deathBlast;
                                qDebug()<<"deathBlast delete";
                            }

                        }
                    }

                    collidingFlag = 1; //�����ӵ���ײ������ı�־λ

                    break;
                }
                it++;//������++
            }

            if(collidingFlag == 1)//ɾ���ӵ�
            {
                delete my_bullets.at(i);
                my_bullets.removeAt(i);



                collidingFlag == 0;
            }

        }

    }

}


void gameView::enemy_bullet_colliding()
{
    int collidingFlag = 0;
    //�����ӵ�����
    for(int i = 0; i<enemy_bullets.size(); ++i)
    {
        if(enemy_bullets[i]->collidingItems().count()>0)
        {

            QList<QGraphicsItem *> list = enemy_bullets[i]->collidingItems();
            QList<QGraphicsItem *>::Iterator it;
            myPlaneItem *myPlane;
            it=list.begin();

            while(it!=list.end())//�����ҷ��ӵ�����ײ�б�
            {
                if(((PixmapItem *)(*it))->cType == MY_PLANE_TYPE)
                {//����ײ�Ķ���Ϊ�з��ɻ�ʱ

                    myPlane= (myPlaneItem*)(*it);
                    myPlane->lifeValue -= enemy_bullets[i]->hurtValue;
                    int bloodBar = 100*myPlane->lifeValue/myPlane->maxLifeValue;
                    if(bloodBar<=0)
                    {
                        bloodBar=0;
                        deathBlast  = new deathBlastItem("MyPlane/images/DeathBlast/4.png",scene);
                        deathBlast->setPos(myPlane->x(),myPlane->y());
                        gameOver_sound->play();
                    }
                    pProgressBar->setValue(bloodBar);  // ����Ѫ��
                    enemy_bullet_blast_sound->play();
                    collidingFlag = 1; //�����ӵ���ײ������ı�־λ
                    break;
                }
                it++;//������++
            }

            if(collidingFlag == 1)//ɾ���ӵ�
            {
                delete enemy_bullets.at(i);
                enemy_bullets.removeAt(i);
                collidingFlag == 0;
            }

        }

    }



    //�ж��ҷ��ɻ��Ƿ������л�
    if(myPlane->collidingItems().count()>0)
    {

        QList<QGraphicsItem *> list2 = myPlane->collidingItems();
        QList<QGraphicsItem *>::Iterator it2;
        enemyPlaneItem *enemyPlane;
        it2=list2.begin();

        while(it2!=list2.end())//�����ҷ��ӵ�����ײ�б�
        {
            if(((PixmapItem *)(*it2))->cType == ENEMY_PLANE_TYPE)
            {//����ײ�Ķ���Ϊ�з��ɻ�ʱ

                enemyPlane= (enemyPlaneItem*)(*it2);
                myPlane->lifeValue -= enemyPlane->collidingHurt;
                int bloodBar2 = 100*myPlane->lifeValue/myPlane->maxLifeValue;
                if(bloodBar2<=0)
                {
                    bloodBar2=0;
                    deathBlast  = new deathBlastItem("MyPlane/images/DeathBlast/4.png",scene);
                    deathBlast->setPos(myPlane->x(),myPlane->y());
                    gameOver_sound->play();
                }
                pProgressBar->setValue(bloodBar2);  // ����Ѫ��
                enemy_bullet_blast_sound->play();

            }
            it2++;//������++
        }

    }

    if(myPlane->lifeValue<=0)//���ҷ��ɻ�����
    {
        myPlane->hide();
         stopAllTimer();
          //QMessageBox::information(this,"��Ϸ����","���ز˵�");
        GameOver->showLabels(this->currentScore,this->HighScore.toInt());
        GameOver->showRanking();
        //delete this;
        GameOver->show();
        //emit backGameWidget_signal();

    }

}

void gameView::enemy_planes_pProgressBar_slot()
{
    qDebug()<<"enemy_planes_pProgressBar_show";
    //�����з��ɻ��б�
    for(int j = 0; j<enemy_planes.size(); ++j)
    {

        //->setPos(mapToScene(myPlane->pos().x()-distance,myPlane->pos().y()));
        qreal x_bar = mapToScene(enemy_planes[j]->pos().x(),enemy_planes[j]->pos().y()).x();
         qreal y_bar = mapToScene(enemy_planes[j]->pos().x(),enemy_planes[j]->pos().y()).y();
         qDebug()<<"x_bar"<<x_bar;
         qDebug()<<"y_bar"<<y_bar;
        //enemy_planes[j]->pProgressBar->setGeometry(enemy_planes[j]->x()+enemy_planes[j]->pixMap.width()/4,enemy_planes[j]->y()+enemy_planes[j]->pixMap.height()+5,enemy_planes[j]->pixMap.width()/2,5);
        enemy_planes[j]->pProgressBar->setGeometry(x_bar,y_bar,enemy_planes[j]->pixMap.width()/2,5);

        enemy_planes[j]->pProgressBar->setValue(100 *enemy_planes[j]->lifeValues/enemy_planes[j]->maxLifeValues);  // ��ǰ����
        if(enemy_planes[j]->lifeValues<=0)
        {
            enemy_planes[j]->pProgressBar->close();
        }
    }


}

// void gameView::stopGameBtn_clicked()
// {

//     if(!this->stopGameFlag)//��Ϸ��ʼ״̬
//     {
//         this->timer1->stop();
//         this->timer2->stop();
//         this->timer3->stop();
//         stopGameBtn->hide();
//         startGameBtn->show();
//         stopGameFlag = stopGameFlag?false:true;//stopGameFlagȡ��
//     }
//    else//��Ϸ��ͣ״̬
//     {
//         this->timer1->start();
//         this->timer2->start();
//         this->timer3->start();
//          startGameBtn->hide();
//         stopGameBtn->show();

//         stopGameFlag = stopGameFlag?false:true;//stopGameFlagȡ��
//     }

// }
bool  gameView::updateHighScore(QString userName,int highScore)
{
    QString str_sql =QString("update user set highScore = %1 where name = '%2'").arg(highScore).arg(userName);
    if(myDatabase::Instance()->executeSql(str_sql))
    {
        return true;
    }
    return false;

}


void gameView::sleep() //��ʱ����
{
    QTime dieTime = QTime::currentTime().addMSecs(1); //��ʱ
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//void sleep(unsigned int msec)
//{
//QTime dieTime = QTime::currentTime().addMSecs(msec);
//while( QTime::currentTime() < dieTime )
//QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//}
//void gameView::stopGameBtn_clicked()
//{
//    //StopTimer->stop();
//    StopTimer->start(25);
//}

//void gameView::startGameBtn_clicked()
//{

//    StopTimer->start(25);
//}
void gameView::closeBtn_clicked()
{

    stopAllTimer();
    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","����ǰ�ķ����ѱ����棬���Ƿ�ȷ���˳���",QMessageBox::Yes|QMessageBox::No))
    {
        exit(0);
    }
    else
    {
        startAllTimer();
    }
}


void gameView::backHomeBtn_clicked()
{

          //��gamewidget���ڷ����ź�

    qDebug()<<"���ز˵�����";
    stopAllTimer();
    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","����ǰ�ķ����ѱ����棬���Ƿ�ȷ���˳���",QMessageBox::Yes|QMessageBox::No))
    {
       emit backGameWidget_signal();
    }
    else
    {
        startAllTimer();
    }

}

void gameView::stopAllTimer()
{
    timer1->stop();
    timer2->stop();
    timer3->stop();

}

void gameView::startAllTimer()
{

    timer1->start(25);
    timer2->start(25);
    timer3->start(25);


}


void gameView::planeShow()
{

    switch(planeChooseFlag)
    {
    case 1:
        delete myPlane;//�ͷŵ�ԭ���ɻ����ڴ棨����ԭ���ķɻ�Ҳ����֣�
        myPlane  = new myPlaneItem("MyPlane/images/PLAYER/Anim_Plane_01/3.png",scene);
        myPlane->setPos(this->width()/2-myPlane->pixMap.width()/2,this->height()-200);

        break;
    case 2:
        delete myPlane;//�ͷŵ�ԭ���ɻ����ڴ棨����ԭ���ķɻ�Ҳ����֣�
        myPlane  = new myPlaneItem("MyPlane/images/PLAYER/Anim_Plane_04/3.png",scene);
        myPlane->setPos(this->width()/2-myPlane->pixMap.width()/2,this->height()-200);

        break;

    case 3:
        delete myPlane;//�ͷŵ�ԭ���ɻ����ڴ棨����ԭ���ķɻ�Ҳ����֣�
        myPlane  = new myPlaneItem("MyPlane/images/PLAYER/Anim_Plane_05/3.png",scene);
        myPlane->setPos(this->width()/2-myPlane->pixMap.width()/2,this->height()-200);

        break;

    case 4:
        delete myPlane;//�ͷŵ�ԭ���ɻ����ڴ棨����ԭ���ķɻ�Ҳ����֣�
        myPlane  = new myPlaneItem("MyPlane/images/PLAYER/Anim_Plane_06/3.png",scene);
        myPlane->setPos(this->width()/2-myPlane->pixMap.width()/2,this->height()-200);

        break;
    }
}

void gameView::gameOver_slot()
{
    delete GameOver;
    emit backGameWidget_signal();
}

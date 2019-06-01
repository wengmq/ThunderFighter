#include "enemyPlaneItem.h"

enemyPlaneItem::enemyPlaneItem(const QString &fileName,QGraphicsScene*scene,int plane_index,int lifeValues,int collidingHurt,int xMove,int yMove,int planeType):
    PixmapItem(fileName,scene, ENEMY_PLANE_TYPE)
{
        this->plane_index = plane_index;
        this->lifeValues = lifeValues;
        this->collidingHurt = collidingHurt;
        this->maxLifeValues = lifeValues;
        this->xMove =  xMove ;
        this->yMove =  yMove ;
        this->planeType = planeType;

        pProgressBar = new QProgressBar();
        pProgressBar->setOrientation(Qt::Horizontal);  // ˮƽ����
        pProgressBar->setMinimum(0);  // ��Сֵ
        pProgressBar->setMaximum(100);  // ���ֵ
        pProgressBar->setValue(100);  // ��ǰ����
        pProgressBar->setStyleSheet("{border:2px solid red;border-radius:5px;text-align:center;}");

}



//void enemyPlaneItem::advance(int phase)
//{

//    pProgressBar->setGeometry(this->mapToScene(0,0).x()+this->pixMap.width()/4,this->mapToScene(0,0).y()+this->pixMap.height()+5,this->pixMap.width()/2,10);

//    pProgressBar->setValue(100 *this->lifeValues/this->maxLifeValues);  // ��ǰ����
//    if(this->lifeValues<=0)
//    {
//        pProgressBar->close();
//    }
//}
//void enemyPlaneItem::advance(int phase)
//{
//    //�����߽�����µ�
//    if(mapToScene(0,0).y()>=1024 || mapToScene(0,0).x()>=580)
//    {
//        this->plane_back();//�ɻ��ص���ʼλ��
//    }

//     //enemy_plane_produce();//�����л�
//     //enemy_plane_move();//�л��ƶ�
////    QTime time;//���������
////    time = QTime::currentTime();
////    qsrand(time.msec()+time.second()*1000);
////     //qDebug()<<enemy_planes.size();

//    int speed=qrand()%10;//�����ٶ�0-10
//    this->setPos(mapToScene(2,speed));//�����·��ƶ�

//    static int a=1;
//    if(mapToScene(0,0).x()<10)
//    {
//        a = 2;
//    }
//    if(mapToScene(0,0).x()>500)
//    {
//        a = 1;
//    }
//    if(a==1)
//    {
//        //this->moveBy(-5,-1);
//        this->setPos(mapToScene(-5,-1));

//    }
//    else
//    {
//        this->setPos(mapToScene(5,1));
//        //this->moveBy(5,1);
//    }

////    enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/Bullet_1.png",scene));
////    enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);

//    enemyBulletItem *enemyBullet = new enemyBulletItem("MyPlane/images/bullet/bullet-110.png",scene);
//    enemyBullet->setPos(this->pos().x(),this->pos().y()+50);

//}
 void enemyPlaneItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
 {
    painter->drawPixmap(0,0,this->pixMap);

 }

 void enemyPlaneItem::plane_back()//�ɻ��ص���ʼλ�ã�������
 {
     setPos(qrand()%580,-300);
 }

// void enemyPlaneItem::enemy_plane_produce()//�����л�
// {
//         QTime time;//���������
//         time = QTime::currentTime();
//         qsrand(time.msec()+time.second()*1000);
//         qDebug()<<enemy_planes.size();
//         if(enemy_planes.size()<1)
//         {
//             enemy_planes.append(new enemyPlaneItem("MyPlane/images/ENEMY1/Anim_Enemy_02.png",scene));
//             enemy_planes.back()->setPos(200,300);
//             qDebug()<<"x ="<<enemy_planes.back()->pos().x()<<"y = "<<enemy_planes.back()->pos().y();
//         }


//         //�����л��ӵ�
//         if(enemy_planes.size()>0)
//         {
//             for(int i = enemy_planes.size()-1;  i>-1;  i++)
//             {
//                 if(enemy_planes[i]->Type == ENEMY_PLANE_TYPE)
//                 {
//                     enemy_bullets.append(new  enemyBulletItem("MyPlane/images/bullet/Bullet_1.png",scene));
//                     enemy_bullets.back()->setPos(enemy_planes[i]->x()+18,enemy_planes[i]->y()+90);
//                 }
//             }

//         }


// }
// void enemyPlaneItem::enemy_plane_move()//�л��ƶ�
// {

//     for(int i=0; i<enemy_planes.size(); i++)
//     {
//         if(enemy_planes[i]->Type == ENEMY_PLANE_TYPE)
//         {
//             static int a=1;
//             if(enemy_planes[i]->x()<10)
//             {
//                 a = 2;
//             }
//             if(enemy_planes[i]->x()>500)
//             {
//                 a = 1;
//             }
//             if(a==1)
//             {
//                 enemy_planes[i]->moveBy(-2,-1);

//             }
//             else
//             {
//                 enemy_planes[i]->moveBy(2,1);
//             }

//         }
//     }

// }

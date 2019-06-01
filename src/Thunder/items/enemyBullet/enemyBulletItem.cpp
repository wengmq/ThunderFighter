#include "enemyBulletItem.h"

enemyBulletItem::enemyBulletItem(const QString &fileName,QGraphicsScene*scene, int x_speed ,int y_speed,int hurtValue):
    PixmapItem(fileName,scene ,ENEMY_BULLET_TYPE)
{
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->hurtValue =  hurtValue;

}
//void enemyBulletItem::advance(int phase)
//{

////    QTime time;//随机数种子
////    time = QTime::currentTime();
////    qsrand(time.msec()+time.second()*1000);
////     //qDebug()<<enemy_planes.size();


//    if(mapToScene(0,0).y()<=0 ||mapToScene(0,0).x()<=0 || mapToScene(0,0).x()>=580 || mapToScene(0,0).y()>=1024)
//    {
//        delete this;
//    }
//    else
//    {
//        this->setPos(mapToScene(0,20));
//    }


//}

void enemyBulletItem::doColliding()
{
//    Qnet *net = new Qnet("fish_image/net1.png",this->scene );

//    net->setPos(mapToScene(0,0));
//    delete this;
}

void enemyBulletItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{

    painter->drawPixmap(0,0,this->pixMap);
//    if(this->collidingItems().count()>0)
//        {
//            doColliding();
//        }

}

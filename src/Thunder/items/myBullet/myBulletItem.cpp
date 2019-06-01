#include "myBulletItem.h"

myBulletItem::myBulletItem(const QString &fileName,QGraphicsScene*scene ):
    PixmapItem(fileName,scene ,MY_BULLET_TYPE)
{



}

//void myBulletItem::advance(int phase)
//{
//    if(mapToScene(0,0).y()<=0 ||mapToScene(0,0).x()<=0 || mapToScene(0,0).x()>=580 || mapToScene(0,0).y()>=1024)
//    {
//        delete this;
//        return;
//    }
//    else
//    {
//            //qDebug()<<"setPos"<<this->y()<<"x:"<<this->x();
//            this->setPos(mapToScene(0,-20));
//    }

//    if(this->collidingItems().count()>0)
//    {
//       // qDebug()<<11111;
//        QList<QGraphicsItem *> list = this->collidingItems();
//        QList<QGraphicsItem *>::Iterator i;
//        enemyPlaneItem *enemyPlane;
//        i=list.begin();
//       // qDebug()<<22222;
//        while(i!=list.end())
//        {
//            if(((PixmapItem *)(*i))->cType != ENEMY_PLANE_TYPE)
//            {
//               // qDebug()<<3333;
//                i++;
//                continue;
//            }
//            else
//            {
//           //  qDebug()<<4444;
//            enemyPlane= (enemyPlaneItem*)(*i);

//            // qDebug()<<555;
//            enemyPlane->plane_back();
//             //qDebug()<<666<<this->Type;
//             delete this;
//             i++;
//            }

//        }

//    }

//    this->hide();
//    delete this;


//}

void myBulletItem::doColliding()
{
//    Qnet *net = new Qnet("fish_image/net1.png",this->scene );

//    net->setPos(mapToScene(0,0));
//    delete this;
}

void myBulletItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{

    painter->drawPixmap(0,0,this->pixMap);
//    if(this->collidingItems().count()>0)
//        {
//            doColliding();
//        }

}

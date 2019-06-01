#include "myPlaneItem.h"

myPlaneItem::myPlaneItem(const QString &fileName,QGraphicsScene*scene,int lifeValue,int attackVlaue ):
    PixmapItem(fileName,scene ,MY_PLANE_TYPE)
{
    this->lifeValue = lifeValue;
    this->maxLifeValue= lifeValue;
    this->attackVlaue =  attackVlaue;

}
//QRectF  myPlaneItem::boundingRect() const
//{
//     return QRectF(-33,-88,66,88);
//}

void myPlaneItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{

    painter->drawPixmap(0,0,this->pixMap);
}
void myPlaneItem::advance(int phase)
{

//          //控制左移
//        if(leftMoveFlag == true && mapToScene(0,0).x()>=0)
//        {
////            this->setX(5);
//            this->setPos(mapToScene(5,0));
//        }

//        //控制右移
//        if(rightMoveFlag == true && mapToScene(0,0).x()<=580)
//        {
////            this->setX(-5);
//            this->setPos(mapToScene(-5,0));
//        }

//        //控制上移
//        if(upMoveFlag == true && mapToScene(0,0).y()>=0)
//        {
////            this->setY(-5);
//            this->setPos(mapToScene(0,5));
//        }
//        if(downMoveFlag == true && mapToScene(0,0).y()<=1024)
//        {
////           this->setY(5);
//            this->setPos(mapToScene(0,-5));
//        }



}



//void myPlaneItem::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_A)
//    {
//        qDebug()<<"left";
////        leftMoveFlag = true;
////        rightMoveFlag = false;// 左右不能同移
//    this->setPos(mapToScene(5,0));
//    }
//    else if (event->key() == Qt::Key_Right)
//    {
//        qDebug()<<"right";
////        leftMoveFlag = false;// 左右不能同移
////        rightMoveFlag = true;
//         this->setPos(mapToScene(-5,0));
//    }
//    else if (event->key() == Qt::Key_Up)
//    {
//        qDebug()<<"up";
////        upMoveFlag = true;
////        downMoveFlag = false;// 上下不能同移
//     this->setPos(mapToScene(0,5));
//    }
//    else if (event->key() == Qt::Key_Down)
//    {
//        qDebug()<<"down";
////        upMoveFlag = false;// 上下不能同移
////        downMoveFlag = true;
//        this->setPos(mapToScene(0,-5));
//    }

//}

//void myPlaneItem::keyReleaseEvent(QKeyEvent *event)
//{

//    if (event->key() == Qt::Key_Left)
//    {
//        leftMoveFlag = false;
//    }
//    else if (event->key() == Qt::Key_Right)
//    {
//        rightMoveFlag = false;
//    }
//    else if (event->key() == Qt::Key_Up)
//    {
//        upMoveFlag = false;
//    }
//    else if (event->key() == Qt::Key_Down)
//    {
//        downMoveFlag = false;
//    }
//}


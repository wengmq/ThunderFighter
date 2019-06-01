#ifndef MYBULLETITEM_H
#define MYBULLETITEM_H
#include "../pixmapitem.h"

#include"../enemyPlane/enemyPlaneItem.h"
#include <QList>
#include<QDebug>
#include<QVariant>
class myBulletItem:public PixmapItem
{
public:

    myBulletItem(const QString &fileName,QGraphicsScene*scene );
   // void advance(int phase);
    void doColliding();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

};

#endif // MYBULLETITEM_H

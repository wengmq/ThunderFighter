#ifndef ENEMYBULLETITEM_H
#define ENEMYBULLETITEM_H
#include "../pixmapitem.h"
class enemyBulletItem:public PixmapItem
{
public:

    enemyBulletItem(const QString &fileName,QGraphicsScene*scene,int x_speed = 3,int y_speed=8,int hurtValue = 1000 );
   // void advance(int phase);
    void doColliding();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    int hurtValue;
    int x_speed;
    int y_speed;


};

#endif // ENEMYBULLETITEM_H

#ifndef MYPLANEITEM_H
#define MYPLANEITEM_H
#include "../pixmapitem.h"
#include <QDebug>
class myPlaneItem:public PixmapItem
{
public:
    myPlaneItem(const QString &fileName,QGraphicsScene*scene,int lifeValue = 10000,int attackVlaue = 100);

    //QRectF boundingRect() const;
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      void advance(int phase);

      int lifeValue;
      int maxLifeValue;
      int attackVlaue;
      //void keyPressEvent(QKeyEvent *event);
//      void keyReleaseEvent(QKeyEvent *event);

private:
      bool leftMoveFlag;
      bool rightMoveFlag;
      bool upMoveFlag;
      bool downMoveFlag;
};

#endif // MYPLANEITEM_H

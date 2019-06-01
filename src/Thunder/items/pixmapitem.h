#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#define MY_PLANE_TYPE 0
#define MY_BULLET_TYPE 1
#define ENEMY_PLANE_TYPE 2
#define ENEMY_BULLET_TYPE 3
#define DEATH_BLAST_TYPE 4

#include <QGraphicsItem>
#include <QtGui>
#include <QString>
#include <QPixmap>

//图元基类
class PixmapItem:public QGraphicsItem
{
    //把所有的图元都加到一个场景，支持碰撞检测，边缘检测，重绘图元
public:

    //传入的图片路径及文件名、要添加到的场景、图元类型
    PixmapItem(const QString &fileName,QGraphicsScene*scene ,int cType);

    //边缘检测
    QRectF boundingRect() const;

    //重绘图元
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    QSizeF size();
    int cType;
public:
    QPixmap pixMap;
    QGraphicsScene *scene;

};

#endif // PIXMAPITEM_H

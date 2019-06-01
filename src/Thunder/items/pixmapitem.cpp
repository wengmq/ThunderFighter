#include "pixmapitem.h"

PixmapItem::PixmapItem(const QString &fileName,QGraphicsScene*scene ,int cType)
{
    //给类成员赋值
    this->pixMap = fileName;
    this->scene = scene;
    this->cType = cType;

    //把图元添加到场景里面
    scene->addItem(this);


}

//边缘检测
QRectF  PixmapItem::boundingRect() const
{
    //从原点坐标开始，大小是图片的大小
     return QRectF(QPointF(0,0),this->pixMap.size());
}

void PixmapItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //绘制图片，从0,0开始绘制
    painter->drawPixmap(0,0,this->pixMap);
}

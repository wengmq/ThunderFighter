#include "pixmapitem.h"

PixmapItem::PixmapItem(const QString &fileName,QGraphicsScene*scene ,int cType)
{
    //�����Ա��ֵ
    this->pixMap = fileName;
    this->scene = scene;
    this->cType = cType;

    //��ͼԪ��ӵ���������
    scene->addItem(this);


}

//��Ե���
QRectF  PixmapItem::boundingRect() const
{
    //��ԭ�����꿪ʼ����С��ͼƬ�Ĵ�С
     return QRectF(QPointF(0,0),this->pixMap.size());
}

void PixmapItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //����ͼƬ����0,0��ʼ����
    painter->drawPixmap(0,0,this->pixMap);
}

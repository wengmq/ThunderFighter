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

//ͼԪ����
class PixmapItem:public QGraphicsItem
{
    //�����е�ͼԪ���ӵ�һ��������֧����ײ��⣬��Ե��⣬�ػ�ͼԪ
public:

    //�����ͼƬ·�����ļ�����Ҫ��ӵ��ĳ�����ͼԪ����
    PixmapItem(const QString &fileName,QGraphicsScene*scene ,int cType);

    //��Ե���
    QRectF boundingRect() const;

    //�ػ�ͼԪ
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    QSizeF size();
    int cType;
public:
    QPixmap pixMap;
    QGraphicsScene *scene;

};

#endif // PIXMAPITEM_H

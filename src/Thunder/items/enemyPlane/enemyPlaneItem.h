#ifndef ENEMYPLANEITEM_H
#define ENEMYPLANEITEM_H
#include<QTimer>
#include<QTime>
#include <QList>
#include "../pixmapitem.h"
#include"../enemyBullet/enemyBulletItem.h"
#include<QProgressBar>
#define PLANE_TYPE_0  0
#define PLANE_TYPE_1  1
#define PLANE_TYPE_2  2
#define PLANE_TYPE_3  3
#define PLANE_TYPE_4  4
class enemyPlaneItem:public PixmapItem
{
public:
    enemyPlaneItem(const QString &fileName,QGraphicsScene*scene,int plane_index,int lifeValues = 600,int collidingHurt = 60,int xMove = 3,int yMove =3,int planeType = PLANE_TYPE_0 );

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //void advance(int phase);
    void plane_back();
//    void enemy_plane_produce();//�����л�
//    void enemy_plane_move();//�л��ƶ�

//    QList<enemyPlaneItem *> enemy_planes; //�л�����
//    QList<enemyBulletItem *> enemy_bullets;  //�л��ӵ�����
    QProgressBar *pProgressBar;
    int planeType;
    int collidingHurt;
    int plane_index;
    int lifeValues;
    int maxLifeValues;
    int xMove;
    int yMove;
};

#endif // ENEMYPLANEITEM_H

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include<QPainter>
#include <QVariant>
#include<QTimer>
#include<QTime>
#include"../dataBase/myDatabase.h"
#include "../items/myBullet/myBulletItem.h"
#include "../items/myPlane/myPlaneItem.h"
#include "../items/enemyPlane/enemyPlaneItem.h"
#include "../items/enemyBullet/enemyBulletItem.h"
#include"../items/deathBlast/deathBlastItem.h"
#include<QProgressBar>
#include<QMessageBox>
#include <QSound>
#include"gameOver.h"
class gameView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit gameView(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
   void mousePressEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);

    bool updateHighScore(QString userName,int highScore);

     QList<myBulletItem *> my_bullets;  //�л��ӵ�����
     QList<enemyPlaneItem *> enemy_planes; //�л�����
     QList<enemyBulletItem *> enemy_bullets;  //�л��ӵ�����
     QList<deathBlastItem *> death_Blasts;  //��ըͼ����

     QTimer *timer1;
     QTimer *timer2;
     QTimer *timer3;
     QTimer *timer4;
     QTimer *advancedTimer;
     QTimer *ProgressBarTimer;
     QTimer *StopTimer;

     QString userName;
     QString HighScore;

     void stopAllTimer();
     void startAllTimer();
     void planeShow();

     gameOver *GameOver;

signals:
      void backGameWidget_signal();


public slots:
     void enemy_plane_produce();//�����л�
     void enemy_plane_move();//�л��ƶ�
//     void plane_move();
     void my_bullet_produce();
     void my_bullet_move();
     void my_bullet_colliding();
     void enemy_bullet_colliding();
     void enemy_planes_pProgressBar_slot();
//     void stopGameBtn_clicked();
//     void startGameBtn_clicked();
    void sleep(); //��ʱ����

    void closeBtn_clicked();
    void backHomeBtn_clicked();

    void deathBlast_produce(qreal x,qreal y);
    void deathBlast_disappear();
    void gameOver_slot();
private:

    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��

    QGraphicsScene *scene;
    QTimer *timer;
    myPlaneItem *myPlane;
    bool mousePressFlag ;

    enemyPlaneItem *enemyPlane1;
    enemyPlaneItem *enemyPlane2;
    enemyPlaneItem *enemyPlane3;
    enemyPlaneItem *enemyPlane4;

    bool isMovingFlag;
    QProgressBar *pProgressBar;
    //QProgressBar *enemy_plane_pProgressBar;
    bool stopGameFlag;

    int widget_w;
    int widget_h;

    int currentScore;
    QLabel *currentScoreLabel;

//    QPushButton *stopGameBtn;
//     QPushButton *startGameBtn;
     QPushButton *closeBtn;
    QPushButton *backHomeBtn;
    bool stopAllTimerFlag;
    deathBlastItem  *deathBlast;
    QSound *my_bullet_launch_sound;
    QSound *enemy_bullet_blast_sound;
    QSound *deathBlast_sound;
   QSound * gameOver_sound;
};

#endif // GAMEVIEW_H

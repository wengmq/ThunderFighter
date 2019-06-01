#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H


#include <QPropertyAnimation>
#include <QLabel>
#include <QParallelAnimationGroup>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include<QIcon>
#include <QtGui/QApplication>
#include <QDesktopWidget>
#include"gameView.h"
#include"../dataBase/myDatabase.h"
#include<QPalette>
#include<QFont>
#include<QTimer>
#include <QMouseEvent>
#include "../other/myMessageBox.h"
#include<Phonon/VideoPlayer>
#include"gameOver.h"
class gameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gameWidget(QWidget *parent = 0);

    QString UserName;
    QString HighScore;
    int newUserFlag;
    void setUserName(QString name);

    void  mousePressEvent(QMouseEvent *event);//����������¼�
    void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
    //void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��




    void gameStart();

    QLabel *HighScoreLabel;
    bool gameStartFlag;
    void count_down();
    gameView *GameView;

    void setBackground();
     void newUserGuide();
signals:

    void backHome_signal();
public slots:
    //void closeBtn_clicked();
    void backHome_slot();
    void count_down_slot();
    void labelChange_slot();
    void GamestartPlay();
    void musicPlay();


private:

     QPushButton *closeBtn;
    QPushButton *backHomeBtn;
    QPushButton *guideSureBtn;
    QPixmap pixmap1;
    QPixmap pixmap2;
    QPixmap pixmap3;
    QPixmap pixmap4;

    QTimer *time;

    QLabel *lab1;
    QLabel *lab2;

    QString mapFinal_str;

    int lightFlag;
    QLabel *labelPixmap;
    int labelChangeFlag;




};

#endif // GAMEWIDGET_H

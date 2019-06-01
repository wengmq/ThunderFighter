#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QIcon>
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include<QPainter>
#include"../dataBase/myDatabase.h"
class gameOver : public QWidget
{
    Q_OBJECT
public:
    explicit gameOver(QWidget *parent = 0);
//    void  mousePressEvent(QMouseEvent *event);
//    void  mouseMoveEvent(QMouseEvent *event);
    void paintEvent( QPaintEvent* ) ;

    void showLabels(int currentScore,int highScore);
    void showRanking();

signals:
    void backGameView_signal();
public slots:
    void sureBtn_clicked();
private:
    QPushButton *sureBtn;
//    QPoint windowPos;     // 获得部件当前位置
//    QPoint mousePos;     // 获得鼠标位置
//    QPoint dPos ;

    QLabel *No1_Label;
    QLabel *No2_Label;
    QLabel *No3_Label;

    QLabel *currentLabel;
    QLabel *highLabel;

};

#endif // GAMEOVER_H

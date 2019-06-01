#ifndef MENUWIDGET_H
#define MENUWIDGET_H

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
#include <QVBoxLayout>
#include "../dataBase/myDatabase.h"
#include "../menu/helpWidget.h"
#include "rankingWidget.h"
#include "setupWidget.h"
#include "../game/gameWidget.h"
#include"mapWidget.h"
//#include <QDialog>
//#include <WindowFlags>
class menuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit menuWidget(QWidget *parent = 0);
    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置

    QString userName;
    void planePicShow();
signals:
    void backLoginSignal();


public slots:
    void backLoginSlot();
    //void helpBackSlot();
    void helpBtn_clicked();
    void setupBtn_click();
    void RanKingBtn_clicked();
    void startBtn_clicked();
    void closeEvent(QCloseEvent *CloseEvent);
    void gameBack_slot();
    void leftBtn_clicked();
    void rightBtn_clicked();
    void closeBtn_click();
    void mapBtn_clicked();
private:
        QLabel *labelPic1;
        QLabel *labelPic2;
        QLabel *labelPic3;
        QMovie *movie1;
         QMovie *movie2;
          QMovie *movie3;
        QPushButton *startBtn;
        QPushButton *RanKingBtn;
        QPushButton *helpBtn;
        QPushButton *setupBtn;
        QPushButton *logoutBtn;
         QPushButton *mapBtn;
        QPushButton *closeBtn;
        QVBoxLayout *vboxlayout;
        helpWidget *helpInterface;
        setupWidget *setupInterface;
        rankingWidget * rankingInterface;
        QPushButton *leftBtn;
        QPushButton *rightBtn;
        gameWidget * gameInterface;
        mapWidget *mapInterface;
        QLabel *planePic1;
        QLabel *planePic2;
        QLabel *planePic3;
        QLabel *planePic4;

};

#endif // MENUWIDGET_H

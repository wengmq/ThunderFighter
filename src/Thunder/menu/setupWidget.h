#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

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
#include <QSound>
#include <QComboBox>
class setupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit setupWidget(QWidget *parent = 0);

    void showMusicBtn();
    void showGuideBtn();
    void showDifficultyBtn();

    void  mousePressEvent(QMouseEvent *event);//重载鼠标点击事件
    void  mouseMoveEvent(QMouseEvent *event);//重载鼠标移动事件
    void paintEvent(QPaintEvent *event);  //重载画图事件
    QPoint windowPos;     // 获得部件当前位置
    QPoint mousePos;     // 获得鼠标位置
    QPoint dPos ;        // 移动后部件所在的位置
signals:

public slots:
    void musicBtn_clicked();
    void guideBtn_clicked();
    void difficultyBtn_clicked();

private:

    QPushButton *musicBtn;
    QPushButton *guideBtn;
    QPushButton *difficultyBtn;
    QPushButton *closeBtn;

};

#endif // SETUPWIDGET_H

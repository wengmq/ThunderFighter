#include "helpWidget.h"

helpWidget::helpWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(450,450);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

   // this->setAutoFillBackground(false);  //这个不设置的话就背景变黑
    this->setWindowFlags(Qt::FramelessWindowHint);//去边框
    this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

    //设置背景图片
//    bgLabel =new QLabel(this) ;
//     bgLabel->setGeometry(0,0,450,450);
//    bgLabel->setStyleSheet("QLabel{border-image:url(MyPlane/images/widget/03_1.png);}");

//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/03_1.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,25,35,35);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(35,35));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

}
//void helpWidget::backBtn_clicked()
//{
//    qDebug()<<"这是帮助！";
//    emit backMenuSignal();
//}

void helpWidget::mousePressEvent(QMouseEvent *event)
{

     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void helpWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}

void helpWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,450,450,QPixmap("MyPlane/images/widget/help11.png"));

}

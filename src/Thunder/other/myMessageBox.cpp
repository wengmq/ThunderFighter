#include "myMessageBox.h"

myMessageBox::myMessageBox(QString bgPic,QWidget *parent):QMessageBox(parent)
                                                         ,m_width(0)
                                                         ,m_high(0)
{

    this->bgPic = bgPic;
    //设置本地编码 头文件 #include <QTextCodec> //编码
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //box1 = new myMessageBox(this);
   this->AutoSetSize(500,756);
    this->setWindowTitle(  QObject::tr("新手引导提示！！" ));
   this->setIcon(QMessageBox::NoIcon);//设置无提示图标
   this->setWindowIcon(QIcon("MyPlane/images/game.ico"));
   this->setbgPix(this->bgPic);
   QPushButton *btn_sure = this->addButton( "" ,QMessageBox::ActionRole);
   btn_sure->setIcon(QIcon("MyPlane/images/btn/ikonw.png"));
   btn_sure->setIconSize(QSize(159,56));
   btn_sure->setFocusPolicy(Qt::NoFocus);
   btn_sure->setFlat(true);
   //去除点击按钮后出现的白色部分
   btn_sure->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
   this->exec();


}


void myMessageBox::AutoSetSize(int width, int high)
{
    m_width = width;
    m_high  = high;
}

void myMessageBox::resizeEvent(QResizeEvent *event)
{
    setFixedSize(m_width,m_high);
}
void myMessageBox::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,m_width,m_high,QPixmap(this->bgPic));
}
void myMessageBox::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void myMessageBox::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void myMessageBox::setbgPix(QString bgPic)
{

    this->bgPic = bgPic;
}

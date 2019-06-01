#include "myMessageBox.h"

myMessageBox::myMessageBox(QString bgPic,QWidget *parent):QMessageBox(parent)
                                                         ,m_width(0)
                                                         ,m_high(0)
{

    this->bgPic = bgPic;
    //���ñ��ر��� ͷ�ļ� #include <QTextCodec> //����
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //box1 = new myMessageBox(this);
   this->AutoSetSize(500,756);
    this->setWindowTitle(  QObject::tr("����������ʾ����" ));
   this->setIcon(QMessageBox::NoIcon);//��������ʾͼ��
   this->setWindowIcon(QIcon("MyPlane/images/game.ico"));
   this->setbgPix(this->bgPic);
   QPushButton *btn_sure = this->addButton( "" ,QMessageBox::ActionRole);
   btn_sure->setIcon(QIcon("MyPlane/images/btn/ikonw.png"));
   btn_sure->setIconSize(QSize(159,56));
   btn_sure->setFocusPolicy(Qt::NoFocus);
   btn_sure->setFlat(true);
   //ȥ�������ť����ֵİ�ɫ����
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
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void myMessageBox::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void myMessageBox::setbgPix(QString bgPic)
{

    this->bgPic = bgPic;
}

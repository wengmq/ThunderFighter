#include "gameOver.h"

gameOver::gameOver(QWidget *parent) :
    QWidget(parent)
{

    this->setFixedSize(700,800);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
   // this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

   // this->setAutoFillBackground(false);  //这个不设置的话就背景变黑
    this->setWindowFlags(Qt::FramelessWindowHint);//去边框
    this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明


//    closeBtn = new QPushButton(this);
//    closeBtn->setGeometry(this->width()-55,25,35,35);
//    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
//    closeBtn->setIconSize(QSize(35,35));
//    closeBtn->setFocusPolicy(Qt::NoFocus);
//    closeBtn->setFlat(true);
//    //去除点击按钮后出现的白色部分
//    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
//    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

    QFont ft;
    ft.setPointSize(18);

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);


    int x0 = 120;
    int y0 = 300;
    int distance = 150;

    No1_Label = new QLabel(this);
    No1_Label->setGeometry(x0,(y0+distance*0)+5,this->width(),50);
    No1_Label->setFont(ft);
    No1_Label->setPalette(pa);

    No2_Label = new QLabel(this);
    No2_Label->setGeometry(x0,(y0+distance*1),this->width(),50);
    No2_Label->setFont(ft);
    No2_Label->setPalette(pa);

    No3_Label = new QLabel(this);
    No3_Label->setGeometry(x0,(y0+distance*2)-10,this->width(),50);
    No3_Label->setFont(ft);
    No3_Label->setPalette(pa);

    currentLabel = new QLabel(this);
    currentLabel->setGeometry(50,this->height()-50,this->width(),50);
    currentLabel->setFont(ft);
    currentLabel->setPalette(pa);


    highLabel = new QLabel(this);
    highLabel->setGeometry(50,this->height()-100,this->width(),50);
    highLabel->setFont(ft);
    highLabel->setPalette(pa);

    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(this->width()-100,this->height()-100,81,81);
    sureBtn->setIcon(QIcon("MyPlane/images/btn/back1111.png"));
    sureBtn->setIconSize(QSize(81,81));
    sureBtn->setFocusPolicy(Qt::NoFocus);
    sureBtn->setFlat(true);

    //去除点击按钮后出现的白色部分
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));

}


//void gameOver::mousePressEvent(QMouseEvent *event)
//{

//     this->windowPos = this->pos();                // 获得部件当前位置
//     this->mousePos = event->globalPos();     // 获得鼠标位置
//     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
//}

//void gameOver::mouseMoveEvent(QMouseEvent *event)
//{
//     this->move(event->globalPos() - this->dPos);
//}

void gameOver::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,700,800,QPixmap("MyPlane/images/widget/gameOverRank2.png"));

}
void gameOver::sureBtn_clicked()
{
       // delete this;
        emit backGameView_signal();
}

void gameOver::showLabels(int currentScore,int highScore)
{
    if(currentScore>highScore)
    {

        highScore = currentScore;
    }

    QString currentLabel_str = QString("您当前的分数是：%1").arg(currentScore);
    currentLabel->setText(currentLabel_str);

    QString highLabel_str = QString("您历史最高的分数是：%1").arg(highScore);
    highLabel->setText(highLabel_str);
}
void gameOver::showRanking()
{
    int queryNum = 3;
    int i = 1;
    QString no1_name;
    QString no1_highScore;

    QString no2_name;
    QString no2_highScore;

    QString no3_name;
    QString no3_highScore;

    QString sql_str = "select name,highScore from user order by highScore desc";
     QSqlQuery *query = myDatabase::Instance()->executeQuery(sql_str);
     while(query->next())
     {
         if(i <= queryNum)
         {
             switch(i)
             {
             case 1:
                 no1_name = query->value(0).toString();
                 no1_highScore = query->value(1).toString();
                 break;

             case 2:
                 no2_name = query->value(0).toString();
                 no2_highScore = query->value(1).toString();
                 break;

             case 3:
                 no3_name = query->value(0).toString();
                 no3_highScore = query->value(1).toString();
                 break;

             }

         }

         i++;
     }

     QString No1_Label_str = QString("NO1: 用户名：%1 最高分：%2").arg(no1_name).arg(no1_highScore);
     No1_Label->setText(No1_Label_str);

     QString No2_Label_str = QString("NO2: 用户名：%1 最高分：%2").arg(no2_name).arg(no2_highScore);
     No2_Label->setText(No2_Label_str);

     QString No3_Label_str = QString("NO3: 用户名：%1 最高分：%2").arg(no3_name).arg(no3_highScore);
     No3_Label->setText(No3_Label_str);


}

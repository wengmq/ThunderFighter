#include "forgetPwdWidget.h"

forgetPwdWidget::forgetPwdWidget(QWidget *parent) :
    QWidget(parent)
{
    //初始化子窗口
    modifyPwdWInterface = new modifyPwdWidget  ;

    this->setFixedSize(400,400);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/3);
    this->setWindowFlags(Qt::FramelessWindowHint);//去边框
    this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

//    //设置背景图片
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg2.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-45,10,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));



    nameLabel  = new QLabel(this);
    qDebug()<<this->userName;
    //nameLabel->setText(QString("您的用户名是：%1").arg(this->userName));//登录界面传进来的用户名
    nameLabel->setGeometry(50,50,300,30);



    questionLabel = new QLabel(this);
    questionLabel->setGeometry(20,120,160,45);
    questionLabel->setText("选择密保问题：");
    questionLabel->setPixmap(QPixmap("MyPlane/images/btn/question.png"));

    answerLabel = new QLabel(this);
    answerLabel->setGeometry(20,205,160,45);
    answerLabel->setText("密保问题答案：");
    answerLabel->setPixmap(QPixmap("MyPlane/images/btn/answer.png"));


    questionBox = new QComboBox(this);
    questionBox->setGeometry(20+180,120,160,35);
    questionBox->addItem("您父亲的名字");
    questionBox->addItem("您母亲的名字");
    questionBox->addItem("您小学班主任的名字");
    questionBox->addItem("您爱人的名字");
    questionBox->addItem("您最好朋友的名字");
    //qDebug()<<questionBox->inputContext();

    answerLineEdit = new QLineEdit(this);
    answerLineEdit->setGeometry(20+180,205,160,35);
    answerLineEdit->setMaxLength(8);


    QFont ft;
    ft.setPointSize(14);
    nameLabel->setFont(ft);
    //questionBox->setFont(ft);
     answerLineEdit->setFont(ft);

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    nameLabel->setPalette(pa);


    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(130,300,159,56);
    sureBtn->setIcon(QIcon("MyPlane/images/btn/sure22.png"));
    sureBtn->setIconSize(QSize(159,56));
    sureBtn->setFocusPolicy(Qt::NoFocus);
    sureBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));
}


void forgetPwdWidget::setuserName(QString name)
{
    this->userName = name;
    nameLabel->setText(QString("您的用户名是：%1").arg(this->userName));//登录界面传进来的用户名
}


void forgetPwdWidget::sureBtn_clicked()
{
    QString name = this->userName;
    QString question = questionBox->currentText();
    QString answer = answerLineEdit->text();

    QSqlQuery *query;//用于接收返回用户表信息
    QString str_sql = QString("select *from user where name = '%1' and question = '%2' and answer = '%3' ").arg(name).arg(question).arg(answer);
    query = myDatabase::Instance()->executeQuery(str_sql);

    if(query->next())//查看查询结果是否有数据
    {
        QMessageBox::information(this,"提示","用户身份确认成功！");
        modifyPwdWInterface->setuserName(this->userName);
        modifyPwdWInterface->show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"提示","密保问题或答案错误！");
    }

}



void forgetPwdWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void forgetPwdWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void forgetPwdWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,400,400,QPixmap("MyPlane/images/widget/Bag_Bg2.png"));
}

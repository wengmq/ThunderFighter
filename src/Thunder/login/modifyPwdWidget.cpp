#include "modifyPwdWidget.h"
#include <QString>
modifyPwdWidget::modifyPwdWidget(QWidget *parent) :
    QWidget(parent)
{
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
    //qDebug()<<this->userName;
    //nameLabel->setText(QString("您的用户名是：%1").arg(this->userName));//登录界面传进来的用户名
    nameLabel->setGeometry(50,50,300,30);





    pwdLabel1 = new QLabel(this);
    pwdLabel1->setGeometry(20+44,120,160,45);
    pwdLabel1->setText("密码：");
    pwdLabel1->setPixmap(QPixmap("MyPlane/images/btn/pwd1.png"));


    pwdLabel2 = new QLabel(this);
    pwdLabel2->setGeometry(20,205,160,45);
    pwdLabel2->setText("确认密码：");
    pwdLabel2->setPixmap(QPixmap("MyPlane/images/btn/pwd2.png"));


    pwdLineEdit1 = new QLineEdit(this);
    pwdLineEdit1->setGeometry(20+180,120,160,30);
    //nameLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    pwdLineEdit1->setMaxLength(12);
  //  nameLineEdit->setClearButtonEnabled(true);
    pwdLineEdit1->setEchoMode(QLineEdit::Password);//设置密文

    QRegExp regx("[0-9]+$");         //输入控制只能输入0-9数字
    QValidator *validator1 = new QRegExpValidator(regx,pwdLineEdit1);
    pwdLineEdit1->setValidator(validator1);
    pwdLineEdit1->setPlaceholderText("密码只能输入数字！");




    pwdLineEdit2 = new QLineEdit(this);
    pwdLineEdit2->setGeometry(20+180,205,160,35);
    pwdLineEdit2->setMaxLength(8);
    pwdLineEdit2->setEchoMode(QLineEdit::Password);//设置密文
    QValidator *validator2 = new QRegExpValidator(regx,pwdLineEdit2);
    pwdLineEdit2->setValidator(validator2);
    pwdLineEdit2->setPlaceholderText("密码只能输入数字！");



    QFont ft;
    ft.setPointSize(14);
    nameLabel->setFont(ft);
//    pwdLineEdit1->setFont(ft);
//    pwdLineEdit2->setFont(ft);

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


void modifyPwdWidget::setuserName(QString name)
{
    this->userName = name;
    nameLabel->setText(QString("您的用户名是：%1").arg(this->userName));//登录界面传进来的用户名
}


void modifyPwdWidget::sureBtn_clicked()
{

    QString pwd1 = pwdLineEdit1->text();
    QString pwd2 = pwdLineEdit2->text();
    QString name = this->userName;

    if(pwd1 == "")
    {
        QMessageBox::information(this,"提示","密码不能为空！");
    }
    else if(pwd1 !=  pwd2)
    {
        QMessageBox::information(this,"提示","两次密码不一致，请重新输入！");
    }
    else
    {

        QString str_sql = QString("update user set pwd = '%1' where name = '%2'").arg(pwd1).arg(name);
        int flag = myDatabase::Instance()->executeSql(str_sql);

        if(flag)//是否修改成功
        {
            QMessageBox::information(this,"提示","用户密码修改成功！");
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"提示","系统错误，密码修改失败！");
        }

    }


}


void modifyPwdWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void modifyPwdWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void modifyPwdWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,400,400,QPixmap("MyPlane/images/widget/Bag_Bg2.png"));
}

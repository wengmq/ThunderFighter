#include "loginWidget.h"
extern int  isNewUser;
extern bool isGuideOn;
loginWidget::loginWidget(QWidget *parent)
    : QWidget(parent)
{
    //初始化子窗口
    menuInterface = new menuWidget();
    forgetPwdInterface = new  forgetPwdWidget() ;

    this->setFixedSize(648,584);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setWindowFlags(Qt::FramelessWindowHint);//去边框
    this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

    //设置背景图片
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/bg_login.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-60,77,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_click()));


    NameLine = new QLineEdit(this);
    NameLine->setGeometry(275,275,192,28);
    NameLine->setPlaceholderText("请输入账号");
    //NameLine->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    PwdLine = new QLineEdit(this);
    PwdLine->setGeometry(275,328,192,28);
    PwdLine->setEchoMode(QLineEdit::Password);//设置密文
    PwdLine->setPlaceholderText("请输入密码");
    //PwdLine->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QRegExp regx("[0-9]+$");         //输入控制只能输入0-9数字
    QValidator *validator1 = new QRegExpValidator(regx,PwdLine);
    PwdLine->setValidator(validator1);
    PwdLine->setPlaceholderText("密码只能为数字");



    QFont ft;//控制字体大小
    ft.setPointSize(14);
    PwdLine->setFont(ft);
    NameLine->setFont(ft);

    QPalette pa; //控制字体颜色
    pa.setColor(QPalette::WindowText,Qt::black);
    PwdLine->setPalette(pa);
    NameLine->setPalette(pa);


    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(150,450,159,56);
    sureBtn->setIcon(QIcon("MyPlane/images/btn/login22.png"));
    sureBtn->setIconSize(QSize(159,56));
    sureBtn->setFocusPolicy(Qt::NoFocus);
    sureBtn->setFlat(true);

    //去除点击按钮后出现的白色部分
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    backBtn = new QPushButton(this);
    backBtn->setGeometry(340,450,159,56);
    backBtn->setIcon(QIcon("MyPlane/images/btn/back22.png"));
    backBtn->setIconSize(QSize(159,56));
    backBtn->setFocusPolicy(Qt::NoFocus);
    backBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    backBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    forgetPwdBtn = new QPushButton(this);
    forgetPwdBtn->setGeometry(360,385,110,29);
    forgetPwdBtn->setIcon(QIcon("MyPlane/images/btn/forgetBtn.png"));
    forgetPwdBtn->setIconSize(QSize(110,29));
    forgetPwdBtn->setFocusPolicy(Qt::NoFocus);
    forgetPwdBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    forgetPwdBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    //forgetPwdInterface.setParent(this);

    touristLoginBtn = new QPushButton(this);
    touristLoginBtn->setGeometry(180,385,110,29);
    touristLoginBtn->setIcon(QIcon("MyPlane/images/btn/touristLogin.png"));
    touristLoginBtn->setIconSize(QSize(110,29));
    touristLoginBtn->setFocusPolicy(Qt::NoFocus);
    touristLoginBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    touristLoginBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    touristLoginBtn->hide();



    this->connect(backBtn,SIGNAL(clicked()),this,SLOT(backBtn_clicked()));
    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));
    this->connect(forgetPwdBtn,SIGNAL(clicked()),this,SLOT(forgetPwdLabel_clicked()));
    this->connect(menuInterface,SIGNAL(backLoginSignal()),this,SLOT(backLogin_slot()));

}

loginWidget::~loginWidget()
{

}

void loginWidget::sureBtn_clicked()
{
    int successFlag = 0;//用于判断是否登录成功
    QString inputName = NameLine->text();
    qDebug()<<inputName;
    QString inputPwd = PwdLine->text();
    qDebug()<<inputPwd;

    QSqlQuery *query;//用于接收返回用户表信息
    QString str_sql("select *from user");
    query = myDatabase::Instance()->executeQuery(str_sql);

    while(query->next())
    {
        QString dbName  = query->value(0).toString();
        QString dbPwd = query->value(1).toString();
        if(inputName==dbName && inputPwd==dbPwd)
        {
            qDebug()<<"登录成功";
            successFlag = 1;
            isNewUser = query->value(5).toInt();//是否是新用户
            if(isNewUser)
            {
                isGuideOn = true;
            }
            this->hide();
            menuInterface->userName = inputName;
            menuInterface->show();
        }
    }
    if(!successFlag)
    {
        qDebug()<<"登录失败";
        if(NameLine->text()=="" || PwdLine->text()=="")
        {
            QMessageBox::information(this,"提示","账号密码不能为空！");
        }
        else
        {
         QMessageBox::information(this,"提示","账号密码不匹配！");
        }
    }

}

void loginWidget::backBtn_clicked()
{
    emit ReturnLoginSignal();
}

void loginWidget::backLogin_slot()
{
    menuInterface->hide();
    this->show();

}

void loginWidget::forgetPwdLabel_clicked()
{
    int flag = findName();
    qDebug()<<flag;
    if(flag)
    {
 //     forgetPwdInterface.userName = NameLine->text();
        forgetPwdInterface->setuserName(NameLine->text());
        forgetPwdInterface->show();
    }
}
int loginWidget::findName()
{
    if(NameLine->text() == "")
    {
        QMessageBox::information(this,"提示","请输入账号！");
    }
    else
    {
        QSqlQuery *query;//用于接收返回用户表信息
        QString str_sql = QString("select *from user where name = '%1'").arg(NameLine->text());
        query = myDatabase::Instance()->executeQuery(str_sql);

        if(query->next())//查看查询结果是否有数据
        {
            return 1;
        }
        else
        {
            QMessageBox::information(this,"提示","该账号不存在，请重新输入！");
            return 0;
        }

    }
    return 0;
}


void loginWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void loginWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void loginWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,648,584,QPixmap("MyPlane/images/widget/bg_login.png"));
}

void loginWidget::closeEvent(QCloseEvent *CloseEvent)
{
    exit(0);
}
void loginWidget::closeBtn_click()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"提示","您是否确认要退出？",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

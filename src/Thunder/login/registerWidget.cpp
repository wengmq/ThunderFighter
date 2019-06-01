#include "registerWidget.h"

registerWidget::registerWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(500,765);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //设置窗口居中 头文件包含： #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    this->setWindowFlags(Qt::FramelessWindowHint);//去边框
   //this->setAttribute(Qt::WA_TranslucentBackground,true);//设置窗口透明

//    //设置背景图片
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg.png")));
//    this->setPalette(palatte);


//    QLabel *nameLabel;
//    QLabel *pwdLabel1;
//    QLabel *pwdLabel2;
//    QLabel *questionLabel1;

//    QLineEdit *nameLineEdit;
//    QLineEdit *pwdLineEdit1;
//    QLineEdit *pwdLineEdit2;
//    QComboBox *questionBox;

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-45,25,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_click()));


    int x0 = 50;
    int y0 = 150;
    int labelWidth =160;
    int lineWidth =200;
    int height = 45;
    int Xdistance = 30;
    int Ydistance = 35;

    registerLabel = new QLabel(this);
    registerLabel->setGeometry(150,20,205,52);
    registerLabel->setPixmap(QPixmap("MyPlane/images/btn/registerLb.png"));

    nameLabel = new QLabel(this);
    nameLabel->setGeometry(x0+29,y0+(Ydistance+height)*0,labelWidth,height);
    nameLabel->setText("用户名：");
    nameLabel->setPixmap(QPixmap("MyPlane/images/btn/name.png"));

    pwdLabel1 = new QLabel(this);
    pwdLabel1->setGeometry(x0+44,y0+(Ydistance+height)*1,labelWidth,height);
    pwdLabel1->setText("密码：");
    pwdLabel1->setPixmap(QPixmap("MyPlane/images/btn/pwd1.png"));


    pwdLabel2 = new QLabel(this);
    pwdLabel2->setGeometry(x0,y0+(Ydistance+height)*2,labelWidth,height);
    pwdLabel2->setText("确认密码：");
    pwdLabel2->setPixmap(QPixmap("MyPlane/images/btn/pwd2.png"));

    questionLabel = new QLabel(this);
    questionLabel->setGeometry(x0,y0+(Ydistance+height)*3,labelWidth,height);
    questionLabel->setText("选择密保问题：");
    questionLabel->setPixmap(QPixmap("MyPlane/images/btn/question.png"));

    answerLabel = new QLabel(this);
    answerLabel->setGeometry(x0,y0+(Ydistance+height)*4,labelWidth,height);
    answerLabel->setText("密保问题答案：");
    answerLabel->setPixmap(QPixmap("MyPlane/images/btn/answer.png"));


    nameLineEdit = new QLineEdit(this);
    nameLineEdit->setGeometry(x0+180,y0+(Ydistance+height)*0,lineWidth,height-10);
    //nameLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    nameLineEdit->setMaxLength(12);
  //  nameLineEdit->setClearButtonEnabled(true);
    nameLineEdit->setPlaceholderText("用户名可中文可英文");

    pwdLineEdit1 = new QLineEdit(this);
    pwdLineEdit1->setGeometry(x0+180,y0+(Ydistance+height)*1,lineWidth,height-10);
    pwdLineEdit1->setMaxLength(8);
    pwdLineEdit1->setEchoMode(QLineEdit::Password);//设置密文
    //pwdLineEdit1->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //只能输入数字
      QRegExp regx("[0-9]+$");         //输入控制只能输入0-9数字
       QValidator *validator1 = new QRegExpValidator(regx,pwdLineEdit1);
       pwdLineEdit1->setValidator(validator1);
    pwdLineEdit1->setPlaceholderText("密码只能输入数字！");


    pwdLineEdit2 = new QLineEdit(this);
    pwdLineEdit2->setGeometry(x0+180,y0+(Ydistance+height)*2,lineWidth,height-10);
    pwdLineEdit2->setMaxLength(8);
    pwdLineEdit2->setEchoMode(QLineEdit::Password);//设置密文
    //pwdLineEdit2->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //只能输入数字

    //限制只能输入数字
    QValidator *validator2 = new QRegExpValidator(regx,pwdLineEdit2);
    pwdLineEdit2->setValidator(validator2);
    pwdLineEdit2->setPlaceholderText("密码只能输入数字！");



//    nameLineEdit = new QLineEdit(this);
//    nameLineEdit->setGeometry(x0+180,y0+(Ydistance+height)*0,lineWidth,height);
    questionBox = new QComboBox(this);
    questionBox->setGeometry(x0+180,y0+(Ydistance+height)*3,lineWidth,height-10);
    questionBox->addItem("您父亲的名字");
    questionBox->addItem("您母亲的名字");
    questionBox->addItem("您小学班主任的名字");
    questionBox->addItem("您爱人的名字");
    questionBox->addItem("您最好朋友的名字");
    //qDebug()<<questionBox->inputContext();

    answerLineEdit = new QLineEdit(this);
    answerLineEdit->setGeometry(x0+180,y0+(Ydistance+height)*4,lineWidth,height-10);
    answerLineEdit->setMaxLength(8);


    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(80,650,159,56);
    sureBtn->setIcon(QIcon("MyPlane/images/btn/sure22.png"));
    sureBtn->setIconSize(QSize(159,56));
    sureBtn->setFocusPolicy(Qt::NoFocus);
    sureBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    backBtn = new QPushButton(this);
    backBtn->setGeometry(270,650,159,56);
    backBtn->setIcon(QIcon("MyPlane/images/btn/back22.png"));
    backBtn->setIconSize(QSize(159,56));
    backBtn->setFocusPolicy(Qt::NoFocus);
    backBtn->setFlat(true);
    //去除点击按钮后出现的白色部分
    backBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    this->connect(backBtn,SIGNAL(clicked()),this,SLOT(backBtn_clicked()));
    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));
}


void registerWidget::backBtn_clicked()
{

    emit BackLoginSignal();

}

int registerWidget::registerReturn()
{

    QString inputName = nameLineEdit->text();
    QString inputPsw1 = pwdLineEdit1->text();
    QString inputPsw2 = pwdLineEdit2->text();
    QString inputQuestion = questionBox->currentText() ;
    QString inputAnswer = answerLineEdit->text();

    qDebug()<<inputName;
    qDebug()<<inputPsw1;
    qDebug()<<inputPsw2;
    qDebug()<<inputQuestion;
    qDebug()<<inputAnswer;


    if(inputName == "")//如果用户名为空
    {
        return 1;
    }
    if(findName())
    {
        return 0;
    }

    if(inputPsw1 == "")//如果第一次密码为空
    {
        return 2;
    }

    if(inputPsw1 != inputPsw2)//如果两次密码不一致
    {
         return 3;
    }
    if(inputAnswer == "")//如果用户名为空
    {
        return 4;
    }
    QString str_sql = QString("insert into user values('%1','%2',%3,'%4','%5',%6)").arg(inputName).arg(inputPsw1).arg(0).arg(inputQuestion).arg(inputAnswer).arg(1);
    //qDebug()<<str_sql;
    if(myDatabase::Instance()->executeSql(str_sql)) //如果语句执行成功
    {
        return 5;
    }
    else//如果语句执行失败
    {
       return 6;
    }





}

void registerWidget::sureBtn_clicked()
{
    //    QLineEdit *nameLineEdit;
    //    QLineEdit *pwdLineEdit1;
    //    QLineEdit *pwdLineEdit2;
    //    QComboBox *questionBox;
    //    QLineEdit *answerLineEdit;
    switch(registerReturn())
    {
    case 1:
        QMessageBox::information(this,"提示","用户名不能为空！！");
        break;
    case 2:
        QMessageBox::information(this,"提示","密码不能为空！！");
        break;

    case 3:
        QMessageBox::information(this,"提示","两次密码不匹配请重新输入！");
        pwdLineEdit1->clear();
        pwdLineEdit2->clear();
        break;
    case 4:
        QMessageBox::information(this,"提示","密保问题不能为空！！");
        break;

    case 5:
        QMessageBox::information(this,"success","用户创建成功！！");
        break;

    case 6:
        QMessageBox::information(this,"failed","该用户名已存在，请重新输入！！");
        nameLineEdit->clear();
        pwdLineEdit1->clear();
        pwdLineEdit2->clear();
        break;

    case 7:

        break;

    }


}

int registerWidget::findName()
{

    QSqlQuery *query;//用于接收返回用户表信息
    QString str_sql = QString("select *from user where name = '%1'").arg(nameLineEdit->text());
    query = myDatabase::Instance()->executeQuery(str_sql);
//        qDebug()<<"查询结果如下：";
//        while(query->next())
//        {

//            QString str_name = query->value(0).toString();

//            qDebug()<<QString("  name: %1   ").arg(str_name);
//        }
    //qDebug()<<"size:"<<query->size();
    if(query->next())//查看查询结果是否有数据
    {
        QMessageBox::information(this,"提示","该账号已存在，请重新输入！");
        return 1;
    }
    else
    {

        return 0;
    }


   return 0;
}


void registerWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // 获得部件当前位置
     this->mousePos = event->globalPos();     // 获得鼠标位置
     this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void registerWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void registerWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,756,QPixmap("MyPlane/images/widget/Bag_Bg.png"));
}
void registerWidget::closeBtn_click()
{

    if(QMessageBox::Yes==QMessageBox::question(this,"提示","您是否确认要退出？",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

#include "loginWidget.h"
extern int  isNewUser;
extern bool isGuideOn;
loginWidget::loginWidget(QWidget *parent)
    : QWidget(parent)
{
    //��ʼ���Ӵ���
    menuInterface = new menuWidget();
    forgetPwdInterface = new  forgetPwdWidget() ;

    this->setFixedSize(648,584);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
    this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

    //���ñ���ͼƬ
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/bg_login.png")));
//    this->setPalette(palatte);

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-60,77,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtn_click()));


    NameLine = new QLineEdit(this);
    NameLine->setGeometry(275,275,192,28);
    NameLine->setPlaceholderText("�������˺�");
    //NameLine->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    PwdLine = new QLineEdit(this);
    PwdLine->setGeometry(275,328,192,28);
    PwdLine->setEchoMode(QLineEdit::Password);//��������
    PwdLine->setPlaceholderText("����������");
    //PwdLine->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QRegExp regx("[0-9]+$");         //�������ֻ������0-9����
    QValidator *validator1 = new QRegExpValidator(regx,PwdLine);
    PwdLine->setValidator(validator1);
    PwdLine->setPlaceholderText("����ֻ��Ϊ����");



    QFont ft;//���������С
    ft.setPointSize(14);
    PwdLine->setFont(ft);
    NameLine->setFont(ft);

    QPalette pa; //����������ɫ
    pa.setColor(QPalette::WindowText,Qt::black);
    PwdLine->setPalette(pa);
    NameLine->setPalette(pa);


    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(150,450,159,56);
    sureBtn->setIcon(QIcon("MyPlane/images/btn/login22.png"));
    sureBtn->setIconSize(QSize(159,56));
    sureBtn->setFocusPolicy(Qt::NoFocus);
    sureBtn->setFlat(true);

    //ȥ�������ť����ֵİ�ɫ����
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    backBtn = new QPushButton(this);
    backBtn->setGeometry(340,450,159,56);
    backBtn->setIcon(QIcon("MyPlane/images/btn/back22.png"));
    backBtn->setIconSize(QSize(159,56));
    backBtn->setFocusPolicy(Qt::NoFocus);
    backBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    backBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    forgetPwdBtn = new QPushButton(this);
    forgetPwdBtn->setGeometry(360,385,110,29);
    forgetPwdBtn->setIcon(QIcon("MyPlane/images/btn/forgetBtn.png"));
    forgetPwdBtn->setIconSize(QSize(110,29));
    forgetPwdBtn->setFocusPolicy(Qt::NoFocus);
    forgetPwdBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    forgetPwdBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    //forgetPwdInterface.setParent(this);

    touristLoginBtn = new QPushButton(this);
    touristLoginBtn->setGeometry(180,385,110,29);
    touristLoginBtn->setIcon(QIcon("MyPlane/images/btn/touristLogin.png"));
    touristLoginBtn->setIconSize(QSize(110,29));
    touristLoginBtn->setFocusPolicy(Qt::NoFocus);
    touristLoginBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
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
    int successFlag = 0;//�����ж��Ƿ��¼�ɹ�
    QString inputName = NameLine->text();
    qDebug()<<inputName;
    QString inputPwd = PwdLine->text();
    qDebug()<<inputPwd;

    QSqlQuery *query;//���ڽ��շ����û�����Ϣ
    QString str_sql("select *from user");
    query = myDatabase::Instance()->executeQuery(str_sql);

    while(query->next())
    {
        QString dbName  = query->value(0).toString();
        QString dbPwd = query->value(1).toString();
        if(inputName==dbName && inputPwd==dbPwd)
        {
            qDebug()<<"��¼�ɹ�";
            successFlag = 1;
            isNewUser = query->value(5).toInt();//�Ƿ������û�
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
        qDebug()<<"��¼ʧ��";
        if(NameLine->text()=="" || PwdLine->text()=="")
        {
            QMessageBox::information(this,"��ʾ","�˺����벻��Ϊ�գ�");
        }
        else
        {
         QMessageBox::information(this,"��ʾ","�˺����벻ƥ�䣡");
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
        QMessageBox::information(this,"��ʾ","�������˺ţ�");
    }
    else
    {
        QSqlQuery *query;//���ڽ��շ����û�����Ϣ
        QString str_sql = QString("select *from user where name = '%1'").arg(NameLine->text());
        query = myDatabase::Instance()->executeQuery(str_sql);

        if(query->next())//�鿴��ѯ����Ƿ�������
        {
            return 1;
        }
        else
        {
            QMessageBox::information(this,"��ʾ","���˺Ų����ڣ����������룡");
            return 0;
        }

    }
    return 0;
}


void loginWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
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

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�ȷ��Ҫ�˳���",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

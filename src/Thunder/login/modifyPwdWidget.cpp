#include "modifyPwdWidget.h"
#include <QString>
modifyPwdWidget::modifyPwdWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(400,400);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/3);
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
   this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

//    //���ñ���ͼƬ
//    QPalette palatte;
//    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg2.png")));
//    this->setPalette(palatte);


    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-45,10,20,20);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));

    nameLabel  = new QLabel(this);
    //qDebug()<<this->userName;
    //nameLabel->setText(QString("�����û����ǣ�%1").arg(this->userName));//��¼���洫�������û���
    nameLabel->setGeometry(50,50,300,30);





    pwdLabel1 = new QLabel(this);
    pwdLabel1->setGeometry(20+44,120,160,45);
    pwdLabel1->setText("���룺");
    pwdLabel1->setPixmap(QPixmap("MyPlane/images/btn/pwd1.png"));


    pwdLabel2 = new QLabel(this);
    pwdLabel2->setGeometry(20,205,160,45);
    pwdLabel2->setText("ȷ�����룺");
    pwdLabel2->setPixmap(QPixmap("MyPlane/images/btn/pwd2.png"));


    pwdLineEdit1 = new QLineEdit(this);
    pwdLineEdit1->setGeometry(20+180,120,160,30);
    //nameLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    pwdLineEdit1->setMaxLength(12);
  //  nameLineEdit->setClearButtonEnabled(true);
    pwdLineEdit1->setEchoMode(QLineEdit::Password);//��������

    QRegExp regx("[0-9]+$");         //�������ֻ������0-9����
    QValidator *validator1 = new QRegExpValidator(regx,pwdLineEdit1);
    pwdLineEdit1->setValidator(validator1);
    pwdLineEdit1->setPlaceholderText("����ֻ���������֣�");




    pwdLineEdit2 = new QLineEdit(this);
    pwdLineEdit2->setGeometry(20+180,205,160,35);
    pwdLineEdit2->setMaxLength(8);
    pwdLineEdit2->setEchoMode(QLineEdit::Password);//��������
    QValidator *validator2 = new QRegExpValidator(regx,pwdLineEdit2);
    pwdLineEdit2->setValidator(validator2);
    pwdLineEdit2->setPlaceholderText("����ֻ���������֣�");



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
    //ȥ�������ť����ֵİ�ɫ����
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));


}


void modifyPwdWidget::setuserName(QString name)
{
    this->userName = name;
    nameLabel->setText(QString("�����û����ǣ�%1").arg(this->userName));//��¼���洫�������û���
}


void modifyPwdWidget::sureBtn_clicked()
{

    QString pwd1 = pwdLineEdit1->text();
    QString pwd2 = pwdLineEdit2->text();
    QString name = this->userName;

    if(pwd1 == "")
    {
        QMessageBox::information(this,"��ʾ","���벻��Ϊ�գ�");
    }
    else if(pwd1 !=  pwd2)
    {
        QMessageBox::information(this,"��ʾ","�������벻һ�£����������룡");
    }
    else
    {

        QString str_sql = QString("update user set pwd = '%1' where name = '%2'").arg(pwd1).arg(name);
        int flag = myDatabase::Instance()->executeSql(str_sql);

        if(flag)//�Ƿ��޸ĳɹ�
        {
            QMessageBox::information(this,"��ʾ","�û������޸ĳɹ���");
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"��ʾ","ϵͳ���������޸�ʧ�ܣ�");
        }

    }


}


void modifyPwdWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
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

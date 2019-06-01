#include "forgetPwdWidget.h"

forgetPwdWidget::forgetPwdWidget(QWidget *parent) :
    QWidget(parent)
{
    //��ʼ���Ӵ���
    modifyPwdWInterface = new modifyPwdWidget  ;

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
    qDebug()<<this->userName;
    //nameLabel->setText(QString("�����û����ǣ�%1").arg(this->userName));//��¼���洫�������û���
    nameLabel->setGeometry(50,50,300,30);



    questionLabel = new QLabel(this);
    questionLabel->setGeometry(20,120,160,45);
    questionLabel->setText("ѡ���ܱ����⣺");
    questionLabel->setPixmap(QPixmap("MyPlane/images/btn/question.png"));

    answerLabel = new QLabel(this);
    answerLabel->setGeometry(20,205,160,45);
    answerLabel->setText("�ܱ�����𰸣�");
    answerLabel->setPixmap(QPixmap("MyPlane/images/btn/answer.png"));


    questionBox = new QComboBox(this);
    questionBox->setGeometry(20+180,120,160,35);
    questionBox->addItem("�����׵�����");
    questionBox->addItem("��ĸ�׵�����");
    questionBox->addItem("��Сѧ�����ε�����");
    questionBox->addItem("�����˵�����");
    questionBox->addItem("��������ѵ�����");
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
    //ȥ�������ť����ֵİ�ɫ����
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_clicked()));
}


void forgetPwdWidget::setuserName(QString name)
{
    this->userName = name;
    nameLabel->setText(QString("�����û����ǣ�%1").arg(this->userName));//��¼���洫�������û���
}


void forgetPwdWidget::sureBtn_clicked()
{
    QString name = this->userName;
    QString question = questionBox->currentText();
    QString answer = answerLineEdit->text();

    QSqlQuery *query;//���ڽ��շ����û�����Ϣ
    QString str_sql = QString("select *from user where name = '%1' and question = '%2' and answer = '%3' ").arg(name).arg(question).arg(answer);
    query = myDatabase::Instance()->executeQuery(str_sql);

    if(query->next())//�鿴��ѯ����Ƿ�������
    {
        QMessageBox::information(this,"��ʾ","�û����ȷ�ϳɹ���");
        modifyPwdWInterface->setuserName(this->userName);
        modifyPwdWInterface->show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"��ʾ","�ܱ������𰸴���");
    }

}



void forgetPwdWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
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

#include "registerWidget.h"

registerWidget::registerWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(500,765);

    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
   //this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

//    //���ñ���ͼƬ
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
    //ȥ�������ť����ֵİ�ɫ����
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
    nameLabel->setText("�û�����");
    nameLabel->setPixmap(QPixmap("MyPlane/images/btn/name.png"));

    pwdLabel1 = new QLabel(this);
    pwdLabel1->setGeometry(x0+44,y0+(Ydistance+height)*1,labelWidth,height);
    pwdLabel1->setText("���룺");
    pwdLabel1->setPixmap(QPixmap("MyPlane/images/btn/pwd1.png"));


    pwdLabel2 = new QLabel(this);
    pwdLabel2->setGeometry(x0,y0+(Ydistance+height)*2,labelWidth,height);
    pwdLabel2->setText("ȷ�����룺");
    pwdLabel2->setPixmap(QPixmap("MyPlane/images/btn/pwd2.png"));

    questionLabel = new QLabel(this);
    questionLabel->setGeometry(x0,y0+(Ydistance+height)*3,labelWidth,height);
    questionLabel->setText("ѡ���ܱ����⣺");
    questionLabel->setPixmap(QPixmap("MyPlane/images/btn/question.png"));

    answerLabel = new QLabel(this);
    answerLabel->setGeometry(x0,y0+(Ydistance+height)*4,labelWidth,height);
    answerLabel->setText("�ܱ�����𰸣�");
    answerLabel->setPixmap(QPixmap("MyPlane/images/btn/answer.png"));


    nameLineEdit = new QLineEdit(this);
    nameLineEdit->setGeometry(x0+180,y0+(Ydistance+height)*0,lineWidth,height-10);
    //nameLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    nameLineEdit->setMaxLength(12);
  //  nameLineEdit->setClearButtonEnabled(true);
    nameLineEdit->setPlaceholderText("�û��������Ŀ�Ӣ��");

    pwdLineEdit1 = new QLineEdit(this);
    pwdLineEdit1->setGeometry(x0+180,y0+(Ydistance+height)*1,lineWidth,height-10);
    pwdLineEdit1->setMaxLength(8);
    pwdLineEdit1->setEchoMode(QLineEdit::Password);//��������
    //pwdLineEdit1->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //ֻ����������
      QRegExp regx("[0-9]+$");         //�������ֻ������0-9����
       QValidator *validator1 = new QRegExpValidator(regx,pwdLineEdit1);
       pwdLineEdit1->setValidator(validator1);
    pwdLineEdit1->setPlaceholderText("����ֻ���������֣�");


    pwdLineEdit2 = new QLineEdit(this);
    pwdLineEdit2->setGeometry(x0+180,y0+(Ydistance+height)*2,lineWidth,height-10);
    pwdLineEdit2->setMaxLength(8);
    pwdLineEdit2->setEchoMode(QLineEdit::Password);//��������
    //pwdLineEdit2->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //ֻ����������

    //����ֻ����������
    QValidator *validator2 = new QRegExpValidator(regx,pwdLineEdit2);
    pwdLineEdit2->setValidator(validator2);
    pwdLineEdit2->setPlaceholderText("����ֻ���������֣�");



//    nameLineEdit = new QLineEdit(this);
//    nameLineEdit->setGeometry(x0+180,y0+(Ydistance+height)*0,lineWidth,height);
    questionBox = new QComboBox(this);
    questionBox->setGeometry(x0+180,y0+(Ydistance+height)*3,lineWidth,height-10);
    questionBox->addItem("�����׵�����");
    questionBox->addItem("��ĸ�׵�����");
    questionBox->addItem("��Сѧ�����ε�����");
    questionBox->addItem("�����˵�����");
    questionBox->addItem("��������ѵ�����");
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
    //ȥ�������ť����ֵİ�ɫ����
    sureBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    backBtn = new QPushButton(this);
    backBtn->setGeometry(270,650,159,56);
    backBtn->setIcon(QIcon("MyPlane/images/btn/back22.png"));
    backBtn->setIconSize(QSize(159,56));
    backBtn->setFocusPolicy(Qt::NoFocus);
    backBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
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


    if(inputName == "")//����û���Ϊ��
    {
        return 1;
    }
    if(findName())
    {
        return 0;
    }

    if(inputPsw1 == "")//�����һ������Ϊ��
    {
        return 2;
    }

    if(inputPsw1 != inputPsw2)//����������벻һ��
    {
         return 3;
    }
    if(inputAnswer == "")//����û���Ϊ��
    {
        return 4;
    }
    QString str_sql = QString("insert into user values('%1','%2',%3,'%4','%5',%6)").arg(inputName).arg(inputPsw1).arg(0).arg(inputQuestion).arg(inputAnswer).arg(1);
    //qDebug()<<str_sql;
    if(myDatabase::Instance()->executeSql(str_sql)) //������ִ�гɹ�
    {
        return 5;
    }
    else//������ִ��ʧ��
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
        QMessageBox::information(this,"��ʾ","�û�������Ϊ�գ���");
        break;
    case 2:
        QMessageBox::information(this,"��ʾ","���벻��Ϊ�գ���");
        break;

    case 3:
        QMessageBox::information(this,"��ʾ","�������벻ƥ�����������룡");
        pwdLineEdit1->clear();
        pwdLineEdit2->clear();
        break;
    case 4:
        QMessageBox::information(this,"��ʾ","�ܱ����ⲻ��Ϊ�գ���");
        break;

    case 5:
        QMessageBox::information(this,"success","�û������ɹ�����");
        break;

    case 6:
        QMessageBox::information(this,"failed","���û����Ѵ��ڣ����������룡��");
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

    QSqlQuery *query;//���ڽ��շ����û�����Ϣ
    QString str_sql = QString("select *from user where name = '%1'").arg(nameLineEdit->text());
    query = myDatabase::Instance()->executeQuery(str_sql);
//        qDebug()<<"��ѯ������£�";
//        while(query->next())
//        {

//            QString str_name = query->value(0).toString();

//            qDebug()<<QString("  name: %1   ").arg(str_name);
//        }
    //qDebug()<<"size:"<<query->size();
    if(query->next())//�鿴��ѯ����Ƿ�������
    {
        QMessageBox::information(this,"��ʾ","���˺��Ѵ��ڣ����������룡");
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
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
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

    if(QMessageBox::Yes==QMessageBox::question(this,"��ʾ","���Ƿ�ȷ��Ҫ�˳���",QMessageBox::Yes|QMessageBox::No))
    {
       this->close();
    }

}

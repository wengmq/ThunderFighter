#include "rankingWidget.h"
#include "ui_rankingWidget.h"
int pageSize = 10;
int pageCount = 0;
int page =1;
int recordCount = 0;





rankingWidget::rankingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rankingWidget)
{
   ui_init();

}

rankingWidget::~rankingWidget()
{
    delete ui;
}


void rankingWidget::mousePressEvent(QMouseEvent *event)
{
     this->windowPos = this->pos();                // ��ò�����ǰλ��
     this->mousePos = event->globalPos();     // ������λ��
     this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
}

void rankingWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);
}
void rankingWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,765,QPixmap("MyPlane/images/widget/Bag_Bg2.png"));
}

void rankingWidget::ui_init()
{
    ui->setupUi(this);

    this->setFixedSize(485,764);
    this->setWindowIcon(QIcon("MyPlane/images/game.ico"));

    //���ô��ھ��� ͷ�ļ������� #include <QtGui/QApplication>  #include <QDesktopWidget>
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

     this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�߿�
     this->setAttribute(Qt::WA_TranslucentBackground,true);//���ô���͸��

    //���ñ���ͼƬ
//    bgLabel =new QLabel(this) ;
//     bgLabel->setGeometry(0,0,450,450);
//    bgLabel->setStyleSheet("QLabel{border-image:url(MyPlane/images/widget/03_1.png);}");

    QPalette palatte;
    palatte.setBrush(QPalette::Background,QBrush(QPixmap("MyPlane/images/widget/Bag_Bg.png")));
    this->setPalette(palatte);

    QFont ft;
    ft.setPointSize(14);
    ui->label->setFont(ft);

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->label->setPalette(pa);

    titleLabel = new QLabel(this);
    titleLabel->setGeometry(100,10,304,71);
    titleLabel->setPixmap(QPixmap("MyPlane/images/btn/ranking.png"));

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(this->width()-55,25,35,35);
    closeBtn->setIcon(QIcon("MyPlane/images/btn/sz_back1.png"));
    closeBtn->setIconSize(QSize(35,35));
    closeBtn->setFocusPolicy(Qt::NoFocus);
    closeBtn->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    closeBtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    this->connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));




   // ui->pushButton_before->setGeometry(this->width()-55,25,35,35);
    ui->pushButton_before->setIcon(QIcon("MyPlane/images/btn/beforePage.png"));
    ui->pushButton_before->setIconSize(QSize(121,41));
    ui->pushButton_before->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_before->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    ui->pushButton_before->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


   // ui->pushButton_next->setGeometry(this->width()-55,25,150,45);
    ui->pushButton_next->setIcon(QIcon("MyPlane/images/btn/nextPage.png"));
    ui->pushButton_next->setIconSize(QSize(121,41));
    ui->pushButton_next->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_next->setFlat(true);
    //ȥ�������ť����ֵİ�ɫ����
    ui->pushButton_next->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");



    QString str_sql;
    queryModel = new QSqlQueryModel(this);
    tablemModel = new QSqlTableModel(this);

    //ָ�������ű�
    tablemModel->setTable("user");
    //����tableview��model(������û������)
    tablemModel->select();
    tablemModel->setHeaderData(0,Qt::Horizontal,"��  ��");//���õ�һ������
    tablemModel->setHeaderData(1,Qt::Horizontal,"�� �� ��");//���õڶ�������


//    ui->tableView->setModel(model);
//    for(int i = 0; i < 10; i++)
//    {
//       // queryModel->setItem(i,0,new QStandardItem("2009441676"));
//           //�����ַ���ɫ
////        queryModel->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
//           //�����ַ�λ��
//        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
//      //  queryModel->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("����")));
//    }

  //  tablemModel->itemData(0).alignment(Qt::AlignCenter);


    //�ֶ��޸ķ�ʽ
    tablemModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    recordCount = tablemModel->rowCount();
    qDebug()<<"recordCount"<<recordCount;

    pageCount = recordCount%pageSize == 0? (recordCount/pageSize) : (recordCount/pageSize+1) ;

    qDebug()<<"pagecount:"<<pageCount;


    str_sql = QString("select rowid as ���� ,*from (select name as �û���, highScore as ��߷� from user ORDER BY highScore desc ) order by ���� limit %1*(%2-1),%3 ").arg(pageSize).arg(page).arg(pageSize);
    queryModel->setQuery(str_sql);
    qDebug()<<str_sql;


    //��ʾ��ѯ����
    ui->tableView->setModel(queryModel);

    QString str_lab = QString("��%1ҳ����%2ҳ").arg(page).arg(pageCount);
    ui->label->setText(str_lab);
    //view �����޸� Ȩ�� ����
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //����Ĭ���п�
    ui->tableView->setColumnWidth(0,132);
    ui->tableView->setColumnWidth(1,132);
    ui->tableView->setColumnWidth(2,132);

    //����Ĭ���и�
    ui->tableView->verticalHeader()->setDefaultSectionSize(46);

    //����ͷȥ��
    ui->tableView->verticalHeader()->hide();

    //����ѡ��ʱΪ����ѡ��
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        //����ɫ����ı䣬��һ����ɫ�仯һ��
   ui->tableView->setAlternatingRowColors(true);
    // ui->tableView->setStyleSheet("QTableView { border: none;selection-background-color: #EE4000;color: red}");

   //���ò��ܸı��п�
   ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

   //���ñ�ͷ��ʽ
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#87CEFA;}");//border:0px solid white;

   //������������
    ui->tableView->setShowGrid(false);

 //  ui->tableView->

}



void rankingWidget::on_pushButton_before_clicked()
{

    page--;
    if(page<=0)
        page = pageCount;

    QString str_sql =  QString("select rowid as ���� ,*from (select name as �û���, highScore as ��߷� from user ORDER BY highScore desc ) order by ���� limit %1*(%2-1),%3").arg(pageSize).arg(page).arg(pageSize);
    queryModel->setQuery(str_sql);
    qDebug()<<str_sql;
    QString str_lab = QString("��%1ҳ����%2ҳ").arg(page).arg(pageCount);
    ui->label->setText(str_lab);

}

void rankingWidget::on_pushButton_next_clicked()
{
    page++;
    if(page>pageCount)
        page = 1;
    QString str_sql =  QString("select rowid as ���� ,*from (select name as �û���, highScore as ��߷� from user ORDER BY highScore desc ) order by ���� limit %1*(%2-1),%3").arg(pageSize).arg(page).arg(pageSize);
    queryModel->setQuery(str_sql);
    qDebug()<<str_sql;
    QString str_lab = QString("��%1ҳ����%2ҳ").arg(page).arg(pageCount);
    ui->label->setText(str_lab);

}

//QVariant rankingWidget::data(const QModelIndex &item, int role) const

//{
//    QVariant value = QSqlQueryModel::data(item, role);
//    if(role ==  Qt::TextAlignmentRole )
//    {
//        value   =   (Qt::AlignCenter);
//        return value;
//    }
//    return value;
//}

#ifndef RANKINGWIDGET_H
#define RANKINGWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>//���ڱ����ʾ
#include <QSqlRecord>


#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QIcon>
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include<QPainter>
#include<QVariant>
namespace Ui {
    class rankingWidget;
}

class rankingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rankingWidget(QWidget *parent = 0);
    ~rankingWidget();
    //QVariant data(const QModelIndex &index, int role) const;
    void ui_init();
    void  mousePressEvent(QMouseEvent *event);//����������¼�
    void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
    void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��

public slots:
    void on_pushButton_before_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::rankingWidget *ui;
    QPushButton *closeBtn;
    QLabel * bgLabel;
    QLabel *titleLabel;
    QSqlTableModel *tablemModel;

    QSqlQueryModel *queryModel;


};

#endif // RANKINGWIDGET_H

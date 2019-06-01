#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

#include <QWidget>
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
#include <QSound>
#include <QComboBox>
class setupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit setupWidget(QWidget *parent = 0);

    void showMusicBtn();
    void showGuideBtn();
    void showDifficultyBtn();

    void  mousePressEvent(QMouseEvent *event);//����������¼�
    void  mouseMoveEvent(QMouseEvent *event);//��������ƶ��¼�
    void paintEvent(QPaintEvent *event);  //���ػ�ͼ�¼�
    QPoint windowPos;     // ��ò�����ǰλ��
    QPoint mousePos;     // ������λ��
    QPoint dPos ;        // �ƶ��󲿼����ڵ�λ��
signals:

public slots:
    void musicBtn_clicked();
    void guideBtn_clicked();
    void difficultyBtn_clicked();

private:

    QPushButton *musicBtn;
    QPushButton *guideBtn;
    QPushButton *difficultyBtn;
    QPushButton *closeBtn;

};

#endif // SETUPWIDGET_H

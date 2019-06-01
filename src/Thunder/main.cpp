#include <QtGui/QApplication>
#include <QTextCodec> //����
#include "dataBase/myDatabase.h"
#include "login/mainWidget.h"
#include "menu/menuWidget.h"
#include "menu/helpWidget.h"
#include "login/loginWidget.h"
#include <QSound>
#include "menu/setupWidget.h"
#include "menu/rankingWidget.h"
#include "game/gameWidget.h"
#include<Phonon/VideoPlayer>
#include "other/myMusic.h"
#include"game/gameOver.h"
#include"menu/mapWidget.h"
QSound music("MyPlane/music/menubg.wav");

Phonon::VideoPlayer *musicPlayer;
Phonon::VideoPlayer *GamestartPlayer;
 //myMusic *menuMusic ;
int  difficultyRanking =2;
bool isGuideOn = false;
int  isNewUser = 0;
bool isMusicOn = true;
int  planeChooseFlag = 1;
int mapChooseFlag = 1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //���ñ��ر��� ͷ�ļ� #include <QTextCodec> //����
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //�����ݿ�
    myDatabase::Instance();


     //���ñ�������
     //music.setLoops(-1);//��������ѭ������
     //music.play();


    mainWidget w;
    w.show();


    return a.exec();
}

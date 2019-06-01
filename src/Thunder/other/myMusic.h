#ifndef MYMUSIC_H
#define MYMUSIC_H

#include <QWidget>
 #include <Phonon/VideoPlayer>
#include<QDebug>
#include <phonon/MediaObject>

using namespace Phonon;
class myMusic : public Phonon::VideoPlayer
{
    Q_OBJECT
public:
    explicit myMusic ( QString fileName, QWidget * parent = 0 );

     //Phonon::VideoPlayer *musicPlayer  ;

        MediaObject * backsound;
        QString fileName;
signals:

public slots:

   // void MusicPlay();
     void playAgain();


};

#endif // MYMUSIC_H

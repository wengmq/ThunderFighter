#include "myMusic.h"


myMusic::myMusic( QString fileName, QWidget *parent)
      : Phonon::VideoPlayer(parent)

  {

    //this->load(Phonon::MediaSource(fileName));

//    musicPlayer = new Phonon::VideoPlayer(Phonon::VideoCategory);
//    musicPlayer->load(Phonon::MediaSource(fileName));
//   // musicPlayer->play();
//    connect(musicPlayer,SIGNAL(finished()),this,SLOT(MusicPlay()));

    this->fileName = fileName;
       backsound = createPlayer(MusicCategory,MediaSource(fileName));
        backsound->play();
        connect(backsound,SIGNAL(aboutToFinish()),this,SLOT(playAgain()));

  }


// void myMusic::MusicPlay()
// {
//     musicPlayer->play();

// }


 void myMusic::playAgain()
 {
     backsound->setCurrentSource(MediaSource(fileName));
     backsound->play();
 }


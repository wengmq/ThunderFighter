/****************************************************************************
** Meta object code from reading C++ file 'gameView.h'
**
** Created: Thu Mar 28 19:02:56 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game/gameView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      75,    9,    9,    9, 0x0a,
      95,    9,    9,    9, 0x0a,
     112,    9,    9,    9, 0x0a,
     134,    9,    9,    9, 0x0a,
     159,    9,    9,    9, 0x0a,
     192,    9,    9,    9, 0x0a,
     200,    9,    9,    9, 0x0a,
     219,    9,    9,    9, 0x0a,
     245,  241,    9,    9, 0x0a,
     277,    9,    9,    9, 0x0a,
     300,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gameView[] = {
    "gameView\0\0backGameWidget_signal()\0"
    "enemy_plane_produce()\0enemy_plane_move()\0"
    "my_bullet_produce()\0my_bullet_move()\0"
    "my_bullet_colliding()\0enemy_bullet_colliding()\0"
    "enemy_planes_pProgressBar_slot()\0"
    "sleep()\0closeBtn_clicked()\0"
    "backHomeBtn_clicked()\0x,y\0"
    "deathBlast_produce(qreal,qreal)\0"
    "deathBlast_disappear()\0gameOver_slot()\0"
};

const QMetaObject gameView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_gameView,
      qt_meta_data_gameView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameView))
        return static_cast<void*>(const_cast< gameView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int gameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backGameWidget_signal(); break;
        case 1: enemy_plane_produce(); break;
        case 2: enemy_plane_move(); break;
        case 3: my_bullet_produce(); break;
        case 4: my_bullet_move(); break;
        case 5: my_bullet_colliding(); break;
        case 6: enemy_bullet_colliding(); break;
        case 7: enemy_planes_pProgressBar_slot(); break;
        case 8: sleep(); break;
        case 9: closeBtn_clicked(); break;
        case 10: backHomeBtn_clicked(); break;
        case 11: deathBlast_produce((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 12: deathBlast_disappear(); break;
        case 13: gameOver_slot(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void gameView::backGameWidget_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

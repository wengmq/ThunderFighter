/****************************************************************************
** Meta object code from reading C++ file 'gameOver.h'
**
** Created: Thu Mar 28 17:49:12 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game/gameOver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameOver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameOver[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gameOver[] = {
    "gameOver\0\0backGameView_signal()\0"
    "sureBtn_clicked()\0"
};

const QMetaObject gameOver::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameOver,
      qt_meta_data_gameOver, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameOver::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameOver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameOver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameOver))
        return static_cast<void*>(const_cast< gameOver*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameOver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backGameView_signal(); break;
        case 1: sureBtn_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void gameOver::backGameView_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

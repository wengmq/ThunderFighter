/****************************************************************************
** Meta object code from reading C++ file 'gameWidget.h'
**
** Created: Thu Mar 28 19:55:55 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game/gameWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x0a,
      46,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      83,   11,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gameWidget[] = {
    "gameWidget\0\0backHome_signal()\0"
    "backHome_slot()\0count_down_slot()\0"
    "labelChange_slot()\0GamestartPlay()\0"
    "musicPlay()\0"
};

const QMetaObject gameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameWidget,
      qt_meta_data_gameWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameWidget))
        return static_cast<void*>(const_cast< gameWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backHome_signal(); break;
        case 1: backHome_slot(); break;
        case 2: count_down_slot(); break;
        case 3: labelChange_slot(); break;
        case 4: GamestartPlay(); break;
        case 5: musicPlay(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void gameWidget::backHome_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

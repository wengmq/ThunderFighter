/****************************************************************************
** Meta object code from reading C++ file 'menuWidget.h'
**
** Created: Thu Mar 28 19:55:51 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu/menuWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_menuWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
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
      81,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     132,  121,   11,   11, 0x0a,
     157,   11,   11,   11, 0x0a,
     173,   11,   11,   11, 0x0a,
     191,   11,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,
     227,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_menuWidget[] = {
    "menuWidget\0\0backLoginSignal()\0"
    "backLoginSlot()\0helpBtn_clicked()\0"
    "setupBtn_click()\0RanKingBtn_clicked()\0"
    "startBtn_clicked()\0CloseEvent\0"
    "closeEvent(QCloseEvent*)\0gameBack_slot()\0"
    "leftBtn_clicked()\0rightBtn_clicked()\0"
    "closeBtn_click()\0mapBtn_clicked()\0"
};

const QMetaObject menuWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_menuWidget,
      qt_meta_data_menuWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &menuWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *menuWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *menuWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_menuWidget))
        return static_cast<void*>(const_cast< menuWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int menuWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backLoginSignal(); break;
        case 1: backLoginSlot(); break;
        case 2: helpBtn_clicked(); break;
        case 3: setupBtn_click(); break;
        case 4: RanKingBtn_clicked(); break;
        case 5: startBtn_clicked(); break;
        case 6: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 7: gameBack_slot(); break;
        case 8: leftBtn_clicked(); break;
        case 9: rightBtn_clicked(); break;
        case 10: closeBtn_click(); break;
        case 11: mapBtn_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void menuWidget::backLoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

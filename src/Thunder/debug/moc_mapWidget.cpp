/****************************************************************************
** Meta object code from reading C++ file 'mapWidget.h'
**
** Created: Thu Mar 28 19:02:58 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu/mapWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mapWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      47,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mapWidget[] = {
    "mapWidget\0\0map1Btn_clicked()\0"
    "map2Btn_clicked()\0map3Btn_clicked()\0"
    "map4Btn_clicked()\0"
};

const QMetaObject mapWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mapWidget,
      qt_meta_data_mapWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mapWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mapWidget))
        return static_cast<void*>(const_cast< mapWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int mapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: map1Btn_clicked(); break;
        case 1: map2Btn_clicked(); break;
        case 2: map3Btn_clicked(); break;
        case 3: map4Btn_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

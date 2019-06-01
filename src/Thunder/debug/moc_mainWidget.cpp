/****************************************************************************
** Meta object code from reading C++ file 'mainWidget.h'
**
** Created: Thu Mar 28 19:55:48 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../login/mainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      31,   11,   11,   11, 0x0a,
      53,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      79,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainWidget[] = {
    "mainWidget\0\0loginBtn_clicked()\0"
    "registerBtn_clicked()\0loginBack()\0"
    "regiterBack()\0musicPlay()\0closeBtn_click()\0"
};

const QMetaObject mainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainWidget,
      qt_meta_data_mainWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainWidget))
        return static_cast<void*>(const_cast< mainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loginBtn_clicked(); break;
        case 1: registerBtn_clicked(); break;
        case 2: loginBack(); break;
        case 3: regiterBack(); break;
        case 4: musicPlay(); break;
        case 5: closeBtn_click(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'registerWidget.h'
**
** Created: Tue Mar 26 19:47:43 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../login/registerWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_registerWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   15,   15,   15, 0x0a,
      52,   15,   15,   15, 0x0a,
      70,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_registerWidget[] = {
    "registerWidget\0\0BackLoginSignal()\0"
    "backBtn_clicked()\0sureBtn_clicked()\0"
    "closeBtn_click()\0"
};

const QMetaObject registerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_registerWidget,
      qt_meta_data_registerWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &registerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *registerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *registerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_registerWidget))
        return static_cast<void*>(const_cast< registerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int registerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: BackLoginSignal(); break;
        case 1: backBtn_clicked(); break;
        case 2: sureBtn_clicked(); break;
        case 3: closeBtn_click(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void registerWidget::BackLoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

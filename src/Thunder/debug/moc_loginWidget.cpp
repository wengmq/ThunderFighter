/****************************************************************************
** Meta object code from reading C++ file 'loginWidget.h'
**
** Created: Thu Mar 28 19:55:44 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../login/loginWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_loginWidget[] = {

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
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x0a,
      69,   12,   12,   12, 0x0a,
      86,   12,   12,   12, 0x0a,
     111,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_loginWidget[] = {
    "loginWidget\0\0ReturnLoginSignal()\0"
    "sureBtn_clicked()\0backBtn_clicked()\0"
    "backLogin_slot()\0forgetPwdLabel_clicked()\0"
    "closeBtn_click()\0"
};

const QMetaObject loginWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_loginWidget,
      qt_meta_data_loginWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &loginWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *loginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *loginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_loginWidget))
        return static_cast<void*>(const_cast< loginWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int loginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ReturnLoginSignal(); break;
        case 1: sureBtn_clicked(); break;
        case 2: backBtn_clicked(); break;
        case 3: backLogin_slot(); break;
        case 4: forgetPwdLabel_clicked(); break;
        case 5: closeBtn_click(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void loginWidget::ReturnLoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

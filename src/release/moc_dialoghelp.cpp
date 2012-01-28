/****************************************************************************
** Meta object code from reading C++ file 'dialoghelp.h'
**
** Created: Fri Jun 26 13:14:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialoghelp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialoghelp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogHelp[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_DialogHelp[] = {
    "DialogHelp\0"
};

const QMetaObject DialogHelp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogHelp,
      qt_meta_data_DialogHelp, 0 }
};

const QMetaObject *DialogHelp::metaObject() const
{
    return &staticMetaObject;
}

void *DialogHelp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogHelp))
        return static_cast<void*>(const_cast< DialogHelp*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogHelp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

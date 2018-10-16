/****************************************************************************
** Meta object code from reading C++ file 'NotebookGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NotebookGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotebookGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NotebookGUI_t {
    QByteArrayData data[7];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotebookGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotebookGUI_t qt_meta_stringdata_NotebookGUI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NotebookGUI"
QT_MOC_LITERAL(1, 12, 9), // "changeTab"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "index"
QT_MOC_LITERAL(4, 29, 10), // "runCommand"
QT_MOC_LITERAL(5, 40, 6), // "Device"
QT_MOC_LITERAL(6, 47, 6) // "string"

    },
    "NotebookGUI\0changeTab\0\0index\0runCommand\0"
    "Device\0string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotebookGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    3,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6, 0x80000000 | 6,    2,    2,    2,

       0        // eod
};

void NotebookGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotebookGUI *_t = static_cast<NotebookGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->runCommand((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< string(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject NotebookGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NotebookGUI.data,
      qt_meta_data_NotebookGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NotebookGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotebookGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NotebookGUI.stringdata0))
        return static_cast<void*>(const_cast< NotebookGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int NotebookGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

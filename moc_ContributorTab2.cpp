/****************************************************************************
** Meta object code from reading C++ file 'ContributorTab2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ContributorTab2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContributorTab2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContributorTab2_t {
    QByteArrayData data[9];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContributorTab2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContributorTab2_t qt_meta_stringdata_ContributorTab2 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ContributorTab2"
QT_MOC_LITERAL(1, 16, 12), // "updateScreen"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "Device"
QT_MOC_LITERAL(4, 37, 6), // "device"
QT_MOC_LITERAL(5, 44, 28), // "on_description_linkActivated"
QT_MOC_LITERAL(6, 73, 4), // "link"
QT_MOC_LITERAL(7, 78, 13), // "receiveReboot"
QT_MOC_LITERAL(8, 92, 13) // "RebootMachine"

    },
    "ContributorTab2\0updateScreen\0\0Device\0"
    "device\0on_description_linkActivated\0"
    "link\0receiveReboot\0RebootMachine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContributorTab2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ContributorTab2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContributorTab2 *_t = static_cast<ContributorTab2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateScreen((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 1: _t->on_description_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->receiveReboot(); break;
        case 3: _t->RebootMachine(); break;
        default: ;
        }
    }
}

const QMetaObject ContributorTab2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContributorTab2.data,
      qt_meta_data_ContributorTab2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContributorTab2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContributorTab2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContributorTab2.stringdata0))
        return static_cast<void*>(const_cast< ContributorTab2*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContributorTab2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

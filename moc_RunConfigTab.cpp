/****************************************************************************
** Meta object code from reading C++ file 'RunConfigTab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RunConfigTab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RunConfigTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RunTab_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RunTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RunTab_t qt_meta_stringdata_RunTab = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RunTab"
QT_MOC_LITERAL(1, 7, 6), // "setTab"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 9), // "setDevice"
QT_MOC_LITERAL(4, 25, 6), // "Device"
QT_MOC_LITERAL(5, 32, 13), // "installButton"
QT_MOC_LITERAL(6, 46, 15), // "uninstallButton"
QT_MOC_LITERAL(7, 62, 13), // "restoreButton"
QT_MOC_LITERAL(8, 76, 7) // "upgrade"

    },
    "RunTab\0setTab\0\0setDevice\0Device\0"
    "installButton\0uninstallButton\0"
    "restoreButton\0upgrade"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RunTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       8,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void RunTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RunTab *_t = static_cast<RunTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setDevice((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 2: _t->installButton((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 3: _t->uninstallButton((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 4: _t->restoreButton((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 5: _t->upgrade((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RunTab::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RunTab::setTab)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RunTab::*_t)(Device );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RunTab::setDevice)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RunTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RunTab.data,
      qt_meta_data_RunTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RunTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RunTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RunTab.stringdata0))
        return static_cast<void*>(const_cast< RunTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int RunTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RunTab::setTab(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RunTab::setDevice(Device _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

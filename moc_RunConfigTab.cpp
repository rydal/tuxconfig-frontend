/****************************************************************************
** Meta object code from reading C++ file 'RunConfigTab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RunConfigTab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RunConfigTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RunTab_t {
    QByteArrayData data[11];
    char stringdata0[112];
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
QT_MOC_LITERAL(3, 15, 11), // "sendCommand"
QT_MOC_LITERAL(4, 27, 6), // "Device"
QT_MOC_LITERAL(5, 34, 6), // "string"
QT_MOC_LITERAL(6, 41, 14), // "vector<string>"
QT_MOC_LITERAL(7, 56, 13), // "installButton"
QT_MOC_LITERAL(8, 70, 15), // "uninstallButton"
QT_MOC_LITERAL(9, 86, 7), // "upgrade"
QT_MOC_LITERAL(10, 94, 17) // "updates_available"

    },
    "RunTab\0setTab\0\0sendCommand\0Device\0"
    "string\0vector<string>\0installButton\0"
    "uninstallButton\0upgrade\0updates_available"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RunTab[] = {

 // content:
       8,       // revision
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
       3,    3,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5, 0x80000000 | 6,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void RunTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RunTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendCommand((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3]))); break;
        case 2: _t->installButton((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 3: _t->uninstallButton((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 4: _t->upgrade((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 5: _t->updates_available(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RunTab::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RunTab::setTab)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RunTab::*)(Device , string , vector<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RunTab::sendCommand)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RunTab::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RunTab.data,
    qt_meta_data_RunTab,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RunTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RunTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RunTab.stringdata0))
        return static_cast<void*>(this);
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RunTab::sendCommand(Device _t1, string _t2, vector<string> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

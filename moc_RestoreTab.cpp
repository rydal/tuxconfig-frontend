/****************************************************************************
** Meta object code from reading C++ file 'RestoreTab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RestoreTab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RestoreTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RestoreTab_t {
    QByteArrayData data[10];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RestoreTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RestoreTab_t qt_meta_stringdata_RestoreTab = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RestoreTab"
QT_MOC_LITERAL(1, 11, 11), // "sendCommand"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "Device"
QT_MOC_LITERAL(4, 31, 6), // "string"
QT_MOC_LITERAL(5, 38, 14), // "vector<string>"
QT_MOC_LITERAL(6, 53, 12), // "updateScreen"
QT_MOC_LITERAL(7, 66, 6), // "setTab"
QT_MOC_LITERAL(8, 73, 6), // "update"
QT_MOC_LITERAL(9, 80, 7) // "message"

    },
    "RestoreTab\0sendCommand\0\0Device\0string\0"
    "vector<string>\0updateScreen\0setTab\0"
    "update\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestoreTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       6,    0,   41,    2, 0x06 /* Public */,
       7,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    9,

       0        // eod
};

void RestoreTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RestoreTab *_t = static_cast<RestoreTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCommand((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3]))); break;
        case 1: _t->updateScreen(); break;
        case 2: _t->setTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->update((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RestoreTab::*_t)(Device , string , vector<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestoreTab::sendCommand)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RestoreTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestoreTab::updateScreen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RestoreTab::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestoreTab::setTab)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RestoreTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RestoreTab.data,
      qt_meta_data_RestoreTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RestoreTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestoreTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RestoreTab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RestoreTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void RestoreTab::sendCommand(Device _t1, string _t2, vector<string> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RestoreTab::updateScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RestoreTab::setTab(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

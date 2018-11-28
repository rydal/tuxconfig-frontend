/****************************************************************************
** Meta object code from reading C++ file 'ConsoleTab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ConsoleTab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConsoleTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConsoleTab_t {
    QByteArrayData data[16];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConsoleTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConsoleTab_t qt_meta_stringdata_ConsoleTab = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ConsoleTab"
QT_MOC_LITERAL(1, 11, 6), // "setTab"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "updateScreen"
QT_MOC_LITERAL(4, 32, 14), // "refreshRestore"
QT_MOC_LITERAL(5, 47, 6), // "string"
QT_MOC_LITERAL(6, 54, 10), // "sendReboot"
QT_MOC_LITERAL(7, 65, 11), // "showButtons"
QT_MOC_LITERAL(8, 77, 14), // "vector<string>"
QT_MOC_LITERAL(9, 92, 7), // "details"
QT_MOC_LITERAL(10, 100, 7), // "success"
QT_MOC_LITERAL(11, 108, 13), // "sendToConsole"
QT_MOC_LITERAL(12, 122, 6), // "Device"
QT_MOC_LITERAL(13, 129, 6), // "device"
QT_MOC_LITERAL(14, 136, 6), // "method"
QT_MOC_LITERAL(15, 143, 10) // "parameters"

    },
    "ConsoleTab\0setTab\0\0updateScreen\0"
    "refreshRestore\0string\0sendReboot\0"
    "showButtons\0vector<string>\0details\0"
    "success\0sendToConsole\0Device\0device\0"
    "method\0parameters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsoleTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,
       6,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   52,    2, 0x0a /* Public */,
      11,    3,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::Bool,    9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 5, 0x80000000 | 8,   13,   14,   15,

       0        // eod
};

void ConsoleTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConsoleTab *_t = static_cast<ConsoleTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateScreen(); break;
        case 2: _t->refreshRestore((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->sendReboot(); break;
        case 4: _t->showButtons((*reinterpret_cast< vector<string>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->sendToConsole((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConsoleTab::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsoleTab::setTab)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConsoleTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsoleTab::updateScreen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ConsoleTab::*_t)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsoleTab::refreshRestore)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ConsoleTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsoleTab::sendReboot)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ConsoleTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConsoleTab.data,
      qt_meta_data_ConsoleTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConsoleTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsoleTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleTab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConsoleTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ConsoleTab::setTab(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConsoleTab::updateScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ConsoleTab::refreshRestore(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ConsoleTab::sendReboot()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

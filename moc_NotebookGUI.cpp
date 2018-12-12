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
    QByteArrayData data[17];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotebookGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotebookGUI_t qt_meta_stringdata_NotebookGUI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NotebookGUI"
QT_MOC_LITERAL(1, 12, 18), // "updatedContributor"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "Device"
QT_MOC_LITERAL(4, 39, 6), // "device"
QT_MOC_LITERAL(5, 46, 11), // "showButtons"
QT_MOC_LITERAL(6, 58, 14), // "vector<string>"
QT_MOC_LITERAL(7, 73, 12), // "updateDevice"
QT_MOC_LITERAL(8, 86, 13), // "sendToConsole"
QT_MOC_LITERAL(9, 100, 6), // "string"
QT_MOC_LITERAL(10, 107, 24), // "updates_available_signal"
QT_MOC_LITERAL(11, 132, 9), // "changeTab"
QT_MOC_LITERAL(12, 142, 5), // "index"
QT_MOC_LITERAL(13, 148, 10), // "runCommand"
QT_MOC_LITERAL(14, 159, 6), // "method"
QT_MOC_LITERAL(15, 166, 10), // "parameters"
QT_MOC_LITERAL(16, 177, 17) // "updateContributor"

    },
    "NotebookGUI\0updatedContributor\0\0Device\0"
    "device\0showButtons\0vector<string>\0"
    "updateDevice\0sendToConsole\0string\0"
    "updates_available_signal\0changeTab\0"
    "index\0runCommand\0method\0parameters\0"
    "updateContributor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotebookGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    2,   57,    2, 0x06 /* Public */,
       7,    1,   62,    2, 0x06 /* Public */,
       8,    3,   65,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   73,    2, 0x0a /* Public */,
      13,    3,   76,    2, 0x0a /* Public */,
      16,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 6,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 6,    4,   14,   15,
    QMetaType::Void,

       0        // eod
};

void NotebookGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotebookGUI *_t = static_cast<NotebookGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatedContributor((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 1: _t->showButtons((*reinterpret_cast< vector<string>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->updateDevice((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 3: _t->sendToConsole((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3]))); break;
        case 4: _t->updates_available_signal(); break;
        case 5: _t->changeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->runCommand((*reinterpret_cast< Device(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3]))); break;
        case 7: _t->updateContributor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NotebookGUI::*_t)(Device );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotebookGUI::updatedContributor)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NotebookGUI::*_t)(vector<string> , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotebookGUI::showButtons)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NotebookGUI::*_t)(Device );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotebookGUI::updateDevice)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NotebookGUI::*_t)(Device , string , vector<string> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotebookGUI::sendToConsole)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NotebookGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotebookGUI::updates_available_signal)) {
                *result = 4;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NotebookGUI::updatedContributor(Device _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NotebookGUI::showButtons(vector<string> _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NotebookGUI::updateDevice(Device _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NotebookGUI::sendToConsole(Device _t1, string _t2, vector<string> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NotebookGUI::updates_available_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

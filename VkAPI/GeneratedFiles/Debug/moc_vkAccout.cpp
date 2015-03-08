/****************************************************************************
** Meta object code from reading C++ file 'vkAccout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vkAccout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vkAccout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vk__vkAccount_t {
    QByteArrayData data[17];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vk__vkAccount_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vk__vkAccount_t qt_meta_stringdata_vk__vkAccount = {
    {
QT_MOC_LITERAL(0, 0, 13), // "vk::vkAccount"
QT_MOC_LITERAL(1, 14, 11), // "syncStarted"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "syncFinished"
QT_MOC_LITERAL(4, 40, 9), // "syncError"
QT_MOC_LITERAL(5, 50, 15), // "requestFinished"
QT_MOC_LITERAL(6, 66, 12), // "requestError"
QT_MOC_LITERAL(7, 79, 15), // "ApiRequestError"
QT_MOC_LITERAL(8, 95, 13), // "requestSended"
QT_MOC_LITERAL(9, 109, 15), // "syncInformation"
QT_MOC_LITERAL(10, 125, 17), // "updateInformation"
QT_MOC_LITERAL(11, 143, 13), // "finishRequest"
QT_MOC_LITERAL(12, 157, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 172, 10), // "first_name"
QT_MOC_LITERAL(14, 183, 9), // "last_mame"
QT_MOC_LITERAL(15, 193, 12), // "access_token"
QT_MOC_LITERAL(16, 206, 7) // "user_id"

    },
    "vk::vkAccount\0syncStarted\0\0syncFinished\0"
    "syncError\0requestFinished\0requestError\0"
    "ApiRequestError\0requestSended\0"
    "syncInformation\0updateInformation\0"
    "finishRequest\0QNetworkReply*\0first_name\0"
    "last_mame\0access_token\0user_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vk__vkAccount[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       4,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   69,    2, 0x0a /* Public */,
      10,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 12,    2,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00095001,
      14, QMetaType::QString, 0x00095001,
      15, QMetaType::QString, 0x00095001,
      16, QMetaType::QString, 0x00095001,

       0        // eod
};

void vk::vkAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vkAccount *_t = static_cast<vkAccount *>(_o);
        switch (_id) {
        case 0: _t->syncStarted(); break;
        case 1: _t->syncFinished(); break;
        case 2: _t->syncError(); break;
        case 3: _t->requestFinished((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->requestError((*reinterpret_cast< const ApiRequestError(*)>(_a[1]))); break;
        case 5: _t->requestSended(); break;
        case 6: _t->syncInformation(); break;
        case 7: _t->updateInformation((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->finishRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vkAccount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::syncStarted)) {
                *result = 0;
            }
        }
        {
            typedef void (vkAccount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::syncFinished)) {
                *result = 1;
            }
        }
        {
            typedef void (vkAccount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::syncError)) {
                *result = 2;
            }
        }
        {
            typedef void (vkAccount::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::requestFinished)) {
                *result = 3;
            }
        }
        {
            typedef void (vkAccount::*_t)(const ApiRequestError & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::requestError)) {
                *result = 4;
            }
        }
        {
            typedef void (vkAccount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vkAccount::requestSended)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject vk::vkAccount::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vk__vkAccount.data,
      qt_meta_data_vk__vkAccount,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vk::vkAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vk::vkAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vk__vkAccount.stringdata))
        return static_cast<void*>(const_cast< vkAccount*>(this));
    return QWidget::qt_metacast(_clname);
}

int vk::vkAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getFirstName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getLastName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getToken(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getUserID(); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void vk::vkAccount::syncStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void vk::vkAccount::syncFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void vk::vkAccount::syncError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void vk::vkAccount::requestFinished(const QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void vk::vkAccount::requestError(const ApiRequestError & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vk::vkAccount::requestSended()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

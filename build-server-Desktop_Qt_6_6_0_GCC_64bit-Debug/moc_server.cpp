/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/server.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSClientHandlerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSClientHandlerENDCLASS = QtMocHelpers::stringData(
    "ClientHandler",
    "clientSubscribedCurrency",
    "",
    "clientUnsubscribedCurrency",
    "clientSubscribedStonks",
    "clientUnsubscribedStonks",
    "clientSubscribedForecast",
    "clientUnsubscribedForecast",
    "sendPeriodicMessageCurrency",
    "sendPeriodicMessageStonks",
    "sendPeriodicMessageForecast"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSClientHandlerENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[14];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[23];
    char stringdata5[25];
    char stringdata6[25];
    char stringdata7[27];
    char stringdata8[28];
    char stringdata9[26];
    char stringdata10[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSClientHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSClientHandlerENDCLASS_t qt_meta_stringdata_CLASSClientHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ClientHandler"
        QT_MOC_LITERAL(14, 24),  // "clientSubscribedCurrency"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 26),  // "clientUnsubscribedCurrency"
        QT_MOC_LITERAL(67, 22),  // "clientSubscribedStonks"
        QT_MOC_LITERAL(90, 24),  // "clientUnsubscribedStonks"
        QT_MOC_LITERAL(115, 24),  // "clientSubscribedForecast"
        QT_MOC_LITERAL(140, 26),  // "clientUnsubscribedForecast"
        QT_MOC_LITERAL(167, 27),  // "sendPeriodicMessageCurrency"
        QT_MOC_LITERAL(195, 25),  // "sendPeriodicMessageStonks"
        QT_MOC_LITERAL(221, 27)   // "sendPeriodicMessageForecast"
    },
    "ClientHandler",
    "clientSubscribedCurrency",
    "",
    "clientUnsubscribedCurrency",
    "clientSubscribedStonks",
    "clientUnsubscribedStonks",
    "clientSubscribedForecast",
    "clientUnsubscribedForecast",
    "sendPeriodicMessageCurrency",
    "sendPeriodicMessageStonks",
    "sendPeriodicMessageForecast"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSClientHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    0,   76,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClientHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSClientHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSClientHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSClientHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ClientHandler, std::true_type>,
        // method 'clientSubscribedCurrency'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clientUnsubscribedCurrency'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clientSubscribedStonks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clientUnsubscribedStonks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clientSubscribedForecast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clientUnsubscribedForecast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendPeriodicMessageCurrency'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendPeriodicMessageStonks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendPeriodicMessageForecast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ClientHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientSubscribedCurrency(); break;
        case 1: _t->clientUnsubscribedCurrency(); break;
        case 2: _t->clientSubscribedStonks(); break;
        case 3: _t->clientUnsubscribedStonks(); break;
        case 4: _t->clientSubscribedForecast(); break;
        case 5: _t->clientUnsubscribedForecast(); break;
        case 6: _t->sendPeriodicMessageCurrency(); break;
        case 7: _t->sendPeriodicMessageStonks(); break;
        case 8: _t->sendPeriodicMessageForecast(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ClientHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSClientHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSserverENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSserverENDCLASS = QtMocHelpers::stringData(
    "server",
    "incomingConnection",
    "",
    "qintptr",
    "socketDescriptor",
    "slotReadyRead",
    "SendToClient",
    "str",
    "QTcpSocket*",
    "socket"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSserverENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[7];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[17];
    char stringdata5[14];
    char stringdata6[13];
    char stringdata7[4];
    char stringdata8[12];
    char stringdata9[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSserverENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSserverENDCLASS_t qt_meta_stringdata_CLASSserverENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "server"
        QT_MOC_LITERAL(7, 18),  // "incomingConnection"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "qintptr"
        QT_MOC_LITERAL(35, 16),  // "socketDescriptor"
        QT_MOC_LITERAL(52, 13),  // "slotReadyRead"
        QT_MOC_LITERAL(66, 12),  // "SendToClient"
        QT_MOC_LITERAL(79, 3),  // "str"
        QT_MOC_LITERAL(83, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(95, 6)   // "socket"
    },
    "server",
    "incomingConnection",
    "",
    "qintptr",
    "socketDescriptor",
    "slotReadyRead",
    "SendToClient",
    "str",
    "QTcpSocket*",
    "socket"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSserverENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       5,    0,   35,    2, 0x0a,    3 /* Public */,
       6,    2,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    7,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject server::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_CLASSserverENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSserverENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSserverENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<server, std::true_type>,
        // method 'incomingConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qintptr, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendToClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>
    >,
    nullptr
} };

void server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->incomingConnection((*reinterpret_cast< std::add_pointer_t<qintptr>>(_a[1]))); break;
        case 1: _t->slotReadyRead(); break;
        case 2: _t->SendToClient((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSserverENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP

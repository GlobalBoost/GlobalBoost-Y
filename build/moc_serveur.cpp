/****************************************************************************
** Meta object code from reading C++ file 'serveur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/serveur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serveur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Serveur_t {
    QByteArrayData data[21];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Serveur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Serveur_t qt_meta_stringdata_Serveur = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 7),
QT_MOC_LITERAL(5, 41, 9),
QT_MOC_LITERAL(6, 51, 11),
QT_MOC_LITERAL(7, 63, 11),
QT_MOC_LITERAL(8, 75, 28),
QT_MOC_LITERAL(9, 104, 9),
QT_MOC_LITERAL(10, 114, 5),
QT_MOC_LITERAL(11, 120, 8),
QT_MOC_LITERAL(12, 129, 3),
QT_MOC_LITERAL(13, 133, 4),
QT_MOC_LITERAL(14, 138, 4),
QT_MOC_LITERAL(15, 143, 5),
QT_MOC_LITERAL(16, 149, 6),
QT_MOC_LITERAL(17, 156, 8),
QT_MOC_LITERAL(18, 165, 7),
QT_MOC_LITERAL(19, 173, 15),
QT_MOC_LITERAL(20, 189, 7)
    },
    "Serveur\0pseudoChanged\0\0newPseudo\0"
    "joinTab\0tabJoined\0readServeur\0errorSocket\0"
    "QAbstractSocket::SocketError\0connected\0"
    "joins\0sendData\0txt\0join\0chan\0leave\0"
    "ecrire\0destChan\0msgTray\0updateUsersList\0"
    "message\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serveur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06,
       4,    0,   97,    2, 0x06,
       5,    0,   98,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   99,    2, 0x0a,
       7,    1,  100,    2, 0x0a,
       9,    0,  103,    2, 0x0a,
      10,    0,  104,    2, 0x0a,
      11,    1,  105,    2, 0x0a,
      13,    1,  108,    2, 0x0a,
      15,    1,  111,    2, 0x0a,
      16,    3,  114,    2, 0x0a,
      16,    2,  121,    2, 0x2a,
      16,    1,  126,    2, 0x2a,
      19,    2,  129,    2, 0x0a,
      19,    1,  134,    2, 0x2a,
      19,    0,  137,    2, 0x2a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   17,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   17,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   20,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,

       0        // eod
};

void Serveur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Serveur *_t = static_cast<Serveur *>(_o);
        switch (_id) {
        case 0: _t->pseudoChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->joinTab(); break;
        case 2: _t->tabJoined(); break;
        case 3: _t->readServeur(); break;
        case 4: _t->errorSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->connected(); break;
        case 6: _t->joins(); break;
        case 7: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->join((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->leave((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ecrire((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->ecrire((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->ecrire((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateUsersList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->updateUsersList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->updateUsersList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Serveur::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Serveur::pseudoChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Serveur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Serveur::joinTab)) {
                *result = 1;
            }
        }
        {
            typedef void (Serveur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Serveur::tabJoined)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Serveur::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_Serveur.data,
      qt_meta_data_Serveur,  qt_static_metacall, 0, 0}
};


const QMetaObject *Serveur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serveur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Serveur.stringdata))
        return static_cast<void*>(const_cast< Serveur*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int Serveur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Serveur::pseudoChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Serveur::joinTab()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Serveur::tabJoined()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

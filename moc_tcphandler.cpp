/****************************************************************************
** Meta object code from reading C++ file 'tcphandler.h'
**
** Created: Tue Apr 15 13:46:29 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcphandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcphandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tcpHandler[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      37,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_tcpHandler[] = {
    "tcpHandler\0\0initialize()\0SetFPGAIP()\0"
    "PingFPGA()\0"
};

const QMetaObject tcpHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tcpHandler,
      qt_meta_data_tcpHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tcpHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tcpHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tcpHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tcpHandler))
        return static_cast<void*>(const_cast< tcpHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int tcpHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initialize(); break;
        case 1: SetFPGAIP(); break;
        case 2: PingFPGA(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

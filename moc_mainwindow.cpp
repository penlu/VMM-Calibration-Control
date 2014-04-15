/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Apr 15 13:46:24 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      76,   11,   11,   11, 0x0a,
      90,   11,   11,   11, 0x0a,
     103,   11,   11,   11, 0x0a,
     117,   11,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,
     140,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     162,   11,   11,   11, 0x0a,
     189,  183,   11,   11, 0x0a,
     228,  216,   11,   11, 0x0a,
     247,   11,   11,   11, 0x0a,
     277,  216,   11,   11, 0x0a,
     312,  300,   11,   11, 0x0a,
     371,  366,  355,   11, 0x0a,
     400,  394,   11,   11, 0x0a,
     418,  394,   11,   11, 0x0a,
     451,  443,  439,   11, 0x0a,
     478,   11,   11,   11, 0x0a,
     497,   11,   11,   11, 0x0a,
     520,   11,   11,   11, 0x0a,
     534,   11,   11,   11, 0x0a,
     591,  558,  550,   11, 0x0a,
     636,  624,  550,   11, 0x0a,
     655,   11,   11,   11, 0x0a,
     686,   11,   11,   11, 0x0a,
     707,   11,   11,   11, 0x0a,
     720,   11,   11,   11, 0x0a,
     736,   11,   11,   11, 0x0a,
     753,   11,   11,   11, 0x0a,
     770,   11,   11,   11, 0x0a,
     804,  792,   11,   11, 0x0a,
     833,  827,   11,   11, 0x0a,
     853,   11,   11,   11, 0x0a,
     873,   11,   11,   11, 0x0a,
     891,   11,   11,   11, 0x0a,
     930,  924,  909,   11, 0x0a,
     954,  924,  909,   11, 0x0a,
     985,   11,   11,   11, 0x0a,
    1006,   11,   11,   11, 0x0a,
    1031,   11,   11,   11, 0x0a,
    1050,   11,   11,   11, 0x0a,
    1080,   11,   11,   11, 0x0a,
    1095,  394,   11,   11, 0x0a,
    1118, 1115,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0PingFec()\0PingFPGA()\0"
    "SetNumberOfFecs(int)\0SetFPGAIP()\0"
    "Connect()\0dataPending()\0ConnectTCP()\0"
    "ConnectFPGA()\0readTCP()\0Disconnect()\0"
    "Merger()\0MergerFPGA()\0updateChannelState()\0"
    "index\0updateChannelVoltages(int)\0"
    "blockOfData\0Sender(QByteArray)\0"
    "SendVector(std::vector<uint>)\0"
    "SenderFPGA(QByteArray)\0socketError\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "QByteArray\0bits\0bitsToBytes(QBitArray)\0"
    "state\0hideChannels(int)\0showDebugScreen(int)\0"
    "int\0package\0packageHandler(QByteArray)\0"
    "clearDebugScreen()\0customCommandHandler()\0"
    "downloadSPI()\0UpdateCounter()\0quint32\0"
    "datagramHex,bitToChange,bitValue\0"
    "ValueToReplace(QString,int,bool)\0"
    "datagramHex\0reverse32(QString)\0"
    "customCommandWithoutResponse()\0"
    "constructHeader(int)\0sendDis(int)\0"
    "threadHandler()\0triggerHandler()\0"
    "dataDAQPending()\0triggerHandler_fpga()\0"
    "inputPacket\0writeFPGAFile(QString)\0"
    "value\0changeDACtoMVs(int)\0openMonitoring(int)\0"
    "initializePlots()\0updateCanvas(int)\0"
    "vector<double>\0bytes\0bytesTobits(QByteArray)\0"
    "bytesTobitsTrigger(QByteArray)\0"
    "SetChambersMapping()\0selectWorkingDirectory()\0"
    "startCalibration()\0loadCalibrationConstants(int)\0"
    "HandleRecipe()\0LoadThresholds(int)\0"
    ",,\0doCalibrationRun(int,int,int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PingFec(); break;
        case 1: PingFPGA(); break;
        case 2: SetNumberOfFecs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: SetFPGAIP(); break;
        case 4: Connect(); break;
        case 5: dataPending(); break;
        case 6: ConnectTCP(); break;
        case 7: ConnectFPGA(); break;
        case 8: readTCP(); break;
        case 9: Disconnect(); break;
        case 10: Merger(); break;
        case 11: MergerFPGA(); break;
        case 12: updateChannelState(); break;
        case 13: updateChannelVoltages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: Sender((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 15: SendVector((*reinterpret_cast< std::vector<uint>(*)>(_a[1]))); break;
        case 16: SenderFPGA((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 18: { QByteArray _r = bitsToBytes((*reinterpret_cast< QBitArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 19: hideChannels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: showDebugScreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: { int _r = packageHandler((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 22: clearDebugScreen(); break;
        case 23: customCommandHandler(); break;
        case 24: downloadSPI(); break;
        case 25: UpdateCounter(); break;
        case 26: { quint32 _r = ValueToReplace((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = _r; }  break;
        case 27: { quint32 _r = reverse32((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = _r; }  break;
        case 28: customCommandWithoutResponse(); break;
        case 29: constructHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: sendDis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: threadHandler(); break;
        case 32: triggerHandler(); break;
        case 33: dataDAQPending(); break;
        case 34: triggerHandler_fpga(); break;
        case 35: writeFPGAFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: changeDACtoMVs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: openMonitoring((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: initializePlots(); break;
        case 39: updateCanvas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: { vector<double> _r = bytesTobits((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<double>*>(_a[0]) = _r; }  break;
        case 41: { vector<double> _r = bytesTobitsTrigger((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<double>*>(_a[0]) = _r; }  break;
        case 42: SetChambersMapping(); break;
        case 43: selectWorkingDirectory(); break;
        case 44: startCalibration(); break;
        case 45: loadCalibrationConstants((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: HandleRecipe(); break;
        case 47: LoadThresholds((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: doCalibrationRun((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 49;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

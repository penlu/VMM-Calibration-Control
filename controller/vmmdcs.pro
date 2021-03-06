#-------------------------------------------------
#
# Project created by QtCreator 2012-06-18T11:31:24
#
#-------------------------------------------------

QT       += core gui
QT           += network

TARGET = vmmdcs
TEMPLATE = app

INCLUDEPATH += $(ROOTSYS)/include
INCLUDEPATH += $(ROOTSYS)/include/root
win32:LIBS += -L$(ROOTSYS)/lib -llibCint -llibRIO -llibNet \
       -llibHist -llibGraf -llibGraf3d -llibGpad -llibTree \
       -llibRint -llibPostscript -llibMatrix -llibPhysics \
       -llibGui -llibRGL -llibMathCore -L$(ROOTSYS)/lib/root
else:LIBS += -L$(ROOTSYS)/lib -lCore -lCint -lRIO -lNet \
       -lHist -lGraf -lGraf3d -lGpad -lTree \
       -lRint -lPostscript -lMatrix -lPhysics \
       -lGui -lRGL -lMathCore -L$(ROOTSYS)/lib/root

SOURCES += main.cpp\
        mainwindow.cpp \
    sleeper.cpp \
    mythread.cpp \
    tcphandlerthread.cpp \
    tcphandler.cpp

HEADERS  += mainwindow.h \
    constants.h \
    sleeper.h \
    mythread.h \
    tcphandlerthread.h \
    tcphandler.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc \
    calibration_data.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2022-06-27T15:03:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TetrisELSFK
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    MyGrid.cpp \
    shape/shapeModel.cpp \
    shape/shapeLine.cpp \
    shape/shapeRect.cpp \
    shape/shapeZ1.cpp \
    shape/shapel1.cpp \
    shape/shapel2.cpp \
    shape/shapeTrangle.cpp \
    shape/shapeZ2.cpp

HEADERS += \
        mainwindow.h \
    mystudio.h \
    MyGrid.h \
    shape/shapeModel.h \
    shape/shapeLine.h \
    shape/shapeRect.h \
    shape/shapeZ1.h \
    shape/shapel1.h \
    shape/shapel2.h \
    shape/shapeTrangle.h \
    shape/shapeZ2.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc

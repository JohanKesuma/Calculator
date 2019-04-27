#-------------------------------------------------
#
# Project created by QtCreator 2019-04-22T19:49:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator-R
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
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../lib/libBacaExcel/build-BacaExcel-Desktop_Qt_5_12_1_GCC_64bit-Debug/ -lBacaExcel

INCLUDEPATH += $$PWD/../lib/libBacaExcel/BacaExcel
DEPENDPATH += $$PWD/../lib/libBacaExcel/BacaExcel

unix:!macx: LIBS += -L$$PWD/../lib/libNormalisasi/build-Normalisasi-Desktop_Qt_5_12_1_GCC_64bit-Debug/ -lNormalisasi

INCLUDEPATH += $$PWD/../lib/libNormalisasi/Normalisasi
DEPENDPATH += $$PWD/../lib/libNormalisasi/Normalisasi

unix:!macx: LIBS += -L$$PWD/../lib/libLinearRegression/build-LinearRegression-Desktop_Qt_5_12_3_GCC_64bit-Debug/ -lLinearRegression

INCLUDEPATH += $$PWD/../lib/libLinearRegression/LinearRegression
DEPENDPATH += $$PWD/../lib/libLinearRegression/LinearRegression

RESOURCES += \
    resources.qrc

unix:!macx: LIBS += -L$$PWD/../lib/libCalculatorUI/build-CalculatorUI-Desktop_Qt_5_12_3_GCC_64bit-Debug/ -lCalculatorUI

INCLUDEPATH += $$PWD/../lib/libCalculatorUI/CalculatorUI
DEPENDPATH += $$PWD/../lib/libCalculatorUI/CalculatorUI

unix:!macx: LIBS += -L$$PWD/../lib/libEdit/build-Edit-Desktop_Qt_5_12_3_GCC_64bit-Debug/ -lEdit

INCLUDEPATH += $$PWD/../lib/libEdit/Edit
DEPENDPATH += $$PWD/../lib/libEdit/Edit

#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T19:25:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Datalogger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    analogPlot.cpp \
    commonStyle.cpp \
    digitalPlot.cpp \
    analogPlot_V2.cpp

HEADERS  += mainwindow.h \
    main.h \
    qcustomplot.h \
    analogPlot.h \
    commonStyle.h \
    digitalPlot.h \
    analogPlot_V2.h

FORMS    += mainwindow.ui \
    analogPlot.ui \
    digitalPlot.ui \
    analogPlot_V2.ui

#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T19:25:24
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Datalogger
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    analogPlot.cpp \
    commonStyle.cpp \
    graphicTracePlot.cpp \
    frameSimulator.cpp \
    frameThread.cpp \
    startThread.cpp \
    startstopemuldata.cpp \
    refreshTimer.cpp \
    displayWindows.cpp \
    graphicPlot.cpp \
    frame.cpp \
    dataFrame.cpp \
    dataFrameSimulator.cpp \
    digitalPlot.cpp

HEADERS  += mainwindow.h \
    main.h \
    qcustomplot.h \
    analogPlot.h \
    commonStyle.h \
    graphicTracePlot.h \
    frameSimulator.h \
    frameThread.h \
    startThread.h \
    startstopemuldata.h \
    refreshTimer.h \
    displayWindows.h \
    graphicPlot.h \
    frame.h \
    dataFrame.h \
    dataFrameSimulator.h \
    digitalPlot.h

FORMS    += mainwindow.ui \
    analogPlot.ui \
    graphicTracePlot.ui \
    startstopemuldata.ui \
    displayWindows.ui \
    graphicPlot.ui \
    analogPlot_copy.ui \
    digitalPlot.ui

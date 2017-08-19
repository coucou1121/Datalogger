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
    frameThread.cpp \
    refreshTimer.cpp \
    dataFrame.cpp \
    dataFrameSimulator.cpp \
    digitalPlot.cpp \
    logoDateTime.cpp \
    stateFrame.cpp \
    errorMessage.cpp \
    settingChannelSelection.cpp \
    settingTimeScaleFactor.cpp \
    settingTriggerSetting.cpp \
    settingTriggerFunction.cpp \
    settingPreTriggerPercentage.cpp \
    settingWindow.cpp \
    globalEnumatedAndExtern.cpp \
    triggerWindow.cpp \
    debugWindow.cpp \
    triggerFunctions.cpp \
    homeWindow.cpp \
    rollWindow.cpp

HEADERS  += mainwindow.h \
    main.h \
    qcustomplot.h \
    analogPlot.h \
    commonStyle.h \
    frameThread.h \
    refreshTimer.h \
    dataFrame.h \
    dataFrameSimulator.h \
    digitalPlot.h \
    logoDateTime.h \
    stateFrame.h \
    errorMessage.h \
    settingChannelSelection.h \
    settingTimeScaleFactor.h \
    settingTriggerSetting.h \
    settingTriggerFunction.h \
    settingPreTriggerPercentage.h \
    settingWindow.h \
    globalEnumatedAndExtern.h \
    triggerWindow.h \
    debugWindow.h \
    triggerFunctions.h \
    homeWindow.h \
    rollWindow.h

FORMS    += mainwindow.ui \
    analogPlot.ui \
    analogPlot_copy.ui \
    digitalPlot.ui \
    logoDateTime.ui \
    stateFrame.ui \
    errorMessage.ui \
    settingChannelSelection.ui \
    settingTimeScaleFactor.ui \
    settingTriggerSetting.ui \
    settingTriggerFunction.ui \
    settingPreTriggerPercentage.ui \
    settingWindow.ui \
    triggerWindow.ui \
    debugWindow.ui \
    homeWindow.ui \
    rollWindow.ui

RESOURCES += \
    images.qrc

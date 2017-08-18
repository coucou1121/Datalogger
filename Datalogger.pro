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
    frameSimulator.cpp \
    frameThread.cpp \
    startThread.cpp \
    startstopemuldata.cpp \
    refreshTimer.cpp \
    frame.cpp \
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
    dataAnalyser.cpp \
    triggerFunctions.cpp \
    displayWindow.cpp \
    homeWindow.cpp

HEADERS  += mainwindow.h \
    main.h \
    qcustomplot.h \
    analogPlot.h \
    commonStyle.h \
    frameSimulator.h \
    frameThread.h \
    startThread.h \
    startstopemuldata.h \
    refreshTimer.h \
    frame.h \
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
    dataAnalyser.h \
    triggerFunctions.h \
    displayWindow.h \
    homeWindow.h

FORMS    += mainwindow.ui \
    analogPlot.ui \
    startstopemuldata.ui \
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
    displayWindow.ui \
    homeWindow.ui

RESOURCES += \
    images.qrc

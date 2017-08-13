#ifndef MAIN_H
#define MAIN_H

//define
#define TITLE "Datalogger"
#define VERSION "Version 1.00"

//libraries
#include <QApplication>
#include <QtWidgets>
#include <QDebug>
#include <QMetaType>

//interfaces
#include "mainwindow.h"
#include "analogPlot.h"
#include "digitalPlot.h"
#include "frameSimulator.h"
#include "frameThread.h"
#include "startThread.h"
#include "startstopemuldata.h"
#include "refreshTimer.h"
#include "displayWindow.h"
#include "dataFrame.h"
#include "dataFrameSimulator.h"
#include "logoDateTime.h"
#include "stateFrame.h"
#include "settingChannelSelection.h"
#include "settingTimeScaleFactor.h"
#include "settingTriggerSetting.h"
#include "settingWindow.h"

#endif // MAIN_H

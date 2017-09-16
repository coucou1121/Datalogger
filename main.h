#ifndef MAIN_H
#define MAIN_H
/**
 * \mainpage Documentation of the Datalogger
 *
 * \section ISEC 4, TB bachelor 2017
 *
 * This is a logic analyseur with trigger equation, real time data acquision and plot.
 * 16 digital and 4 analogs channels
 *
 * This is a windows compatible software, that not the final one for the Raspberry Pi
 * Can be use only for training or Demo.
 *
 * \author Blessemaille Sébastien
 * \version 1.0
 * \date 14.09.2017
 * \brief main file for the Datalogger
 */

//define
#define TITLE "Datalogger"
#define VERSION "Version 1.00"

//libraries
#include <QApplication>
#include <QtWidgets>
#include <QDebug>

//interfaces
#include "mainwindow.h"
#include "analogPlot.h"
#include "digitalPlot.h"
#include "frameThread.h"
#include "refreshTimer.h"
#include "rollWindow.h"
#include "dataFrame.h"
#include "dataFrameSimulator.h"
#include "logoDateTime.h"
#include "stateFrame.h"
#include "settingChannelSelection.h"
#include "settingTimeScaleFactor.h"
#include "settingTriggerSetting.h"
#include "settingWindow.h"

#endif // MAIN_H

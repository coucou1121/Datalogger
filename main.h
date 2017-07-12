#ifndef MAIN_H
#define MAIN_H

//define
#define TITLE "Datalogger"
#define VERSION "Version 1.00"

//libraries
#include <QApplication>
#include <QDebug>
#include <QMetaType>

//interfaces
#include "mainwindow.h"
#include "analogPlot.h"
#include "digitalPlot.h"
#include "graphicTracePlot.h"
#include "frameSimulator.h"
#include "frameThread.h"
#include "startThread.h"
#include "startstopemuldata.h"
#include "refreshTimer.h"
#include "displayWindows.h"
#include "graphicPlot.h"
#include "dataFrame.h"
#include "dataFrameSimulator.h"
#include "logoDateTime.h"
#include "errorFrame.h"
#include "stateFrame.h"

#endif // MAIN_H

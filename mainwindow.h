#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include <QMetaType>

#include "main.h"
#include "commonStyle.h"
#include "baseWindow.h"
#include "settingWindow.h"
#include "triggerWindow.h"
#include "displayWindows.h"
#include "debugWindow.h"
#include "refreshTimer.h"
#include "dataFrameSimulator.h"
#include "triggerWindow.h"


namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //timer for x axis
    QTimer dataTimer;

    //setup basic style for the main wondows
    void setupStyle();

    //add value for display
    void addNewFrame( QVector<DataFrame> dataFrameVector);

private:
    Ui::MainWindow *ui;

    //value of the selected trigger function
    quint16 _valueTriggerFunction;

    //thread
    QThread *_threadTick;               // create tick for frequency simulation
    QThread *_threadNewDataFrame;       // create a new data
    QThread *_threadDisplayRefresh;     // Display refreshement

    //timer for thread
    refreshTimer *_tickTimer;
    refreshTimer *_newDataFrameTimer;
    refreshTimer *_refreshDisplayTimer;

    //ui windows
    BaseWindow *_baseWindow;
    SettingWindow *_settingWindow;
    TriggerWindow *_triggerWindow;
    DisplayWindows *_displayWindow;
    DebugWindow *_debugWindow;

    //Style
    CommonStyle _myStyle;

    //widget for status bar
    QWidget *_widgetStatusBar;

    QHBoxLayout *_hlayoutStatus = new QHBoxLayout;

    QPushButton *_btBase;
    QPushButton *_btSetting;
    QPushButton *_btTrigger;
    QPushButton *_btDisplay;
    QPushButton *_btDebug;

    //set the bottom status bar
    void setStatusBar();

    //set the pushbutton color to grey
    void resetPushButtonColor();

    //set the application with default value
    void mainSetup();

    //setup signal and slot
    void setupSignalAndSlot();

    //setup default start value for all variable in this application
    void setupDefaultValue();

    //manage state of the startStop button
    void _startStopButtonManager(int state);

    //array for data recorder
    QVector<DataFrame> _dataFrameVectorReccorder;

    //frame simulator
    DataFrameSimulator *_dataFrameSimulator;

public slots:
    void changeStateStartStopButton(int state);
    void startThread();
    void stopThread();
    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);
    void refreshDisplay();

private slots:
    void _btBase_released();
    void _btSetting_released();
    void _btTrigger_released();
    void _btDisplay_released();
    void _btDebug_released();
    void on_pushButton_StartStop_released();
};

#endif // MAINWINDOW_H

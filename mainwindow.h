#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define LINUX 0
#define NUMBER_DOTS_ON_TRACE 400

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include <QMetaType>

#include "main.h"
#include "commonStyle.h"
#include "initWindow.h"
#include "homeWindow.h"
#include "settingWindow.h"
#include "triggerWindow.h"
#include "rollWindow.h"
#include "debugWindow.h"
#include "refreshTimer.h"
#include "dataFrameSimulator.h"
#include "triggerWindow.h"
#include "triggerFunctions.h"

#if LINUX
#include "FTDI/ftd2xx.h"
#include "FTDIFunction.h"
#endif

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

    //set the application with default value
    void mainSetup();

private:
    Ui::MainWindow *ui;

    //value of the selected trigger function
    //quint16 _valueTriggerFunction;

    //thread
    QThread *_threadTick;               // create tick for frequency simulation
    QThread *_threadNewDataFrame;       // create a new data
    QThread *_threadDisplayRefresh;     // Display refreshement

    //timer for thread
    RefreshTimer *_tickTimer;
    RefreshTimer *_newDataFrameTimer;
    RefreshTimer *_refreshDisplayTimer;

    //ui windows
    InitWindow *_initWindow;
    HomeWindow *_homeWindow;
    SettingWindow *_settingWindow;
    TriggerWindow *_triggerWindow;
    RollWindow *_rollWindow;
    DebugWindow *_debugWindow;

    void _hideAllWindows();

    //Style
    CommonStyle _myStyle;

    //widget for status bar
    QWidget *_widgetStatusBar;

    QHBoxLayout *_hlayoutStatus;

    QPushButton *_btHome;
    QPushButton *_btSetting;
    QPushButton *_btTrigger;
    QPushButton *_btRoll;
    QPushButton *_btDebug;

    bool _btHomeWasPressed;
    bool _btSettingWasPressed;
    bool _btTriggerWasPressed;
    bool _btRollWasPressed;
    bool _btDebugWasPressed;

    //main state graph
    void _mainStateGraphe();
    void _goToNextState();
    GlobalEnumatedAndExtern::eMainStateApplication _mainStateStep;
    GlobalEnumatedAndExtern::eMainStateDisplay _mainStateDisplay;

    //trig state graph
    void _trigStateGraph();
    GlobalEnumatedAndExtern::eTrigState _trigStateStep;

    //roll state graph
    void _rollStateGraph();
    GlobalEnumatedAndExtern::eRollState _rollStateStep;

    //evaluation of the trigger function
    bool _triggerFunctionEvaluatedTrue;

    //set the bottom status bar
    void _setStatusBar();

    //set the pushbutton color to grey
    void _resetPushButtonColor();

    //setup signal and slot
    void _setupSignalAndSlot();

    //setup default start value for all variable in this application
    void _setupDefaultValue();

    //manage state of the startStop button
    void _startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::eBPStartStopState state);

    //array for data recorder
    QVector<DataFrame> _dataFrameReccorder;
    QVector<DataFrame> _dataFrameTrace;
    QVector<DataFrame>::iterator _itProducer;
    QVector<DataFrame>::iterator _itConsumer;
    QVector<DataFrame>::iterator _itTrace;

    //frame simulator
    DataFrameSimulator *_dataFrameSimulator;

    //value of the selected trigger function
    TriggerFunctions *_triggerFuntion;

    //check if on trig
    bool _onTrigTrue;

    //FTDI connection
#if LINUX
    FTDIFunction *_FTDIdevice;
#endif
    quint32 _baudRateSpeed2M;
    quint16 _baudRateSpeed9600;
#if LINUX
    //FTDI management
    bool _FTDIconnection();
#endif
    //wait delay
    void _waitDelay(int delayInSeconde);

public slots:
    void changeStateStartStopButton(int state);
    void startThread();
    void stopThread();
    void addNewDataFrame(int itProducerAdress);
    void refreshDisplay();

private slots:
    void _btHome_released();
    void _btSetting_released();
    void _btTrigger_released();
    void _btRoll_released();
    void _btDebug_released();
    void on_pushButton_StartStop_released();
};

#endif // MAINWINDOW_H

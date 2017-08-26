#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define LINUX 1
#define NUMBER_DOTS_ON_TRACE 400
#define NB_FRAME_READ_EVERY_CYCLE 8

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

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
#include "dataFrameLiveReading.h"
#include "frameThread.h"

//#if LINUX
#include "FTDI/ftd2xx.h"
#include "FTDIFunction.h"
//#endif

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

    //actif wait delay
    void _waitDelay(int delayInSeconde);

    //thread
    QThread *_threadTick;               // create tick for frequency simulation
    QThread *_threadNewDataFrame;       // create a new data
    QThread *_threadDisplayRefresh;     // Display refreshement
    QThread *_threadRealTimeReading;          // Manage the real time reading
    FrameThread *_frameThread;

    //timer for thread
    RefreshTimer *_tickTimer;
    RefreshTimer *_newDataFrameTimer;
    RefreshTimer *_refreshDisplayTimer;
    RefreshTimer *_getNewLiveData;

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

    //memorise simulation mode
    bool _inSimulation;

    //FTDI connection
//#if LINUX
    FTDIFunction *_FTDIdevice;
//#endif
    quint32 _baudRateSpeed2M;
    quint16 _baudRateSpeed9600;
//#if LINUX
    //FTDI management
    bool _FTDIconnection();
    bool _FTDI_OK;
    QMap<int, QString> _FTDIStatePossibleTXT;

    //realtime reading
    DataFrameLiveReading *_dataFrameLiveReading;

//#endif

public slots:
    void changeStateStartStopButton(int state);
    void startThread();
    void stopThread();
    void addNewSimulatedDataFrame(int itProducerAdress);
    void addNewLiveDataFrame(int itProducerAdress);
    void refreshDisplay();
    void checkBoxEmulationModeChanged(bool checked);

private slots:
    void _btHome_released();
    void _btSetting_released();
    void _btTrigger_released();
    void _btRoll_released();
    void _btDebug_released();
    void on_pushButton_StartStop_released();

signals:
    void _errorFTDIDeviceNotFound(quint8 errorNumber, bool active);
};

#endif // MAINWINDOW_H

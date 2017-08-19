#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString BPMenuHomeTxt;
extern QString BPMenuSetTxt;
extern QString BPMenuTrigTxt;
extern QString BPMenuRollTxt;
extern QString BPMenuDebugTxt;

extern QString BPStartStopStateStartTxt;
extern QString BPStartStopStateStopTxt;
extern QString BPStartStopStateHoldTxt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _btHomeWasPressed(false),
    _btSettingWasPressed(false),
    _btTriggerWasPressed(false),
    _btRollWasPressed(false),
    _btDebugWasPressed(false),
    _trigStateStep(GlobalEnumatedAndExtern::trigReady)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE, MINIMUM_HEIGHT_SIZE);

    //create windows object
    _homeWindow = new HomeWindow();
    _settingWindow = new SettingWindow();
    _triggerWindow = new TriggerWindow();
    _displayWindow = new DisplayWindow();
    _debugWindow = new DebugWindow();
    _hlayoutStatus = new QHBoxLayout();

    this->_mainSetup();
    this->setupStyle();
    this->_setStatusBar();

    //create thread object
    _threadTick = new QThread;
    _threadNewDataFrame = new QThread;
    _threadDisplayRefresh = new QThread;

    //create timerfor thread
    _tickTimer = new RefreshTimer(false, "Tick timer", 1);
    _newDataFrameTimer = new RefreshTimer(false, "Data updated timer", 1000);
    _refreshDisplayTimer = new RefreshTimer(false, "Refres Display timer", 100);

    //create data frame simulautor
    _dataFrameSimulator = new DataFrameSimulator("Frame Simulator");

    //move timer into the thread
    _tickTimer->moveToThread(_threadTick);
    _newDataFrameTimer->moveToThread(_threadNewDataFrame);
    _refreshDisplayTimer->moveToThread(_threadDisplayRefresh);

    //select home menu when start the application
    this->_btHome_released();

    //setup signal and slot
    this->_setupSignalAndSlot();

    //setup default values
    this->_setupDefaultValue();

    //start thread for display refreshement
    _threadDisplayRefresh->start();
    _threadTick->start();
    _threadNewDataFrame->start();

    //perso type for signal
    qRegisterMetaType<QVector<DataFrame>>("QVector<DataFrame>");
    //qRegisterMetaType<TriggerFunctions>("TriggerFunctions");

    //get the setting in trigger function windows
    this->_triggerFuntion = _settingWindow->getTriggerFuntion();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_mainSetup()
{
    //add base windows in windows layout
    ui->gridLayout->addWidget(_homeWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(_settingWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(_triggerWindow, 0, 1, 6, 1);

    //add display window in window layout
    ui->gridLayout->addWidget(_displayWindow, 0, 1, 6, 1);

    //add debug window in window layout
    ui->gridLayout->addWidget(_debugWindow, 0, 1, 6, 1);

    //set title on homeWindow
    _homeWindow->setTitle("Datalogger");

    //set version on homeWindow
    _homeWindow->setVersion("1.0");

    //set start state of application
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateInit;

    //set start display state of application
    this->_mainStateDisplay = GlobalEnumatedAndExtern::init;

    //set backGroud color and text on pushButton StartStop
    this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

    //set basic draw on roll on
    _displayWindow->setDrawLeftToRight(false);

    //set trigger function to false (no trig at startuo)
    _triggerFunctionEvaluatedTrue = false;

    //start state graph
    this->_mainStateGraphe();
}

void MainWindow::_setupDefaultValue()
{
    _debugWindow->setNbSavedFrame(65536); //max 999999999 for the slot
    _debugWindow->setFrameSize(64);
    _debugWindow->setBaudRateFTDI(2000000);
}

void MainWindow::_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::eBPStartStopState state)
{
    GlobalEnumatedAndExtern::eBPStartStopState eState;
    eState = (GlobalEnumatedAndExtern::eBPStartStopState) state;

    switch (eState)
    {
    case GlobalEnumatedAndExtern::start:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateStartTxt);
        break;
    case GlobalEnumatedAndExtern::stop:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getBackGroundColorErrorFrame().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateStopTxt);
        break;
    case GlobalEnumatedAndExtern::hold:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getBackGroundColorErrorFrame().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateHoldTxt);
        break;
    default:
        break;
    }
}

void MainWindow::changeStateStartStopButton(int state)
{
    this->_startStopButtonTextAndColorManager((GlobalEnumatedAndExtern::eBPStartStopState)state);
}

void MainWindow::startThread()
{
    //_tickTimer->startTimer();
    _newDataFrameTimer->startTimer();
    _refreshDisplayTimer->startTimer();
}

void MainWindow::stopThread()
{
    _tickTimer->stopTimer();
    _newDataFrameTimer->stopTimer();
    _refreshDisplayTimer->stopTimer();
}

void MainWindow::addNewDataFrame(QVector<DataFrame> dataFrameVector)
{

    for(QVector<DataFrame>::iterator it = dataFrameVector.begin(); it != dataFrameVector.end(); it++)
    {
        //check trigger function
        this->_triggerFuntion->onTrig(it);

         //add value in buffer
        _dataFrameVectorReccorder.append(*it);

        //adapte the size with pretrigger value
        if( _dataFrameVectorReccorder.size() > 1000)
        {
            _dataFrameVectorReccorder.remove(0);
        }
    }

    //send value to the plot
    this->_displayWindow->addNewDataFrame(dataFrameVector);
    this->_triggerWindow->addNewDataFrame(dataFrameVector);
    qDebug() << objectName() << "nbValue" << _dataFrameVectorReccorder.size();
    this->_triggerFuntion = _settingWindow->getTriggerFuntion();
    //this->_triggerFuntion->displayValue();
}

void MainWindow::refreshDisplay()
{
    this->_displayWindow->refreshPlot();
    this->_triggerWindow->refreshPlot();
}

void MainWindow::_setupSignalAndSlot()
{
    //manage trace in trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInTriggerMenu(int)), this->_triggerWindow, SLOT(addTrace(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInTriggerMenu(int)), this->_triggerWindow, SLOT(hideTrace(int)));

    //Sychronise setting menu <--> trigger menu, the trace range
    //setting menu -> trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonRangeAI1WasChangedFromSettingMenu()),
                     this->_triggerWindow, SLOT(pushButtonRangeAI1_changeRange()));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonRangeAI2WasChangedFromSettingMenu()),
                     this->_triggerWindow, SLOT(pushButtonRangeAI2_changeRange()));
    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this->_settingWindow, SLOT(pushButtonRangeAI1_changeRange()));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this->_settingWindow, SLOT(pushButtonRangeAI2_changeRange()));

    //Sychronise setting menu <--> trigger menu, the trigger edge
    //setting menu -> trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI1WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI1_changeEdge(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI2WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI2_changeEdge(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI3WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI3_changeEdge(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI4WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI4_changeEdge(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeAI1WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeAI1_changeEdge(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeAI2WasChangedFromSettingMenu(int)),
                     this->_triggerWindow, SLOT(pushButtonEdgeAI2_changeEdge(int)));

    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI1WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI1_changeEdge(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI2WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI2_changeEdge(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI3WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI3_changeEdge(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI4WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI4_changeEdge(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeAI1WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeAI1_changeEdge(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeAI2WasChanged(int)),
                     this->_settingWindow, SLOT(pushButtonEdgeAI2_changeEdge(int)));

    //Sychronise setting menu <--> trigger menu, the trigger values for traces
    //setting menu -> trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxDI1_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxDI1_changeValue(double)));
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxDI2_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxDI2_changeValue(double)));
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxDI3_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxDI3_changeValue(double)));
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxDI4_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxDI4_changeValue(double)));
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxAI1_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxAI1_changeValue(double)));
    QObject::connect(this->_settingWindow, SIGNAL(_doubleSpinBoxAI2_valueWasChangedFromSettingMenu(double)),
                     this->_triggerWindow, SLOT(doubleSpinBoxAI2_changeValue(double)));

    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxDI1_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxDI1_changeValue(double)));
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxDI2_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxDI2_changeValue(double)));
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxDI3_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxDI3_changeValue(double)));
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxDI4_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxDI4_changeValue(double)));
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxAI1_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxAI1_changeValue(double)));
    QObject::connect(this->_triggerWindow, SIGNAL(_doubleSpinBoxAI2_valueWasChangedFromTriggerMenu(double)),
                     this->_settingWindow, SLOT(doubleSpinBoxAI2_changeValue(double)));


    //Sychronise setting menu <--> trigger menu, the selected trace and logical operator in trigger function
    //setting menu -> trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxTopLeft_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxTopRight_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxBottomLeft_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxBottomRight_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxTopMiddle_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxMiddle_changeCurrentIndex(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(comboBoxBottomMiddle_changeCurrentIndex(int)));

    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxTopLeft_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxTopRight_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxBottomLeft_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxBottomRight_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxTopMiddle_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxMiddle_changeCurrentIndex(int)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this->_settingWindow, SLOT(comboBoxBottomMiddle_changeCurrentIndex(int)));

    //set visible trace in display menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInDisplayMenu(int)), this->_displayWindow, SLOT(_addTrace(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInDisplayMenu(int)), this->_displayWindow, SLOT(_hideTrace(int)));

    //send new value for scale factor in setting menu
    QObject::connect(this->_debugWindow, SIGNAL(_nbFrameSavedChanged(quint64)), this->_settingWindow, SLOT(_received_NbFrameSavedChanged(quint64)));
    QObject::connect(this->_debugWindow, SIGNAL(_frameSizeChanged(int)), this->_settingWindow, SLOT(_received_SizeFrameChange(int)));
    QObject::connect(this->_debugWindow, SIGNAL(_FTDIBaudrateChanged(int)), this->_settingWindow, SLOT(_received_FTDIBaudrateChange(int)));

    //error management
    QObject::connect(this->_settingWindow, SIGNAL(_errorNoSelectedTrace(int,bool)), ui->widgetError, SLOT(_reveived_Error(int,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorNoSelectedTriggerTrace(int,bool)), ui->widgetError, SLOT(_reveived_Error(int,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorFrequencyToLow(int,bool)), ui->widgetError, SLOT(_reveived_Error(int,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorWrongEquation(int,bool)), ui->widgetError, SLOT(_reveived_Error(int,bool)));
    QObject::connect(this->_triggerWindow, SIGNAL(_errorWrongEquation(int,bool)), ui->widgetError, SLOT(_reveived_Error(int,bool)));

    //timer management to be sure they start correctly
    //    QObject::connect(this->_threadTick, SIGNAL(started), this->_tickTimer, SLOT(start()));
    //    QObject::connect(this->_threadDisplayRefresh, SIGNAL(started), this->_refreshDisplayTimer, SLOT(start()));
    //    QObject::connect(this->_threadDataFramSimulator, SIGNAL(started), this->_dataFrameSimulator, SLOT(start()));

    //create new data frame from dataFrameSimulator
    QObject::connect(this->_newDataFrameTimer, SIGNAL(_tickFinished()), _dataFrameSimulator, SLOT(createDataFrame()));
    //QObject::connect(_dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &graphicPlot, SLOT(addYValue(quint8)));
    //QObject::connect(dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &analogPlot, SLOT(addYValue(quint8)));
    QObject::connect(_dataFrameSimulator, SIGNAL(dataFrameWasSent(QVector<DataFrame>)),this,SLOT(addNewDataFrame(QVector<DataFrame>)));

    //refresh the display
    QObject::connect(_refreshDisplayTimer, SIGNAL(_tickFinished()), this, SLOT(refreshDisplay()));

    //application on trig
    //QObject::connect(dataFrameSimulator, SIGNAL(valueDI1_8Updated(quint8)), &DisplayWindow, SLOT(addValueDI1_8(quint8)));
    //QObject::connect(dataFrameSimulator, SIGNAL(valueDI9_16Updated(quint8)), &DisplayWindow, SLOT(addValueDI9_16(quint8)));

    // QObject::connect(dataFrameSimulator, SIGNAL(valueAI1Updated(quint8)), &DisplayWindow, SLOT(addValueAI1(quint8)));
    // QObject::connect(dataFrameSimulator, SIGNAL(valueAI2Updated(quint8)), &DisplayWindow, SLOT(addValueAI2(quint8)));
    // QObject::connect(dataFrameSimulator, SIGNAL(valueAI3Updated(quint8)), &DisplayWindow, SLOT(addValueAI3(quint8)));
    // QObject::connect(dataFrameSimulator, SIGNAL(valueAI4Updated(quint8)), &DisplayWindow, SLOT(addValueAI4(quint8)));
}

void MainWindow::setupStyle()
{
    QPalette palette;
    palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());
    this->setPalette(palette);
}

void MainWindow::_hideAllWindows()
{
    _homeWindow->hide();
    _settingWindow->hide();
    _triggerWindow->hide();
    _displayWindow->hide();
    _debugWindow->hide();
}

void MainWindow::_mainStateGraphe()
{
    //hide all windows
    this->_hideAllWindows();

    //action to do
    switch (_mainStateStep)
    {
    case GlobalEnumatedAndExtern::mainStateInit:
        //show home page
        this->_homeWindow->show();

        //next step
        this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;

        //go to the next step
        //        this->_goToNextState();
        qDebug() << "main state on : " << "init";
        break;
    case GlobalEnumatedAndExtern::mainStateStop:
        //stop display refresh and data analyseur thread
        this->stopThread();

        //remove dark back ground on push button
        this->_resetPushButtonColor();

        //set display state to stopped
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::stopped);

        //next step
        this->_mainStateStep = GlobalEnumatedAndExtern::mainStateReady;

        // go to next state
        qDebug() << "main state on : " << "Stop";
        this->_goToNextState();
        break;
    case GlobalEnumatedAndExtern::mainStateReady:
        _btHome->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                               "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
        //reset BP Home state
        this->_btHomeWasPressed = false;

        //show home window
        _homeWindow->show();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        qDebug() << "main state on : " << "ready";
        break;
    case GlobalEnumatedAndExtern::mainStateSet:
        _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                  "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

        //reset BP set state
        this->_btSettingWasPressed = false;

        //show setting window
        _settingWindow->show();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        //check if they are some selected trace
        _settingWindow->checkIfAreSelectedTrace();

        qDebug() << "main state on : " << "set";
        break;
    case GlobalEnumatedAndExtern::mainStateTrig:
        _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                  "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

        //reset BP trig state
        this->_btTriggerWasPressed = false;

        //show trigger window
        _triggerWindow->show();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        //check if they are some selected trace
        _settingWindow->checkIfAreSelectedTrace();

        qDebug() << "main state on : " << "trig";
        break;
    case GlobalEnumatedAndExtern::mainStateRoll:
        _btRoll->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                               "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

        //reset BP roll state
        this->_btRollWasPressed = false;

        //show roll window
        _displayWindow->show();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        //check if they are some selected trace
        _settingWindow->checkIfAreSelectedTrace();

        qDebug() << "main state on : " << "roll";
        break;
    case GlobalEnumatedAndExtern::mainStateDebug:
        _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

        //reset BP debug state
        this->_btDebugWasPressed = false;

        //show debug window
        _debugWindow->show();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        qDebug() << "main state on : " << "Debug";
        break;
    default:
        break;
    }
}

void MainWindow::_goToNextState()
{
    // init state
    if(!this->_btHomeWasPressed && !this->_btSettingWasPressed && !this->_btTriggerWasPressed &&
            !this->_btRollWasPressed && !this->_btDebugWasPressed)
    {
        this->_mainStateGraphe();
    }
    // after init
    else
    {
        if(this->_btHomeWasPressed)
        {
            this->_mainStateStep = GlobalEnumatedAndExtern::mainStateReady;
            this->_mainStateGraphe();
        }
        else if(this->_btSettingWasPressed)
        {
            this->_mainStateStep = GlobalEnumatedAndExtern::mainStateSet;
            this->_mainStateGraphe();
        }
        else if(this->_btTriggerWasPressed)
        {
            this->_mainStateStep = GlobalEnumatedAndExtern::mainStateTrig;
            this->_mainStateGraphe();
        }
        else if(this->_btRollWasPressed)
        {
            this->_mainStateStep = GlobalEnumatedAndExtern::mainStateRoll;
            this->_mainStateGraphe();
        }
        else if(this->_btDebugWasPressed)
        {
            this->_mainStateStep = GlobalEnumatedAndExtern::mainStateDebug;
            this->_mainStateGraphe();
        }
    }
}

void MainWindow::_trigStateGraph()
{
    switch (this->_trigStateStep)
    {
    case GlobalEnumatedAndExtern::trigNoReady:
        break;
    case GlobalEnumatedAndExtern::trigReady:
        //change StartStopButton to Start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //stop thread for analysing and refresh the display
        this->stopThread();

        //set display state to Run Trig
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        break;
    case GlobalEnumatedAndExtern::trigRunTrig:
        //change StartStopButton to Stop
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::stop);

        //start thread for analysing and refresh the display
        this->startThread();

        //set display state to Run Trig
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::runTrig);

        break;
    case GlobalEnumatedAndExtern::trigTrigged:
        //change StartStopButton to start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //stop thread for analysing and refresh the display
        this->stopThread();

        //set display state to Run Trig
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::trigged);

        break;
    default:
        break;
    }
}

void MainWindow::_setStatusBar()
{
    _widgetStatusBar = new QWidget();
    _btHome = new QPushButton(BPMenuHomeTxt);
    _btSetting = new QPushButton(BPMenuSetTxt);
    _btTrigger = new QPushButton(BPMenuTrigTxt);
    _btRoll = new QPushButton(BPMenuRollTxt);
    _btDebug = new QPushButton(BPMenuDebugTxt);
    _hlayoutStatus = new QHBoxLayout(_widgetStatusBar);

    //horizontal layout setting
    _hlayoutStatus->setMargin(0);
    _hlayoutStatus->setSpacing(0);
    _hlayoutStatus->setContentsMargins(0,0,0,0);

    //button setting
    _btHome->setAutoFillBackground(true);
    _btSetting->setAutoFillBackground(true);
    _btTrigger->setAutoFillBackground(true);
    _btRoll->setAutoFillBackground(true);
    _btDebug->setAutoFillBackground(true);

    //set the intialisation color
    _btHome->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btRoll->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                            "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");

    //add to the status bar at bottom of the mainwoindos
    _hlayoutStatus->addWidget(_btHome);
    _hlayoutStatus->addWidget(_btSetting);
    _hlayoutStatus->addWidget(_btTrigger);
    _hlayoutStatus->addWidget(_btRoll);
    _hlayoutStatus->addWidget(_btDebug);

    ui->statusBar->addWidget(_widgetStatusBar);

    //connect signal and slot
    connect(_btHome, SIGNAL (released()),this, SLOT (_btHome_released()));
    connect(_btSetting, SIGNAL (released()),this, SLOT (_btSetting_released()));
    connect(_btTrigger, SIGNAL (released()),this, SLOT (_btTrigger_released()));
    connect(_btRoll, SIGNAL (released()),this, SLOT (_btRoll_released()));
    connect(_btDebug, SIGNAL (released()),this, SLOT (_btDebug_released()));

}

void MainWindow::_resetPushButtonColor()
{
    _btHome->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btRoll->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                            "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
}

void MainWindow::_btHome_released()
{
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;
    this->_btHomeWasPressed = true;
    this->_mainStateGraphe();
}

void MainWindow::_btSetting_released()
{
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;
    this->_btSettingWasPressed = true;
    this->_mainStateGraphe();
}

void MainWindow::_btTrigger_released()
{
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;
    this->_btTriggerWasPressed = true;
    this->_mainStateGraphe();
}

void MainWindow::_btRoll_released()
{
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;
    this->_btRollWasPressed = true;
    this->_mainStateGraphe();
}

void MainWindow::_btDebug_released()
{
    this->_mainStateStep = GlobalEnumatedAndExtern::mainStateStop;
    this->_btDebugWasPressed = true;
    this->_mainStateGraphe();
}

void MainWindow::on_pushButton_StartStop_released()
{
    GlobalEnumatedAndExtern::eBPStartStopState stateBp;

    stateBp = ui->pushButton_StartStop->text() == BPStartStopStateStartTxt ?
                GlobalEnumatedAndExtern::start : GlobalEnumatedAndExtern::stop;

    //if waitting to start
    if(stateBp == GlobalEnumatedAndExtern::start)
    {
        switch (_mainStateStep)
        {
        //manage trigger function
        case GlobalEnumatedAndExtern::mainStateTrig:
            switch (_trigStateStep)
            {
            case GlobalEnumatedAndExtern::trigReady:
                //next application state
                this->_trigStateStep = GlobalEnumatedAndExtern::trigRunTrig;
                this->_trigStateGraph();
                break;
            case GlobalEnumatedAndExtern::trigTrigged:
                //next application state
                this->_trigStateStep = GlobalEnumatedAndExtern::trigRunTrig;
                this->_trigStateGraph();
                break;
            default:
                break;
            }
            break;
            //manage roll function
        case GlobalEnumatedAndExtern::mainStateRoll:
            break;
        default:
            break;
        }

    }
    //system in analysing
    else
    {
        switch (_mainStateStep)
        {
        case GlobalEnumatedAndExtern::mainStateReady:
            break;
        case GlobalEnumatedAndExtern::mainStateSet:
            break;
        case GlobalEnumatedAndExtern::mainStateTrig:
            if(this->_triggerFuntion->onTrigStatus())
            {
                this->_trigStateStep = GlobalEnumatedAndExtern::trigTrigged;
            }
            else
            {
                this->_trigStateStep = GlobalEnumatedAndExtern::trigReady;
            }
            this->_trigStateGraph();
            break;
        case GlobalEnumatedAndExtern::mainStateRoll:
            break;
        case GlobalEnumatedAndExtern::mainStateDebug:
            break;
        default:
            break;
        }
    }
    _displayWindow->setDrawLeftToRight(_settingWindow->triggerFunctionEnable());
    qDebug() << objectName() << "trigger Enable" << _settingWindow->triggerFunctionEnable();
}

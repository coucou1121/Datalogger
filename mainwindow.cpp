#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString BPStartStopStateBlockTxt;
extern QString BPStartStopStateStartTxt;
extern QString BPStartStopStateStopTxt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE, MINIMUM_HEIGHT_SIZE);

    //create thread object
    _threadTick = new QThread;
    _threadNewDataFrame = new QThread;
    _threadDisplayRefresh = new QThread;

    //create timerfor thread
    _tickTimer = new RefreshTimer(false, "Tick timer", 1);
    _newDataFrameTimer = new RefreshTimer(false, "Data updated timer", 10);
    _refreshDisplayTimer = new RefreshTimer(false, "Refres Display timer", 100);

    //create data frame simulautor
    _dataFrameSimulator = new DataFrameSimulator("Frame Simulator");

    //move timer into the thread
    _tickTimer->moveToThread(_threadTick);
    _newDataFrameTimer->moveToThread(_threadNewDataFrame);
    _refreshDisplayTimer->moveToThread(_threadDisplayRefresh);

    //create windows object
    _baseWindow = new BaseWindow();
    _settingWindow = new SettingWindow();
    _triggerWindow = new TriggerWindow();
    _displayWindow = new DisplayWindow();
    _debugWindow = new DebugWindow();

    _hlayoutStatus = new QHBoxLayout();

    this->_mainSetup();
    this->setupStyle();
    this->_setStatusBar();

    //select Setting menu when start the application
    this->_btSetting_released();

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

    //get edge selection in trigger setting windows

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_mainSetup()
{
    //add base windows in windows layout
    ui->gridLayout->addWidget(_baseWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(_settingWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(_triggerWindow, 0, 1, 6, 1);

    //add display window in window layout
    ui->gridLayout->addWidget(_displayWindow, 0, 1, 6, 1);

    //add debug window in window layout
    ui->gridLayout->addWidget(_debugWindow, 0, 1, 6, 1);

    //set title on baseWindows
    _baseWindow->setTitle("Datalogger");

    //set version on baseWindows
    _baseWindow->setVersion("1.0");

    //set backGroud color and text on pushButton StartStop
    this->_startStopButtonManager((int)GlobalEnumatedAndExtern::start);

    //set basic draw on roll on
    _displayWindow->setDrawLeftToRight(false);

    //set trigger function to false (no trig at startuo)
    _triggerFunctionEvaluatedTrue = false;
}

void MainWindow::_setupDefaultValue()
{
    _debugWindow->setNbSavedFrame(65536); //max 999999999 for the slot
    _debugWindow->setFrameSize(64);
    _debugWindow->setBaudRateFTDI(2000000);
}

void MainWindow::_startStopButtonManager(int state)
{
    GlobalEnumatedAndExtern::eBPStartStopState eState;
    eState = (GlobalEnumatedAndExtern::eBPStartStopState) state;

    switch (eState)
    {
    case GlobalEnumatedAndExtern::block:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getBackGroundColorErrorFrame().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateBlockTxt);
        //set enable
        ui->pushButton_StartStop->setEnabled(false);
        break;
    case GlobalEnumatedAndExtern::start:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateStartTxt);
        //set enable
        ui->pushButton_StartStop->setEnabled(true);
        break;
    case GlobalEnumatedAndExtern::stop:
        //set backgroud color
        ui->pushButton_StartStop->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                                "stop: 1" + _myStyle.getBackGroundColorBottomBar().name() +
                                                ", stop: 0 #ffffff);");
        //set text
        ui->pushButton_StartStop->setText(BPStartStopStateStopTxt);
        //set enable
        ui->pushButton_StartStop->setEnabled(true);
        break;
    default:
        break;
    }
}

void MainWindow::changeStateStartStopButton(int state)
{
    this->_startStopButtonManager(state);
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
    QObject::connect(this->_debugWindow, SIGNAL(_nbFrameSavedChanged(quint64)), this->_settingWindow, SLOT(_recievedNbFrameSavedChanged(quint64)));
    QObject::connect(this->_debugWindow, SIGNAL(_frameSizeChanged(int)), this->_settingWindow, SLOT(_recievedSizeFrameChange(int)));
    QObject::connect(this->_debugWindow, SIGNAL(_FTDIBaudrateChanged(int)), this->_settingWindow, SLOT(_recievedFTDIBaudrateChange(int)));

    //error management
    QObject::connect(this->_settingWindow, SIGNAL(_errorFrequencyToLow(int,bool)), ui->widgetError, SLOT(_reveivedError(int,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorWrongEquation(int,bool)), ui->widgetError, SLOT(_reveivedError(int,bool)));

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

void MainWindow::_setStatusBar()
{
    _widgetStatusBar = new QWidget();
    _btBase = new QPushButton("Base");
    _btSetting = new QPushButton("Setting");
    _btTrigger = new QPushButton("Trigger");
    _btDisplay = new QPushButton("Display");
    _btDebug = new QPushButton("Debug");
    _hlayoutStatus = new QHBoxLayout(_widgetStatusBar);

    //horizontal layout setting
    _hlayoutStatus->setMargin(0);
    _hlayoutStatus->setSpacing(0);
    _hlayoutStatus->setContentsMargins(0,0,0,0);

    //button setting
    _btBase->setAutoFillBackground(true);
    _btSetting->setAutoFillBackground(true);
    _btTrigger->setAutoFillBackground(true);
    _btDisplay->setAutoFillBackground(true);
    _btDebug->setAutoFillBackground(true);

    //set the intialisation color
    _btBase->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDisplay->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                              "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                            "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");

    //add to the status bar at bottom of the mainwoindos
    _hlayoutStatus->addWidget(_btBase);
    _hlayoutStatus->addWidget(_btSetting);
    _hlayoutStatus->addWidget(_btTrigger);
    _hlayoutStatus->addWidget(_btDisplay);
    _hlayoutStatus->addWidget(_btDebug);

    ui->statusBar->addWidget(_widgetStatusBar);

    //connect signal and slot
    connect(_btBase, SIGNAL (released()),this, SLOT (_btBase_released()));
    connect(_btSetting, SIGNAL (released()),this, SLOT (_btSetting_released()));
    connect(_btTrigger, SIGNAL (released()),this, SLOT (_btTrigger_released()));
    connect(_btDisplay, SIGNAL (released()),this, SLOT (_btDisplay_released()));
    connect(_btDebug, SIGNAL (released()),this, SLOT (_btDebug_released()));

}

void MainWindow::_resetPushButtonColor()
{
    _btBase->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDisplay->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() + ";");

    _baseWindow->hide();
    _settingWindow->hide();
    _triggerWindow->hide();
    _displayWindow->hide();
    _debugWindow->hide();
}

void MainWindow::_btBase_released()
{
    this->_resetPushButtonColor();
    _btBase->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _baseWindow->show();
}

void MainWindow::_btSetting_released()
{
    this->_resetPushButtonColor();
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _settingWindow->show();
}

void MainWindow::_btTrigger_released()
{
    this->_resetPushButtonColor();
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _triggerWindow->show();
}

void MainWindow::_btDisplay_released()
{
    this->_resetPushButtonColor();
    _btDisplay->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _displayWindow->show();
}

void MainWindow::_btDebug_released()
{
    this->_resetPushButtonColor();
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _debugWindow->show();
}

void MainWindow::on_pushButton_StartStop_released()
{
    GlobalEnumatedAndExtern::eBPStartStopState stateBp;

    stateBp = ui->pushButton_StartStop->text() == BPStartStopStateStartTxt ? GlobalEnumatedAndExtern::stop : GlobalEnumatedAndExtern::start;

    if(stateBp == GlobalEnumatedAndExtern::start)
    {
        this->_startStopButtonManager((int)GlobalEnumatedAndExtern::start);
        this->stopThread();
        ui->widgetState->setMainState(GlobalEnumatedAndExtern::mainStateStop);
//        _displayWindow->setDrawLeftToRight(_settingWindow->triggerFunctionEnable());
//        qDebug() << objectName() << "trigger Enable" << _settingWindow->triggerFunctionEnable();
    }
    else
    {
        this->_startStopButtonManager((int)GlobalEnumatedAndExtern::stop);
        this->startThread();
        if(_settingWindow->triggerFunctionEnable())
        {
            ui->widgetState->setMainState(GlobalEnumatedAndExtern::mainStateOnTrig);
        }
        else
        {
            ui->widgetState->setMainState(GlobalEnumatedAndExtern::mainStateRollOn);
        }
//        _displayWindow->setDrawLeftToRight(_settingWindow->triggerFunctionEnable());
//        qDebug() << objectName() << "trigger Enable" << _settingWindow->triggerFunctionEnable();
    }
    _displayWindow->setDrawLeftToRight(_settingWindow->triggerFunctionEnable());
    qDebug() << objectName() << "trigger Enable" << _settingWindow->triggerFunctionEnable();
}

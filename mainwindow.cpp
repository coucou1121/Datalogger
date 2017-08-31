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

    //create windows object
    _initWindow(new InitWindow()),
    _homeWindow(new HomeWindow()),
    _settingWindow(new SettingWindow()),
    _triggerWindow(new TriggerWindow()),
    _rollWindow(new RollWindow()),
    _debugWindow(new DebugWindow()),
    _hlayoutStatus(new QHBoxLayout()),

    //create data frame simulautor
    _dataFrameSimulator(new DataFrameSimulator("Frame Simulator")),

    //create the data frame for realtime reading
//    _dataFrameLiveReading(new DataFrameLiveReading("data live reading", NB_FRAME_READ_EVERY_CYCLE)),

    //create FTDI device
    _FTDIdevice(new FTDIFunction("FTDI device")),

    //create thread object
    _threadDataAnalysis(new FrameThread(false, "tick data analysis", 10)),
    _threadNewDataFrame(new FrameThread(true, "simulated data", 1000)),
    _threadDisplayRefresh(new FrameThread(true, "refresh display", 100)),

    _threadRealTimeReading(new QThread),
    _frameThread(new FrameThread(false, "real data", 1000)),

    //create timer for thread
    //    _tickTimer(new RefreshTimer(false, "Tick timer", 1)),
    //    _newDataFrameTimer(new RefreshTimer(false, "Data updated timer", 200)),
    //    _refreshDisplayTimer(new RefreshTimer(true, "Refres Display timer", 100)),
    //    _getNewLiveData(new RefreshTimer(false, "Tick timer", 100)),

    //creat circular array
    _dataFrameReccorder(65536),
    _dataFrameTrace(NB_FRAME_CREATE_AT_EVERY_TICK),
    _itConsumer(_dataFrameReccorder.begin()),
    _itProducer(_dataFrameReccorder.begin()),
    _itIntProducer(0),
    _itTrace(_dataFrameTrace.begin()),

    //state of menu button pressed as false
    _btHomeWasPressed(false),
    _btSettingWasPressed(false),
    _btTriggerWasPressed(false),
    _btRollWasPressed(false),
    _btDebugWasPressed(false),

    //state graph initialisation
    _mainStateStep(GlobalEnumatedAndExtern::mainStateInit),
    _trigStateStep(GlobalEnumatedAndExtern::trigReady),
    _rollStateStep(GlobalEnumatedAndExtern::rollReady),
    //create the FTDI object
        #if LINUX
    //    _FTDIdevice(new FTDIFunction("FTDI functions")),
        #endif
    _baudRateSpeed2M(2000000),
    _baudRateSpeed9600(9600),
    //_FTDI_OK(false),

    //set application on trig to falae
    _onTrigTrue(false),

    //nombre value after trig
    _nbValueAfterTrig(NB_FRAME_MEMORIZED),
    _amontOfValueAfterTrig(NB_FRAME_MEMORIZED),

    //set application on simulation to false
    _inSimulation(false)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE, MINIMUM_HEIGHT_SIZE);

    //move timer into the thread
    //    _tickTimer->moveToThread(_threadDataAnalysis);
    //    _newDataFrameTimer->moveToThread(_threadNewDataFrame);
    //    _refreshDisplayTimer->moveToThread(_threadDisplayRefresh);
    //_FTDIdevice->moveToThread(_threadRealTimeReading);
//    _FTDIdevice->moveToThread(_frameThread);

    //key - value for FTDI state possible
    _FTDIStatePossibleTXT = GlobalEnumatedAndExtern::initFTDIStatePossibleTXT();

    //setup signal and slot
    this->_setupSignalAndSlot();

    //setup default values
    this->_setupDefaultValue();

    //start threat for create new data
    this->_threadNewDataFrame->start();

    //start thread for check new data
    //this->_threadDataAnalysis->start();

    //start thread for display refreshement
    this->_threadDisplayRefresh->start();

    //this->_frameThread->start();
    // start thread for real time data reading
    //this->_threadRealTimeReading->start();
    //this->_dataFrameLiveReading->start();

    //setup customise style
    this->setupStyle();

    //set the bottom menu bar
    this->_setStatusBar();
    //personal type for signal
    //qRegisterMetaType<QVector<DataFrame> >("QVector<DataFrame>");
    //qRegisterMetaType<TriggerFunctions>("TriggerFunctions");

    //select direction to plot
    _rollWindow->setDrawRightToLeft(true);
    _triggerWindow->setDrawRightToLeft(true);

    //get the setting in trigger function windows
    this->_triggerFuntion = _settingWindow->getTriggerFuntion();

    //set the point of circular buffer for data to the frame simulator
    this->_dataFrameSimulator->setDataFrameVectorReccorder(&this->_dataFrameReccorder);
    this->_dataFrameSimulator->setItProducer(this->_itProducer);
    this->_dataFrameSimulator->setItConsumerAdress(this->_dataFrameReccorder.end());

    //set the point of circular buffer for data to the FTDI device
//    this->_FTDIdevice->setDataFrameVectorReccorder(&this->_dataFrameReccorder);
//    this->_FTDIdevice->setItProducer(this->_itProducer);
//    this->_FTDIdevice->setItConsumerAdress(this->_dataFrameReccorder.end());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainSetup()
{
    //add init window in windows layout
    ui->gridLayout->addWidget(_initWindow, 0, 1, 7, 1);

    //add home window in window layout
    ui->gridLayout->addWidget(_homeWindow, 0, 1, 7, 1);

    //add setting window in window layout
    ui->gridLayout->addWidget(_settingWindow, 0, 1, 7, 1);

    //add setting window in window layout
    ui->gridLayout->addWidget(_triggerWindow, 0, 1, 7, 1);

    //add display window in window layout
    ui->gridLayout->addWidget(_rollWindow, 0, 1, 7, 1);

    //add debug window in window layout
    ui->gridLayout->addWidget(_debugWindow, 0, 1, 7, 1);

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

    //set trigger function to false (no trig at startus)
    _triggerFunctionEvaluatedTrue = false;

    //set the size of the plot in roll windows
    this->_rollWindow->setSizeOfPlot(SIZE_OF_PLOT);

    //set the size of the plot in the trigger windows
    this->_triggerWindow->setSizeOfPlot(SIZE_OF_PLOT);

    //set the size of the plot in the trigger windows
    ui->widgetPlotSetting->setSizeOfPlots(SIZE_OF_PLOT);

    // get the FTDI device frome the real time reading thread
    // this->_FTDIdevice = this->_dataFrameLiveReading->FTDIdevice();

    // start thread for real time reading
    this->_threadRealTimeReading->start();

    //start state graph of application
    this->_mainStateGraphe();

    //set the FTDI device to the debug menu
//    this->_debugWindow->setFTDIdevice(this->_FTDIdevice);

    //set the FTDI device to the dataFrameLiveReading
    //this->_frameThread->setFTDIFunction(*this->_FTDIdevice);

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

#if LINUX
bool MainWindow::_FTDIconnection()
{
    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIDeviceFound)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIDeviceFound]);

        this->_waitDelay(1);

        //display device information
        _initWindow->addTextInLabel("number of device : " + QString::number(this->_FTDIdevice->numDevs()));
        _initWindow->addTextInLabel("Flags = \t0x" + QString::number(this->_FTDIdevice->Flags()));
        _initWindow->addTextInLabel("Type  = \t0x" + QString::number(this->_FTDIdevice->Type()));
        _initWindow->addTextInLabel("ID    = \t0x" + QString::number(this->_FTDIdevice->ID()));
        _initWindow->addTextInLabel("LocId = \t0x" + QString::number(this->_FTDIdevice->LocId()));
        _initWindow->addTextInLabel("SerialNumber\t: " + this->_FTDIdevice->SerialNumber());
        _initWindow->addTextInLabel("Description\t: " + this->_FTDIdevice->Description());

        this->_waitDelay(1);

    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIDeviceFound]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIopened)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIopened]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIopened]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIUSBparameterSetted)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIUSBparameterSetted]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIUSBparameterSetted]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIBaudRateSetted)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIBaudRateSetted]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIBaudRateSetted]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIDataCaracteristiqueSetted)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIDataCaracteristiqueSetted]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIDataCaracteristiqueSetted]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIFlowControlSetted)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIFlowControlSetted]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIFlowControlSetted]);
    }

    this->_waitDelay(1);

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDITxRxBufferFree)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDITxRxBufferFree]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDITxRxBufferFree]);
    }

    if(this->_FTDIdevice->FTDIState() >= GlobalEnumatedAndExtern::FTDIready)
    {
        _initWindow->addTextInLabel(this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIready]);
    }
    else
    {
        _initWindow->addTextInLabel("error befor state "+ this->_FTDIStatePossibleTXT[GlobalEnumatedAndExtern::FTDIready]);
    }

    this->_waitDelay(1);

    return (this->_FTDIdevice->FTDI_OK());
}
#endif
void MainWindow::_waitDelay(int delayInSeconde)
{
    QTime dieTime= QTime::currentTime().addSecs(delayInSeconde);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::changeStateStartStopButton(int state)
{
    this->_startStopButtonTextAndColorManager((GlobalEnumatedAndExtern::eBPStartStopState)state);
}

void MainWindow::startThread()
{
    this->_threadDataAnalysis->start();
    this->_threadDisplayRefresh->start();
    //in simulation mode
    if(this->_inSimulation)
    {
        //start thread for simulation data
        this->_threadNewDataFrame->startWorking();

        //start thread for data analysing
        this->_threadDataAnalysis->startWorking();
    }
    else
    {
#if LINUX
        if(this->_FTDI_OK)
        {
            this->_getNewLiveData->startTimer();

        }
#endif
    }

    //start refreshing display
    this->_threadDisplayRefresh->startWorking();

}

void MainWindow::stopThread()
{
    //    _tickTimer->stopTimer();

    // if it's in roll mode
    if(this->_mainStateStep == GlobalEnumatedAndExtern::mainStateRoll)
    {
        //stop dispaly refreshing
        this->_threadDisplayRefresh->stopWorking();
    }
    else
    {
        //stop thread for simulation data
        this->_threadNewDataFrame->stopWorking();

        //stop thread for data analysing
        this->_threadDataAnalysis->stopWorking();
        //       qDebug() << "real time thread running : " << this->_threadRealTimeReading->isRunning();
        //        _newDataFrameTimer->stopTimer();
        //this->_dataFrameLiveReading->stopReading();
        //        if(!this->_dataFrameLiveReading->isRunning())
        //        {
        //            this->_dataFrameLiveReading->start();
        //       }

        //       this->_dataFrameLiveReading->stopReading();
        //        qDebug() << "real time thread running after : " << this->_threadRealTimeReading->isRunning();

    }
}

void MainWindow::addNewProducteurAdress(int itProducerAdress)
{
    _itIntProducer = itProducerAdress;
}

void MainWindow::addNewSimulatedDataFrame()
{
    //wait untile the first data was creating
    int i = 0;
    this->_onTrigTrue = false;
    static bool memoOnTrigTrue = false;
    this->_itTrace = _dataFrameTrace.begin();
    this->_triggerFuntion = _settingWindow->getTriggerFuntion();

    if(!memoOnTrigTrue)
    {
        this->_nbValueAfterTrig = _amontOfValueAfterTrig;
    }

    //    qDebug() << objectName() << "received addNewSimulatedDataFrame";
    while(i< 1 && !_onTrigTrue)
        //    while(i< 50 && this->_nbValueAfterTrig > 0)
    {

        //if to fast and arrived on the data creation pointer
        if((int)_itConsumer != _itIntProducer)
        {
            //set the new position to frame emulator
            this->_dataFrameSimulator->setItConsumerAdress(_itConsumer);

            //read the circular array and put on the trace array for futur ploting
            *_itTrace = *this->_itConsumer;

            switch (_mainStateStep)
            {
            case GlobalEnumatedAndExtern::mainStateRoll:
                //send value to the plot
                this->_rollWindow->addNewDataFrame(_itTrace);
                break;
            case GlobalEnumatedAndExtern::mainStateTrig:

                //check trigger function
                _onTrigTrue =  this->_triggerFuntion->onTrig(_itTrace);

                //change state is case of trig
                if(_onTrigTrue && !memoOnTrigTrue)
                {
                    _trigStateStep = GlobalEnumatedAndExtern::trigTrigged;
                    _trigStateGraph();
                    memoOnTrigTrue = true;
                }

                //decrease nomber of value after trig
                if(memoOnTrigTrue)
                {
                    this->_nbValueAfterTrig = this->_nbValueAfterTrig > 0 ?
                                this->_nbValueAfterTrig - 1 : 0;
                    qDebug() << "rest of value :" << _nbValueAfterTrig;
                }

                //when ervery data are saved
                if(memoOnTrigTrue && _nbValueAfterTrig == 0)
                {
                    //stop the reccording
                    this->stopThread();

                    //reset for next start
                    memoOnTrigTrue = false;
                }

                //send value to the plot
                this->_triggerWindow->addNewDataFrame(_itTrace);
                break;
            default:
                break;
            }

            this->_itConsumer++;
            this->_itTrace++;
            this->_itConsumer = this->_itConsumer != _dataFrameReccorder.begin()? this->_itConsumer : this->_dataFrameReccorder.begin();
            this->_itTrace = this->_itTrace != _dataFrameTrace.end() ? this->_itTrace : this->_dataFrameTrace.begin();

        }
        i++;
    }
}

void MainWindow::addNewLiveDataFrame(int itProducerAdress)
{
    //   qDebug() << objectName() << "received addNewLiveDataFrame";

    for(int i = 0; i< 10 ; i++) // NB_LIVE_READING_DATA; i++)

        //   for(QVector<DataFrame>::iterator it = _dataFrameTrace.begin(); it != _dataFrameTrace.end(); it++)
    {
        //if to fast and arrived on the data creation pointeur
        if((int)_itConsumer != itProducerAdress)
        {
            //set the new position to frame emulator
            this->_dataFrameSimulator->setItConsumerAdress(_itConsumer);

            //read the circular array and put on the trace array for futur ploting
            *_itTrace = *this->_itConsumer;

            //check trigger function
            _onTrigTrue =  this->_triggerFuntion->onTrig(_itTrace);

            if(_onTrigTrue)
            {
                _trigStateStep = GlobalEnumatedAndExtern::trigTrigged;
                _trigStateGraph();
            }

            this->_itConsumer++;
            this->_itTrace++;
            this->_itConsumer = this->_itConsumer != _dataFrameReccorder.begin()? this->_itConsumer : this->_dataFrameReccorder.begin();
            this->_itTrace = this->_itTrace != _dataFrameTrace.end() ? this->_itTrace : this->_dataFrameTrace.begin();
        }
    }
}

void MainWindow::refreshDisplay()
{
    this->_rollWindow->refreshPlot();
    this->_triggerWindow->refreshPlot();
}

void MainWindow::checkBoxEmulationModeChanged(bool checked)
{
    this->_inSimulation = checked;

    if(checked)
    {
#if LINUX
        emit _errorFTDIDeviceNotFound(GlobalEnumatedAndExtern::errorFTDIDeviceNotFound, false);
#endif
    }
    else
    {
        //restart application in init mode
        this->_mainStateStep = GlobalEnumatedAndExtern::mainStateInit;
        this->_mainStateGraphe();
    }
}

void MainWindow::received__settingSizeOfPlotWasChanged(int nbPixels)
{
    this->_rollWindow->setSizeOfPlot(nbPixels);
    this->_triggerWindow->setSizeOfPlot(nbPixels);
}

void MainWindow::_setupSignalAndSlot()
{
    //manage the size of plot
    QObject::connect(ui->widgetPlotSetting, SIGNAL(_settingSizeOfPlotWasChanged(int)), this, SLOT(received__settingSizeOfPlotWasChanged(int)));

    //manage the number of frame saved after trigger
    QObject::connect(_settingWindow, SIGNAL(_percentPreTriggerWasChanged(quint8)),
                     this, SLOT(received_percentPreTriggerChanged(quint8)));

    //manage trace in trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInTriggerMenu(quint8)), this->_triggerWindow, SLOT(addTrace(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInTriggerMenu(quint8)), this->_triggerWindow, SLOT(hideTrace(quint8)));

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
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI1WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI1_changeEdge(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI2WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI2_changeEdge(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI3WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI3_changeEdge(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeDI4WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeDI4_changeEdge(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeAI1WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeAI1_changeEdge(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonEdgeAI2WasChangedFromSettingMenu(quint8)),
                     this->_triggerWindow, SLOT(pushButtonEdgeAI2_changeEdge(quint8)));

    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI1WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI1_changeEdge(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI2WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI2_changeEdge(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI3WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI3_changeEdge(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeDI4WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeDI4_changeEdge(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeAI1WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeAI1_changeEdge(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonEdgeAI2WasChanged(quint8)),
                     this->_settingWindow, SLOT(pushButtonEdgeAI2_changeEdge(quint8)));

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
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxTopLeft_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxTopRight_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxBottomLeft_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxBottomRight_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxTopMiddle_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxMiddle_changeCurrentIndex(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(quint8)),
                     this->_triggerWindow, SLOT(comboBoxBottomMiddle_changeCurrentIndex(quint8)));

    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxTopLeft_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxTopRight_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxBottomLeft_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxBottomRight_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxTopMiddle_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxMiddle_changeCurrentIndex(quint8)));
    QObject::connect(this->_triggerWindow, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(quint8)),
                     this->_settingWindow, SLOT(comboBoxBottomMiddle_changeCurrentIndex(quint8)));

    //set visible trace in display menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInDisplayMenu(quint8)), this->_rollWindow, SLOT(addTrace(quint8)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInDisplayMenu(quint8)), this->_rollWindow, SLOT(hideTrace(quint8)));

    //send new value for scale factor in setting menu
    QObject::connect(this->_debugWindow, SIGNAL(_nbFrameSavedChanged(quint64)), this->_settingWindow, SLOT(_received_NbFrameSavedChanged(quint64)));
    QObject::connect(this->_debugWindow, SIGNAL(_frameSizeChanged(int)), this->_settingWindow, SLOT(_received_SizeFrameChange(int)));
#if LINUX
    QObject::connect(this->_debugWindow, SIGNAL(_FTDIBaudrateChanged(int)), this->_settingWindow, SLOT(_received_FTDIBaudrateChange(int)));
#endif
    //error management
    QObject::connect(this->_settingWindow, SIGNAL(_errorNoSelectedTrace(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorNoSelectedTriggerTrace(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorFrequencyToLow(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
    QObject::connect(this->_settingWindow, SIGNAL(_errorWrongEquation(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
    QObject::connect(this->_triggerWindow, SIGNAL(_errorWrongEquation(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
#if LINUX
    QObject::connect(this, SIGNAL(_errorFTDIDeviceNotFound(quint8,bool)), ui->widgetError, SLOT(_reveived_Error(quint8,bool)));
#endif
    //manage application in simulation mode or not
    QObject::connect(this->_debugWindow, SIGNAL(_checkBoxEmulationModeStatusWasChanged(bool)), this, SLOT(checkBoxEmulationModeChanged(bool)));

    //timer management to be sure they start correctly
    //    QObject::connect(this->_threadDataAnalysis, SIGNAL(started), this->_tickTimer, SLOT(start()));
    //    QObject::connect(this->_threadDisplayRefresh, SIGNAL(started), this->_refreshDisplayTimer, SLOT(start()));
    //    QObject::connect(this->_threadDataFramSimulator, SIGNAL(started), this->_dataFrameSimulator, SLOT(start()));

    //refresh plot
    QObject::connect(this->_threadDisplayRefresh, SIGNAL(delayFinished()), this, SLOT(refreshDisplay()));

    //create new data frame from dataFrameSimulator
    QObject::connect(this->_threadNewDataFrame, SIGNAL(delayFinished()), _dataFrameSimulator, SLOT(createDataFrame()));
    //QObject::connect(_dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &graphicPlot, SLOT(addYValue(quint8)));
    //QObject::connect(dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &analogPlot, SLOT(addYValue(quint8)));
    QObject::connect(_dataFrameSimulator, SIGNAL(dataFrameWasSent(int)),this,SLOT(addNewProducteurAdress(int)));

    //check trig and add data in plot
    QObject::connect(_threadDataAnalysis, SIGNAL(delayFinished()), this, SLOT(addNewSimulatedDataFrame()));
    //start real time reading
    //QObject::connect(this->_FTDIdevice, SIGNAL(_startReading()), this->_FTDIdevice, SLOT(recieved_startReading()));
#if LINUX
    //refresh the display
    QObject::connect(_frameThread, SIGNAL(delayFinished()), this->_FTDIdevice, SLOT(received_connectFTDIDevice()));
    QObject::connect(_FTDIdevice, SIGNAL(dataFrameWasSent(int)), this, SLOT(addNewLiveDataFrame(int)));
#endif
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
    _initWindow->hide();
    _homeWindow->hide();
    _settingWindow->hide();
    _triggerWindow->hide();
    _rollWindow->hide();
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

        //clear text
        this->_initWindow->clearTextLabel();
        _initWindow->addTextInLabel("Initilisation is running...\n\n");

        //show home page
        this->_initWindow->show();

        //hide menu bottom bar
        ui->statusBar->hide();

        qDebug() << "main state on : " << "init";
        //connect the FTDI device
#if LINUX
#if INI_MESSAGE_DISPLAY

        this->_FTDI_OK = this->_FTDIconnection();
#endif
        if(this->_FTDI_OK)
        {
            this->_waitDelay(1);
            _initWindow->addTextInLabel("\n Initialisation sucessfull...");
            emit _errorFTDIDeviceNotFound(GlobalEnumatedAndExtern::errorFTDIDeviceNotFound, false);
        }
        else
        {
            _initWindow->addTextInLabel("\n FTDI not working...");

            this->_waitDelay(3);
            emit _errorFTDIDeviceNotFound(GlobalEnumatedAndExtern::errorFTDIDeviceNotFound, true);
        }
#endif
        _initWindow->addTextInLabel("\n Starting up application...");
#if LINUX
        //set the device in debug windows
        //_debugWindow->setFTDIdevice(this->_FTDIdevice);
        //if all init passed
#endif
        this->_waitDelay(1);

        //show menu bottom bar
        ui->statusBar->show();
        //_FTDIdevice->liveReading(&_FTDIdevice->_dataStart);
        //start application on the hme page
        this->_btHome_released();

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

        //set trig state to ready
        this->_trigStateStep = GlobalEnumatedAndExtern::trigReady;
        this->_trigStateGraph();

        //set roll state to ready
        this->_rollStateStep = GlobalEnumatedAndExtern::rollReady;
        this->_rollStateGraph();

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
        //activate roll button menu
        _btRoll->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                               "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

        //reset BP roll state
        this->_btRollWasPressed = false;

        //show roll window
        _rollWindow->show();

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
    // stop state
    if(_mainStateStep == GlobalEnumatedAndExtern::mainStateStop)
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
    case GlobalEnumatedAndExtern::trigNotReady:
        break;
    case GlobalEnumatedAndExtern::trigReady:

        //change StartStopButton to Start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //stop thread for analysing and refresh the display
        this->stopThread();

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        break;
    case GlobalEnumatedAndExtern::trigRunTrig:
        //change StartStopButton to Stop
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::stop);

        //start thread for analysing and refresh the display
        this->startThread();

        //set display state to Run Trig
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::runTrig);

        //qDebug() << "running status" << this->_dataFrameLiveReading->isRunning();
        //this->_dataFrameLiveReading->startReading();
        break;
    case GlobalEnumatedAndExtern::trigTrigged:
        //change StartStopButton to start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //stop thread for analysing and refresh the display
        //       this->stopThread();

        //set display state to trigged
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::trigged);

        break;
    default:
        break;
    }
}

void MainWindow::_rollStateGraph()
{
    switch (this->_rollStateStep)
    {
    case GlobalEnumatedAndExtern::rollNotReady:
        break;
    case GlobalEnumatedAndExtern::rollReady:
        //change StartStopButton to Start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //set display state to ready
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::ready);

        break;
    case GlobalEnumatedAndExtern::rollRollOn:
        //change StartStopButton to hold
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::hold);

        //start thread for analysing and refresh the display
        this->startThread();

        //set display state to roll on
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::rollOn);

        break;
    case GlobalEnumatedAndExtern::rollPaused:
        //change StartStopButton to start
        this->_startStopButtonTextAndColorManager(GlobalEnumatedAndExtern::start);

        //stop thread for analysing and refresh the display
        this->stopThread();

        //set display state to paused
        ui->widgetState->setDisplayState(GlobalEnumatedAndExtern::paused);

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
        //can start if there are in simulation or
        //not in simulation mode and ftdi device all right
        if(this->_inSimulation
        #if LINUX
                || (!this->_inSimulation && this->_FTDI_OK)
        #endif
                )
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
                switch (_rollStateStep)
                {
                case GlobalEnumatedAndExtern::rollReady:
                    //next roll state
                    this->_rollStateStep = GlobalEnumatedAndExtern::rollRollOn;
                    this->_rollStateGraph();
                    break;
                case GlobalEnumatedAndExtern::rollPaused:
                    //next roll state
                    this->_rollStateStep = GlobalEnumatedAndExtern::rollRollOn;
                    this->_rollStateGraph();
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
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
            switch (_rollStateStep)
            {
            case GlobalEnumatedAndExtern::rollRollOn:
                //next roll state
                this->_rollStateStep = GlobalEnumatedAndExtern::rollPaused;
                this->_rollStateGraph();
                break;
            default:
                break;
            }
        case GlobalEnumatedAndExtern::mainStateDebug:
            break;
        default:
            break;
        }
    }
    //    qDebug() << objectName() << "trigger Enable" << _settingWindow->triggerFunctionEnable();
}

void MainWindow::received_percentPreTriggerChanged(quint8 percent)
{
    this->_amontOfValueAfterTrig = NB_FRAME_MEMORIZED -((NB_FRAME_MEMORIZED * percent) / 100);
    qDebug() << "nb Frame saved after trig" << this->_amontOfValueAfterTrig;
}

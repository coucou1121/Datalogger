#include "mainwindow.h"
#include "ui_mainwindow.h"

//ready for work
//just to be sure
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE, MINIMUM_HEIGHT_SIZE);

    //create windows object
    _baseWindow = new BaseWindow();
    _settingWindow = new SettingWindow();
    _triggerWindow = new TriggerWindow();
    _displayWindow = new DisplayWindows();
    _debugWindow = new DebugWindow();

    this->mainSetup();
    this->setupStyle();
    this->setStatusBar();

    //select Setting menu when start the application
    this->_btSetting_released();

    //setup signal and slot
    this->setupSignalAndSlot();

    //setup default values
    this->setupDefaultValue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainSetup()
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

}

void MainWindow::setupDefaultValue()
{
    _debugWindow->setNbSavedFrame(65536); //max 999999999 for the slot
    _debugWindow->setFrameSize(64);
    _debugWindow->setBaudRateFTDI(2000000);
}

void MainWindow::setupSignalAndSlot()
{
    //manage trace in trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInTriggerMenu(int)), this->_triggerWindow, SLOT(_addTrace(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInTriggerMenu(int)), this->_triggerWindow, SLOT(_hideTrace(int)));

    //manage range in trigger menu
    //setting menu -> trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonRangeAI1WasChangedFromSettingMenu()),
                     this->_triggerWindow, SLOT(_pushButtonRangeAI1Changed()));
    QObject::connect(this->_settingWindow, SIGNAL(_pushButtonRangeAI2WasChangedFromSettingMenu()),
                     this->_triggerWindow, SLOT(_pushButtonRangeAI2Changed()));
    //trigger menu -> setting menu
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this->_settingWindow, SLOT(_recieved_pushButtonRangeAI1ChangedFromTriggerMenu()));
    QObject::connect(this->_triggerWindow, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this->_settingWindow, SLOT(_recieved_pushButtonRangeAI2ChangedFromTriggerMenu()));

    //manage select trace in trigger fonction menu of setting menu to trigger menu
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxTopLeft_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxTopRight_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxBottomLeft_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxBottomRight_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxTopMiddle_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxMiddle_currentIndexChanged(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this->_triggerWindow, SLOT(_comboBoxBottomMiddle_currentIndexChanged(int)));

    //manage trace in display menu
    QObject::connect(this->_settingWindow, SIGNAL(_addTraceInDisplayMenu(int)), this->_displayWindow, SLOT(_addTrace(int)));
    QObject::connect(this->_settingWindow, SIGNAL(_removeTraceInDisplayMenu(int)), this->_displayWindow, SLOT(_hideTrace(int)));

    //send new value for scale factor in setting menu
    QObject::connect(this->_debugWindow, SIGNAL(_nbFrameSavedChanged(quint64)), this->_settingWindow, SLOT(_recievedNbFrameSavedChanged(quint64)));
    QObject::connect(this->_debugWindow, SIGNAL(_frameSizeChanged(int)), this->_settingWindow, SLOT(_recievedSizeFrameChange(int)));
    QObject::connect(this->_debugWindow, SIGNAL(_FTDIBaudrateChanged(int)), this->_settingWindow, SLOT(_recievedFTDIBaudrateChange(int)));

    //error management
    QObject::connect(this->_settingWindow, SIGNAL(_errorFrequencyToLow(int,bool)), ui->widgetError, SLOT(_reveivedError(int,bool)));
}

void MainWindow::setupStyle()
{
    QPalette palette;
    palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());
    //palette.setColor(QPalette::Foreground,Qt::red);
    this->setPalette(palette);
}

void MainWindow::setStatusBar()
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

void MainWindow::resetPushButtonColor()
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
    this->resetPushButtonColor();
    _btBase->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _baseWindow->show();
}

void MainWindow::_btSetting_released()
{
    this->resetPushButtonColor();
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _settingWindow->show();
}

void MainWindow::_btTrigger_released()
{
    this->resetPushButtonColor();
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _triggerWindow->show();
}

void MainWindow::_btDisplay_released()
{
    this->resetPushButtonColor();
    _btDisplay->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _displayWindow->show();
}

void MainWindow::_btDebug_released()
{
    this->resetPushButtonColor();
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    _debugWindow->show();
}


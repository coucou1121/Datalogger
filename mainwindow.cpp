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
    baseWindow = new BaseWindow();
    settingWindow = new SettingWindow();
    triggerWindow = new TriggerWindow();
    displayWindow = new DisplayWindows();

    this->mainSetup();
    this->setupStyle();
    this->setStatusBar();

    this->_btSetting_released();

    //setup signal and slot
    this->setupSignalAndSlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainSetup()
{
    //add base windows in windows layout
    ui->gridLayout->addWidget(baseWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(settingWindow, 0, 1, 6, 1);

    //add setting windows in windows layout
    ui->gridLayout->addWidget(triggerWindow, 0, 1, 6, 1);

    //add display window in window layout
    ui->gridLayout->addWidget(displayWindow, 0, 1, 6, 1);

    //set title on baseWindows
    baseWindow->setTitle("Datalogger");

    //set version on baseWindows
    baseWindow->setVersion("1.0");

}

void MainWindow::setupSignalAndSlot()
{
    QObject::connect(this->settingWindow, SIGNAL(_addTraceInTriggerMenu(int)), this->triggerWindow, SLOT(_addTrace(int)));
    QObject::connect(this->settingWindow, SIGNAL(_removeTraceInTriggerMenu(int)), this->triggerWindow, SLOT(_hideTrace(int)));

    QObject::connect(this->settingWindow, SIGNAL(_addTraceInDisplayMenu(int)), this->displayWindow, SLOT(_addTrace(int)));
    QObject::connect(this->settingWindow, SIGNAL(_removeTraceInDisplayMenu(int)), this->displayWindow, SLOT(_hideTrace(int)));
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

    baseWindow->hide();
    settingWindow->hide();
    triggerWindow->hide();
    displayWindow->hide();
}

void MainWindow::_btBase_released()
{
    this->resetPushButtonColor();
    _btBase->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    baseWindow->show();
}

void MainWindow::_btSetting_released()
{
    this->resetPushButtonColor();
    _btSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    settingWindow->show();
}

void MainWindow::_btTrigger_released()
{
    this->resetPushButtonColor();
    _btTrigger->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    triggerWindow->show();
}

void MainWindow::_btDisplay_released()
{
    this->resetPushButtonColor();
    _btDisplay->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
    displayWindow->show();
}

void MainWindow::_btDebug_released()
{
    this->resetPushButtonColor();
    _btDebug->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}


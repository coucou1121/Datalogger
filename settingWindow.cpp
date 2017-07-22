#include "settingWindow.h"
#include "ui_settingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    this->setupSignalAndSlot();
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::setupSignalAndSlot()
{
    //lock or unlock the selection in trigger setting menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btSeleccted(int,bool)), ui->widgetTriggerSetting, SLOT(_btSelected(int,bool)));

    //add button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));

    //remove button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));

    //add Trace in all needed menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_addTrace(int)),this, SLOT(_recievedAddTraceFromChannelSelection(int)));

    //remove Trace in  all needed menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_removeTrace(int)),this, SLOT(_recievedRemoveTraceFromChannelSelection(int)));

    //update save frame number in time scale factor menu
    QObject::connect(this, SIGNAL(_nbFrameSavedChange(quint64)),ui->widgetTimeScallFactor, SLOT(_nbFrameSavedWasChanged(quint64)));

    //update size of one frame
    QObject::connect(this, SIGNAL(_sizeFrameChange(int)),ui->widgetTimeScallFactor, SLOT(_sizeFrameWasChanged(int)));

    //update save frame number in time scale factor menu
    QObject::connect(this, SIGNAL(_FTDIBaudrateChange(int)),ui->widgetTimeScallFactor, SLOT(_FTDIBaudrateWasChanged(int)));

    //error management
    QObject::connect(ui->widgetTimeScallFactor, SIGNAL(_errorFrequencyToLow(int,bool)),this, SLOT(_recievedErrorFrequencyToLow(int,bool)));
}

void SettingWindow::_recievedAddTraceFromChannelSelection(int traceNumber)
{
    // add in trigger menu
    emit _addTraceInTriggerMenu(traceNumber);

    // add in display menu
    emit _addTraceInDisplayMenu(traceNumber);
}

void SettingWindow::_recievedRemoveTraceFromChannelSelection(int traceNumber)
{
    //remove in trigger menu
    emit _removeTraceInTriggerMenu(traceNumber);

    //remove in display menu
    emit _removeTraceInDisplayMenu(traceNumber);
}

void SettingWindow::_recievedErrorFrequencyToLow(int errorNumber, bool active)
{
    emit _errorFrequencyToLow(errorNumber, active);
}

void SettingWindow::_recievedNbFrameSavedChanged(quint64 nbFrameChanged)
{
 //   qDebug() << objectName() << nbFrameChanged;
    emit _nbFrameSavedChange(nbFrameChanged);
}

void SettingWindow::_recievedSizeFrameChange(int frameSize)
{
//    qDebug() << objectName() << frameSize;
    emit _sizeFrameChange(frameSize);
}

void SettingWindow::_recievedFTDIBaudrateChange(int FTDIBaudrate)
{
 //   qDebug() << objectName() << FTDIBaudrate;
    emit _FTDIBaudrateChange(FTDIBaudrate);
}

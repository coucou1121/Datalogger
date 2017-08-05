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

    //manage range in trigger menu
    //setting menu -> trigger menu
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI1ChangedFromSettingMenu()));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI2ChangedFromSettingMenu()));
    //trigger menu -> setting menu
    QObject::connect(this, SIGNAL(_pushButtonRangeAI1WasChangedFromTriggerMenu()),
                     ui->widgetTriggerSetting, SLOT(_pushButtonRangeAI1Changed()));
    QObject::connect(this, SIGNAL(_pushButtonRangeAI2WasChangedFromTriggerMenu()),
                     ui->widgetTriggerSetting, SLOT(_pushButtonRangeAI2Changed()));

    //add button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));

    //remove button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));

    //select same trace according with the setting menu in the other trigger setting function
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxTopLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxTopRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxBottomLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxBottomRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxTopMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recievedComboBoxBottomMiddle_currentIndexChanged(int)));

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

void SettingWindow::_recieved_pushButtonRangeAI1ChangedFromSettingMenu()
{
    emit _pushButtonRangeAI1WasChangedFromSettingMenu();
}

void SettingWindow::_recieved_pushButtonRangeAI2ChangedFromSettingMenu()
{
    emit _pushButtonRangeAI2WasChangedFromSettingMenu();
}

void SettingWindow::_recieved_pushButtonRangeAI1ChangedFromTriggerMenu()
{
    qDebug() << objectName() << "recieved _recieved_pushButtonRangeAI1ChangedFromTriggerMenu";
    emit _pushButtonRangeAI1WasChangedFromTriggerMenu();
}

void SettingWindow::_recieved_pushButtonRangeAI2ChangedFromTriggerMenu()
{
    emit _pushButtonRangeAI2WasChangedFromTriggerMenu();
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

void SettingWindow::_recievedComboBoxTopLeft_currentIndexChanged(int index)
{
//    qDebug()<< objectName() << " comboBoxTopLeft received index changed : " << index;
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxTopRight_currentIndexChanged(int index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxBottomLeft_currentIndexChanged(int index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxBottomRight_currentIndexChanged(int index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxTopMiddle_currentIndexChanged(int index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxMiddle_currentIndexChanged(int index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_recievedComboBoxBottomMiddle_currentIndexChanged(int index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

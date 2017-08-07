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

    //connection of all signals from setting menu to outside
    //manage range
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI1Changed()));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI2Changed()));

    //manage eEdge
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI1WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI1Changed(int)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI2WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI2Changed(int)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI3WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI3Changed(int)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI4WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI4Changed(int)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeAI1WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeAI1Changed(int)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeAI2WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeAI2Changed(int)));

    //manage value in doubleSpinBoxes
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI1_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI2_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI2_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI3_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI3_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI4_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI4_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxAI1_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxAI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxAI2_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxAI2_valueChanged(double)));

    //add button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));

    //remove button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));

    //select same trace according with the setting menu in the other trigger setting function
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomMiddle_currentIndexChanged(int)));

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

void SettingWindow::_recieved_pushButtonRangeAI1Changed()
{
    emit _pushButtonRangeAI1WasChangedFromSettingMenu();
}

void SettingWindow::_recieved_pushButtonRangeAI2Changed()
{
    emit _pushButtonRangeAI2WasChangedFromSettingMenu();
}

void SettingWindow::_recieved_pushButtonEdgeDI1Changed(int eEdge)
{
    emit _pushButtonEdgeDI1WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recieved_pushButtonEdgeDI2Changed(int eEdge)
{
    emit _pushButtonEdgeDI2WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recieved_pushButtonEdgeDI3Changed(int eEdge)
{
    emit _pushButtonEdgeDI3WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recieved_pushButtonEdgeDI4Changed(int eEdge)
{
    emit _pushButtonEdgeDI4WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recieved_pushButtonEdgeAI1Changed(int eEdge)
{
    emit _pushButtonEdgeAI1WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recieved_pushButtonEdgeAI2Changed(int eEdge)
{
    emit _pushButtonEdgeAI2WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_recievedNbFrameSavedChanged(quint64 nbFrameChanged)
{
    emit _nbFrameSavedChange(nbFrameChanged);
}

void SettingWindow::_recievedSizeFrameChange(int frameSize)
{
    emit _sizeFrameChange(frameSize);
}

void SettingWindow::_recievedFTDIBaudrateChange(int FTDIBaudrate)
{
    emit _FTDIBaudrateChange(FTDIBaudrate);
}

void SettingWindow::pushButtonRangeAI1_changeRange()
{
    ui->widgetTriggerSetting->pushButtonRangeAI1_ChangeRange();
}

void SettingWindow::pushButtonRangeAI2_changeRange()
{
    ui->widgetTriggerSetting->pushButtonRangeAI2_ChangeRange();
}

void SettingWindow::pushButtonEdgeDI1_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI1_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI2_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI2_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI3_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI3_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI4_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI4_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeAI1_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeAI1_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeAI2_changeEdge(int eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeAI2_changeEdge(eEdge);
}

void SettingWindow::doubleSpinBoxDI1_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxDI1_changeValue(value);
}

void SettingWindow::doubleSpinBoxDI2_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxDI2_changeValue(value);
}

void SettingWindow::doubleSpinBoxDI3_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxDI3_changeValue(value);
}

void SettingWindow::doubleSpinBoxDI4_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxDI4_changeValue(value);
}

void SettingWindow::doubleSpinBoxAI1_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxAI1_changeValue(value);
}

void SettingWindow::doubleSpinBoxAI2_changeValue(double value)
{
    ui->widgetTriggerSetting->doubleSpinBoxAI2_changeValue(value);
}

void SettingWindow::_recieved_doubleSpinBoxDI1_valueChanged(double value)
{
    emit _doubleSpinBoxDI1_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_doubleSpinBoxDI2_valueChanged(double value)
{
    emit _doubleSpinBoxDI2_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_doubleSpinBoxDI3_valueChanged(double value)
{
    emit _doubleSpinBoxDI3_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_doubleSpinBoxDI4_valueChanged(double value)
{
    emit _doubleSpinBoxDI4_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_doubleSpinBoxAI1_valueChanged(double value)
{
    emit _doubleSpinBoxAI1_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_doubleSpinBoxAI2_valueChanged(double value)
{
    emit _doubleSpinBoxAI2_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_recieved_ComboBoxTopLeft_currentIndexChanged(int index)
{
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxTopRight_currentIndexChanged(int index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxBottomLeft_currentIndexChanged(int index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxBottomRight_currentIndexChanged(int index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxTopMiddle_currentIndexChanged(int index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxMiddle_currentIndexChanged(int index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_recieved_ComboBoxBottomMiddle_currentIndexChanged(int index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

void SettingWindow::comboBoxTopLeft_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopLeft_currentIndexChanged(index);
}

void SettingWindow::comboBoxTopRight_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopRight_currentIndexChanged(index);
}

void SettingWindow::comboBoxBottomLeft_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomLeft_currentIndexChanged(index);
}

void SettingWindow::comboBoxBottomRight_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomRight_currentIndexChanged(index);
}

void SettingWindow::comboBoxTopMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopMiddle_currentIndexChanged(index);
}

void SettingWindow::comboBoxMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxMiddle_currentIndexChanged(index);
}

void SettingWindow::comboBoxBottomMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomMiddle_currentIndexChanged(index);
}

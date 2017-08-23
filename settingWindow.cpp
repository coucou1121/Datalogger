#include "settingWindow.h"
#include "ui_settingWindow.h"

extern qint8 minRange0;
extern qint8 maxRange0_24;
extern qint8 maxRange0_30;
extern qint8 minRange_15_15;
extern qint8 maxRange_15_15;

SettingWindow::SettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    this->_setupSignalAndSlot();
//    this->enableWindows(true);

    _triggerFunctionEnable = false;

    _triggerFunction = new TriggerFunctions();
    _triggerSetting = new TriggerFunctions();
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::_setupSignalAndSlot()
{
    //lock or unlock the selection in trigger setting menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btSeleccted(quint8,bool)), ui->widgetTriggerSetting, SLOT(_btSelected(quint8,bool)));

    //connection of all signals from setting menu to outside
    //manage range
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this, SLOT(_received_pushButtonRangeAI1Changed()));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this, SLOT(_received_pushButtonRangeAI2Changed()));

    //manage eEdge
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI1WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeDI1Changed(quint8)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI2WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeDI2Changed(quint8)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI3WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeDI3Changed(quint8)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeDI4WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeDI4Changed(quint8)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeAI1WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeAI1Changed(quint8)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_pushButtonEdgeAI2WasChanged(quint8)),
                     this, SLOT(_received_pushButtonEdgeAI2Changed(quint8)));

    //manage value in doubleSpinBoxes
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI1_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxDI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI2_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxDI2_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI3_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxDI3_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxDI4_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxDI4_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxAI1_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxAI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSetting, SIGNAL(_doubleSpinBoxAI2_valueWasChanged(double)),
                     this, SLOT(_received_doubleSpinBoxAI2_valueChanged(double)));

    //add trace in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(quint8)),ui->widgetTriggerFunction, SLOT(comboboxAddItem(quint8)));

    //remove trace in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(quint8)),ui->widgetTriggerFunction, SLOT(comboboxRevmoveItem(quint8)));

    //select same trace according with the setting menu in the other trigger setting function
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxTopLeft_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxTopRight_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxBottomLeft_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxBottomRight_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxTopMiddle_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxMiddle_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_received_ComboBoxBottomMiddle_currentIndexChanged(quint8)));

    //add Trace in all needed menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_addTrace(quint8)),this, SLOT(_received_AddTraceFromChannelSelection(quint8)));

    //remove Trace in  all needed menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_removeTrace(quint8)),this, SLOT(_received_RemoveTraceFromChannelSelection(quint8)));

    //update save frame number in time scale factor menu
    QObject::connect(this, SIGNAL(_nbFrameSavedChange(quint64)),ui->widgetTimeScaleFactor, SLOT(_nbFrameSavedWasChanged(quint64)));

    //update size of one frame
    QObject::connect(this, SIGNAL(_sizeFrameChange(int)),ui->widgetTimeScaleFactor, SLOT(_sizeFrameWasChanged(int)));

    //update save frame number in time scale factor menu
    QObject::connect(this, SIGNAL(_FTDIBaudrateChange(int)),ui->widgetTimeScaleFactor, SLOT(_FTDIBaudrateWasChanged(int)));

    //error management
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_errorNoSelectedTrace(quint8,bool)),
                     this, SLOT(_received_errorNoSelectedTrace(quint8,bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_errorNoSelectedTriggerTrace(quint8,bool)),
                     this, SLOT(_received_errorNoSectedTriggerTrace(quint8,bool)));
    QObject::connect(ui->widgetTimeScaleFactor, SIGNAL(_errorFrequencyToLow(quint8,bool)),
                     this, SLOT(_received_errorFrequencyToLow(quint8,bool)));
    QObject::connect(ui->widgetTriggerFunction, SIGNAL(_errorWrongEquation(quint8,bool)),
                     this, SLOT(_received_errorWrongEquation(quint8,bool)));
}

quint8 SettingWindow::doubleToQint8(double value, GlobalEnumatedAndExtern::eRangeValue range)
{
    qint8 minRangeValue = 0;
    qint8 maxRangeValue = 0;

    qDebug() << value;
    switch (range)
    {
    case GlobalEnumatedAndExtern::range0_24:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_24;
        break;
    case GlobalEnumatedAndExtern::range0_30:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_30;
        break;
    case GlobalEnumatedAndExtern::range15_15:
        minRangeValue = minRange_15_15;
        maxRangeValue = maxRange_15_15;
        break;
    default:
        break;
    }

    double result = value;
//    qDebug() << "double value : " << result;
    quint8 resultInt = (quint8)result;
//    qDebug() << "int value : " << resultInt;

    return resultInt;
}

bool SettingWindow::triggerFunctionEnable() const
{
    return _triggerFunctionEnable;
}

TriggerFunctions *SettingWindow::getTriggerFuntion()
{
    _triggerFunction = ui->widgetTriggerFunction->triggerFuntion();
    _triggerSetting = ui->widgetTriggerSetting->triggerSetting();

    //collapse value from trigger setting to trigger function
    this->_triggerFunction->setBtDI1Edge(_triggerSetting->btDI1Edge());
    this->_triggerFunction->setBtDI2Edge(_triggerSetting->btDI2Edge());
    this->_triggerFunction->setBtDI3Edge(_triggerSetting->btDI3Edge());
    this->_triggerFunction->setBtDI4Edge(_triggerSetting->btDI4Edge());
    this->_triggerFunction->setBtAI1Edge(_triggerSetting->btAI1Edge());
    this->_triggerFunction->setBtAI2Edge(_triggerSetting->btAI2Edge());

    this->_triggerFunction->setDoubleSpinBoxDI1(_triggerSetting->doubleSpinBoxDI1());
    this->_triggerFunction->setDoubleSpinBoxDI2(_triggerSetting->doubleSpinBoxDI2());
    this->_triggerFunction->setDoubleSpinBoxDI3(_triggerSetting->doubleSpinBoxDI3());
    this->_triggerFunction->setDoubleSpinBoxDI4(_triggerSetting->doubleSpinBoxDI4());
    this->_triggerFunction->setDoubleSpinBoxAI1(_triggerSetting->doubleSpinBoxAI1());
    this->_triggerFunction->setDoubleSpinBoxAI2(_triggerSetting->doubleSpinBoxAI2());

 //   qDebug() << objectName() << "AI2 : " << _triggerSetting->doubleSpinBoxAI2();
    return this->_triggerFunction;
}

void SettingWindow::checkIfAreSelectedTrace()
{
    ui->widgetChannelSelection->_checkIfAreSelectedTrace();
}

void SettingWindow::_received_AddTraceFromChannelSelection(quint8 traceNumber)
{    
    // add in trigger menu
    emit _addTraceInTriggerMenu(traceNumber);

    // add in display menu
    emit _addTraceInDisplayMenu(traceNumber);

    //check if trace selected
    _triggerFunctionEnable = ui->widgetTriggerFunction->areSomeTraceSelected();

    qDebug() << "_recievedAddTraceFromChannelSelection" << _triggerFunctionEnable;

}

void SettingWindow::_received_RemoveTraceFromChannelSelection(quint8 traceNumber)
{   
    //remove in trigger menu
    emit _removeTraceInTriggerMenu(traceNumber);

    //remove in display menu
    emit _removeTraceInDisplayMenu(traceNumber);

    qDebug() << "_recievedRemoveTraceFromChannelSelection" << _triggerFunctionEnable;
}

void SettingWindow::_received_errorNoSelectedTrace(quint8 errorNumber, bool active)
{
   emit _errorNoSelectedTrace(errorNumber, active);
}

void SettingWindow::_received_errorNoSectedTriggerTrace(quint8 errorNumber, bool active)
{
   emit _errorNoSelectedTriggerTrace(errorNumber, active);
}

void SettingWindow::_received_errorFrequencyToLow(quint8 errorNumber, bool active)
{
    emit _errorFrequencyToLow(errorNumber, active);
}

void SettingWindow::_received_errorWrongEquation(quint8 errorNumber, bool active)
{
    emit _errorWrongEquation(errorNumber, active);
}

void SettingWindow::_received_pushButtonRangeAI1Changed()
{
    emit _pushButtonRangeAI1WasChangedFromSettingMenu();
}

void SettingWindow::_received_pushButtonRangeAI2Changed()
{
    emit _pushButtonRangeAI2WasChangedFromSettingMenu();
}

void SettingWindow::_received_pushButtonEdgeDI1Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI1WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_pushButtonEdgeDI2Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI2WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_pushButtonEdgeDI3Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI3WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_pushButtonEdgeDI4Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI4WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_pushButtonEdgeAI1Changed(quint8 eEdge)
{
    emit _pushButtonEdgeAI1WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_pushButtonEdgeAI2Changed(quint8 eEdge)
{
    emit _pushButtonEdgeAI2WasChangedFromSettingMenu(eEdge);
}

void SettingWindow::_received_NbFrameSavedChanged(quint64 nbFrameChanged)
{
    emit _nbFrameSavedChange(nbFrameChanged);
}

void SettingWindow::_received_SizeFrameChange(int frameSize)
{
    emit _sizeFrameChange(frameSize);
}

void SettingWindow::_received_FTDIBaudrateChange(int FTDIBaudrate)
{
    emit _FTDIBaudrateChange(FTDIBaudrate);
}

//void SettingWindow::enableWindows(bool enableState)
//{
//    ui->widgetTriggerFunction->setEnabled(enableState);
//    ui->widgetTriggerSetting->setEnabled(enableState);
//}

void SettingWindow::pushButtonRangeAI1_changeRange()
{
    ui->widgetTriggerSetting->pushButtonRangeAI1_ChangeRange();
}

void SettingWindow::pushButtonRangeAI2_changeRange()
{
    ui->widgetTriggerSetting->pushButtonRangeAI2_ChangeRange();
}

void SettingWindow::pushButtonEdgeDI1_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI1_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI2_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI2_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI3_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI3_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeDI4_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeDI4_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeAI1_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSetting->pushButtonEdgeAI1_changeEdge(eEdge);
}

void SettingWindow::pushButtonEdgeAI2_changeEdge(quint8 eEdge)
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

void SettingWindow::_received_doubleSpinBoxDI1_valueChanged(double value)
{
    emit _doubleSpinBoxDI1_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_doubleSpinBoxDI2_valueChanged(double value)
{
    emit _doubleSpinBoxDI2_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_doubleSpinBoxDI3_valueChanged(double value)
{
    emit _doubleSpinBoxDI3_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_doubleSpinBoxDI4_valueChanged(double value)
{
    emit _doubleSpinBoxDI4_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_doubleSpinBoxAI1_valueChanged(double value)
{
    emit _doubleSpinBoxAI1_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_doubleSpinBoxAI2_valueChanged(double value)
{
    emit _doubleSpinBoxAI2_valueWasChangedFromSettingMenu(value);
}

void SettingWindow::_received_ComboBoxTopLeft_currentIndexChanged(quint8 index)
{
    //check if trace selected
    _triggerFunctionEnable = ui->widgetTriggerFunction->areSomeTraceSelected();

    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxTopRight_currentIndexChanged(quint8 index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxBottomLeft_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxBottomRight_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxTopMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void SettingWindow::_received_ComboBoxBottomMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

void SettingWindow::comboBoxTopLeft_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxTopLeft_changeCurrentIndex(index);
}

void SettingWindow::comboBoxTopRight_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxTopRight_changeCurrentIndex(index);
}

void SettingWindow::comboBoxBottomLeft_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxBottomLeft_changeCurrentIndex(index);
}

void SettingWindow::comboBoxBottomRight_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxBottomRight_changeCurrentIndex(index);
}

void SettingWindow::comboBoxTopMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxTopMiddle_changeCurrentIndex(index);
}

void SettingWindow::comboBoxMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxMiddle_changeCurrentIndex(index);
}

void SettingWindow::comboBoxBottomMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunction->comboBoxBottomMiddle_changeCurrentIndex(index);
}

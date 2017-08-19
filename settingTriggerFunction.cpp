#include "settingTriggerFunction.h"
#include "ui_settingTriggerFunction.h"

extern QString opNoneTxt;
extern QString opAndTxt;
extern QString opOrTxt;
extern QString opNoTAndTxt;
extern QString opNotOrTxt;

SettingTriggerFunction::SettingTriggerFunction(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTriggerFunction)
{
    ui->setupUi(this);

    //set value of the trigger funtion to 0
    _triggerFuntion = new TriggerFunctions();

    //initialise the Key - Value for combobx
    _triggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    // setup the style
    this->_setupStyle();

    // add all logical operator in all comboboxes
    this->_setupLogicalCombobox(ui->comboBoxTopMiddle);
    this->_setupLogicalCombobox(ui->comboBoxMiddle);
    this->_setupLogicalCombobox(ui->comboBoxBottomMiddle);

    // add "none" of all trace comboboxes
    this->_setupTraceCombobox();

    //set no trace selected
    this->_areSomeTraceSelected = false;

    //desable the Combobox excepte the top left
    ui->comboBoxTopLeft->setEnabled(true);
    ui->comboBoxTopRight->setEnabled(false);
    ui->comboBoxBottomLeft->setEnabled(false);
    ui->comboBoxBottomRight->setEnabled(false);
    ui->comboBoxTopMiddle->setEnabled(false);
    ui->comboBoxMiddle->setEnabled(false);
    ui->comboBoxBottomMiddle->setEnabled(false);

    //error management
    QObject::connect(this->_triggerFuntion, SIGNAL(_errorWrongEquation(quint8,bool)),
                     this, SLOT(_received_errorWrongEquation(quint8,bool)));
}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
}

bool SettingTriggerFunction::areSomeTraceSelected() const
{
    return _areSomeTraceSelected;
}

TriggerFunctions *SettingTriggerFunction::triggerFuntion() const
{
    return _triggerFuntion;
}

void SettingTriggerFunction::comboboxRevmoveItem(quint8 buttonNumber)
{
    _triggerTraceSelected.remove(buttonNumber);
    this->_updateCombobox();
}

void SettingTriggerFunction::comboBoxTopLeft_changeCurrentIndex(quint8 index)
{
    ui->comboBoxTopLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxTopRight_changeCurrentIndex(quint8 index)
{
    ui->comboBoxTopRight->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxBottomLeft_changeCurrentIndex(quint8 index)
{
    ui->comboBoxBottomLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxBottomRight_changeCurrentIndex(quint8 index)
{
    ui->comboBoxBottomRight->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxTopMiddle_changeCurrentIndex(quint8 index)
{
    ui->comboBoxTopMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxMiddle_changeCurrentIndex(quint8 index)
{
    ui->comboBoxMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::comboBoxBottomMiddle_changeCurrentIndex(quint8 index)
{
    ui->comboBoxBottomMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::_setupStyle()
{
    ui->labelTitleTriggerFunction->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                 "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

void SettingTriggerFunction::_setupTraceCombobox()
{
    ui->comboBoxTopLeft->addItem(_triggerTracePossible[0]);
    ui->comboBoxTopRight->addItem(_triggerTracePossible[0]);
    ui->comboBoxBottomLeft->addItem(_triggerTracePossible[0]);
    ui->comboBoxBottomRight->addItem(_triggerTracePossible[0]);
}

void SettingTriggerFunction::_setupLogicalCombobox(QComboBox *combobox)
{
    combobox->addItem(opNoneTxt);
    combobox->addItem(opAndTxt);
    combobox->addItem(opOrTxt);
    combobox->addItem(opNoTAndTxt);
    combobox->addItem(opNotOrTxt);
}

void SettingTriggerFunction::_updateCombobox()
{
    int nbItem = 0;
    //empty the combobox
    ui->comboBoxTopLeft->clear();
    ui->comboBoxTopRight->clear();
    ui->comboBoxBottomLeft->clear();
    ui->comboBoxBottomRight->clear();

    //add "none"
    this->_setupTraceCombobox();

    //update all traces
    for(QMap<int, QString>::iterator it = _triggerTraceSelected.begin(); it != _triggerTraceSelected.end(); it++)
    {
        ui->comboBoxTopLeft->addItem(*it);
        ui->comboBoxTopRight->addItem(*it);
        ui->comboBoxBottomLeft->addItem(*it);
        ui->comboBoxBottomRight->addItem(*it);
        nbItem++;
    }
}

void SettingTriggerFunction::comboboxAddItem(quint8 buttonNumber)
{
    //if its DI1 -> DI4, AI1 and AI2
    if(     buttonNumber < GlobalEnumatedAndExtern::btDI5 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI2)
    {
        _triggerTraceSelected[buttonNumber] = _triggerTracePossible[buttonNumber];
        this->_updateCombobox();
    }

}

void SettingTriggerFunction::on_comboBoxTopLeft_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    quint8 selectedTrace = _triggerTracePossible.key(ui->comboBoxTopLeft->currentText());
    GlobalEnumatedAndExtern::eTracePossible trace = (GlobalEnumatedAndExtern::eTracePossible)selectedTrace;
    this->_triggerFuntion->setTraceA(trace);

    if(ui->comboBoxTopLeft->currentIndex()>0)
    {
        ui->comboBoxTopMiddle->setEnabled(true);
        //set if are some selected trace
        _areSomeTraceSelected = true;
        on_comboBoxTopMiddle_currentIndexChanged(ui->comboBoxTopMiddle->currentIndex());
    }
    else
    {
        _areSomeTraceSelected = false;
        ui->comboBoxTopMiddle->setEnabled(false);
        ui->comboBoxTopRight->setEnabled(false);
        ui->comboBoxMiddle->setEnabled(false);
        ui->comboBoxBottomLeft->setEnabled(false);
        ui->comboBoxBottomRight->setEnabled(false);
        ui->comboBoxBottomMiddle->setEnabled(false);
    }
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxTopRight_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    quint8 selectedTrace = _triggerTracePossible.key(ui->comboBoxTopRight->currentText());
    GlobalEnumatedAndExtern::eTracePossible trace = (GlobalEnumatedAndExtern::eTracePossible)selectedTrace;
    if(ui->comboBoxTopRight->isEnabled())
    {
        this->_triggerFuntion->setTraceB(trace);
    }
    else
    {
        this->_triggerFuntion->setTraceB(GlobalEnumatedAndExtern::btNone);
    }

    if(ui->comboBoxTopRight->currentIndex()>0)
    {
        ui->comboBoxMiddle->setEnabled(true);
        on_comboBoxMiddle_currentIndexChanged(ui->comboBoxMiddle->currentIndex());
    }
    else
    {
        ui->comboBoxMiddle->setEnabled(false);
        ui->comboBoxBottomLeft->setEnabled(false);
        ui->comboBoxBottomRight->setEnabled(false);
        ui->comboBoxBottomMiddle->setEnabled(false);
    }

    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomLeft_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    quint8 selectedTrace = _triggerTracePossible.key(ui->comboBoxBottomLeft->currentText());
    GlobalEnumatedAndExtern::eTracePossible trace = (GlobalEnumatedAndExtern::eTracePossible)selectedTrace;
    this->_triggerFuntion->setTraceC(trace);


    if(ui->comboBoxBottomLeft->currentIndex()>0)
    {
        ui->comboBoxBottomMiddle->setEnabled(true);
        on_comboBoxBottomMiddle_currentIndexChanged(ui->comboBoxBottomMiddle->currentIndex());
    }
    else
    {
        ui->comboBoxBottomRight->setEnabled(false);
        ui->comboBoxBottomMiddle->setEnabled(false);
    }

    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomRight_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    quint8 selectedTrace = _triggerTracePossible.key(ui->comboBoxBottomRight->currentText());
    GlobalEnumatedAndExtern::eTracePossible trace = (GlobalEnumatedAndExtern::eTracePossible)selectedTrace;
    this->_triggerFuntion->setTraceD(trace);

    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxTopMiddle_currentIndexChanged(int index)
{
    GlobalEnumatedAndExtern::eLogicOperator selectedOperator = (GlobalEnumatedAndExtern::eLogicOperator)index;
    this->_triggerFuntion->setLogicalOperator_Top(selectedOperator);

    if(ui->comboBoxTopMiddle->currentIndex()>0)
    {
        ui->comboBoxTopRight->setEnabled(true);
        on_comboBoxTopRight_currentIndexChanged(ui->comboBoxTopRight->currentIndex());
    }
    else
    {
        ui->comboBoxTopRight->setEnabled(false);
        ui->comboBoxMiddle->setEnabled(false);
        ui->comboBoxBottomLeft->setEnabled(false);
        ui->comboBoxBottomRight->setEnabled(false);
        ui->comboBoxBottomMiddle->setEnabled(false);
        this->_triggerFuntion->setTraceB(GlobalEnumatedAndExtern::btNone);
        this->_triggerFuntion->setTraceC(GlobalEnumatedAndExtern::btNone);
        this->_triggerFuntion->setTraceD(GlobalEnumatedAndExtern::btNone);
        this->_triggerFuntion->setLogicalOperator_Middle(GlobalEnumatedAndExtern::opNone);
        this->_triggerFuntion->setLogicalOperator_Bottom(GlobalEnumatedAndExtern::opNone);
    }

    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxMiddle_currentIndexChanged(int index)
{
    GlobalEnumatedAndExtern::eLogicOperator selectedOperator = (GlobalEnumatedAndExtern::eLogicOperator)index;
    this->_triggerFuntion->setLogicalOperator_Middle(selectedOperator);

    if(ui->comboBoxMiddle->currentIndex()>0)
    {
        ui->comboBoxBottomLeft->setEnabled(true);
        on_comboBoxBottomLeft_currentIndexChanged(ui->comboBoxBottomLeft->currentIndex());
    }
    else
    {
        ui->comboBoxBottomLeft->setEnabled(false);
        ui->comboBoxBottomRight->setEnabled(false);
        ui->comboBoxBottomMiddle->setEnabled(false);
        this->_triggerFuntion->setTraceC(GlobalEnumatedAndExtern::btNone);
        this->_triggerFuntion->setTraceD(GlobalEnumatedAndExtern::btNone);
        this->_triggerFuntion->setLogicalOperator_Bottom(GlobalEnumatedAndExtern::opNone);
    }

    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomMiddle_currentIndexChanged(int index)
{
    GlobalEnumatedAndExtern::eLogicOperator selectedOperator = (GlobalEnumatedAndExtern::eLogicOperator)index;
    this->_triggerFuntion->setLogicalOperator_Bottom(selectedOperator);

    if(ui->comboBoxBottomMiddle->currentIndex()>0)
    {
        ui->comboBoxBottomRight->setEnabled(true);
        on_comboBoxBottomRight_currentIndexChanged(ui->comboBoxBottomRight->currentIndex());
    }
    else
    {
        ui->comboBoxBottomRight->setEnabled(false);
        this->_triggerFuntion->setTraceD(GlobalEnumatedAndExtern::btNone);
    }

    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

void SettingTriggerFunction::_received_errorWrongEquation(quint8 errorNumber, bool active)
{
    emit _errorWrongEquation(errorNumber,active);
}

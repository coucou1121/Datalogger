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
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    // setup the style
    this->setupStyle();

    // add all logical operator in all comboboxes
    this->setupLogicalCombobox(ui->comboBoxTopMiddle);
    this->setupLogicalCombobox(ui->comboBoxMiddle);
    this->setupLogicalCombobox(ui->comboBoxBottomMiddle);

    // add "none" of all trace comboboxes
    this->setupTraceCombobox();

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
}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
}

bool SettingTriggerFunction::areSomeTraceSelected() const
{
    return _areSomeTraceSelected;
}

void SettingTriggerFunction::setupStyle()
{
    ui->labelTitleTriggerFunction->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                 "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

void SettingTriggerFunction::setupTraceCombobox()
{
    ui->comboBoxTopLeft->addItem(TriggerTracePossible[0]);
    ui->comboBoxTopRight->addItem(TriggerTracePossible[0]);
    ui->comboBoxBottomLeft->addItem(TriggerTracePossible[0]);
    ui->comboBoxBottomRight->addItem(TriggerTracePossible[0]);
}

void SettingTriggerFunction::setupLogicalCombobox(QComboBox *combobox)
{
    combobox->addItem(opNoneTxt);
    combobox->addItem(opAndTxt);
    combobox->addItem(opOrTxt);
    combobox->addItem(opNoTAndTxt);
    combobox->addItem(opNotOrTxt);
}

void SettingTriggerFunction::updateCombobox()
{
    int nbItem = 0;
    //empty the combobox
    ui->comboBoxTopLeft->clear();
    ui->comboBoxTopRight->clear();
    ui->comboBoxBottomLeft->clear();
    ui->comboBoxBottomRight->clear();

    //add "none"
    this->setupTraceCombobox();

    //update all traces
    for(QMap<int, QString>::iterator it = TriggerTraceSelected.begin(); it != TriggerTraceSelected.end(); it++)
    {
        ui->comboBoxTopLeft->addItem(*it);
        ui->comboBoxTopRight->addItem(*it);
        ui->comboBoxBottomLeft->addItem(*it);
        ui->comboBoxBottomRight->addItem(*it);
        nbItem++;
    }
}

void SettingTriggerFunction::_comboboxAddItem(int buttonNumber)
{
    //if its DI1 -> DI4, AI1 and AI2
    if(     buttonNumber < GlobalEnumatedAndExtern::btDI5 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI2)
    {
        TriggerTraceSelected[buttonNumber] = TriggerTracePossible[buttonNumber];
        this->updateCombobox();
    }

}

void SettingTriggerFunction::_comboboxRevmoveItem(int buttonNumber)
{
    TriggerTraceSelected.remove(buttonNumber);
    this->updateCombobox();
}

void SettingTriggerFunction::_comboBoxTopLeft_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopLeft received index changed : " << index;
    ui->comboBoxTopLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxTopRight_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopRight received index changed : " << index;
    ui->comboBoxTopRight->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomLeft_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomLeft received index changed : " << index;
    ui->comboBoxBottomLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomRight_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomRight received index changed : " << index;
    ui->comboBoxBottomRight->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxTopMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopMiddle received index changed : " << index;
    ui->comboBoxTopMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxMiddle received index changed : " << index;
    ui->comboBoxMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomMiddle received index changed : " << index;
    ui->comboBoxBottomMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::on_comboBoxTopLeft_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    int selectedTrace = TriggerTracePossible.key(ui->comboBoxTopLeft->currentText());
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
    int selectedTrace = TriggerTracePossible.key(ui->comboBoxTopRight->currentText());
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

    this->_triggerFuntion->displayValue();

    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomLeft_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    int selectedTrace = TriggerTracePossible.key(ui->comboBoxBottomLeft->currentText());
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

    this->_triggerFuntion->displayValue();

    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomRight_currentIndexChanged(int index)
{
    //set the selected signal in trigger function
    int selectedTrace = TriggerTracePossible.key(ui->comboBoxBottomRight->currentText());
    GlobalEnumatedAndExtern::eTracePossible trace = (GlobalEnumatedAndExtern::eTracePossible)selectedTrace;
    this->_triggerFuntion->setTraceD(trace);

    this->_triggerFuntion->displayValue();

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

    this->_triggerFuntion->displayValue();

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

    this->_triggerFuntion->displayValue();

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

    this->_triggerFuntion->displayValue();

    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

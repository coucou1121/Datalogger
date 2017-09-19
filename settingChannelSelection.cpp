#include "settingChannelSelection.h"
#include "ui_settingChannelSelection.h"

SettingChannelSelection::SettingChannelSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingChannelSelection),
    _sumOfSelectedTrace(0),
    _sumOfTriggerSelectedTrace(0)
{
    //initialise the Key - Value for combobx
    _triggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    ui->setupUi(this);
    this->_setupStyle();
    this->_setupUILayout();
    this->_setupLabel();
}

SettingChannelSelection::~SettingChannelSelection()
{
    delete ui;
}

void SettingChannelSelection::_setupStyle()
{
    CommonStyle::setbackGroundColorLabel(ui->labelTitleChanelSelection);
}

void SettingChannelSelection::_setupUILayout()
{
    //button setup
    _setupButtonBackGround(ui->btDI1, GlobalEnumatedAndExtern::btDI1, false);
    _setupButtonBackGround(ui->btDI2, GlobalEnumatedAndExtern::btDI2, false);
    _setupButtonBackGround(ui->btDI3, GlobalEnumatedAndExtern::btDI3, false);
    _setupButtonBackGround(ui->btDI4, GlobalEnumatedAndExtern::btDI4, false);
    _setupButtonBackGround(ui->btDI5, GlobalEnumatedAndExtern::btDI5, false);
    _setupButtonBackGround(ui->btDI6, GlobalEnumatedAndExtern::btDI6, false);
    _setupButtonBackGround(ui->btDI7, GlobalEnumatedAndExtern::btDI7, false);
    _setupButtonBackGround(ui->btDI8, GlobalEnumatedAndExtern::btDI8, false);
    _setupButtonBackGround(ui->btDI9, GlobalEnumatedAndExtern::btDI9, false);
    _setupButtonBackGround(ui->btDI10, GlobalEnumatedAndExtern::btDI10, false);
    _setupButtonBackGround(ui->btDI11, GlobalEnumatedAndExtern::btDI11, false);
    _setupButtonBackGround(ui->btDI12, GlobalEnumatedAndExtern::btDI12, false);
    _setupButtonBackGround(ui->btDI13, GlobalEnumatedAndExtern::btDI13, false);
    _setupButtonBackGround(ui->btDI14, GlobalEnumatedAndExtern::btDI14, false);
    _setupButtonBackGround(ui->btDI15, GlobalEnumatedAndExtern::btDI15, false);
    _setupButtonBackGround(ui->btDI16, GlobalEnumatedAndExtern::btDI16, false);

    _setupButtonBackGround(ui->btAI1, GlobalEnumatedAndExtern::btAI1, false);
    _setupButtonBackGround(ui->btAI2, GlobalEnumatedAndExtern::btAI2, false);
    _setupButtonBackGround(ui->btAI3, GlobalEnumatedAndExtern::btAI3, false);
    _setupButtonBackGround(ui->btAI4, GlobalEnumatedAndExtern::btAI4, false);
}

void SettingChannelSelection::_setupLabel()
{
    ui->btDI1->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI1]);
    ui->btDI2->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI2]);
    ui->btDI3->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI3]);
    ui->btDI4->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI4]);
    ui->btDI5->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI5]);
    ui->btDI6->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI6]);
    ui->btDI7->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI7]);
    ui->btDI8->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI8]);
    ui->btDI9->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI9]);
    ui->btDI10->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI10]);
    ui->btDI11->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI11]);
    ui->btDI12->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI12]);
    ui->btDI13->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI13]);
    ui->btDI14->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI14]);
    ui->btDI15->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI15]);
    ui->btDI16->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI16]);

    ui->btAI1->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI1]);
    ui->btAI2->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI2]);
    ui->btAI3->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI3]);
    ui->btAI4->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI4]);

}

void SettingChannelSelection::_setupButtonBackGround(QPushButton *pushbutton, GlobalEnumatedAndExtern::eTracePossible trace , bool btSelected)
{
    if(btSelected)
    {
        switch (trace)
        {
        case GlobalEnumatedAndExtern::btAI1:
        case GlobalEnumatedAndExtern::btAI2:
        case GlobalEnumatedAndExtern::btAI3:
        case GlobalEnumatedAndExtern::btAI4:
            CommonStyle::setBackGroundColorAISelected(pushbutton);
            break;
        default:
            CommonStyle::setBackGroundColorDISelected(pushbutton);
            break;
        }
    }
    else
    {
        CommonStyle::setBackGroundColor(pushbutton);
    }
}

void SettingChannelSelection::emitBtSignal(int buttonNumber, bool btSelected)
{

    if(btSelected)
    {
        //increase number of selected trace
        this->_sumOfSelectedTrace++;

        //increase number of trigger selected trace
        if(buttonNumber == GlobalEnumatedAndExtern::btDI1 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI2 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI3 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI4 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI2)
        {
            this->_sumOfTriggerSelectedTrace++;
        }

        //unlock trigger setting in trigger setting menu
        emit _btSeleccted(buttonNumber, btSelected);


        //add selection in trigger function combobox
        emit _btAddList(buttonNumber);

        //show trace in trigger menu
        emit _addTrace(buttonNumber);

    }
    else
    {
        //decrease number of selected trace
        this->_sumOfSelectedTrace--;

        //decrease number of trigger selected trace
        if(buttonNumber == GlobalEnumatedAndExtern::btDI1 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI2 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI3 ||
                buttonNumber == GlobalEnumatedAndExtern::btDI4 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI2)
        {
            this->_sumOfTriggerSelectedTrace--;
        }

        //remove selection in trigger function combobox
        emit _btRemoveList(buttonNumber);

        //hide trace in trigger menu
        emit _removeTrace(buttonNumber);
    }

    emit _btSeleccted(buttonNumber, btSelected);

    this->_checkIfAreSelectedTrace();
}

void SettingChannelSelection::_checkIfAreSelectedTrace()
{
    //check if aren't selected trace
    if(this->_sumOfSelectedTrace <= 0)
    {
        emit _errorNoSelectedTrace(GlobalEnumatedAndExtern::errorNoSelectedTrace, true);
    }
    else
    {
        emit _errorNoSelectedTrace(GlobalEnumatedAndExtern::errorNoSelectedTrace, false);
    }

    //check if aren't trigger selected trace
    if(this->_sumOfTriggerSelectedTrace <= 0)
    {
        emit _errorNoSelectedTriggerTrace(GlobalEnumatedAndExtern::errorNoSelectedTriggerTrace, true);
    }
    else
    {
        emit _errorNoSelectedTriggerTrace(GlobalEnumatedAndExtern::errorNoSelectedTriggerTrace, false);
    }
}

void SettingChannelSelection::on_btDI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI1, GlobalEnumatedAndExtern::btDI1, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI1, btSelected);
}

void SettingChannelSelection::on_btDI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI2, GlobalEnumatedAndExtern::btDI2, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI2, btSelected);
}

void SettingChannelSelection::on_btDI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI3, GlobalEnumatedAndExtern::btDI3, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI3, btSelected);
}

void SettingChannelSelection::on_btDI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI4, GlobalEnumatedAndExtern::btDI4, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI4, btSelected);
}

void SettingChannelSelection::on_btDI5_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI5, GlobalEnumatedAndExtern::btDI5, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI5, btSelected);
}

void SettingChannelSelection::on_btDI6_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI6, GlobalEnumatedAndExtern::btDI6, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI6, btSelected);
}

void SettingChannelSelection::on_btDI7_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI7, GlobalEnumatedAndExtern::btDI7, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI7, btSelected);
}

void SettingChannelSelection::on_btDI8_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI8, GlobalEnumatedAndExtern::btDI8, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI8, btSelected);
}

void SettingChannelSelection::on_btDI9_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI9, GlobalEnumatedAndExtern::btDI9, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI9, btSelected);
}

void SettingChannelSelection::on_btDI10_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI10, GlobalEnumatedAndExtern::btDI10, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI10, btSelected);
}

void SettingChannelSelection::on_btDI11_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI11, GlobalEnumatedAndExtern::btDI11, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI11, btSelected);
}

void SettingChannelSelection::on_btDI12_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI12, GlobalEnumatedAndExtern::btDI12, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI12, btSelected);
}

void SettingChannelSelection::on_btDI13_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI13, GlobalEnumatedAndExtern::btDI13, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI13, btSelected);
}

void SettingChannelSelection::on_btDI14_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI14, GlobalEnumatedAndExtern::btDI14, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI14, btSelected);
}

void SettingChannelSelection::on_btDI15_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI15, GlobalEnumatedAndExtern::btDI15, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI15, btSelected);
}

void SettingChannelSelection::on_btDI16_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI16, GlobalEnumatedAndExtern::btDI16, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI16, btSelected);
}

void SettingChannelSelection::on_btAI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI1, GlobalEnumatedAndExtern::btAI1, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI1, btSelected);
}

void SettingChannelSelection::on_btAI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI2, GlobalEnumatedAndExtern::btAI2, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI2, btSelected);
}

void SettingChannelSelection::on_btAI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI3, GlobalEnumatedAndExtern::btAI3, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI3, btSelected);
}

void SettingChannelSelection::on_btAI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI4, GlobalEnumatedAndExtern::btAI4, btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI4, btSelected);
}

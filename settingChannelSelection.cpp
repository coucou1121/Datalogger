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
    ui->labelTitleChanelSelection->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                 "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

void SettingChannelSelection::_setupUILayout()
{
    //button setup
    _setupButton(ui->btDI1, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI2, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI3, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI4, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI5, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI6, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI7, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI8, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI9, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI10, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI11, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI12, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI13, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI14, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI15, _myStyle.getBackGroundColor());
    _setupButton(ui->btDI16, _myStyle.getBackGroundColor());

    _setupButton(ui->btAI1, _myStyle.getBackGroundColor());
    _setupButton(ui->btAI2, _myStyle.getBackGroundColor());
    _setupButton(ui->btAI3, _myStyle.getBackGroundColor());
    _setupButton(ui->btAI4, _myStyle.getBackGroundColor());
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
    ui->btDI9->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI8]);
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

void SettingChannelSelection::_setupButton(QPushButton *pushbutton, QColor btColor)
{
    this->_setupButtonBackGround(pushbutton, btColor, false);
}

void SettingChannelSelection::_setupButtonBackGround(QPushButton *pushbutton, QColor btSelectedColor, bool btSelected)
{
    if(btSelected)
    {
        pushbutton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + btSelectedColor.name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
        pushbutton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getBackGroundColor().name() +
                                  ", stop: 0 #ffffff);");
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

        {
            //add selection in trigger function combobox
            emit _btAddList(buttonNumber);

            //show trace in trigger menu
            emit _addTrace(buttonNumber);
        }

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
    //check if aren't trigger selected trace
    else if(this->_sumOfTriggerSelectedTrace <= 0)
    {
        emit _errorNoSelectedTriggerTrace(GlobalEnumatedAndExtern::errorNoSelectedTriggerTrace, true);
    }
    else
    {
        emit _errorNoSelectedTrace(GlobalEnumatedAndExtern::errorNoSelectedTrace, false);

        //check if are trigger selected trace
        if(this->_sumOfTriggerSelectedTrace > 0)
        {
            emit _errorNoSelectedTriggerTrace(GlobalEnumatedAndExtern::errorNoSelectedTriggerTrace, false);
        }
    }
}

void SettingChannelSelection::on_btDI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI1, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI1, btSelected);
}

void SettingChannelSelection::on_btDI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI2, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI2, btSelected);
}

void SettingChannelSelection::on_btDI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI3, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI3, btSelected);
}

void SettingChannelSelection::on_btDI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI4, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI4, btSelected);
}

void SettingChannelSelection::on_btDI5_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI5, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI5, btSelected);
}

void SettingChannelSelection::on_btDI6_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI6, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI6, btSelected);
}

void SettingChannelSelection::on_btDI7_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI7, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI7, btSelected);
}

void SettingChannelSelection::on_btDI8_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI8, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI8, btSelected);
}

void SettingChannelSelection::on_btDI9_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI9, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI9, btSelected);
}

void SettingChannelSelection::on_btDI10_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI10, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI10, btSelected);
}

void SettingChannelSelection::on_btDI11_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI11, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI11, btSelected);
}

void SettingChannelSelection::on_btDI12_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI12, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI12, btSelected);
}

void SettingChannelSelection::on_btDI13_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI13, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI13, btSelected);
}

void SettingChannelSelection::on_btDI14_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI14, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI14, btSelected);
}

void SettingChannelSelection::on_btDI15_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI15, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI15, btSelected);
}

void SettingChannelSelection::on_btDI16_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btDI16, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI16, btSelected);
}

void SettingChannelSelection::on_btAI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI1, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI1, btSelected);
}

void SettingChannelSelection::on_btAI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI2, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI2, btSelected);
}

void SettingChannelSelection::on_btAI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI3, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI3, btSelected);
}

void SettingChannelSelection::on_btAI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->_setupButtonBackGround(ui->btAI4, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI4, btSelected);
}

#include "settingChannelSelection.h"
#include "ui_settingChannelSelection.h"

SettingChannelSelection::SettingChannelSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingChannelSelection)
{
    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    ui->setupUi(this);
    setupStyle();
    setupUILayout();
    setupLabel();
}

SettingChannelSelection::~SettingChannelSelection()
{
    delete ui;
}

void SettingChannelSelection::setupStyle()
{
    ui->labelTitleChanelSelection->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                 "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

void SettingChannelSelection::setupUILayout()
{
    //button setup
    setupButton(ui->btDI1, _myStyle.getBackGroundColor());
    setupButton(ui->btDI2, _myStyle.getBackGroundColor());
    setupButton(ui->btDI3, _myStyle.getBackGroundColor());
    setupButton(ui->btDI4, _myStyle.getBackGroundColor());
    setupButton(ui->btDI5, _myStyle.getBackGroundColor());
    setupButton(ui->btDI6, _myStyle.getBackGroundColor());
    setupButton(ui->btDI7, _myStyle.getBackGroundColor());
    setupButton(ui->btDI8, _myStyle.getBackGroundColor());
    setupButton(ui->btDI9, _myStyle.getBackGroundColor());
    setupButton(ui->btDI10, _myStyle.getBackGroundColor());
    setupButton(ui->btDI11, _myStyle.getBackGroundColor());
    setupButton(ui->btDI12, _myStyle.getBackGroundColor());
    setupButton(ui->btDI13, _myStyle.getBackGroundColor());
    setupButton(ui->btDI14, _myStyle.getBackGroundColor());
    setupButton(ui->btDI15, _myStyle.getBackGroundColor());
    setupButton(ui->btDI16, _myStyle.getBackGroundColor());

    setupButton(ui->btAI1, _myStyle.getBackGroundColor());
    setupButton(ui->btAI2, _myStyle.getBackGroundColor());
    setupButton(ui->btAI3, _myStyle.getBackGroundColor());
    setupButton(ui->btAI4, _myStyle.getBackGroundColor());
}

void SettingChannelSelection::setupLabel()
{
    ui->btDI1->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI1]);
    ui->btDI2->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI2]);
    ui->btDI3->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI3]);
    ui->btDI4->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI4]);
    ui->btDI5->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI5]);
    ui->btDI6->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI6]);
    ui->btDI7->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI7]);
    ui->btDI8->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI8]);
    ui->btDI9->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI8]);
    ui->btDI10->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI10]);
    ui->btDI11->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI11]);
    ui->btDI12->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI12]);
    ui->btDI13->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI13]);
    ui->btDI14->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI14]);
    ui->btDI15->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI15]);
    ui->btDI16->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btDI16]);

    ui->btAI1->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btAI1]);
    ui->btAI2->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btAI2]);
    ui->btAI3->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btAI3]);
    ui->btAI4->setText(TriggerTracePossible[GlobalEnumatedAndExtern::btAI4]);

}

void SettingChannelSelection::setupButton(QPushButton *pushbutton, QColor btColor)
{
    this->setupButtonBackGround(pushbutton, btColor, false);
}

void SettingChannelSelection::setupButtonBackGround(QPushButton *pushbutton, QColor btSelectedColor, bool btSelected)
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
        //unlock trigger setting in trigger setting menu
        emit _btSeleccted(buttonNumber, btSelected);


        //if its DI1 -> DI4, AI1 and AI2
        if(     buttonNumber < GlobalEnumatedAndExtern::btDI5 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
                buttonNumber == GlobalEnumatedAndExtern::btAI2)
        {
            //add selection in trigger function combobox
            emit _btAddList(buttonNumber);

            //show trace in trigger menu
            emit _addTrace(buttonNumber);
        }

    }
    else
    {
        //remove selection in trigger function combobox
        emit _btRemoveList(buttonNumber);

        //hide trace in trigger menu
        emit _removeTrace(buttonNumber);
    }

    emit _btSeleccted(buttonNumber, btSelected);
}

void SettingChannelSelection::on_btDI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI1, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI1, btSelected);
}

void SettingChannelSelection::on_btDI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI2, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI2, btSelected);
}

void SettingChannelSelection::on_btDI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI3, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI3, btSelected);
}

void SettingChannelSelection::on_btDI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI4, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI4, btSelected);
}

void SettingChannelSelection::on_btDI5_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI5, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI5, btSelected);
}

void SettingChannelSelection::on_btDI6_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI6, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI6, btSelected);
}

void SettingChannelSelection::on_btDI7_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI7, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI7, btSelected);
}

void SettingChannelSelection::on_btDI8_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI8, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI8, btSelected);
}

void SettingChannelSelection::on_btDI9_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI9, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI9, btSelected);
}

void SettingChannelSelection::on_btDI10_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI10, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI10, btSelected);
}

void SettingChannelSelection::on_btDI11_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI11, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI11, btSelected);
}

void SettingChannelSelection::on_btDI12_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI12, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI12, btSelected);
}

void SettingChannelSelection::on_btDI13_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI13, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI13, btSelected);
}

void SettingChannelSelection::on_btDI14_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI14, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI14, btSelected);
}

void SettingChannelSelection::on_btDI15_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI15, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI15, btSelected);
}

void SettingChannelSelection::on_btDI16_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btDI16, _myStyle.getTraceColorDigitalPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btDI16, btSelected);
}

void SettingChannelSelection::on_btAI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btAI1, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI1, btSelected);
}

void SettingChannelSelection::on_btAI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btAI2, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI2, btSelected);
}

void SettingChannelSelection::on_btAI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btAI3, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI3, btSelected);
}

void SettingChannelSelection::on_btAI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    this->setupButtonBackGround(ui->btAI4, _myStyle.getTraceColorAnalogPlot(), btSelected);
    this->emitBtSignal(GlobalEnumatedAndExtern::btAI4, btSelected);
}

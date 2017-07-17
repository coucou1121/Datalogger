#include "settingChannelSelection.h"
#include "ui_settingChannelSelection.h"

SettingChannelSelection::SettingChannelSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingChannelSelection)
{
    ui->setupUi(this);
    setupStyle();
    setupUILayout();
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

    //selecte button DI1 -> DI4 and AI1 -> AI4
    this->on_btDI1_released();
    this->on_btDI2_released();
    this->on_btDI3_released();
    this->on_btDI4_released();
    this->on_btAI1_released();
    this->on_btAI2_released();
    this->on_btAI3_released();
    this->on_btAI4_released();

}

void SettingChannelSelection::setupButton(QPushButton *pushbutton, QColor btColor)
{
    pushbutton->setMinimumSize(40,25);
    pushbutton->setMaximumSize(140,125);
    //pushbutton->setStyleSheet("background-color:" + btColor.name() + ";");
    pushbutton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                     "stop: 1" + btColor.name() +
                                     ", stop: 0 #ffffff);");
}

void SettingChannelSelection::on_btDI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
        emit _btAddList(GlobalEnumated::btDI1);
    }
    else
    {
       ui->btDI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
       emit _btRemoveList(GlobalEnumated::btDI1);
    }

    emit _btDI1Selected(btSelected);
}

void SettingChannelSelection::on_btDI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)
    {
        ui->btDI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
        emit _btAddList(GlobalEnumated::btDI2);
    }
    else
    {
       ui->btDI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
       emit _btRemoveList(GlobalEnumated::btDI2);
    }

    emit _btDI2Selected(btSelected);
}

void SettingChannelSelection::on_btDI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
        emit _btAddList(GlobalEnumated::btDI3);
    }
    else
    {
      ui->btDI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                               "stop: 1" + _myStyle.getBackGroundColor().name() +
                               ", stop: 0 #ffffff);");
      emit _btRemoveList(GlobalEnumated::btDI3);
    }

    emit _btDI3Selected(btSelected);
}

void SettingChannelSelection::on_btDI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI4Selected(btSelected);
}

void SettingChannelSelection::on_btDI5_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI5->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI5->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI5Selected(btSelected);
}

void SettingChannelSelection::on_btDI6_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI6->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI6->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI6Selected(btSelected);
}

void SettingChannelSelection::on_btDI7_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI7->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI7->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI7Selected(btSelected);
}

void SettingChannelSelection::on_btDI8_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI8->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI8->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI8Selected(btSelected);
}

void SettingChannelSelection::on_btDI9_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI9->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI9->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btDI9Selected(btSelected);
}

void SettingChannelSelection::on_btDI10_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)
    {
       ui->btDI10->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                 ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI10->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }
    emit _btDI10Selected(btSelected);

}

void SettingChannelSelection::on_btDI11_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI11->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI11->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI11Selected(btSelected);
}

void SettingChannelSelection::on_btDI12_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI12->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI12->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI2Selected(btSelected);
}

void SettingChannelSelection::on_btDI13_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI13->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI13->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI13Selected(btSelected);
}

void SettingChannelSelection::on_btDI14_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI14->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI14->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI14Selected(btSelected);
}

void SettingChannelSelection::on_btDI15_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI15->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI15->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI15Selected(btSelected);
}

void SettingChannelSelection::on_btDI16_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btDI16->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorDigitalPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btDI16->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                 "stop: 1" + _myStyle.getBackGroundColor().name() +
                                 ", stop: 0 #ffffff);");
    }

    emit _btDI16Selected(btSelected);
}

void SettingChannelSelection::on_btAI1_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btAI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorAnalogPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
      ui->btAI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                               "stop: 1" + _myStyle.getBackGroundColor().name() +
                               ", stop: 0 #ffffff);");
    }

    emit _btAI1Selected(btSelected);
}

void SettingChannelSelection::on_btAI2_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btAI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorAnalogPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btAI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btAI2Selected(btSelected);
}

void SettingChannelSelection::on_btAI3_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btAI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorAnalogPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btAI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btAI3Selected(btSelected);
}

void SettingChannelSelection::on_btAI4_released()
{
    static bool btSelected = false;
    btSelected = btSelected == true? false : true;

    if(btSelected)    {
        ui->btAI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 1" + _myStyle.getTraceColorAnalogPlot().name() +
                                  ", stop: 0 #ffffff);");
    }
    else
    {
       ui->btAI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 1" + _myStyle.getBackGroundColor().name() +
                                ", stop: 0 #ffffff);");
    }

    emit _btAI4Selected(btSelected);
}

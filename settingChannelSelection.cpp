#include "settingChannelSelection.h"
#include "ui_settingChannelSelection.h"

SettingChannelSelection::SettingChannelSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingChannelSelection)
{
    ui->setupUi(this);
    setupUILayout();
}

SettingChannelSelection::~SettingChannelSelection()
{
    delete ui;
}

void SettingChannelSelection::setupUILayout()
{
    //create all button
    _btDI1 = new QPushButton("DI1");
    _btDI2 = new QPushButton("DI2");
    _btDI3 = new QPushButton("DI3");
    _btDI4 = new QPushButton("DI4");
    _btDI5 = new QPushButton("DI5");
    _btDI6 = new QPushButton("DI6");
    _btDI7 = new QPushButton("DI7");
    _btDI8 = new QPushButton("DI8");
    _btDI9 = new QPushButton("DI9");
    _btDI10 = new QPushButton("DI10");
    _btDI11 = new QPushButton("DI11");
    _btDI12 = new QPushButton("DI12");
    _btDI13 = new QPushButton("DI13");
    _btDI14 = new QPushButton("DI14");
    _btDI15 = new QPushButton("DI15");
    _btDI16 = new QPushButton("DI16");

    _btAI1 = new QPushButton("AI1");
    _btAI2 = new QPushButton("AI2");
    _btAI3 = new QPushButton("AI3");
    _btAI4 = new QPushButton("AI4");

    //button setup
    setupButton(_btDI1, _myStyle.getTraceColorDigitalPlot());
    setupButton(_btDI2, _myStyle.getTraceColorDigitalPlot());
    setupButton(_btDI3, _myStyle.getTraceColorDigitalPlot());
    setupButton(_btDI4, _myStyle.getTraceColorDigitalPlot());
    setupButton(_btDI5, _myStyle.getBackGroundColor());
    setupButton(_btDI6, _myStyle.getBackGroundColor());
    setupButton(_btDI7, _myStyle.getBackGroundColor());
    setupButton(_btDI8, _myStyle.getBackGroundColor());
    setupButton(_btDI9, _myStyle.getBackGroundColor());
    setupButton(_btDI10, _myStyle.getBackGroundColor());
    setupButton(_btDI11, _myStyle.getBackGroundColor());
    setupButton(_btDI12, _myStyle.getBackGroundColor());
    setupButton(_btDI13, _myStyle.getBackGroundColor());
    setupButton(_btDI14, _myStyle.getBackGroundColor());
    setupButton(_btDI15, _myStyle.getBackGroundColor());
    setupButton(_btDI16, _myStyle.getBackGroundColor());

    setupButton(_btAI1, _myStyle.getTraceColorAnalogPlot());
    setupButton(_btAI2, _myStyle.getTraceColorAnalogPlot());
    setupButton(_btAI3, _myStyle.getTraceColorAnalogPlot());
    setupButton(_btAI4, _myStyle.getTraceColorAnalogPlot());

    //display on the grid
    ui->gridLayout->addWidget(_btDI1, 0, 0);
    ui->gridLayout->addWidget(_btDI2, 0, 1);
    ui->gridLayout->addWidget(_btDI3, 0, 2);
    ui->gridLayout->addWidget(_btDI4, 0, 3);
    ui->gridLayout->addWidget(_btDI5, 0, 4);
    ui->gridLayout->addWidget(_btDI6, 0, 5);
    ui->gridLayout->addWidget(_btDI7, 0, 6);
    ui->gridLayout->addWidget(_btDI8, 0, 7);

    ui->gridLayout->addWidget(_btDI9, 1, 0);
    ui->gridLayout->addWidget(_btDI10, 1, 1);
    ui->gridLayout->addWidget(_btDI11, 1, 2);
    ui->gridLayout->addWidget(_btDI12, 1, 3);
    ui->gridLayout->addWidget(_btDI13, 1, 4);
    ui->gridLayout->addWidget(_btDI14, 1, 5);
    ui->gridLayout->addWidget(_btDI15, 1, 6);
    ui->gridLayout->addWidget(_btDI16, 1, 7);

    ui->gridLayout->addWidget(_btAI1, 2, 0);
    ui->gridLayout->addWidget(_btAI2, 2, 1);
    ui->gridLayout->addWidget(_btAI3, 2, 2);
    ui->gridLayout->addWidget(_btAI4, 2, 3);

    //connect signal and slot
    connect(_btDI1, SIGNAL (released()),this, SLOT (_btDI1_released()));
    connect(_btDI2, SIGNAL (released()),this, SLOT (_btDI2_released()));
    connect(_btDI3, SIGNAL (released()),this, SLOT (_btDI3_released()));
    connect(_btDI4, SIGNAL (released()),this, SLOT (_btDI4_released()));
    connect(_btDI5, SIGNAL (released()),this, SLOT (_btDI5_released()));
    connect(_btDI6, SIGNAL (released()),this, SLOT (_btDI6_released()));
    connect(_btDI7, SIGNAL (released()),this, SLOT (_btDI7_released()));
    connect(_btDI8, SIGNAL (released()),this, SLOT (_btDI8_released()));
    connect(_btDI9, SIGNAL (released()),this, SLOT (_btDI9_released()));
    connect(_btDI10, SIGNAL (released()),this, SLOT (_btDI10_released()));
    connect(_btDI11, SIGNAL (released()),this, SLOT (_btDI11_released()));
    connect(_btDI12, SIGNAL (released()),this, SLOT (_btDI12_released()));
    connect(_btDI13, SIGNAL (released()),this, SLOT (_btDI13_released()));
    connect(_btDI14, SIGNAL (released()),this, SLOT (_btDI14_released()));
    connect(_btDI15, SIGNAL (released()),this, SLOT (_btDI15_released()));
    connect(_btDI16, SIGNAL (released()),this, SLOT (_btDI16_released()));

    connect(_btAI1, SIGNAL (released()),this, SLOT (_btAI1_released()));
    connect(_btAI2, SIGNAL (released()),this, SLOT (_btAI2_released()));
    connect(_btAI3, SIGNAL (released()),this, SLOT (_btAI3_released()));
    connect(_btAI4, SIGNAL (released()),this, SLOT (_btAI4_released()));

}

void SettingChannelSelection::setupButton(QPushButton *pushbutton, QColor btColor)
{
    pushbutton->setMinimumSize(40,25);
    pushbutton->setMaximumSize(140,125);
    pushbutton->setStyleSheet("background-color:" + btColor.name() + ";");
}

void SettingChannelSelection::_btDI1_released()
{

    if(_btDI1->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI1->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI1Selected(true);
    }
    else
    {
       _btDI1->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI1Selected(false);
    }
}

void SettingChannelSelection::_btDI2_released()
{
    if(_btDI2->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI2->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI2Selected(true);
    }
    else
    {
       _btDI2->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI2Selected(false);
    }
}

void SettingChannelSelection::_btDI3_released()
{
    if(_btDI3->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI3->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI3Selected(true);
    }
    else
    {
       _btDI3->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI3Selected(false);
    }
}

void SettingChannelSelection::_btDI4_released()
{
    if(_btDI4->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI4->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI4Selected(true);
    }
    else
    {
       _btDI4->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI4Selected(false);
    }
}

void SettingChannelSelection::_btDI5_released()
{
    if(_btDI5->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI5->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI5Selected(true);
    }
    else
    {
       _btDI5->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI5Selected(false);
    }
}

void SettingChannelSelection::_btDI6_released()
{
    if(_btDI6->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI6->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI6Selected(true);
    }
    else
    {
       _btDI6->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI6Selected(false);
    }
}

void SettingChannelSelection::_btDI7_released()
{
    if(_btDI7->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI7->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI7Selected(true);
    }
    else
    {
       _btDI7->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI7Selected(false);
    }
}

void SettingChannelSelection::_btDI8_released()
{
    if(_btDI8->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI8->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI8Selected(true);
    }
    else
    {
       _btDI8->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI8Selected(false);
    }
}

void SettingChannelSelection::_btDI9_released()
{
    if(_btDI9->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI9->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI9Selected(true);
    }
    else
    {
       _btDI9->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI9Selected(false);
    }
}

void SettingChannelSelection::_btDI10_released()
{
    if(_btDI10->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI10->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI10Selected(true);
    }
    else
    {
       _btDI10->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI10Selected(false);
    }
}

void SettingChannelSelection::_btDI11_released()
{
    if(_btDI11->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI11->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI11Selected(true);
    }
    else
    {
       _btDI11->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI11Selected(false);
    }
}

void SettingChannelSelection::_btDI12_released()
{
    if(_btDI12->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI12->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI12Selected(true);
    }
    else
    {
       _btDI12->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI12Selected(false);
    }
}

void SettingChannelSelection::_btDI13_released()
{
    if(_btDI13->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI13->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI13Selected(true);
    }
    else
    {
       _btDI13->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI13Selected(false);
    }
}

void SettingChannelSelection::_btDI14_released()
{
    if(_btDI14->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI14->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI14Selected(true);
    }
    else
    {
       _btDI14->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI14Selected(false);
    }
}

void SettingChannelSelection::_btDI15_released()
{
    if(_btDI15->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI15->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI15Selected(true);
    }
    else
    {
       _btDI15->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI15Selected(false);
    }
}

void SettingChannelSelection::_btDI16_released()
{
    if(_btDI16->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btDI16->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
       emit _btDI16Selected(true);
    }
    else
    {
       _btDI16->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btDI16Selected(false);
    }
}

void SettingChannelSelection::_btAI1_released()
{
    if(_btAI1->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btAI1->setStyleSheet("background-color:" + _myStyle.getTraceColorAnalogPlot().name() + ";");
       emit _btAI1Selected(true);
    }
    else
    {
       _btAI1->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btAI1Selected(false);
    }
}

void SettingChannelSelection::_btAI2_released()
{
    if(_btAI2->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btAI2->setStyleSheet("background-color:" + _myStyle.getTraceColorAnalogPlot().name() + ";");
       emit _btAI2Selected(true);
    }
    else
    {
       _btAI2->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btAI2Selected(false);
    }
}

void SettingChannelSelection::_btAI3_released()
{
    if(_btAI3->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btAI3->setStyleSheet("background-color:" + _myStyle.getTraceColorAnalogPlot().name() + ";");
       emit _btAI3Selected(true);
    }
    else
    {
       _btAI3->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btAI3Selected(false);
    }
}

void SettingChannelSelection::_btAI4_released()
{
    if(_btAI4->palette().background().color() == _myStyle.getBackGroundColor())
    {
       _btAI4->setStyleSheet("background-color:" + _myStyle.getTraceColorAnalogPlot().name() + ";");
       emit _btAI4Selected(true);
    }
    else
    {
       _btAI4->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name() + ";");
       emit _btAI4Selected(false);
    }
}

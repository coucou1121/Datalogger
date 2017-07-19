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
    //block or unblack the selection in trigger setting menu
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI1select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI2select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI3select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI4select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI1select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI2select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI3select(bool)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI4select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btSeleccted(int,bool)), ui->widgetTriggerSetting, SLOT(_btSelected(int,bool)));

     //add button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));

     //remove button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));

    //add Trace in trigger menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_addTrace(int)),this, SLOT(_recievedAddTraceFromChannelSelection(int)));

    //remove Trace in trigger menu
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_removeTrace(int)),this, SLOT(_recievedRemoveTraceFromChannelSelection(int)));
}

void SettingWindow::_recievedAddTraceFromChannelSelection(int traceNumber)
{
    emit _addTraceInTriggerMenu(traceNumber);
}

void SettingWindow::_recievedRemoveTraceFromChannelSelection(int traceNumber)
{
    emit _removeTraceInTriggerMenu(traceNumber);
}

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
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI1select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI2select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI3select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI4select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI1select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI2select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI3select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI4select(bool)));

     //add button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI2AddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI3AddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI4AddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI1AddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI2AddList(int)),ui->widgetTriggerFunction, SLOT(_comboboxAddItem(int)));

     //remove button in all trigger function combobox
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btRemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI2RemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI3RemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI4RemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI1RemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
//    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI2RemoveList(int)),ui->widgetTriggerFunction, SLOT(_comboboxRevmoveItem(int)));
}

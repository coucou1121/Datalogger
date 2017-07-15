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
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI1select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI2select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI3select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btDI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_DI4select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI1Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI1select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI2Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI2select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI3Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI3select(bool)));
    QObject::connect(ui->widgetChannelSelection, SIGNAL(_btAI4Selected(bool)), ui->widgetTriggerSetting, SLOT(_AI4select(bool)));
}

#include "settingTriggerSetting.h"
#include "ui_settingTriggerSetting.h"

SettingTriggerSetting::SettingTriggerSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingTriggerSetting)
{
    ui->setupUi(this);
}

SettingTriggerSetting::~SettingTriggerSetting()
{
    delete ui;
}

#include "settingPreTriggerPercentage.h"
#include "ui_settingPreTriggerPercentage.h"

SettingPreTriggerPercentage::SettingPreTriggerPercentage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPreTriggerPercentage)
{
    ui->setupUi(this);
}

SettingPreTriggerPercentage::~SettingPreTriggerPercentage()
{
    delete ui;
}

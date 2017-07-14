#include "settingTriggerFunction.h"
#include "ui_settingTriggerFunction.h"

SettingTriggerFunction::SettingTriggerFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingTriggerFunction)
{
    ui->setupUi(this);
}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
}

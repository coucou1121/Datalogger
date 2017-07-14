#include "settingTriggerFunction.h"
#include "ui_settingTriggerFunction.h"

SettingTriggerFunction::SettingTriggerFunction(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTriggerFunction)
{
    ui->setupUi(this);
    this->setupStyle();
}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
}

void SettingTriggerFunction::setupStyle()
{
    ui->labelTitleTriggerFunction->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                           "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

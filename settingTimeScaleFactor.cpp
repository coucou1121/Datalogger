#include "settingTimeScaleFactor.h"
#include "ui_settingTimeScaleFactor.h"

SettingTimeScaleFactor::SettingTimeScaleFactor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTimeScaleFactor)
{
    ui->setupUi(this);
}

SettingTimeScaleFactor::~SettingTimeScaleFactor()
{
    delete ui;
}

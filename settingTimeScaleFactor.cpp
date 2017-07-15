#include "settingTimeScaleFactor.h"
#include "ui_settingTimeScaleFactor.h"

SettingTimeScaleFactor::SettingTimeScaleFactor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTimeScaleFactor)
{
    ui->setupUi(this);
    this->setupStyle();
}

SettingTimeScaleFactor::~SettingTimeScaleFactor()
{
    delete ui;
}

void SettingTimeScaleFactor::setupStyle()
{
    //setup style main title
    ui->labelTitleTimeScallFactor->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                      "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

    //setup sample / second frame
    ui->widgetSampleSecond->setStyleSheet("background-color:" + _myStyle.getBackGroundColorFrame().name()+ ";");
    ui->labelFrequency->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");

     //setup Duration frame
    ui->widgetDuration->setStyleSheet("background-color:" + _myStyle.getBackGroundColorFrame().name()+ ";");
    ui->labelDay->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
    ui->labelHrs->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
    ui->labelMin->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
    ui->labelSec->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
}

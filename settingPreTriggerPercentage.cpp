#include "settingPreTriggerPercentage.h"
#include "ui_settingPreTriggerPercentage.h"

SettingPreTriggerPercentage::SettingPreTriggerPercentage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingPreTriggerPercentage)
{
    ui->setupUi(this);
    _maximumRange = 2000;
    _stepOnClick = 100;

    //set the minimum and maximum on the progress bar
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(100);

    //set the step value for one click on both time trig setting
    ui->spinBoxTimeBeforeTrig->setSingleStep(_stepOnClick);
    ui->spinBoxTimeAfterTrig->setSingleStep(_stepOnClick);

    //set the strat valus of both time trig setting
    ui->spinBoxTimeBeforeTrig->setValue(0);
    ui->spinBoxTimeAfterTrig->setValue(_maximumRange);

    //set the maximum reccord time in seconde
    ui->labelMaxTime->setText(QString::number(_maximumRange/1000));

    this->setupStyle();
}

SettingPreTriggerPercentage::~SettingPreTriggerPercentage()
{
    delete ui;
}

void SettingPreTriggerPercentage::setupStyle()
{
    //setup style main title
    ui->labelTitlePreTriggerPercentage->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                      "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");

    //setup style Time befor and after trig title
    ui->labelTimeBeforTrigTitle->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name()+ ";");
    ui->labelTimeAfterTrigTitle->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name()+ ";");

    //setup style all spinbox
    _myStyle.setSpinBoxShape(ui->spinBoxTimeBeforeTrig);
    _myStyle.setSpinBoxShape(ui->spinBoxTimeAfterTrig);
}

void SettingPreTriggerPercentage::setStepOnClick(int stepOnClick)
{
    _stepOnClick = stepOnClick;
}

void SettingPreTriggerPercentage::setMaximumRange(int maximumRange)
{
    _maximumRange = maximumRange;
}

void SettingPreTriggerPercentage::on_spinBoxTimeBeforeTrig_valueChanged(int arg1)
{
    int percentValue = (arg1 * ui->progressBar->maximum())/_maximumRange;

    //modify the vlue at the time after trig
    ui->spinBoxTimeAfterTrig->setValue(_maximumRange-arg1);

    //set the percent in progress bar
    ui->progressBar->setValue(percentValue);
}

void SettingPreTriggerPercentage::on_spinBoxTimeAfterTrig_valueChanged(int arg1)
{
    //modify the vlue at the time befor trig
    ui->spinBoxTimeBeforeTrig->setValue(_maximumRange-arg1);
}

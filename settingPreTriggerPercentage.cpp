#include "settingPreTriggerPercentage.h"
#include "ui_settingPreTriggerPercentage.h"

SettingPreTriggerPercentage::SettingPreTriggerPercentage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingPreTriggerPercentage)
{
    ui->setupUi(this);
    _maximumRange = 2000; //time in miliseconde
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
    CommonStyle::setbackGroundColorLabel(ui->labelTitlePreTriggerPercentage);

    //setup style Time befor and after trig title
    CommonStyle::setbackGroundColorLabelPlot(ui->labelTimeBeforTrigTitle);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelTimeAfterTrigTitle);

    //setup style all spinbox
    CommonStyle::setSpinBoxShape(ui->spinBoxTimeBeforeTrig);
    CommonStyle::setSpinBoxShape(ui->spinBoxTimeAfterTrig);
}

void SettingPreTriggerPercentage::setStepOnClick(const quint8 &stepOnClick)
{
    _stepOnClick = stepOnClick;
}

void SettingPreTriggerPercentage::setMaximumRange(const quint16 &maximumRange)
{
    _maximumRange = maximumRange;
}

void SettingPreTriggerPercentage::on_spinBoxTimeBeforeTrig_valueChanged(int arg1)
{
    quint8 percentValue = (arg1 * ui->progressBar->maximum())/_maximumRange;

    qDebug() << "befor trig percent value" << percentValue;

    //modify the value at the time after trig
    ui->spinBoxTimeAfterTrig->setValue(_maximumRange-arg1);

    //set the percent in progress bar
    ui->progressBar->setValue(percentValue);

    //send the new value to the mainwindows for set the valeu after triger
    emit _percentPreTriggerWasChanged(percentValue);
}

void SettingPreTriggerPercentage::on_spinBoxTimeAfterTrig_valueChanged(int arg1)
{
    //modify the vlue at the time befor trig
    ui->spinBoxTimeBeforeTrig->setValue(_maximumRange-arg1);
}

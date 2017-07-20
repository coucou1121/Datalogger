#include "settingTimeScaleFactor.h"
#include "ui_settingTimeScaleFactor.h"

SettingTimeScaleFactor::SettingTimeScaleFactor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTimeScaleFactor)
{
    ui->setupUi(this);

    //key value for peridoe possible value
    _peridePossible  = GlobalEnumatedAndExtern::initPeridePossible();;

    //key value for peridoe possible texte
    _peridePossibleTxt = GlobalEnumatedAndExtern::initPeridePossibleTxt();

    this->setupStyle();

   this->_initPeriode();
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

void SettingTimeScaleFactor::_initPeriode()
{
    //update all traces
    for(auto e : _peridePossibleTxt.keys())
    {
        ui->comboBoxPeriod->addItem(_peridePossibleTxt[e], e);
    }
}

void SettingTimeScaleFactor::_initDuration(int index)
{
    ui->labelFrequency->setText(QString::number(1/_peridePossible[index]*1000));
}

void SettingTimeScaleFactor::on_comboBoxPeriod_currentTextChanged(const QString &arg1)
{
    qDebug() << arg1;
}

void SettingTimeScaleFactor::on_comboBoxPeriod_currentIndexChanged(int index)
{
    qDebug() << index;
   _initDuration(index);
}

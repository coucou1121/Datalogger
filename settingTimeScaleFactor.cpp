#include "settingTimeScaleFactor.h"
#include "ui_settingTimeScaleFactor.h"

SettingTimeScaleFactor::SettingTimeScaleFactor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTimeScaleFactor)
{
    ui->setupUi(this);

    _frequency = 0;
    _FTDIbaudrate = 0;

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
    CommonStyle::setbackGroundColorLabel(ui->labelTitleTimeScallFactor);

    //setup sample / second frame
//    ui->widgetSampleSecond->setStyleSheet("background-color:" + _myStyle.getBackGroundColorFrame().name()+ ";");
    CommonStyle::setbackGroundColorFrame(ui->widgetSampleSecond);
//    ui->labelFrequency->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
    CommonStyle::setbackGroundColorLabelPlot(ui->labelFrequency);

    //setup Duration frame
    CommonStyle::setbackGroundColorFrame(ui->widgetDuration);
 //   ui->widgetDuration->setStyleSheet("background-color:" + _myStyle.getBackGroundColorFrame().name()+ ";");
    CommonStyle::setbackGroundColorLabelPlot(ui->labelYear);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelMonth);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelDay);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelHrs);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelMin);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelSec);
//    ui->labelYear->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
//    ui->labelMonth->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
//    ui->labelDay->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
//    ui->labelHrs->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
//    ui->labelMin->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
//    ui->labelSec->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
}

void SettingTimeScaleFactor::_initPeriode()
{
    foreach(int key, _peridePossibleTxt.keys() )
    {
        ui->comboBoxPeriod->addItem(_peridePossibleTxt[key], key);
    }
}

void SettingTimeScaleFactor::_initDuration()
{
    QDateTime dateToDay = QDateTime::currentDateTime();
    QDateTime deadTimeRecord;
 //   QDateTime delayBetweenToDayAndRecord;
    quint64 dateToDayInMiliSecond = dateToDay.toMSecsSinceEpoch();

 //   QTime recordTime;
 //   QDate recordDate;

    int recordYear = 0;
    int recordMonth = 0;
    int recordDay = 0;
    int recordHours = 0;
    int recordMinits = 0;
    float recordSeconds = 0;
    int recordMiliSeconde = 0;

    quint64 recordTimeInMiliSeconde = 0;
    //float timeSecondeComma = 0;

    //qDebug() << dateToDay;
    //time calculation


    //get time in seconde as a float if _frequency <= _FTDIbaudrate
    if(_frequency <= _FTDIbaudrate)
    {
        recordTimeInMiliSeconde = ((_nbFrameSaved*_frameSize*1000)/(float)_frequency);
        emit _errorFrequencyToLow(GlobalEnumatedAndExtern::errorSamplingFrequencyToHigh, false);
    }
    else
    {
        qDebug() << "_frequency" << _frequency << ", _FTDIbaudrate" << _FTDIbaudrate;
        recordTimeInMiliSeconde = 0;
        emit _errorFrequencyToLow(GlobalEnumatedAndExtern::errorSamplingFrequencyToHigh, true);
    }
    //keep the the rest after the comma
    //timeSecondeComma = recordTimeInSeconde - (quint64)recordTimeInSeconde;

    //tranforme float to date and time
    //recordTime = dateToDay.time().addMSecs(recordTimeInMiliSeconde);
    deadTimeRecord.setMSecsSinceEpoch(dateToDayInMiliSecond + recordTimeInMiliSeconde);

//    qDebug() << "record time in milisecond:" << recordTimeInMiliSeconde;
//    qDebug() << "start recording          :" << dateToDay.toString("dd MMMM yyyy hh:mm:ss.zzz");
//    qDebug() << "record time              :" << deadTimeRecord.toString("dd MMMM yyyy hh:mm:ss.zzz");

    recordYear = deadTimeRecord.date().year() - dateToDay.date().year();
    recordMonth = deadTimeRecord.date().month() - dateToDay.date().month();
    recordDay = deadTimeRecord.date().day() - dateToDay.date().day();
    recordHours = deadTimeRecord.time().hour() - dateToDay.time().hour();
    recordMinits = deadTimeRecord.time().minute() - dateToDay.time().minute();
    recordSeconds = deadTimeRecord.time().second() - dateToDay.time().second();
    recordMiliSeconde =deadTimeRecord.time().msec() - dateToDay.time().msec();

    if(recordMiliSeconde<0)
    {
        recordSeconds--;
        recordMiliSeconde += 1000;
    }

    if(recordSeconds<0)
    {
        recordMinits--;
        recordSeconds += 60;
    }

    if(recordMinits<0)
    {
        recordHours--;
        recordMinits += 60;
    }

    if(recordHours<0)
    {
        recordDay--;
        recordHours += 24;
    }

    if(recordDay<0)
    {
        recordMonth--;
        recordDay += deadTimeRecord.date().daysInMonth();
    }
    if(recordMonth<0)
    {
        recordYear--;
        recordMonth += 12;
    }

    ui->labelYear->setText(QString::number(recordYear));
    ui->labelMonth->setText(QString::number(recordMonth));
    ui->labelDay->setText(QString::number(recordDay));
    ui->labelHrs->setText(QString::number(recordHours));
    ui->labelMin->setText(QString::number(recordMinits));
    ui->labelSec->setText(QString::number(recordSeconds+(float)recordMiliSeconde/1000));

//    qDebug() << "record year" << recordYear;
//    qDebug() << "record month" << recordMonth;
//    qDebug() << "record day" << recordDay;
//    qDebug() << "record hour" << recordHours;
//    qDebug() << "record minits" << recordMinits;
//    qDebug() << "record seconde" << recordSeconds;
//    qDebug() << "record mili second" << recordMiliSeconde;

    recordSeconds = deadTimeRecord.secsTo(dateToDay);


//    qDebug() << "dead time" << deadTimeRecord.toString("dd MMMM yyyy : hh:mm:ss.zzz");

}

void SettingTimeScaleFactor::_initSampleRate(int index)
{
    _frequency = 1000/_peridePossible[index];//*1000;
    _FTDIbaudrate = _frequency;
    QString frequencyTxt = QString("%1").arg(_frequency, 0, 'g', 13);
    int w_size = frequencyTxt.size();

    qDebug() << "a: " << QString("%1").arg(_frequency, 0, 'g', 13) ;
    qDebug() << _frequency << " , " << frequencyTxt;
    if (w_size > 3) {
        frequencyTxt.insert(frequencyTxt.size() - 3, "'");
    }
    if (w_size > 6) {
        frequencyTxt.insert(frequencyTxt.size() - 7, "'");
    }
    ui->labelFrequency->setText(frequencyTxt);
    _initDuration();
}

void SettingTimeScaleFactor::_nbFrameSavedWasChanged(quint64 nbFrameChanged)
{
 //   qDebug() << objectName() << nbFrameChanged;
    _nbFrameSaved = nbFrameChanged;
    this->_initDuration();
}

void SettingTimeScaleFactor::_sizeFrameWasChanged(int frameSize)
{
//    qDebug() << objectName() << frameSize;
    _frameSize = frameSize;
    this->_initDuration();
}

void SettingTimeScaleFactor::_FTDIBaudrateWasChanged(int FTDIBaudrate)
{
//    qDebug() << objectName() << FTDIBaudrate;
    _FTDIbaudrate = FTDIBaudrate;
    this->_initDuration();
}

void SettingTimeScaleFactor::on_comboBoxPeriod_currentTextChanged(const QString &arg1)
{
    qDebug() << "on_comboBoxPeriod_currentTextChanged" << arg1;
}

void SettingTimeScaleFactor::on_comboBoxPeriod_currentIndexChanged(int index)
{
//    qDebug() << "on_comboBoxPeriod_currentIndexChanged" << index;
    _initSampleRate(index);
}

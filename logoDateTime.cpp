#include "logoDateTime.h"
#include "ui_logoDateTime.h"

LogoDateTime::LogoDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoDateTime)
{
    _timer = new QTimer(this);
    ui->setupUi(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(_showTime()));
    _timer->start(1000);
    _showTime();
}

LogoDateTime::~LogoDateTime()
{
    delete ui;
}

void LogoDateTime::_showTime()
{
    QLocale l(QLocale::English, QLocale::UnitedStates);
            QLocale::setDefault(l);
    _dateTimeToDay = QDateTime::currentDateTime();
    _timeToDay = _dateTimeToDay.time();
    QString timeStr = _timeToDay.toString("hh : mm : ss");
    ui->labelTime->setText(timeStr);

    _dateToDay = _dateTimeToDay.date();
    QString dateToDayStr = _dateToDay.toString("dd / MM / yyyy");
    ui->labelDate->setText(dateToDayStr);
}

#include "logoDateTime.h"
#include "ui_logoDateTime.h"

LogoDateTime::LogoDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoDateTime)
{
    timer = new QTimer(this);
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

LogoDateTime::~LogoDateTime()
{
    delete ui;
}

void LogoDateTime::showTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QTime time = dateTime.time();
    QString timeStr = time.toString("hh : mm : ss");
    ui->labelTime->setText(timeStr);

    QDate dateToDay = dateTime.date();
    QString dateToDayStr = dateToDay.toString("dd  MMMM  yyyy");
    ui->labelDate->setText(dateToDayStr);
}

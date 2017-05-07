#include "startstopemuldata.h"
#include "ui_startstopemuldata.h"

StartStopEmulData::StartStopEmulData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartStopEmulData),
    _timeInterval(TIMER)
{
    ui->setupUi(this);
    _start = false;
    _timer = new QTimer(this);
    _frameData = new FrameSimulator();
    _microTimer = new FrameThread();
   // _microTimer->start();
    //connect(this, SIGNAL(refreshPlot()), qApp, SLOT(updatePlot()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(emulData()));
}

StartStopEmulData::~StartStopEmulData()
{
    delete ui;
}

bool StartStopEmulData::start() const
{
    return _start;
}

void StartStopEmulData::setStart(bool start)
{
    _start = start;
}

void StartStopEmulData::startMicroTimer()
{
    _microTimer->start();
}

void StartStopEmulData::on_PB_start_clicked()
{
    _start = true;
    _timer->start(_timeInterval);
    emulData();
}

int StartStopEmulData::timeInterval() const
{
    return _timeInterval;
}

void StartStopEmulData::setTimeInterval(int timeInterval)
{
    _timeInterval = timeInterval;
}

FrameSimulator *StartStopEmulData::frameData() const
{
    return _frameData;
}

void StartStopEmulData::on_PB_stop_clicked()
{
    _start = false;
}

void StartStopEmulData::on_PB_reset_clicked()
{
    _frameData->resetCPT();
}

void StartStopEmulData::emulData()
{
    if(_start)
    {
        _frameData->incValue();
        _frameData->displayValue();
        emit refreshPlot();
    }
}

#include "refreshTimer.h"

refreshTimer::refreshTimer(bool isCounting, QString name, int timeInterval, QObject *parent) :
    QObject(parent)
{
    this->setObjectName(name);
    _isCounting = isCounting;
    _timeInterval = timeInterval;
    count = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCount()));
    timer->start(_timeInterval);
}

void refreshTimer::startTimer()
{
    _isCounting = true;
}

void refreshTimer::stopTimer()
{
    _isCounting = false;
}

void refreshTimer::updateCount()
{
 //   count++;
    // qDebug() << objectName() << " count: " << count;

    //if(count%1000==0)
    // {
    // }
    if(_isCounting)
    {
 //       qDebug() << objectName() <<  "took" << timerElapse.elapsed() << "millisecondes";
        timerElapse.restart();
        emit tickFinished();
    }
}


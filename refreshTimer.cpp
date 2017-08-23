#include "refreshTimer.h"

RefreshTimer::RefreshTimer(bool isCounting, QString name, int timeInterval, QObject *parent) :
    QObject(parent)
{
    this->setObjectName(name);
    _isCounting = isCounting;
    _timeInterval = timeInterval;
    _count = 0;
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(_updateCount()));
    _timer->start(_timeInterval);
}

void RefreshTimer::startTimer()
{
    _isCounting = true;
}

void RefreshTimer::stopTimer()
{
    _isCounting = false;
}

void RefreshTimer::_updateCount()
{
//    _count++;
 //    qDebug() << objectName() << " count: " << _count;

    //if(count%1000==0)
    // {
    // }
    if(_isCounting)
    {
//        qDebug() << objectName() <<  "took" << _timerElapse.elapsed() << "millisecondes";
        _timerElapse.restart();
        emit _tickFinished();
    }
}


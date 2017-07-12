#include "refreshTimer.h"

refreshTimer::refreshTimer(bool wantToSleep, QString name, int timeInterval, QObject *parent) :
    QObject(parent)
{
    this->setObjectName(name);
    m_wantToSleep = wantToSleep;
    count = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCount()));
    timer->start(timeInterval);
}

void refreshTimer::updateCount()
{
    count++;
   // qDebug() << objectName() << " count: " << count;

    //if(count%1000==0)
   // {
       qDebug() << objectName() <<  "took" << timerElapse.elapsed() << "millisecondes";
       timerElapse.restart();
   // }
    emit tickFinished();
}


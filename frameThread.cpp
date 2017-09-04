#include "frameThread.h"

FrameThread::FrameThread(bool isWorking, QString name, quint16 delay) :
    _isWorking(isWorking),
    _delay(delay)
{
    this->setObjectName(name);
    moveToThread(this);
}

void FrameThread::usleep(unsigned long usecs)
{
    //   qDebug() << "coucou";
    QThread::usleep(usecs);
}

void FrameThread::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}

void FrameThread::sleep(unsigned long secs)
{
    QThread::sleep(secs);
}

void FrameThread::startWorking()
{
    qDebug() << objectName() << "received start Working";
    this->_isWorking = true;
}

void FrameThread::stopWorking()
{
    qDebug() << objectName() << "received stop Working";
    this->_isWorking = false;
}

// run() will be called when a thread starts
void FrameThread::run()
{
    unsigned long int cpt=0;

    while(true)
    {

 //       qDebug() << objectName() << thread()->currentThreadId() << cpt << "is working : " << this->_isWorking;
        if(_isWorking)
        {
            cpt++;
            //    _frame.displayValue();
            emit delayFinished();
        }
        else
        {

        }
        this->msleep(_delay);
    }

}




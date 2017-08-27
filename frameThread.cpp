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
    this->_isWorking = true;
}

void FrameThread::stopWorking()
{
    this->_isWorking = false;
}

// run() will be called when a thread starts
void FrameThread::run()
{
    unsigned long int cpt=0;

    while(true)
    {
        if(_isWorking)
        {
            cpt++;
//            qDebug() << objectName() << thread()->currentThreadId() << cpt;
            //    _frame.displayValue();
            emit delayFinished();
            this->msleep(_delay);
        }
    }

}




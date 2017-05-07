#ifndef FRAMETHREAD_H
#define FRAMETHREAD_H

#include <QtDebug>
#include <QThread>
#include "frameSimulator.h"


class FrameThread : public QThread
{
    Q_OBJECT
public:
    FrameThread();
    static void usleep(unsigned long usecs); //{QThread::usleep(usecs);}
    static void msleep(unsigned long msecs); //{QThread::msleep(msecs);}
    static void sleep(unsigned long secs); //{QThread::sleep(secs);}

protected:
    void run();

private:
    //    FrameSimulator _frame;

};

#endif // FRAMETHREAD_H

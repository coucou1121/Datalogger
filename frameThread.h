#ifndef FRAMETHREAD_H
#define FRAMETHREAD_H

#include <QtDebug>
#include <QThread>


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

};

#endif // FRAMETHREAD_H

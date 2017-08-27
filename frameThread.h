#ifndef FRAMETHREAD_H
#define FRAMETHREAD_H

#include <QtDebug>
#include <QThread>


class FrameThread : public QThread
{
    Q_OBJECT
public:
    FrameThread(QString name, quint16 delay);
    static void usleep(unsigned long usecs); //{QThread::usleep(usecs);}
    static void msleep(unsigned long msecs); //{QThread::msleep(msecs);}
    static void sleep(unsigned long secs); //{QThread::sleep(secs);}

protected:
    void run();
private:
    quint16 _delay;

signals:
    void delayFinished();
};

#endif // FRAMETHREAD_H

#include "frameThread.h"

FrameThread::FrameThread()
{
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

// run() will be called when a thread starts
void FrameThread::run()
{
 unsigned long int cpt=0;

   while(1)
   {
       cpt++;
       qDebug() << "hello from worker thread " << thread()->currentThreadId() << cpt;
//    _frame.displayValue();
   this->msleep(1);
   }

}

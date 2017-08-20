#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString title = TITLE;
    QString version = VERSION;

    MainWindow mainWindow;
    mainWindow.show();

    mainWindow.mainSetup();
    //thread
//    QThread *threadTick = new QThread;              // First thread
//    QThread *threadNewDataFrame = new QThread;    // Second thread
//    QThread *threadDisplayRefresh = new QThread;    // Second thread

//    //QThread *threadDataFramSimulator = new QThread; // data frame simulation

//    //timer for thread
//    RefreshTimer *tickTimer = new RefreshTimer(false, "Tick", 1000);
//    RefreshTimer *newDataFrame = new RefreshTimer(true, "Data updated", 10);
//    RefreshTimer *refreshDisplayTimer = new RefreshTimer(true, "Refres Display", 100);



    //dataFrameSimulator->moveToThread(threadDataFramSimulator);

    //implement start slot to start timer
    //QObject::connect(threadTick, SIGNAL(started), tickTimer, SLOT(start()));
    //QObject::connect(threadDisplayRefresh, SIGNAL(started), refreshDisplayTimer, SLOT(start()));
    //QObject::connect(threadDataFramSimulator, SIGNAL(started), dataFrameSimulator, SLOT(start()));




    //thread start

    //threadDataFramSimulator->start();

    //analogPlot.setYValue(dataFrameSimulator->CPT());


    return a.exec();
}



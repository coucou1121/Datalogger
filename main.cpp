#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow mainWindows;
    //AnalogPlot analogPlotWindows;
   // DigitalPlot digitalPlotWindows;
    //GraphicTracePlot graphicTracePlotWindows;
    //FrameSimulator frame;
    //FrameThread frameThreadTest;
    //StartStopEmulData emuldata;
    DisplayWindows displayWindows;
    //AnalogPlot analogPlot;
    GraphicPlot graphicPlot;
    DataFrame dataFrame;

    //mainWindows.setupStyle();
    //mainWindows.show();
    //analogPlotWindows.setMinimumWidth(960);
    //digitalPlotWindows.show();
    //analogPlotWindows.show();
    //graphicTracePlotWindows.show();
    //emuldata.show();
    //qDebug() << "hello from GUI thread " << frameThreadTest.thread()->currentThreadId();
    //frameThreadTest.start();
    //frameThreadTest.wait();  // do not exit before the thread is completed!
    displayWindows.show();
    //analogPlot.show();
    //graphicPlot.show();
    //thread
    QThread *threadTick = new QThread; // First thread
    QThread *threadDisplayRefresh = new QThread; // Second thread

    //timer for thread
    refreshTimer *tickTimer = new refreshTimer(false, "Tick", 100);
    refreshTimer *refreshDisplayTimer = new refreshTimer(true, "Refres Display", 1000);

    //frame simulator
    DataFrameSimulator *dataFrameSimulator = new DataFrameSimulator("Frame Simulator");

    //move time into the thread
    tickTimer->moveToThread(threadTick);
    refreshDisplayTimer->moveToThread(threadDisplayRefresh);

    //implement start slot to start timer
    QObject::connect(threadTick, SIGNAL(started), tickTimer, SLOT(start()));
    QObject::connect(threadDisplayRefresh, SIGNAL(started), refreshDisplayTimer, SLOT(start()));

    //increment the data frame simulator
    QObject::connect(tickTimer, SIGNAL(tickFinished()), dataFrameSimulator, SLOT(incValue()));
    //QObject::connect(dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &graphicPlot, SLOT(addYValue(quint8)));
    //QObject::connect(dataFrameSimulator, SIGNAL(valueUpdated(quint8)), &analogPlot, SLOT(addYValue(quint8)));

    QObject::connect(dataFrameSimulator, SIGNAL(valueDI1_8Updated(quint8)), &displayWindows, SLOT(addValueDI1_8(quint8)));
    QObject::connect(dataFrameSimulator, SIGNAL(valueDI9_16Updated(quint8)), &displayWindows, SLOT(addValueDI9_16(quint8)));

    QObject::connect(dataFrameSimulator, SIGNAL(valueAI1Updated(quint8)), &displayWindows, SLOT(addValueAI1(quint8)));
    QObject::connect(dataFrameSimulator, SIGNAL(valueAI2Updated(quint8)), &displayWindows, SLOT(addValueAI2(quint8)));
    QObject::connect(dataFrameSimulator, SIGNAL(valueAI3Updated(quint8)), &displayWindows, SLOT(addValueAI3(quint8)));
    QObject::connect(dataFrameSimulator, SIGNAL(valueAI4Updated(quint8)), &displayWindows, SLOT(addValueAI4(quint8)));


    //refresh the plot
    //QObject::connect(refreshDisplayTimer, SIGNAL(tickFinished()), &graphicPlot, SLOT(updatePlot()));
    //QObject::connect(refreshDisplayTimer, SIGNAL(tickFinished()), &analogPlot, SLOT(updatePlot()));
    QObject::connect(refreshDisplayTimer, SIGNAL(tickFinished()), &displayWindows, SLOT(replot()));

    //thread start
    threadTick->start();
    threadDisplayRefresh->start();

    //analogPlot.setYValue(dataFrameSimulator->CPT());
    //
    return a.exec();
}



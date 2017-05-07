#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindows;
    AnalogPlot analogPlotWindows;
    DigitalPlot digitalPlotWindows;
    GraphicTracePlot graphicTracePlotWindows;
    FrameSimulator frame;
    FrameThread frameThreadTest;
    //StartStopEmulData emuldata;
    //mainWindows.setupStyle();
    //mainWindows.show();
    //analogPlotWindows.setMinimumWidth(960);
    //digitalPlotWindows.show();
    //analogPlotWindows.show();
    graphicTracePlotWindows.show();
   // emuldata.show();
//    qDebug() << "hello from GUI thread " << frameThreadTest.thread()->currentThreadId();
    //frameThreadTest.start();
//    frameThreadTest.wait();  // do not exit before the thread is completed!

    return a.exec();
}



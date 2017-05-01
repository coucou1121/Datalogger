#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindows;
    AnalogPlot analogPlotWindows;
    DigitalPlot digitalPlotWindows;
    //mainWindows.setupStyle();
    mainWindows.show();
    //analogPlotWindows.setMinimumWidth(960);
    //digitalPlotWindows.show();
    analogPlotWindows.show();


    return a.exec();
}



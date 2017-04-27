#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindows;
    AnalogPlot analogPlotWindows;
    mainWindows.setupStyle();
    mainWindows.show();
    analogPlotWindows.setMinimumWidth(960);
    //analogPlotWindows.show();


    return a.exec();
}



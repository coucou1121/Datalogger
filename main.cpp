#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindows;
    AnalogPlot analogPlotWindows;
    mainWindows.setupStyle();
    mainWindows.show();
    analogPlotWindows.show();


    return a.exec();
}



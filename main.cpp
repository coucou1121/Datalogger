#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindows;
    mainWindows.setupStyle();
    mainWindows.show();


    return a.exec();
}

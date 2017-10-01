#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    mainWindow.mainSetup();

    return a.exec();
}



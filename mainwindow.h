#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define MINIMUM_WIDTH_SIZE 1280
#define MINIMUM_HEIGHT_SIZE 720

#include <QMainWindow>
#include <QTimer>
#include "main.h"
#include "commonStyle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //timer for x axis
    QTimer dataTimer;

    //cetup the basic style for the main wondows
    void setupStyle();

private:
    Ui::MainWindow *ui;
    CommonStyle myStyle;

private slots:

};

#endif // MAINWINDOW_H

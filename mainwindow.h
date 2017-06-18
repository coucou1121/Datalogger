#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTimer>
#include <QThread>
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

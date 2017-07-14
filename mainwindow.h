#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include "main.h"
#include "commonStyle.h"
#include "baseWindow.h"
#include "settingWindow.h"

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

    // diffrent windows
    BaseWindow *baseWindow;
    SettingWindow *settingWindows;
    void setStatusBar();

    //Style
    CommonStyle _myStyle;

    //widget for status bar
    QWidget *_widgetStatusBar;

    QHBoxLayout *_hlayoutStatus = new QHBoxLayout;

    QPushButton *_btBase;
    QPushButton *_btSetting;
    QPushButton *_btTrigger;
    QPushButton *_btDisplay;
    QPushButton *_btDebug;

    void resetPushButtonColor();
    void mainSetup();

private slots:

    void _btBase_released();
    void _btSetting_released();
    void _btTrigger_released();
    void _btDisplay_released();
    void _btDebug_released();
};

#endif // MAINWINDOW_H

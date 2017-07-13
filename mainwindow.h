#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
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

    //set title
    void setTitle(const QString &title);

    //set version
    void setVersion(const QString &version);

private:
    Ui::MainWindow *ui;

    void setStatusBar();

    //Style
    CommonStyle _myStyle;

    //title
    QString _title;

    //Version
    QString _version;

    //widget for status bar
    QWidget *_widgetStatusBar;

    QHBoxLayout *_hlayoutStatus = new QHBoxLayout;

    QPushButton *_btBase;
    QPushButton *_btSetting;
    QPushButton *_btTrigger;
    QPushButton *_btDisplay;
    QPushButton *_btDebug;

    void resetPushButtonColor();

private slots:

    void _btBase_released();
    void _btSetting_released();
    void _btTrigger_released();
    void _btDisplay_released();
    void _btDebug_released();
};

#endif // MAINWINDOW_H

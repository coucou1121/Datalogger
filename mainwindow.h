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

    //set title
    void setTitle(const QString &title);

    //set version
    void setVersion(const QString &version);

private:
    Ui::MainWindow *ui;

    CommonStyle _myStyle;
    QString _title;
    QString _version;
private slots:

};

#endif // MAINWINDOW_H

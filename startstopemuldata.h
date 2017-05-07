#ifndef STARTSTOPEMULDATA_H
#define STARTSTOPEMULDATA_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include "frameThread.h"
#include "frameSimulator.h"

#define TIMER 1000

namespace Ui {
class StartStopEmulData;
}

class StartStopEmulData : public QDialog
{
    Q_OBJECT

public:
    explicit StartStopEmulData(QWidget *parent = 0);
    ~StartStopEmulData();

    bool start() const;
    void setStart(bool start);
    void startMicroTimer();
    FrameSimulator *frameData() const;

    int timeInterval() const;
    void setTimeInterval(int timeInterval);

public slots:
    void on_PB_start_clicked();

signals:
    void refreshPlot();

private:
    bool _start;
    int _timeInterval;
    QTimer *_timer;
    FrameThread *_microTimer;
    FrameSimulator *_frameData;

private slots:

    void on_PB_stop_clicked();
    void on_PB_reset_clicked();
    void emulData();


private:
    Ui::StartStopEmulData *ui;
};

#endif // STARTSTOPEMULDATA_H

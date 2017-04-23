#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define TIMER_REFRESH 500
#define NB_X_VALUES_DISPLAY 100

namespace Ui {
class AnalogPlot;
}

class AnalogPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogPlot(QWidget *parent = 0);
    ~AnalogPlot();

    //function
   // void setupRealtimeDataDemo();

private:

    //Interface
    Ui::AnalogPlot *ui;

    //style
    CommonStyle _myStyle;

    // This object will hold the current value as a text
    // that will appear at the extreme right of the plot,
    QCPItemText *_ValueIndex;

    // The time between each update, this
    // will be  used by the timer to call "updatePlot" slot
    qreal _timeInterval;

    //timer;
    QTimer dataTimer;

    // Data buffers
    QVector<qreal> _YData;
    QVector<qreal> _XData;

    //function
    void setupPlot();
    void setupStyle(QCustomPlot *customPlot);
    void setupTrace(QCustomPlot *customPlot);

private slots:
    // This function is responsible for ploting
    // and updating the graphs , with each timer tick
    void updatePlot(QCustomPlot *customPlot);
    void realtimeDataSlot();

};

#endif // ANALOGPLOT_H

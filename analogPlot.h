#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define AI_TIMER_REFRESH 100
#define AI_DISPLAY_REFRESH 0
#define AI_NB_TRACE 2
#define AI_RESOLUTION 100
#define AI_NB_X_PIXELS 200
#define AI_NB_X_VALUES_DISPLAY_LIVE     AI_NB_X_PIXELS/AI_NB_TRACE
#define AI_NB_X_VALUES_DISPLAY_HOLD 100
#define AI_X_AXIS_MIN_VALUE -1.2
#define AI_Y_AXIS_MIN_VALUE 1.2

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

    //getter
    int getMinValue() const;
    int getMaxValue() const;


    int getYValue() const;
    void setYValue(int yValue);

public slots:
    void updatePlot();

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
    int _timeInterval;

    //reccroding value
    int _maxValue = 0;
    int _minValue = 0;
    int _yValue = 0;

    // Data buffers
    QVector<double> _YData;
    QVector<double> _minusYData;
    QVector<double> _XData;

    QVector<int> _XDataInt;
    QVector<int> _Y1DataInt;
    QVector<int> _Y2DataInt;

    //setter
    void setMinValue(int value);
    void setMaxValue(int value);


    //function
   // void setupPlot();
    //void setupStyle(QCustomPlot *customPlot);
   // void setupTrace(QCustomPlot *customPlot);

private slots:
    // This function is responsible for ploting
    // and updating the graphs , with each timer tick
    void realtimeDataSlot();

};

#endif // ANALOGPLOT_H

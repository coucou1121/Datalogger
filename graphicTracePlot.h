#ifndef GRAPHICTRACEPLOT_H
#define GRAPHICTRACEPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define TIMER_REFRESH 10
#define DISPLAY_REFRESH 1
#define NB_TRACE 2
#define RESOLUTION 10
#define NB_X_PIXELS 10
#define NB_X_VALUES_DISPLAY_LIVE     NB_X_PIXELS/NB_TRACE
#define NB_X_VALUES_DISPLAY_HOLD 100
#define X_AXIS_MIN_VALUE -1.2
#define Y_AXIS_MIN_VALUE 1.2


namespace Ui {
class GraphicTracePlot;
}

class GraphicTracePlot : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicTracePlot(QWidget *parent = 0);
    ~GraphicTracePlot();

    //getter
    int getMinValue() const;
    int getMaxValue() const;


private:

    //Interface
    Ui::GraphicTracePlot *ui;

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
    void setupPlot();
    void setupStyle(QCustomPlot *customPlot);
    void setupTrace(QCustomPlot *customPlot);

private slots:
    // This function is responsible for ploting
    // and updating the graphs , with each timer tick
    void updatePlot();
    void realtimeDataSlot();

};

#endif // GRAPHICTRACEPLOT_H

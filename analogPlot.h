#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

//#define AI_TIMER_REFRESH 100
//#define AI_DISPLAY_REFRESH 0
#define AI_NB_TRACE 1
//#define AI_RESOLUTION 900
#define AI_NB_X_PIXELS 200 //500 //795
#define AI_NB_X_VALUES_DISPLAY_LIVE     AI_NB_X_PIXELS/AI_NB_TRACE
//#define AI_NB_X_VALUES_DISPLAY_HOLD 100
//#define AI_GRAPH_0_X_AXIS_MIN_VALUE -1.2

//gap of 0.2 beetween trace add display frame
#define AI_Y_AXIS_MIN_VALUE -0.2
#define AI_Y_AXIS_MAX_VALUE 255.2

//gap of 0.2 beetween trigger trace add display frame
#define AI_TRIGGER_Y_AXIS_MIN_VALUE -0.2
#define AI_TRIGGER_Y_AXIS_MAX_VALUE 1.2

namespace Ui {
class AnalogPlot;
}

class AnalogPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogPlot(QWidget *parent = 0);
    ~AnalogPlot();

    quint64 CPT() const;
    void setCPT(const quint64 &CPT);

    quint8 yValue() const;
    void setYValue(quint8 yValue);

    //change title name
    void setTitleName(QString name);

    //change range name
    void setRangeName(QString name);

    //direction du draw
    // if true, draw left to right, mode roll on
    // if flase, draw right to left, mode trig
    void setDrawRightToLeft(bool drawRightToLeft);

    void replot();

    void setNbPixels(const quint16 &nbPixels);

    void setSettingTriggerValue(const quint8 &settingTriggerValue);

private:
    Ui::AnalogPlot *ui;

    QCustomPlot *_plot;

    QCPGraph *_graph1;

    QCPItemStraightLine *_line;

    quint16 _nbPixels;
    quint64 _CPT;
    quint64 _CPTMin;
    quint64 _CPTMax;
    quint8 _yValue;
    quint8 _settingTriggerValue;
    //int _minValue = 0;

    QColor _traceSettingColor;

    // Data buffers
    QVector<double> _YData;
    QVector<double> _minusYData;
    QVector<double> _XData;

    QVector<int> _XDataInt;
    QVector<int> _Y1DataInt;
    QVector<int> _Y2DataInt;

    //style
    CommonStyle _myStyle;

    //set plot style
    void setupStyle(QCustomPlot *customPlot);

    //set curve style
    void setupTrace(QCPGraph *graph);

    //plot array pointer
    QSharedPointer<QCPGraphDataContainer> _arrayPlotContainerPointer;

public slots:
    void updatePlot();
    void addYValue(quint8 valueGraph1, quint8 settingTriggerValue);
};

#endif // ANALOGPLOT_H

#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define AI_TIMER_REFRESH 100
#define AI_DISPLAY_REFRESH 0
#define AI_NB_TRACE 2
#define AI_RESOLUTION 900
#define AI_NB_X_PIXELS 900
#define AI_NB_X_VALUES_DISPLAY_LIVE     AI_NB_X_PIXELS/AI_NB_TRACE
#define AI_NB_X_VALUES_DISPLAY_HOLD 100
#define AI_X_AXIS_MIN_VALUE -1.2
#define AI_Y_AXIS_MIN_VALUE 1.2
#define AI_Y_AXIS_MAX_VALUE 255

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

public slots:
    void updatePlot();
    void addYValue(quint8 value);

private:
    Ui::AnalogPlot *ui;

    quint64 _CPT;
    quint8 _yValue;
    int _minValue = 0;

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
    void setupTrace(QCustomPlot *customPlot);
};

#endif // ANALOGPLOT_H

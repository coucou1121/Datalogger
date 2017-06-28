#ifndef DIGITALPLOT_H
#define DIGITALPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define DI_TIMER_REFRESH 100
#define DI_DISPLAY_REFRESH 0
#define DI_NB_TRACE 1
#define DI_RESOLUTION 900
#define DI_NB_X_PIXELS 795
#define DI_NB_X_VALUES_DISPLAY_LIVE     DI_NB_X_PIXELS/DI_NB_TRACE
#define DI_NB_X_VALUES_DISPLAY_HOLD 100
#define DI_X_AXIS_MIN_VALUE 0
#define DI_Y_AXIS_MIN_VALUE -0.2
#define DI_Y_AXIS_MAX_VALUE 1.2

namespace Ui {
class DigitalPlot;
}

class DigitalPlot : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalPlot(QWidget *parent = 0);
    ~DigitalPlot();

    quint64 CPT() const;
    void setCPT(const quint64 &CPT);

    quint8 yValue() const;
    void setYValue(const quint8 &yValue);

    //change title name
    void setTitleName(QString name);

public slots:
    void updatePlot();
    void addYValue(quint8 value);
    void replot();

private:
    Ui::DigitalPlot *ui;

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

#endif // DIGITALPLOT_H

#ifndef GRAPHICPLOT_H
#define GRAPHICPLOT_H

#include <QWidget>

#include "qcustomplot.h"
#include "commonStyle.h"


//#define TIMER_REFRESH 1
//#define DISPLAY_REFRESH 10
#define NB_TRACE 1
//#define RESOLUTION 1
#define NB_X_PIXELS 900
#define NB_X_VALUES_DISPLAY_LIVE     NB_X_PIXELS/NB_TRACE
#define NB_X_VALUES_DISPLAY_HOLD 100
//#define X_AXIS_MIN_VALUE 0
#define Y_AXIS_MIN_VALUE 0
#define Y_AXIS_MAX_VALUE 255

#define IN_DOOR_DATA 0 // 0 use the frame simulator

namespace Ui {
class GraphicPlot;
}

class GraphicPlot : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicPlot(QWidget *parent = 0);
    ~GraphicPlot();    

    quint64 CPT() const;
    void setCPT(const quint64 &CPT);

    quint8 yValue() const;
    void setYValue(quint8 yValue);

public slots:
    void updatePlot();
    void addYValue(quint8 value);

private:
    Ui::GraphicPlot *ui;

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

#endif // GRAPHICPLOT_H

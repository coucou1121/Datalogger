#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include "commonStyle.h"

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
    void setupRealtimeDataDemo(QCustomPlot *customPlot);

private:

    //Interface
    Ui::AnalogPlot *ui;

    //style
    CommonStyle myStyle;

    //function
    void setupPlot();
    void setupStyle(QCustomPlot *customPlot);
    void setupTrace(QCustomPlot *customPlot);
};

#endif // ANALOGPLOT_H

#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class AnalogPlot;
}

class AnalogPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogPlot(QWidget *parent = 0);
    ~AnalogPlot();

    void setupRealtimeDataDemo(QCustomPlot *customPlot);

private:

    Ui::AnalogPlot *ui;

    void setupPlot();
    void setupStyle(QCustomPlot *customPlot);
};

#endif // ANALOGPLOT_H

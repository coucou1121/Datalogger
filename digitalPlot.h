#ifndef DIGITALPLOT_H
#define DIGITALPLOT_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "commonStyle.h"

#define DI_TIMER_REFRESH 1
#define DI_NB_X_VALUES_DISPLAY_LIVE 200
#define DI_NB_X_VALUES_DISPLAY_HOLD 100


namespace Ui {
class DigitalPlot;
}

class DigitalPlot : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalPlot(QWidget *parent = 0);
    ~DigitalPlot();


    //function
   // void setupRealtimeDataDemo();

    //getter
    int getMinValue() const;
    int getMaxValue() const;

private:
    Ui::DigitalPlot *ui;

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

#endif // DIGITALPLOT_H

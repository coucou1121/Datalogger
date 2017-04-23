#ifndef COMMONSTYLE_H
#define COMMONSTYLE_H

#include <QColor>

//main windows
#define BACKGROUD_COLOR 82,82,82    //RGB, R=82, G=82, B=82,    aplha = 255

//analog plot
#define ANALOG_PLOT_BACKGROUD_COLOR         25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255
#define ANALOG_PLOT_BACKGROUD_COLOR_PLOT    25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255

#define ANALOG_PLOT_GRID_COLOR              255, 255, 0, 100        //RGB, R=140,   G=140,  B=140   aplha = 100
#define ANALOG_PLOT_AXE_GRID_COLOR          255, 255, 0             //RGB, R=140,   G=140,  B=140   aplha = 255

#define ANALOG_PLOT_AXIS_COLOR              250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_COLOR         250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_SUB_TICK_COLOR     250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_LABEL_COLOR   250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255

class CommonStyle
{
public:
    CommonStyle();


    QColor getBackGroundColor() const;
    QColor getBackGroundColorAnalogPlot() const;
    QColor getGridColorAnalogPlot() const;
    QColor getAxisGridColorAnalogPlot() const;
    QColor getAxisColorAnalogPlot() const;
    QColor getAxisTickColorAnalogPlot() const;
    QColor getAxisSubTickColorAnalogPlot() const;
    QColor getAxisTickLabelColorAnalogPlot() const;

private:
    //backrgound
    QColor backGroundColor;
    QColor backGroundColorAnalogPlot;

    //Grid
    QColor gridColorAnalogPlot;
    QColor axisGridColorAnalogPlot;

    //Axis
    QColor axisColorAnalogPlot;
    QColor axisTickColorAnalogPlot;
    QColor axisSubTickColorAnalogPlot;
    QColor axisTickLabelColorAnalogPlot;

};



#endif // COMMONSTYLE_H

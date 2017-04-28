#ifndef COMMONSTYLE_H
#define COMMONSTYLE_H

#include <QColor>

//main windows
//size
#define MINIMUM_WIDTH_SIZE 1280
#define MINIMUM_HEIGHT_SIZE 720

//color
#define BACKGROUD_COLOR 82,82,82    //RGB, R=82, G=82, B=82,    aplha = 255

//ANALOG plot
//size
#define ANALOG_PLOT_MINIMUM_WIDTH_SIZE 960
#define ANALOG_PLOT_MINIMUM_HEIGHT_SIZE 22

//color
#define ANALOG_PLOT_BACKGROUD_COLOR         25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255
#define ANALOG_PLOT_BACKGROUD_COLOR_PLOT    25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255

#define ANALOG_PLOT_GRID_COLOR              255, 255, 0, 100        //RGB, R=140,   G=140,  B=140   aplha = 100
#define ANALOG_PLOT_AXE_GRID_COLOR          255, 255, 0             //RGB, R=140,   G=140,  B=140   aplha = 255

#define ANALOG_PLOT_AXIS_COLOR              250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_COLOR         250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_SUB_TICK_COLOR     250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_LABEL_COLOR   250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
//pen
#define ANALOG_PLOT_TRACE                   0, 0, 255               //RGB, R=0,   G=0,  B=255   aplha = 255

//DIGITAL plot
//size
#define DIGITAL_PLOT_MINIMUM_WIDTH_SIZE 960
#define DIGITAL_PLOT_MINIMUM_HEIGHT_SIZE 22

//color
#define DIGITAL_PLOT_BACKGROUD_COLOR         25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255
#define DIGITAL_PLOT_BACKGROUD_COLOR_PLOT    25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255

#define DIGITAL_PLOT_GRID_COLOR              255, 255, 0, 100        //RGB, R=140,   G=140,  B=140   aplha = 100
#define DIGITAL_PLOT_AXE_GRID_COLOR          255, 255, 0             //RGB, R=140,   G=140,  B=140   aplha = 255

#define DIGITAL_PLOT_AXIS_COLOR              250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_TICK_COLOR         250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_SUB_TICK_COLOR     250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_TICK_LABEL_COLOR   250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
//pen
#define DIGITAL_PLOT_TRACE                   0, 255, 0               //RGB, R=0,   G=255,  B=0   aplha = 255


class CommonStyle
{
public:
    CommonStyle();

    //background
    QColor getBackGroundColor() const;
    QColor getBackGroundColorAnalogPlot() const;

    //plot
    QColor getGridColorAnalogPlot() const;
    QColor getAxisGridColorAnalogPlot() const;
    QColor getAxisColorAnalogPlot() const;
    QColor getAxisTickColorAnalogPlot() const;
    QColor getAxisSubTickColorAnalogPlot() const;
    QColor getAxisTickLabelColorAnalogPlot() const;

    //pen
    //analog trace
    QColor getTraceColorAnalogPlot() const;

    //digital trace
    QColor getTraceColorDigitalPlot() const;

private:
    //analog plot
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

    //pen
    //analoge trace
    QColor traceColorAnalogPlot;

    //digital trace
    QColor traceColorDigitalPlot;
};



#endif // COMMONSTYLE_H

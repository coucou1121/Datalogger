#include "commonStyle.h"

CommonStyle::CommonStyle()
{
    //main windows
    backGroundColor.setRgb(BACKGROUD_COLOR);

    //Analog plot
    backGroundColorAnalogPlot.setRgb(ANALOG_PLOT_BACKGROUD_COLOR);
    gridColorAnalogPlot.setRgb(ANALOG_PLOT_GRID_COLOR);
    axisGridColorAnalogPlot.setRgb(ANALOG_PLOT_AXE_GRID_COLOR);
    axisTickColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_TICK_COLOR);
    axisSubTickColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_SUB_TICK_COLOR);
    axisTickLabelColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_TICK_LABEL_COLOR);

    //pen
    //analog trace
    traceColorAnalogPlot.setRgb(ANALOG_PLOT_TRACE);

    //Digital trace
    traceColorDigitalPlot.setRgb(DIGITAL_PLOT_TRACE);
}

QColor CommonStyle::getBackGroundColor() const
{
    return backGroundColor;
}

QColor CommonStyle::getBackGroundColorAnalogPlot() const
{
    return backGroundColorAnalogPlot;
}

QColor CommonStyle::getGridColorAnalogPlot() const
{
    return gridColorAnalogPlot;
}

QColor CommonStyle::getAxisGridColorAnalogPlot() const
{
    return axisGridColorAnalogPlot;
}

QColor CommonStyle::getAxisColorAnalogPlot() const
{
    return axisColorAnalogPlot;
}

QColor CommonStyle::getAxisTickColorAnalogPlot() const
{
    return axisTickColorAnalogPlot;
}

QColor CommonStyle::getAxisSubTickColorAnalogPlot() const
{
    return axisSubTickColorAnalogPlot;
}

QColor CommonStyle::getAxisTickLabelColorAnalogPlot() const
{
    return axisTickLabelColorAnalogPlot;
}

QColor CommonStyle::getTraceColorAnalogPlot() const
{
    return traceColorAnalogPlot;
}

QColor CommonStyle::getTraceColorDigitalPlot() const
{
    return traceColorDigitalPlot;
}

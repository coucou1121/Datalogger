#include "commonStyle.h"

CommonStyle::CommonStyle()
{
    //main windows
    backGroundColor.setRgb(BACKGROUD_COLOR);
    backGroundColorBottomBar.setRgb(BACKGROUD_COLOR_BOTTOM_BAR);
    backGroundColorErrorFrame.setRgb(BACKGROUD_COLOR_ERROR_FRAME);
    backGroundColorButtonStatusbarSelected.setRgb(BACKGROUD_COLOR_BUTTON_STATUS_BAR_SELECTED);
    backGroundColorButtonStatusbarUnselected.setRgb(BACKGROUD_COLOR_BUTTON_STATUS_BAR_UNSELECTED);

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

QColor CommonStyle::getBackGroundColorBottomBar() const
{
    return backGroundColorBottomBar;
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

QColor CommonStyle::getBackGroundColorButtonStatusbarSelected() const
{
    return backGroundColorButtonStatusbarSelected;
}

QColor CommonStyle::getBackGroundColorButtonStatusbarUnselected() const
{
    return backGroundColorButtonStatusbarUnselected;
}

QColor CommonStyle::getBackGroundColorErrorFrame() const
{
    return backGroundColorErrorFrame;
}

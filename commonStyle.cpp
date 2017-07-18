#include "commonStyle.h"

CommonStyle::CommonStyle()
{
    //main windows
    backGroundColor.setRgb(BACKGROUD_COLOR);
    backGroundColorBottomBar.setRgb(BACKGROUD_COLOR_BOTTOM_BAR);
    backGroundColorFrame.setRgb(BACKGROUD_COLOR_FRAME);
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

QColor CommonStyle::getBackGroundColorFrame() const
{
    return backGroundColorFrame;
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

void CommonStyle::setPushButtonUnselected(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + this->getBackGroundColorButtonStatusbarUnselected().name() +
                              ", stop: 0 #ffffff);");
}

void CommonStyle::setPushButtonBlocked(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + this->getBackGroundColor().name()+ ";");
}

void CommonStyle::setSpinBoxShape(QSpinBox *spinBox)
{
    spinBox->setStyleSheet("QSpinBox::up-button { subcontrol-position: left; width: 30px; height: 40px;}"
                           "QSpinBox::down-button { subcontrol-position: right; width: 30px; height: 40px;}"
                           "QSpinBox {background-color: " + this->getBackGroundColorButtonStatusbarUnselected().name()+ ";}"
                           "QSpinBox { border: 3px inset grey; }");
}

void CommonStyle::setDoublespinBoxShape(QDoubleSpinBox *doubleSpinBox)
{
    doubleSpinBox->setStyleSheet("QDoubleSpinBox::up-button { subcontrol-position: left; width: 30px; height: 40px;}"
                                 "QDoubleSpinBox::down-button { subcontrol-position: right; width: 30px; height: 40px;}"
                                 "QDoubleSpinBox {background-color: " + this->getBackGroundColorButtonStatusbarUnselected().name()+ ";}"
                                 "QDoubleSpinBox { border: 3px inset grey; }");
}

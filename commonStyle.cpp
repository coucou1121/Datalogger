#include "commonStyle.h"

CommonStyle::CommonStyle()
{
    //main windows
    _backGroundColor.setRgb(BACKGROUD_COLOR);
    _backGroundColorBottomBar.setRgb(BACKGROUD_COLOR_BOTTOM_BAR);
    _backGroundColorFrame.setRgb(BACKGROUD_COLOR_FRAME);
    _backGroundColorErrorFrame.setRgb(BACKGROUD_COLOR_ERROR_FRAME);
    _backGroundColorButtonStatusbarSelected.setRgb(BACKGROUD_COLOR_BUTTON_STATUS_BAR_SELECTED);
    _backGroundColorButtonStatusbarUnselected.setRgb(BACKGROUD_COLOR_BUTTON_STATUS_BAR_UNSELECTED);

    //Analog plot
    _backGroundColorAnalogPlot.setRgb(ANALOG_PLOT_BACKGROUD_COLOR);
    _gridColorAnalogPlot.setRgb(ANALOG_PLOT_GRID_COLOR);
    _axisGridColorAnalogPlot.setRgb(ANALOG_PLOT_AXE_GRID_COLOR);
    _axisTickColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_TICK_COLOR);
    _axisSubTickColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_SUB_TICK_COLOR);
    _axisTickLabelColorAnalogPlot.setRgb(ANALOG_PLOT_AXIS_TICK_LABEL_COLOR);

    //pen
    //analog trace
    _traceColorAnalogPlot.setRgb(ANALOG_PLOT_TRACE);

    //Digital trace
    _traceColorDigitalPlot.setRgb(DIGITAL_PLOT_TRACE);

    //error line
    _errorLineInTrouble.setRgb(ERROR_LINE_COLOR_IN_TROUBLE);
}

QColor CommonStyle::getBackGroundColor() const
{
    return _backGroundColor;
}

QColor CommonStyle::getBackGroundColorBottomBar() const
{
    return _backGroundColorBottomBar;
}

QColor CommonStyle::getBackGroundColorAnalogPlot() const
{
    return _backGroundColorAnalogPlot;
}

QColor CommonStyle::getGridColorAnalogPlot() const
{
    return _gridColorAnalogPlot;
}

QColor CommonStyle::getAxisGridColorAnalogPlot() const
{
    return _axisGridColorAnalogPlot;
}

QColor CommonStyle::getAxisColorAnalogPlot() const
{
    return _axisColorAnalogPlot;
}

QColor CommonStyle::getAxisTickColorAnalogPlot() const
{
    return _axisTickColorAnalogPlot;
}

QColor CommonStyle::getAxisSubTickColorAnalogPlot() const
{
    return _axisSubTickColorAnalogPlot;
}

QColor CommonStyle::getAxisTickLabelColorAnalogPlot() const
{
    return _axisTickLabelColorAnalogPlot;
}

QColor CommonStyle::getTraceColorAnalogPlot() const
{
    return _traceColorAnalogPlot;
}

QColor CommonStyle::getTraceColorDigitalPlot() const
{
    return _traceColorDigitalPlot;
}

QColor CommonStyle::getBackGroundColorFrame() const
{
    return _backGroundColorFrame;
}

QColor CommonStyle::getBackGroundColorButtonStatusbarSelected() const
{
    return _backGroundColorButtonStatusbarSelected;
}

QColor CommonStyle::getBackGroundColorButtonStatusbarUnselected() const
{
    return _backGroundColorButtonStatusbarUnselected;
}

QColor CommonStyle::getBackGroundColorErrorFrame() const
{
    return _backGroundColorErrorFrame;
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

QColor CommonStyle::getErrorLineInTrouble() const
{
    return _errorLineInTrouble;
}

#include "commonStyle.h"

void CommonStyle::setbackGroundColorLabel(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColorPushButtonDark.name() +
                              "; color:" + _backGroundColorPushButtonLight.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorLabel(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + _backGroundColorPushButtonDark.name() +
                              "; color:" + _backGroundColorPushButtonLight.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorLabelUnselected(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColorPushButtonLight.name() +
                              "; color:" + _backGroundColorPushButtonDark.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorLabelUnselected(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + _backGroundColorPushButtonLight.name() +
                              "; color:" + _backGroundColorPushButtonDark.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorLabelPlot(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColorLabel.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorLabelPlotSmall(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColorLabel.name() + "; font: 10pt;");
}

void CommonStyle::setbackGroundColorFrame(QFrame *frame)
{
    frame->setStyleSheet("background-color:" + _backGroundColorLabel.name() + "; font: 12pt;");
}

void CommonStyle::setbackGroundColorFrame(QWidget *widget)
{
    widget->setStyleSheet("background-color:" + _backGroundColorLabel.name() + "; font: 12pt;");
}

void CommonStyle::setBackGroundColorPlot(QCPAxisRect *qcpAxisRect)
{
    qcpAxisRect->setBackground(_backGroundColorPlot);
}

void CommonStyle::setBackGroundColorDILabel(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundLabelDIPlotON.name() + ";");
}

void CommonStyle::setBackGroundColorRedDILabel(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundLabelRedDIPlotON.name() + ";");
}

void CommonStyle::setErrorColor(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColorErrorFrame.name()+ ";");
}

void CommonStyle::setErrorColor(QFrame *frame)
{
    frame->setStyleSheet("background-color:" + _errorLineInTrouble.name()+ ";");
}

void CommonStyle::setBackGroundColor(QCustomPlot *customPlot)
{
    customPlot->setBackground(_backGroundColor);
}

void CommonStyle::setBackGroundColor(QLabel *label)
{
    label->setStyleSheet("background-color:" + _backGroundColor.name()+ "; font: 12pt;");
}

void CommonStyle::setBackGroundColor(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _backGroundColorPushButtonLight.name() +
                              ", stop: 0 #ffffff); font: 12pt;");
}

void CommonStyle::setBackGroundColorAISelected(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _traceColorAnalogPlot.name() +
                              ", stop: 0 #ffffff); font: 12pt;");
}

void CommonStyle::setBackGroundColorDISelected(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _traceColorDigitalPlot.name() +
                              ", stop: 0 #ffffff); font: 12pt;");
}

void CommonStyle::setStylePlot(QCustomPlot *customPlot)
{
    //set margin
    customPlot->axisRect()->setAutoMargins(QCP::msNone);

   //Set the axis color and line type
   customPlot->xAxis->setBasePen(QPen(_axisColorPlot, 1));
   customPlot->yAxis->setBasePen(QPen(_axisColorPlot, 1));
   customPlot->xAxis->setTickPen(QPen(_axisTickPlot, 1));
   customPlot->yAxis->setTickPen(QPen(_axisTickPlot, 1));
   customPlot->xAxis->setSubTickPen(QPen(_axisTickPlot, 1));
   customPlot->yAxis->setSubTickPen(QPen(_axisTickPlot, 1));
   customPlot->xAxis->setTickLabelColor(_axisColorPlot);
   customPlot->yAxis->setTickLabelColor(_axisColorPlot);
   customPlot->xAxis->setTicks(true);
   customPlot->yAxis->setTicks(true);
   customPlot->xAxis->setSubTicks(true);
   customPlot->xAxis->setTickLabels(false);
   customPlot->yAxis->setTickLabels(false);

   //Set the grid plot color and line type
   customPlot->xAxis->grid()->setVisible(false);
   customPlot->yAxis->grid()->setVisible(false);
   customPlot->xAxis->grid()->setSubGridVisible(true);
   customPlot->yAxis->grid()->setSubGridVisible(true);
   customPlot->xAxis->grid()->setSubGridPen(QPen(_gridColorPlot, 1, Qt::DotLine));
   customPlot->yAxis->grid()->setSubGridPen(QPen(_gridColorPlot, 1, Qt::DotLine));

   //Set the axis grid color and line type
   customPlot->xAxis->grid()->setPen(QPen(_gridColorPlot, 1, Qt::DotLine));
   customPlot->yAxis->grid()->setPen(QPen(_gridColorPlot, 1, Qt::DotLine));

   //y Axis color and line type
   customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
   customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);

   //rescale the axis
   customPlot->rescaleAxes();
}

void CommonStyle::setTraceColorAnalogPlot(QCPGraph *graph)
{
    graph->setPen(QPen(_traceColorAnalogPlot));
}

void CommonStyle::setTraceColorDigitalPlot(QCPGraph *graph)
{
    graph->setPen(QPen(_traceColorDigitalPlot));
}

void CommonStyle::setTraceColorTriggerPlot(QCPGraph *graph)
{
    graph->setPen(QPen(_errorLineInTrouble));
}

void CommonStyle::setTraceColorTriggerPlot(QCPItemStraightLine *line)
{
    line->setPen(QPen(_errorLineInTrouble));
}

void CommonStyle::setPushButtonUnselected(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _backGroundColorPushButtonDark.name() +
                              ", stop: 0 #ffffff); font: 12pt;");
}

void CommonStyle::setPushButtonBlocked(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + _backGroundColor.name()+ "; font: 12pt;");
}

void CommonStyle::setSpinBoxShape(QSpinBox *spinBox)
{
    spinBox->setStyleSheet("QSpinBox::up-button { subcontrol-position: left; width: 30px; height: 40px;}"
                           "QSpinBox::down-button { subcontrol-position: right; width: 30px; height: 40px;}"
                           "QSpinBox {background-color: " + _backGroundColorPushButtonLight.name()+
                           ";}" "QSpinBox { border: 3px inset grey; }");
}

void CommonStyle::setDoublespinBoxShape(QDoubleSpinBox *doubleSpinBox)
{
    doubleSpinBox->setStyleSheet("QDoubleSpinBox::up-button { subcontrol-position: left; width: 30px; height: 40px;}"
                                 "QDoubleSpinBox::down-button { subcontrol-position: right; width: 30px; height: 40px;}"
                                 "QDoubleSpinBox {background-color: " + _backGroundColorPushButtonLight.name()+
                                 ";} QDoubleSpinBox { border: 3px inset grey; }");
}

void CommonStyle::setStartButtonToGreen(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _traceColorDigitalPlot.name() +
                              ", stop: 0 #ffffff); font: bold 22pt;");
}

void CommonStyle::setStartButtonToRed(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                              "stop: 1" + _backGroundColorErrorFrame.name() +
                              ", stop: 0 #ffffff); font: bold 22pt;");
}

void CommonStyle::setButtonStatusBarSelect(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + _backGroundColorPushButtonDark.name() +
                              "; color:" + _backGroundColorPushButtonLight.name() + "; font: 12pt;");
}

void CommonStyle::setButtonStatusBarUnselect(QPushButton *pushButton)
{
    pushButton->setStyleSheet("background-color:" + _backGroundColorPushButtonLight.name() +
                              "; color:" + _backGroundColorPushButtonDark.name() + "; font: 12pt;");
}

//BACKGROUND
QColor CommonStyle::_backGroundColor(BACKGROUD_COLOR);
QColor CommonStyle::_backGroundColorFrame(BACKGROUD_COLOR_FRAME);
QColor CommonStyle::_backGroundColorLabel(BACKGROUD_COLOR_LABEL);
QColor CommonStyle::_backGroundColorPlot(BACKGROUD_COLOR_PLOT);
QColor CommonStyle::_backGroundColorPushButtonLight(BACKGROUD_COLOR_PUSHBUTTON_LIGHT);
QColor CommonStyle::_backGroundColorPushButtonDark(BACKGROUD_COLOR_PUSHBUTTON_DARK);

//ERROR
QColor CommonStyle::_backGroundColorErrorFrame(BACKGROUD_COLOR_ERROR_FRAME);
QColor CommonStyle::_errorLineInTrouble(ERROR_LINE_COLOR_IN_TROUBLE);

//PLOTS
//Grid
QColor CommonStyle::_gridColorPlot(GRID_COLOR_PLOT);
//Axis
QColor CommonStyle::_axisColorPlot(AXIS_COLOR_PLOT);
QColor CommonStyle::_axisTickPlot(AXIS_COLOR_PLOT);

//pen
//analoge trace
QColor CommonStyle::_traceColorAnalogPlot(ANALOG_PLOT_TRACE);

//digital trace
QColor CommonStyle::_traceColorDigitalPlot(DIGITAL_PLOT_TRACE);
QColor CommonStyle::_backGroundLabelDIPlotON(DIGITAL_PLOT_TRACE_ON);
QColor CommonStyle::_backGroundLabelRedDIPlotON(DIGITAL_RED_PLOT_TRACE_ON);

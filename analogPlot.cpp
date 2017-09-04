#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot),
    _CPT(0),
    _CPTMin(0),
    _CPTMax(795)
{
    ui->setupUi(this);
    _plot = ui->widget_AI;
    _plot->addGraph();
    _graph1 = _plot->graph(0);
    _line = new QCPItemStraightLine(_plot);
    setupStyle(this->_plot);
    setupTrace(this->_graph1);
    CommonStyle::setbackGroundColorFrame(ui->frame);
    _arrayPlotContainerPointer = ui->widget_AI->graph(0)->data();
}

AnalogPlot::~AnalogPlot()
{
    delete ui;
}

void AnalogPlot::setTitleName(QString name)
{
    ui->labelNameAI->setText(name);
}

void AnalogPlot::setRangeName(QString name)
{
    ui->labelRangeAI->setText(name + "[V]");
}

void AnalogPlot::setDrawRightToLeft(bool drawRightToLeft)
{
    ui->widget_AI->xAxis->setRangeReversed(!drawRightToLeft);
}

void AnalogPlot::setupStyle(QCustomPlot *customPlot)
{

    //back ground Color behing the plot
    CommonStyle::setBackGroundColor(customPlot);

    //back ground color of the plot
    CommonStyle::setBackGroundColorPlot(customPlot->axisRect());

    //Set the axis color and line type
    CommonStyle::setStylePlot(customPlot);
    CommonStyle::setbackGroundColorLabelPlotSmall(ui->labelRangeAI);

    //set the axis range
    customPlot->xAxis->setRange(0, this->_nbPixels);
    customPlot->yAxis->setRange(AI_Y_AXIS_MIN_VALUE, AI_Y_AXIS_MAX_VALUE);

}

void AnalogPlot::setupTrace(QCPGraph *graph)
{
    //trace
    CommonStyle::setTraceColorAnalogPlot(graph);
 //graph   graph->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));

    //trigger line
    CommonStyle::setTraceColorTriggerPlot(_line);
    //_line->setPen(QPen(_myStyle.getErrorLineInTrouble()));
}

void AnalogPlot::updatePlot()
{

    // add data on th plot
    this->_graph1->setData(_arrayPlotContainerPointer);


    // make key axis range scroll with the data:
    this->_plot->xAxis->setRange(_CPT, this->_nbPixels, Qt::AlignRight);

    //ui->tracePlot->yAxis->rescale();

    // Update the plot widget
    //ui->widget_AI->replot();
}

void AnalogPlot::addYValue(quint8 valueGraph1, quint8 settingTriggerValue)
{
//    qDebug() << objectName() << " Data recieved graph" << valueGraph1 << "trigger" << settingTriggerValue ;
    _CPT++;
//    _CPT = _CPT > 5000 ? 0 : _CPT;
    _settingTriggerValue = settingTriggerValue;

    _line->point1->setCoords(0, _settingTriggerValue);
    _line->point2->setCoords(796, _settingTriggerValue);


    _arrayPlotContainerPointer->add(QCPGraphData(_CPT, valueGraph1));

    if(_arrayPlotContainerPointer->size() > _nbPixels)
    {
        _CPTMin = _CPT - 796;
        _CPTMax = _CPT - _nbPixels;
        _arrayPlotContainerPointer->remove(_CPTMin, _CPTMax);
        _line->point1->setCoords(_CPTMin, _settingTriggerValue);
        _line->point2->setCoords(_CPTMax, _settingTriggerValue);
    }
    qDebug() << objectName() << "CPT: " << _CPT;
}

void AnalogPlot::replot()
{
    this->updatePlot();
    this->_graph1->layer()->replot();
}

void AnalogPlot::setNbPixels(const quint16 &nbPixels)
{
    _nbPixels = nbPixels;
}

void AnalogPlot::setSettingTriggerValue(const quint8 &settingTriggerValue)
{
//    qDebug() << objectName() << " Data recieved trigger" << settingTriggerValue ;
    _settingTriggerValue = settingTriggerValue;
    _line->point1->setCoords(_CPTMin, _settingTriggerValue);
    _line->point2->setCoords(_CPTMax, _settingTriggerValue);
}

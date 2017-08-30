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
    //_line =  new QCPItemStraightLine(_plot->item());
    _line = new QCPItemStraightLine(_plot);
    setupStyle(this->_plot);
    setupTrace(this->_graph1);
    ui->TLname_AI->setStyleSheet("background-color:" + _myStyle.getBackGroundColorBottomBar().name() + ";");
    _arrayPlotContainerPointer = ui->widget_AI->graph(0)->data();
}

AnalogPlot::~AnalogPlot()
{
    delete ui;
}

void AnalogPlot::setTitleName(QString name)
{
    ui->TLname_AI->setText(name);
}

void AnalogPlot::setDrawRightToLeft(bool drawRightToLeft)
{
    ui->widget_AI->xAxis->setRangeReversed(drawRightToLeft);
}

void AnalogPlot::setupStyle(QCustomPlot *customPlot)
{

    //back ground Color behing the plot
    customPlot->setBackground(_myStyle.getBackGroundColor());

    //back ground color of the plot
    customPlot->axisRect()->setBackground(_myStyle.getBackGroundColorAnalogPlot());

    //set margin
    customPlot->axisRect()->setAutoMargins(QCP::msNone);

    //Set the axis color and line type
    customPlot->xAxis->setBasePen(QPen(_myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->yAxis->setBasePen(QPen(_myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->xAxis->setTickPen(QPen(_myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->yAxis->setTickPen(QPen(_myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->xAxis->setSubTickPen(QPen(_myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->yAxis->setSubTickPen(QPen(_myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->xAxis->setTickLabelColor(_myStyle.getAxisTickLabelColorAnalogPlot());
    customPlot->yAxis->setTickLabelColor(_myStyle.getAxisTickLabelColorAnalogPlot());
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
    customPlot->xAxis->grid()->setSubGridPen(QPen(_myStyle.getGridColorAnalogPlot(), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(_myStyle.getGridColorAnalogPlot(), 1, Qt::DotLine));

    //Set the axis grid color and line type
    customPlot->xAxis->grid()->setPen(QPen(_myStyle.getAxisGridColorAnalogPlot(), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(_myStyle.getAxisGridColorAnalogPlot(), 1, Qt::DotLine));


    //y Axis color and line type
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    //    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    //    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);


    //rescale the axis
    customPlot->rescaleAxes();

    //set the axis range
    customPlot->xAxis->setRange(0, this->_nbPixels);
    customPlot->yAxis->setRange(AI_Y_AXIS_MIN_VALUE, AI_Y_AXIS_MAX_VALUE);

}

void AnalogPlot::setupTrace(QCPGraph *graph)
{
    //trace
    graph->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));

    //trigger line
    _line->setPen(QPen(_myStyle.getErrorLineInTrouble()));
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
    qDebug() << objectName() << " Data recieved graph" << valueGraph1 << "trigger" << settingTriggerValue ;
    _CPT++;
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
}

void AnalogPlot::replot()
{
    this->updatePlot();
    this->_plot->replot();
}

void AnalogPlot::setNbPixels(const quint16 &nbPixels)
{
    _nbPixels = nbPixels;
}

void AnalogPlot::setSettingTriggerValue(const quint8 &settingTriggerValue)
{
    qDebug() << objectName() << " Data recieved trigger" << settingTriggerValue ;
    _settingTriggerValue = settingTriggerValue;
    _line->point1->setCoords(_CPTMin, _settingTriggerValue);
    _line->point2->setCoords(_CPTMax, _settingTriggerValue);
}

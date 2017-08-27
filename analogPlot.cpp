#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot),
    _CPT(0)
{
    ui->setupUi(this);
    setupStyle(ui->widget_AI);
    setupTrace(ui->widget_AI);
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

void AnalogPlot::setTraceColorblue()
{
    _traceSettingColor = _myStyle.getTraceColorAnalogPlot();
    ui->widget_AI->graph(0)->setPen(QPen(_traceSettingColor));
}

void AnalogPlot::setTraceColorRed()
{
    _traceSettingColor = _myStyle.getErrorLineInTrouble();
    ui->widget_AI->graph(0)->setPen(QPen(_traceSettingColor));
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

void AnalogPlot::setupTrace(QCustomPlot *customPlot)
{
    //trace
    customPlot->addGraph();
 //   customPlot->graph(0)->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));
    //   customPlot->graph(0)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

    //set color to green as default
    this->setTraceColorblue();

    //Trigger
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(_myStyle.getTraceColorDigitalPlot()));
    //   customPlot->graph(1)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

    //  customPlot->addGraph(); // red line
    //  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));
}

void AnalogPlot::updatePlot()
{

    // add data on th plot
//    ui->widget_AI->graph(0)->setData(_XData , _YData);
    ui->widget_AI->graph(0)->setData(_arrayPlotContainerPointer);

    //    ui->tracePlot->graph(1)->setData(_XData , _minusYData);
    // Now this is the tricky part, the previous part
    // was easy and nothing new in it.


    // Set the range of the vertical and horizontal axis of the plot ( not the graph )
    // so all the data will be centered. first we get the min and max of the x and y data
    //    QVector<double>::iterator xMaxIt = std::max_element( _XData.begin() , _XData.end() );
    //    QVector<double>::iterator xMinIt = std::min_element( _XData.begin() , _XData.end() );
    //    QVector<double>::iterator yMaxIt = std::max_element( _YData.begin() , _YData.end() );


    //    qreal yPlotMin = 0;
    //    qreal yPlotMax = *yMaxIt;

    //    qreal xPlotMin = *xMinIt;
    //    qreal xPlotMax = *xMaxIt;
    //        qreal xPlotMin = -1.1;
    //        qreal xPlotMax = 1.1;

    //qreal yPlotMin = 0;
    //qreal yPlotMax = 31;


    //ui->tracePlot->yAxis->setRange(yPlotMin , yPlotMax);
    // make key axis range scroll with the data:
    ui->widget_AI->xAxis->setRange(_CPT, AI_NB_X_VALUES_DISPLAY_LIVE, Qt::AlignRight);

    //ui->tracePlot->yAxis->rescale();

    // Update the plot widget
    //ui->widget_AI->replot();
}

void AnalogPlot::addYValue(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    _CPT++;

    _arrayPlotContainerPointer->add(QCPGraphData(_CPT, value));
 //   _XData.append(_CPT);

 //   _YData.append(value);
    //   _minusYData.append(-value);
    // int _maxValue = value > _maxValue ? value : _maxValue;
    // int _minValue = value < _minValue ? value : _minValue;
    //    int trigger = 80;
    //    trigger = value < 400 ? 200 : 500;
    // Keep the data buffers size under NB_X_VALUES_DISPLAY value each,
    // so our memory won't explode with random numbers
//    if( _XData.size() > AI_NB_X_VALUES_DISPLAY_LIVE){
//        _XData.remove(0);
//        _YData.remove(0);
    //    _minusYData.remove(0);
    //}
}

void AnalogPlot::replot()
{
    ui->widget_AI->replot();
}

void AnalogPlot::setNbPixels(const quint16 &nbPixels)
{
    _nbPixels = nbPixels;
}

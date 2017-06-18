#include "graphicPlot.h"
#include "ui_graphicPlot.h"

GraphicPlot::GraphicPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicPlot)
{
    ui->setupUi(this);
    setupStyle(ui->widget);
    setupTrace(ui->widget);
    _CPT = 0;
}

GraphicPlot::~GraphicPlot()
{
    delete ui;
}

void GraphicPlot::updatePlot()
{
    ui->widget->graph(0)->setData(_XData , _YData);

    // make key axis range scroll with the data:
    ui->widget->xAxis->setRange(this->CPT(), NB_X_VALUES_DISPLAY_LIVE, Qt::AlignRight);

    // Update the plot widget
    ui->widget->replot();
}

void GraphicPlot::addYValue(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    _CPT++;
    _XData.append(_CPT);

    _YData.append(value);
    //   _minusYData.append(-value);
    // int _maxValue = value > _maxValue ? value : _maxValue;
    // int _minValue = value < _minValue ? value : _minValue;
    //    int trigger = 80;
    //    trigger = value < 400 ? 200 : 500;
    // Keep the data buffers size under NB_X_VALUES_DISPLAY value each,
    // so our memory won't explode with random numbers
    if( _XData.size() > NB_X_VALUES_DISPLAY_LIVE){
        _XData.remove(0);
        _YData.remove(0);
    //    _minusYData.remove(0);
    }
}

quint8 GraphicPlot::yValue() const
{
    return _yValue;
}

void GraphicPlot::setYValue(quint8 yValue)
{
    _yValue = yValue;
}

quint64 GraphicPlot::CPT() const
{
    return _CPT;
}

void GraphicPlot::setCPT(const quint64 &CPT)
{
    _CPT = CPT;
}


void GraphicPlot::setupStyle(QCustomPlot *customPlot)
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
    customPlot->xAxis->setRange(0, NB_X_VALUES_DISPLAY_LIVE);
    customPlot->yAxis->setRange(Y_AXIS_MIN_VALUE, Y_AXIS_MAX_VALUE);

}

void GraphicPlot::setupTrace(QCustomPlot *customPlot)
{
    //trace
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));
    //   customPlot->graph(0)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

    //Trigger
    customPlot->addGraph();
       customPlot->graph(1)->setPen(QPen(_myStyle.getTraceColorDigitalPlot()));
    //   customPlot->graph(1)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

    //  customPlot->addGraph(); // red line
    //  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));

#if IN_DOOR_DATA
    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    // QTimer *timer = new QTimer(this);
    //    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    timer->start(_timeInterval); // Interval 0 means to refresh as fast as possible
#endif
}

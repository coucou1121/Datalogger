#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot),
  _timeInterval(TIMER_REFRESH)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE_ANALOG_PLOT, MINIMUM_HEIGHT_SIZE_ANALOG_PLOT);
    //setup the style, curve and real time plot
    setupPlot();

}

AnalogPlot::~AnalogPlot()
{
    delete ui;
}

void AnalogPlot::setMaxValue(int value)
{
    _maxValue = value;
}

int AnalogPlot::getMinValue() const
{
    return _minValue;
}

int AnalogPlot::getMaxValue() const
{
    return _maxValue;
}

void AnalogPlot::setMinValue(int value)
{
    _minValue = value;
}

void AnalogPlot::setupPlot()
{
    //setup the style
    setupStyle(ui->tracePlot);

    //setup the trace
    setupTrace(ui->tracePlot);

}

void AnalogPlot::setupStyle(QCustomPlot *customPlot)
{

    //back ground Color behing the plot
    customPlot->setBackground(_myStyle.getBackGroundColor());

    //back ground color of the plot
    customPlot->axisRect()->setBackground(_myStyle.getBackGroundColorAnalogPlot());

    //Set the axis color and line type
    customPlot->xAxis->setBasePen(QPen(_myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->yAxis->setBasePen(QPen(_myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->xAxis->setTickPen(QPen(_myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->yAxis->setTickPen(QPen(_myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->xAxis->setSubTickPen(QPen(_myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->yAxis->setSubTickPen(QPen(_myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->xAxis->setTickLabelColor(_myStyle.getAxisTickLabelColorAnalogPlot());
    customPlot->yAxis->setTickLabelColor(_myStyle.getAxisTickLabelColorAnalogPlot());
    customPlot->xAxis->setTicks(false);
    customPlot->yAxis->setTicks(false);
    customPlot->xAxis->setSubTicks(false);
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
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);


    //rescale the axis
    customPlot->rescaleAxes();

    //set the axis range
    //customPlot->xAxis->setRange(0, 110);
    //customPlot->yAxis->setRange(0, 110);

}

void AnalogPlot::setupTrace(QCustomPlot *customPlot)
{
   customPlot->addGraph(); // blue line
   customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
   customPlot->graph(0)->setBrush(QBrush(QColor(40, 110, 255)));

   customPlot->addGraph();
   customPlot->graph(1)->setPen(QPen(QColor(40, 110, 255)));
   customPlot->graph(1)->setBrush(QBrush(QColor(40, 110, 255)));

 //  customPlot->addGraph(); // red line
 //  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer->start(_timeInterval); // Interval 0 means to refresh as fast as possible

}

void AnalogPlot::realtimeDataSlot()
{
    // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double key = 0;
#else
    //double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/10000.0;
#endif

    double key = QDateTime::currentMSecsSinceEpoch() - QDateTime(QDate::currentDate()).toMSecsSinceEpoch();
    static int dataX = 0;
    static int dataY = 100;

    dataX = dataX >100 ? 0 : dataX + 1;
    dataY = dataY < 0  ? 100 : dataY - 1;
    double addPointDelai = 1.;
    static double lastPointKey = 0;
    if (key-lastPointKey > addPointDelai) // at most add point every 10 ms
    {

        // add data to lines:
        ui->tracePlot->graph(1)->addData(key, dataX);
        ui->tracePlot->graph(0)->addData(key, dataY);

        ui->tracePlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;


    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->tracePlot->xAxis->setRange(key, NB_X_VALUES_DISPLAY_HOLD, Qt::AlignRight);
    ui->tracePlot->replot();


}

void AnalogPlot::updatePlot()
{

//    static double CPT = 0;
//    CPT = CPT > 150 ? 0 : CPT+1;

    double CPT = (QDateTime::currentMSecsSinceEpoch() - QDateTime(QDate::currentDate()).toMSecsSinceEpoch())/TIMER_REFRESH;
    //Add the CPT in x data buffer
    _XData.append(CPT);

    // Generate random data with variations
    // This will generate a random intiger between [ 0 , 1 ]
    //qreal r = static_cast<qreal>( rand() ) / RAND_MAX  ;
#if ANALOG_PLOT
    int r = static_cast<int>( rand()%100 ) ;
    // the next value will be 80 plus or minus 5
    double value = 80 + 5 * r;
#else

    double value = static_cast<double>( rand()%2 );

#endif
    //Add the value in y data buffer
    _YData.append(value);
    _minusYData.append(-value);
   // int _maxValue = value > _maxValue ? value : _maxValue;
   // int _minValue = value < _minValue ? value : _minValue;
#if ANALOG_PLOT
    int trigger = 80;
    trigger = value < 400 ? 200 : 500;
#endif
    // Keep the data buffers size under NB_X_VALUES_DISPLAY value each,
    // so our memory won't explode with random numbers
    if( _XData.size() > NB_X_VALUES_DISPLAY_LIVE){
        _XData.remove(0);
        _YData.remove(0);
        _minusYData.remove(0);
    }

    // Add the data to the graph
    //ui->tracePlot->graph(0)->addData(_XData , _YData);
    ui->tracePlot->graph(0)->setData(_XData , _YData);
    ui->tracePlot->graph(1)->setData(_XData , _minusYData);
    // Now this is the tricky part, the previous part
    // was easy and nothing new in it.


    // Set the range of the vertical and horizontal axis of the plot ( not the graph )
    // so all the data will be centered. first we get the min and max of the x and y data
    QVector<double>::iterator xMaxIt = std::max_element( _XData.begin() , _XData.end() );
    QVector<double>::iterator xMinIt = std::min_element( _XData.begin() , _XData.end() );
    QVector<double>::iterator yMaxIt = std::max_element( _YData.begin() , _YData.end() );


    qreal yPlotMin = 0;
    qreal yPlotMax = *yMaxIt;

    qreal xPlotMin = *xMinIt;
    qreal xPlotMax = *xMaxIt;

//    // The yOffset just to make sure that the graph won't take the whole
//    // space in the plot widget, and to keep a margin at the top, the same goes for xOffset
    qreal yOffset = 0.1 * (yPlotMax - yPlotMin) ;
    qreal xOffset = 0.5 * (xPlotMax - xPlotMin);
      ui->tracePlot->xAxis->setRange(xPlotMin , xPlotMax + xOffset);
      ui->tracePlot->yAxis->setRange(-yOffset-yPlotMax , yPlotMax + yOffset);
//    ui->tracePlot->xAxis->setRange(xPlotMin , xPlotMax);
//    ui->tracePlot->yAxis->setRange(yPlotMin , yPlotMax);
//    //************************************************************//
    // Generate the data for the horizontal line, that changes with
    // the last value of the main graph
//    QVector<double> tmpYYData;
//    QVector<double> tmpXXData;
    // Since it's a horizontal line, we only need to feed it two points
    // and both points have the y value
//    tmpYYData.append( _YData.last() );
//    tmpYYData.append( _YData.last() );

    // To make the line cross the plot widget horizontally,
    // from extreme left to extreme right
//    tmpXXData.append( _XData.first() );
//    tmpXXData.append( _XData.last() + xOffset );
    // Finaly set the horizental line data
//    ui->tracePlot->graph( 1 )->setData( tmpXXData , tmpYYData );
//************************************************************//
    // Now to the text item that displays the current value
    // as a string.
    // These are the coordinates of the text item,
    // the offsets here are just to make the text appear
    // next and above a the horizontal line.
//    qreal indexX = _XData.last() + 0.5 * xOffset;
//    qreal indexY = _YData.last() + 0.2 * yOffset;

    // Set the coordinate that we calculated
//    _ValueIndex->position->setCoords( indexX , indexY );
    // Set the text that we want to display
//    _ValueIndex->setText(  QString::number( tmpYYData.last() ) + "  MB/s" );

 //   ui->tracePlot->graph(0)->removeData(key-NB_X_VALUES_DISPLAY,);

    // make key axis range scroll with the data:
    ui->tracePlot->xAxis->setRange(CPT, NB_X_VALUES_DISPLAY_LIVE, Qt::AlignRight);

    //ui->tracePlot->yAxis->rescale();

    // Update the plot widget
    ui->tracePlot->replot();
}

#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot),
    _timeInterval(TIMER_REFRESH)
{
    ui->setupUi(this);
    setMinimumWidth( 900 );
    //setup the style, curve and real time plot
    setupPlot();

}

AnalogPlot::~AnalogPlot()
{
    delete ui;
}

void AnalogPlot::setupPlot()
{
    //setup the style
    setupStyle(ui->tracePlot);

    //add graph

    //setup the trace
    setupTrace(ui->tracePlot);

    //setup the trace in real time
    //setupRealtimeDataDemo();

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
    customPlot->addGraph(); // red line
    customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s:%z");
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->yAxis->setRange(0, 100);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
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
    double addPointDelai = 1;
    static double lastPointKey = 0;
    if (key-lastPointKey > addPointDelai) // at most add point every 10 ms
        //if (key-lastPointKey > (speedAxis >> dividerForPontDrawing)) // at most add point every seconde
    {

        // add data to lines:
        ui->tracePlot->graph(1)->addData(key, dataX);
        ui->tracePlot->graph(0)->addData(key, dataY);
        ui->tracePlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;


    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->tracePlot->xAxis->setRange(key+0.25, 1, Qt::AlignRight);
    ui->tracePlot->replot();


}

void AnalogPlot::updatePlot(QCustomPlot *customPlot)
{

    // Get the current time
    QTime tm = QTime::currentTime();
    // Convert the curretn time to millseconds
    qreal seconds = 60 * 60 * tm.hour() + 60 * tm.minute() + tm.second();
    //qreal timeValue = 1000 * seconds + tm.msec();
    qreal timeValue = 1000 * seconds + tm.msec();
    // Add the time the x data buffer
    _XData.append(timeValue);
    // Generate random data with small variations
    // This will generate a random intiger between [ 0 , 1 ]
    //qreal r = static_cast<qreal>( rand() ) / RAND_MAX  ;
    qreal r = static_cast<qreal>( rand()%100 ) ;
    // the next value will be 80 plus or minus 5
    qreal value = 80 + 5 * r;
    _YData.append(value);

    // Keep the data buffers size under 100 value each,
    // so our moemoty won't explode with random numbers
    if( _XData.size() > 100 ){
        _XData.remove( 0 );
        _YData.remove( 0 );
    }

    // Add the data to the graph
    customPlot->graph(0)->setData(_XData , _YData);
    // Now this is the tricky part, the previous part
    // was easy and nothing new in it.

    // Set the range of the vertical and horizontal axis of the plot ( not the graph )
    // so all the data will be centered. first we get the min and max of the x and y data
    QVector<double>::iterator xMaxIt = std::max_element( _XData.begin() , _XData.end() );
    QVector<double>::iterator xMinIt = std::min_element( _XData.begin() , _XData.end() );
    QVector<double>::iterator yMaxIt = std::max_element( _YData.begin() , _YData.end() );


    qreal yPlotMin = 0;
    qreal yPlotMax = *yMaxIt;

    // qreal xPlotMin = *xMinIt;
    qreal xPlotMax = *xMaxIt;
    qreal xPlotMin = xPlotMax-*xMinIt;//NB_X_VALUES_DISPLAY;

    // The yOffset just to make sure that the graph won't take the whole
    // space in the plot widget, and to keep a margin at the top, the same goes for xOffset
    qreal yOffset = 0.3 * ( yPlotMax - yPlotMin ) ;
    qreal xOffset = 0.5 *( xPlotMax - xPlotMin );
    customPlot->xAxis->setRange( xPlotMin , xPlotMax + xOffset );
    customPlot->yAxis->setRange(yPlotMin , yPlotMax + yOffset);
    //************************************************************//
    // Generate the data for the horizontal line, that changes with
    // the last value of the main graph
    QVector<double> tmpYYData;
    QVector<double> tmpXXData;
    // Since it's a horizontal line, we only need to feed it two points
    // and both points have the y value
    tmpYYData.append( _YData.last() );
    tmpYYData.append( _YData.last() );

    // To make the line cross the plot widget horizontally,
    // from extreme left to extreme right
    tmpXXData.append( _XData.first() );
    tmpXXData.append( _XData.last() + xOffset );
    // Finaly set the horizental line data
    customPlot->graph( 1 )->setData( tmpXXData , tmpYYData );
    //************************************************************//
    // Now to the text item that displays the current value
    // as a string.
    // These are the coordinates of the text item,
    // the offsets here are just to make the text appear
    // next and above a the horizontal line.
    qreal indexX = _XData.last() + 0.5 * xOffset;
    qreal indexY = _YData.last() + 0.2 * yOffset;

    // Set the coordinate that we calculated
    _ValueIndex->position->setCoords( indexX , indexY );
    // Set the text that we want to display
    _ValueIndex->setText(  QString::number( tmpYYData.last() ) + "  MB/s" );


    // Update the plot widget
    customPlot->replot();
}

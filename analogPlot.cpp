#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot),
    _timeInterval(AI_TIMER_REFRESH)
{
    ui->setupUi(this);
    setMinimumSize(ANALOG_PLOT_MINIMUM_WIDTH_SIZE, ANALOG_PLOT_MINIMUM_HEIGHT_SIZE);
    //set margin
    ui->tracePlot->axisRect()->setAutoMargins(QCP::msNone);
    //ui->tracePlot->axisRect()->setMargins(QMargins(0,0,0,0));
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
    customPlot->xAxis->setRange(0, AI_NB_X_VALUES_DISPLAY_LIVE*5);
    customPlot->yAxis->setRange(-1.2, 1.2);

}

void AnalogPlot::setupTrace(QCustomPlot *customPlot)
{
   //trace
   customPlot->addGraph();
   customPlot->graph(0)->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));
//   customPlot->graph(0)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

   //Trigger
   customPlot->addGraph();
//   customPlot->graph(1)->setPen(QPen(_myStyle.getTraceColorAnalogPlot()));
//   customPlot->graph(1)->setBrush(QBrush(_myStyle.getTraceColorAnalogPlot()));

 //  customPlot->addGraph(); // red line
 //  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    timer->start(_timeInterval); // Interval 0 means to refresh as fast as possible

}

void AnalogPlot::realtimeDataSlot()
{
    // calculate two new data points:
  #if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double key = 0;
  #else
    static qint64 key = 0;
  #endif
    _XData.append(key);
    static double value = 0;
    double value0 = qSin(value); //qSin(key*1.6+qCos(key*1.7)*2)*10 + qSin(key*1.2+0.56)*20 + 26;
    double value1 = qCos(value); //qSin(key*1.3+qCos(key*1.2)*1.2)*7 + qSin(key*0.9+0.26)*24 + 26;

    _YData.append(value0);
    _minusYData.append(value1);

    if( _XData.size() > AI_NB_X_VALUES_DISPLAY_LIVE-1){
        _XData.remove(0);
        _YData.remove(0);
        _minusYData.remove(0);
    }

    static int lastPointKey = 10;
    lastPointKey = lastPointKey >= 0 ? lastPointKey - 1 : 1;
//    if (lastPointKey <= 0) // at most add point every 10 ms
//    {
      // add data to lines:
      ui->tracePlot->graph(0)->setData(_XData, _YData);
      ui->tracePlot->graph(1)->setData(_XData, _minusYData);

      // rescale value (vertical) axis to fit the current data:
//     ui->tracePlot->graph(0)->rescaleValueAxis();
//      ui->tracePlot->graph(1)->rescaleValueAxis(true);
//    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->tracePlot->xAxis->setRange(key, AI_NB_X_VALUES_DISPLAY_LIVE*5, Qt::AlignRight);
    ui->tracePlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    ui->lcdNumberFPS->display(ui->tracePlot->graph(0)->data()->size()+ui->tracePlot->graph(1)->data()->size());
    ui->lcdNumberMs->display((int)key);
//    if (key-lastFpsKey > 2) // average fps over 2 seconds
 //   {
//      ui->FPS->setText("coucou");
//            QString("%1 FPS, Total Data points: %2")
//            .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
//            .arg(ui->tracePlot->graph(0)->data()->count()+ui->tracePlot->graph(1)->data()->count())
//            , 0);
 //     lastFpsKey = key;
 //     frameCount = 0;
  //  }
    key = key + 1;
    value = value+1./AI_RESOLUTION;
}


void AnalogPlot::updatePlot()
{

//    static double CPT = 0;
//    CPT = CPT > 150 ? 0 : CPT+1;

    double CPT = (QDateTime::currentMSecsSinceEpoch() -
                  QDateTime(QDate::currentDate()).toMSecsSinceEpoch())/AI_TIMER_REFRESH;
    //Add the CPT in x data buffer
    _XData.append(CPT);

    // Generate random data with variations
    // This will generate a random intiger between [ 0 , 1 ]
    //qreal r = static_cast<qreal>( rand() ) / RAND_MAX  ;
    int r = static_cast<int>( rand()%30 ) ;
    // the next value will be 80 plus or minus 5
//    double value = 80 + 5 * r;
    //Add the value in y data buffer
    _YData.append(r);
 //   _minusYData.append(-value);
   // int _maxValue = value > _maxValue ? value : _maxValue;
   // int _minValue = value < _minValue ? value : _minValue;
//    int trigger = 80;
//    trigger = value < 400 ? 200 : 500;
    // Keep the data buffers size under NB_X_VALUES_DISPLAY value each,
    // so our memory won't explode with random numbers
    if( _XData.size() > AI_NB_X_VALUES_DISPLAY_LIVE-1){
        _XData.remove(0);
        _YData.remove(0);
//        _minusYData.remove(0);
    }

    // Add the data to the graph
    //ui->tracePlot->graph(0)->addData(_XData , _YData);
    ui->tracePlot->graph(0)->setData(_XData , _YData);
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

        qreal yPlotMin = 0;
        qreal yPlotMax = 31;


//    // The yOffset just to make sure that the graph won't take the whole
//    // space in the plot widget, and to keep a margin at the top, the same goes for xOffset
//    qreal yOffset = 0.1 * (yPlotMax - yPlotMin) ;
//    qreal xOffset = 0.5 * (xPlotMax - xPlotMin);
//      ui->tracePlot->xAxis->setRange(xPlotMin , xPlotMax + xOffset);
//      ui->tracePlot->yAxis->setRange(-yOffset-yPlotMax , yPlotMax + yOffset);
//    ui->tracePlot->xAxis->setRange(xPlotMin , xPlotMax);
    ui->tracePlot->yAxis->setRange(yPlotMin , yPlotMax);
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
    ui->tracePlot->xAxis->setRange(CPT, AI_NB_X_VALUES_DISPLAY_LIVE, Qt::AlignRight);

    ui->tracePlot->yAxis->rescale();

    // Update the plot widget
    ui->tracePlot->replot();
}

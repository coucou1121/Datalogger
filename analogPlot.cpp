#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot)
{
    ui->setupUi(this);

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
    //setupTrace(ui->tracePlot);

    //setup the trace in real time
    //setupRealtimeDataDemo(ui->tracePlot);

}

void AnalogPlot::setupStyle(QCustomPlot *customPlot)
{

    //back ground Color behing the plot
    customPlot->setBackground(myStyle.getBackGroundColor());

    //back ground color of the plot
    customPlot->axisRect()->setBackground(myStyle.getBackGroundColorAnalogPlot());

    //Set the axis color and line type
    customPlot->xAxis->setBasePen(QPen(myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->yAxis->setBasePen(QPen(myStyle.getAxisColorAnalogPlot(), 1));
    customPlot->xAxis->setTickPen(QPen(myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->yAxis->setTickPen(QPen(myStyle.getAxisTickColorAnalogPlot(), 1));
    customPlot->xAxis->setSubTickPen(QPen(myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->yAxis->setSubTickPen(QPen(myStyle.getAxisSubTickColorAnalogPlot(), 1));
    customPlot->xAxis->setTickLabelColor(myStyle.getAxisTickLabelColorAnalogPlot());
    customPlot->yAxis->setTickLabelColor(myStyle.getAxisTickLabelColorAnalogPlot());

    //Set the grid plot color and line type
    customPlot->xAxis->grid()->setVisible(false);
    customPlot->yAxis->grid()->setVisible(false);
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setSubGridPen(QPen(myStyle.getGridColorAnalogPlot(), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(myStyle.getGridColorAnalogPlot(), 1, Qt::DotLine));

    //Set the axis grid color and line type
    customPlot->xAxis->grid()->setPen(QPen(myStyle.getAxisGridColorAnalogPlot(), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(myStyle.getAxisGridColorAnalogPlot(), 1, Qt::DotLine));


    //y Axis color and line type
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);


    //rescale the axis
    customPlot->rescaleAxes();

    //set the axis range
    customPlot->xAxis->setRange(0, 110);
    customPlot->yAxis->setRange(0, 110);

}

void AnalogPlot::setupTrace(QCustomPlot *customPlot)
{

//    customPlot->xAxis->setTickLabelType( QCPAxis::ltDateTime );
//    // Set the x axis time string format
//    customPlot->xAxis->setDateTimeFormat( "hh:mm:ss:zzz" );
//    customPlot->xAxis->setAutoTickStep( true );
//    customPlot->yAxis->setAutoTickStep( true );

//    // Allocating memory for the text item that will
//    // display the current value as a text.
//    m_ValueIndex = new QCPItemText( customPlot );
//    // Set the font of the text item
//    m_ValueIndex->setFont(QFont(font().family(), 8)); // make font a bit larger
//    // Add the text item to the plt widget
//    customPlot->addItem(m_ValueIndex);

//    // Change the color of the graphs
//    QColor brushClr = Qt::green;
//    brushClr.setAlphaF( .5 );
//    customPlot->graph( 0 )->setBrush( brushClr );
//    customPlot->graph( 0 )->setPen( QColor() );
//    customPlot->graph( 1 )->setPen( QColor() );


//    // setup a timer and start it.
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout() ), this, SLOT( updatePlot()));
//    timer->start(timeInterval);
}

void AnalogPlot::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
    // include this section to fully disable antialiasing for higher performance:
    /*
    customPlot->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);
    customPlot->legend->setFont(font);
    */
//    customPlot->addGraph(); // blue line
//    customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
//    customPlot->addGraph(); // red line
//    customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

//    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
//    timeTicker->setTimeFormat("%h:%m:%s");
//    customPlot->xAxis->setTicker(timeTicker);
//    customPlot->axisRect()->setupFullAxesBox();
//    customPlot->yAxis->setRange(-1.2, 1.2);

    // make left and bottom axes transfer their ranges to right and top axes:
//    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
//    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

//    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
//    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
//    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

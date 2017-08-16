#include "digitalPlot.h"
#include "ui_digitalPlot.h"

DigitalPlot::DigitalPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitalPlot)
{
    ui->setupUi(this);
    setupStyle(ui->widget_DI);
    setupTrace(ui->widget_DI);
    ui->TLname_DI->setStyleSheet("background-color:" + _myStyle.getBackGroundColorBottomBar().name() + ";");
    _arrayPlotContainerPointer = ui->widget_DI->graph(0)->data();
    _CPT = 0;
}

DigitalPlot::~DigitalPlot()
{
    delete ui;
}

void DigitalPlot::setTitleName(QString name)
{
    ui->TLname_DI->setText(name);
}

void DigitalPlot::setDrawLeftToRight(bool drawLeftToRight)
{
      ui->widget_DI->xAxis->setRangeReversed(!drawLeftToRight);
}

void DigitalPlot::setupStyle(QCustomPlot *customPlot)
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
    customPlot->xAxis->setRange(0, DI_NB_X_VALUES_DISPLAY_LIVE);
    customPlot->yAxis->setRange(DI_Y_AXIS_MIN_VALUE, DI_Y_AXIS_MAX_VALUE);
}

void DigitalPlot::setupTrace(QCustomPlot *customPlot)
{
    //trace
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(_myStyle.getTraceColorDigitalPlot()));
   // customPlot->graph(0)->setBrush(QBrush(_myStyle.getTraceColorDigitalPlot()));

    //Trigger
    //customPlot->addGraph();
    //customPlot->graph(1)->setPen(QPen(_myStyle.getTraceColorDigitalPlot()));
   // customPlot->graph(1)->setBrush(QBrush(_myStyle.getTraceColorDigitalPlot()));

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

void DigitalPlot::updatePlot()
{

    // add data on th plot
    //ui->widget_DI->graph(0)->setData(_XData , _YData, true);
    ui->widget_DI->graph(0)->setData(_arrayPlotContainerPointer);

    //ui->widget_DI->graph(0)->addData(_XData , _YData);

    // make key axis range scroll with the data:
    ui->widget_DI->xAxis->setRange(_CPT, DI_NB_X_VALUES_DISPLAY_LIVE, Qt::AlignRight);

    // Update the plot widget
    //ui->widget_DI->replot();
}

void DigitalPlot::addYValue(quint8 value)
{
    //qDebug() << objectName() << " Datas recieved " << value;
    if(value)
    {
        ui->TLname_DI->setStyleSheet("background-color:" + _myStyle.getTraceColorDigitalPlot().name() + ";");
    }
    else
    {
        ui->TLname_DI->setStyleSheet("background-color:" + _myStyle.getBackGroundColorBottomBar().name() + ";");
    }
    _CPT++;

    _arrayPlotContainerPointer->add(QCPGraphData(_CPT, value));
//    _XData.append(_CPT);

//    _YData.append(value);
//    if( _XData.size() > DI_NB_X_VALUES_DISPLAY_LIVE){
//        _XData.remove(0);
//        _YData.remove(0);
//       // _minusYData.remove(0);
//    }
}

void DigitalPlot::replot()
{
    ui->widget_DI->replot();
}

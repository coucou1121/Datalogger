#include "digitalPlot.h"
#include "ui_digitalPlot.h"

DigitalPlot::DigitalPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitalPlot),
    _isRed(false),
    _yValue(0),
    _CPT(0)
{
    ui->setupUi(this);
    setupStyle(ui->widget_DI);
    setupTrace(ui->widget_DI);
    CommonStyle::setbackGroundColorLabelPlot(ui->labelTitleDI);
    _arrayPlotContainerPointer = ui->widget_DI->graph(0)->data();
}

DigitalPlot::~DigitalPlot()
{
    delete ui;
}

void DigitalPlot::setTitleName(QString name)
{
    ui->labelTitleDI->setText(name);
}

void DigitalPlot::setTraceColorGreen()
{
    CommonStyle::setTraceColorDigitalPlot(ui->widget_DI->graph(0));
    this->_isRed = false;
}

void DigitalPlot::setTraceColorRed()
{
    CommonStyle::setTraceColorTriggerPlot(ui->widget_DI->graph(0));
    this->_isRed = true;
}

void DigitalPlot::setDrawRightToLeft(bool drawRightToLeft)
{
      ui->widget_DI->xAxis->setRangeReversed(!drawRightToLeft);
}

void DigitalPlot::setupStyle(QCustomPlot *customPlot)
{
    //back ground Color behing the plot
    CommonStyle::setBackGroundColor(customPlot);

    //back ground color of the plot
    CommonStyle::setBackGroundColorPlot(customPlot->axisRect());

    //Set the axis color and line type
    CommonStyle::setStylePlot(customPlot);

    //set the axis range
    customPlot->xAxis->setRange(0, DI_NB_X_VALUES_DISPLAY_LIVE);
    customPlot->yAxis->setRange(DI_Y_AXIS_MIN_VALUE, DI_Y_AXIS_MAX_VALUE);
}

void DigitalPlot::setupTrace(QCustomPlot *customPlot)
{
    //trace
    customPlot->addGraph();

    //set color to green as default
    this->setTraceColorGreen();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2, SLOT(setRange(QCPRange)));
}

void DigitalPlot::updatePlot()
{

    // add data on th plot
    //ui->widget_DI->graph(0)->setData(_XData , _YData, true);
    ui->widget_DI->graph(0)->setData(_arrayPlotContainerPointer);

    //ui->widget_DI->graph(0)->addData(_XData , _YData);

    // make key axis range scroll with the data:
    ui->widget_DI->xAxis->setRange(_CPT, this->_nbPixels, Qt::AlignRight);

    // Update the plot widget
    //ui->widget_DI->replot();
}

void DigitalPlot::addYValue(quint8 value)
{
    //qDebug() << objectName() << " Datas recieved " << value;
    _yValue = value;
//    if(value)
//    {
//        ui->TLname_DI->setStyleSheet("background-color:" + this->_traceSettingColor.name() + ";");
//    }
//    else
//    {
//        ui->TLname_DI->setStyleSheet("background-color:" + _myStyle.getBackGroundColorBottomBar().name() + ";");
//    }
    _CPT++;

    _arrayPlotContainerPointer->add(QCPGraphData(_CPT, value));

    if(_arrayPlotContainerPointer->size() > _nbPixels)
    {
        _arrayPlotContainerPointer->remove(_CPT - 796, _CPT - _nbPixels);
    }
}

void DigitalPlot::replot()
{
        if(_yValue)
        {
            if(this->_isRed)
            {
                CommonStyle::setBackGroundColorRedDILabel(ui->labelTitleDI);
            }
            else
            {
                CommonStyle::setBackGroundColorDILabel(ui->labelTitleDI);
            }
        }
        else
        {
           CommonStyle::setbackGroundColorLabelPlot(ui->labelTitleDI);
        }
    this->updatePlot();
    ui->widget_DI->replot();
}

void DigitalPlot::setNbPixels(const quint16 &nbPixels)
{
    _nbPixels = nbPixels;
}

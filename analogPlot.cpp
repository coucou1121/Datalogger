#include "analogPlot.h"
#include "ui_analogPlot.h"

AnalogPlot::AnalogPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot)
{
    ui->setupUi(this);
}

AnalogPlot::~AnalogPlot()
{
    delete ui;
}

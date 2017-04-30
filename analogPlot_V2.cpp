#include "analogPlot_V2.h"
#include "ui_analogPlot_V2.h"

AnalogPlot_V2::AnalogPlot_V2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogPlot_V2)
{
    ui->setupUi(this);
}

AnalogPlot_V2::~AnalogPlot_V2()
{
    delete ui;
}

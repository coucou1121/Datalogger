#include "plotSetting.h"
#include "ui_plotSetting.h"

PlotSetting::PlotSetting(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PlotSetting)
{
    ui->setupUi(this);

    //setup style
    setupStyle();
}

PlotSetting::~PlotSetting()
{
    delete ui;
}

void PlotSetting::setupStyle()
{
    //title shape
    CommonStyle::setbackGroundColorLabel(ui->labelTitlePlotSetting);

    //set doublespinbox shape
    //setup style all spinbox
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBox);

}

void PlotSetting::setSizeOfPlots(int nbPixels)
{
    ui->doubleSpinBox->setValue(nbPixels);
}

void PlotSetting::setTitle(QString nameTxt)
{
    ui->labelTitlePlotSetting->setText(nameTxt);
}

void PlotSetting::setStartValue(double startValue)
{
    ui->doubleSpinBox->setValue(startValue);
}

void PlotSetting::setMinimum(double valueMin)
{
    ui->doubleSpinBox->setMinimum(valueMin);
}

void PlotSetting::setMaximum(double valueMin)
{
    ui->doubleSpinBox->setMaximum(valueMin);
}

void PlotSetting::setStep(double stepValue)
{
    ui->doubleSpinBox->setSingleStep(stepValue);
}

void PlotSetting::on_doubleSpinBox_valueChanged(double arg1)
{
   emit _settingSizeOfPlotWasChanged(static_cast<int>(arg1));
}

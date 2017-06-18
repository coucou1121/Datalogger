#include "displayWindows.h"
#include "ui_displayWindows.h"

DisplayWindows::DisplayWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindows)
{
    ui->setupUi(this);
}

DisplayWindows::~DisplayWindows()
{
    delete ui;
}

void DisplayWindows::replot()
{
    qDebug() << objectName() << " replot recieved ";
    ui->AI1->updatePlot();
    ui->AI2->updatePlot();
    ui->AI3->updatePlot();
    ui->AI4->updatePlot();
}

void DisplayWindows::addValueAI1(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->AI1->addYValue(value);
}

void DisplayWindows::addValueAI2(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->AI2->addYValue(value);
}

void DisplayWindows::addValueAI3(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->AI3->addYValue(value);
}

void DisplayWindows::addValueAI4(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->AI4->addYValue(value);
}

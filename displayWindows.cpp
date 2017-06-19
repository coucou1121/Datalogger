#include "displayWindows.h"
#include "ui_displayWindows.h"

DisplayWindows::DisplayWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindows)
{
    ui->setupUi(this);
    this->setupStyle();

    ui->DI1->setTitleName("DI1");
    ui->DI2->setTitleName("DI2");
    ui->DI3->setTitleName("DI3");
    ui->DI4->setTitleName("DI4");
    ui->DI5->setTitleName("DI5");
    ui->DI6->setTitleName("DI6");
    ui->DI7->setTitleName("DI7");
    ui->DI8->setTitleName("DI8");
    ui->DI9->setTitleName("DI9");
    ui->DI10->setTitleName("DI10");
    ui->DI11->setTitleName("DI11");
    ui->DI12->setTitleName("DI12");
    ui->DI13->setTitleName("DI13");
    ui->DI14->setTitleName("DI14");
    ui->DI15->setTitleName("DI15");
    ui->DI16->setTitleName("DI16");

    ui->AI1->setTitleName("AI1");
    ui->AI2->setTitleName("AI2");
    ui->AI3->setTitleName("AI3");
    ui->AI4->setTitleName("AI4");
}


DisplayWindows::~DisplayWindows()
{
    delete ui;
}

void DisplayWindows::setupStyle()
{
    _palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());
    this->setPalette(_palette);
}

void DisplayWindows::replot()
{
    qDebug() << objectName() << " replot recieved ";
    ui->DI1->updatePlot();
    ui->DI2->updatePlot();
    ui->DI3->updatePlot();
    ui->DI4->updatePlot();
    ui->DI5->updatePlot();
    ui->DI6->updatePlot();
    ui->DI7->updatePlot();
    ui->DI8->updatePlot();
    ui->DI9->updatePlot();
    ui->DI10->updatePlot();
    ui->DI11->updatePlot();
    ui->DI12->updatePlot();
    ui->DI13->updatePlot();
    ui->DI14->updatePlot();
    ui->DI15->updatePlot();
    ui->DI16->updatePlot();

    ui->AI1->updatePlot();
    ui->AI2->updatePlot();
    ui->AI3->updatePlot();
    ui->AI4->updatePlot();
}

void DisplayWindows::addValueDI1_8(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->DI1->addYValue((value & 0x01) >> 0);
    ui->DI2->addYValue((value & 0x02) >> 1);
    ui->DI3->addYValue((value & 0x04) >> 2);
    ui->DI4->addYValue((value & 0x08) >> 3);
    ui->DI5->addYValue((value & 0x10) >> 4);
    ui->DI6->addYValue((value & 0x20) >> 5);
    ui->DI7->addYValue((value & 0x40) >> 6);
    ui->DI8->addYValue((value & 0x80) >> 7);
}

void DisplayWindows::addValueDI9_16(quint8 value)
{
    qDebug() << objectName() << " Data recieved " << value;
    ui->DI9->addYValue((value & 0x01) >> 0);
    ui->DI10->addYValue((value & 0x02) >> 1);
    ui->DI11->addYValue((value & 0x04) >> 2);
    ui->DI12->addYValue((value & 0x08) >> 3);
    ui->DI13->addYValue((value & 0x10) >> 4);
    ui->DI14->addYValue((value & 0x20) >> 5);
    ui->DI15->addYValue((value & 0x40) >> 6);
    ui->DI16->addYValue((value & 0x80) >> 7);
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

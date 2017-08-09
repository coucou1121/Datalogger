#include "displayWindows.h"
#include "ui_displayWindows.h"

DisplayWindows::DisplayWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindows)
{
    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    ui->setupUi(this);
    this->setupStyle();

    //setup title name of all trace
    this->_setAllTraceName();

    //hide all trace
    this->_hideAllTrace();
}


DisplayWindows::~DisplayWindows()
{
    delete ui;
}

void DisplayWindows::setDrawLeftToRight(bool drawLeftToRight)
{
    ui->DI1->setDrawLeftToRight(drawLeftToRight);
    ui->DI2->setDrawLeftToRight(drawLeftToRight);
    ui->DI3->setDrawLeftToRight(drawLeftToRight);
    ui->DI4->setDrawLeftToRight(drawLeftToRight);
    ui->DI5->setDrawLeftToRight(drawLeftToRight);
    ui->DI6->setDrawLeftToRight(drawLeftToRight);
    ui->DI7->setDrawLeftToRight(drawLeftToRight);
    ui->DI8->setDrawLeftToRight(drawLeftToRight);
    ui->DI9->setDrawLeftToRight(drawLeftToRight);
    ui->DI10->setDrawLeftToRight(drawLeftToRight);
    ui->DI11->setDrawLeftToRight(drawLeftToRight);
    ui->DI12->setDrawLeftToRight(drawLeftToRight);
    ui->DI13->setDrawLeftToRight(drawLeftToRight);
    ui->DI14->setDrawLeftToRight(drawLeftToRight);
    ui->DI15->setDrawLeftToRight(drawLeftToRight);
    ui->DI16->setDrawLeftToRight(drawLeftToRight);

    ui->AI1->setDrawLeftToRight(drawLeftToRight);
    ui->AI2->setDrawLeftToRight(drawLeftToRight);
    ui->AI3->setDrawLeftToRight(drawLeftToRight);
    ui->AI4->setDrawLeftToRight(drawLeftToRight);
}

void DisplayWindows::refreshPlot()
{
    if(this->isVisible())
    {
    if(ui->DI1->isVisible())
    {
        ui->DI1->updatePlot();
        ui->DI1->replot();
    }
    if(ui->DI2->isVisible())
    {
        ui->DI2->updatePlot();
        ui->DI2->replot();
    }
    if(ui->DI3->isVisible())
    {
        ui->DI3->updatePlot();
        ui->DI3->replot();
    }
    if(ui->DI4->isVisible())
    {
        ui->DI4->updatePlot();
        ui->DI4->replot();
    }
    if(ui->DI5->isVisible())
    {
        ui->DI5->updatePlot();
        ui->DI5->replot();
    }
    if(ui->DI6->isVisible())
    {
        ui->DI6->updatePlot();
        ui->DI6->replot();
    }
    if(ui->DI7->isVisible())
    {
        ui->DI7->updatePlot();
        ui->DI7->replot();
    }
    if(ui->DI8->isVisible())
    {
        ui->DI8->updatePlot();
        ui->DI8->replot();
    }
    if(ui->DI9->isVisible())
    {
        ui->DI9->updatePlot();
        ui->DI9->replot();
    }
    if(ui->DI10->isVisible())
    {
        ui->DI10->updatePlot();
        ui->DI10->replot();
    }
    if(ui->DI11->isVisible())
    {
        ui->DI11->updatePlot();
        ui->DI11->replot();
    }
    if(ui->DI12->isVisible())
    {
        ui->DI12->updatePlot();
        ui->DI12->replot();
    }
    if(ui->DI13->isVisible())
    {
        ui->DI13->updatePlot();
        ui->DI13->replot();
    }
    if(ui->DI14->isVisible())
    {
        ui->DI14->updatePlot();
        ui->DI14->replot();
    }
    if(ui->DI15->isVisible())
    {
        ui->DI15->updatePlot();
        ui->DI15->replot();
    }
    if(ui->DI16->isVisible())
    {
        ui->DI16->updatePlot();
        ui->DI16->replot();
    }
    if(ui->AI1->isVisible())
    {
        ui->AI1->updatePlot();
        ui->AI1->replot();
    }
    if(ui->AI2->isVisible())
    {
        ui->AI2->updatePlot();
        ui->AI2->replot();
    }
    if(ui->AI3->isVisible())
    {
        ui->AI3->updatePlot();
        ui->AI3->replot();
    }
    if(ui->AI4->isVisible())
    {
        ui->AI4->updatePlot();
        ui->AI4->replot();
    }
    //qDebug() << objectName() << "took" << timerElapse.elapsed() << "miliseconds" << " for refresh";
    timerElapse.restart();
    }
}

void DisplayWindows::_addTrace(int enumTrace)
{
    qDebug() << objectName() << "recieved " << "_addTrace : " << enumTrace;
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->DI1->show();
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->DI2->show();
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->DI3->show();
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->DI4->show();
        break;
    case GlobalEnumatedAndExtern::btDI5:
        ui->DI5->show();
        break;
    case GlobalEnumatedAndExtern::btDI6:
        ui->DI6->show();
        break;
    case GlobalEnumatedAndExtern::btDI7:
        ui->DI7->show();
        break;
    case GlobalEnumatedAndExtern::btDI8:
        ui->DI8->show();
        break;
    case GlobalEnumatedAndExtern::btDI9:
        ui->DI9->show();
        break;
    case GlobalEnumatedAndExtern::btDI10:
        ui->DI10->show();
        break;
    case GlobalEnumatedAndExtern::btDI11:
        ui->DI11->show();
        break;
    case GlobalEnumatedAndExtern::btDI12:
        ui->DI12->show();
        break;
    case GlobalEnumatedAndExtern::btDI13:
        ui->DI13->show();
        break;
    case GlobalEnumatedAndExtern::btDI14:
        ui->DI14->show();
        break;
    case GlobalEnumatedAndExtern::btDI15:
        ui->DI15->show();
        break;
    case GlobalEnumatedAndExtern::btDI16:
        ui->DI16->show();
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->AI1->show();
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->AI2->show();
        break;
    case GlobalEnumatedAndExtern::btAI3:
        ui->AI3->show();
        break;
    case GlobalEnumatedAndExtern::btAI4:
        ui->AI4->show();
        break;
    default :
        break;
    }
}

void DisplayWindows::_hideTrace(int enumTrace)
{
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->DI1->hide();
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->DI2->hide();
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->DI3->hide();
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->DI4->hide();
        break;
    case GlobalEnumatedAndExtern::btDI5:
        ui->DI5->hide();
        break;
    case GlobalEnumatedAndExtern::btDI6:
        ui->DI6->hide();
        break;
    case GlobalEnumatedAndExtern::btDI7:
        ui->DI7->hide();
        break;
    case GlobalEnumatedAndExtern::btDI8:
        ui->DI8->hide();
        break;
    case GlobalEnumatedAndExtern::btDI9:
        ui->DI9->hide();
        break;
    case GlobalEnumatedAndExtern::btDI10:
        ui->DI10->hide();
        break;
    case GlobalEnumatedAndExtern::btDI11:
        ui->DI11->hide();
        break;
    case GlobalEnumatedAndExtern::btDI12:
        ui->DI12->hide();
        break;
    case GlobalEnumatedAndExtern::btDI13:
        ui->DI13->hide();
        break;
    case GlobalEnumatedAndExtern::btDI14:
        ui->DI14->hide();
        break;
    case GlobalEnumatedAndExtern::btDI15:
        ui->DI15->hide();
        break;
    case GlobalEnumatedAndExtern::btDI16:
        ui->DI16->hide();
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->AI1->hide();
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->AI2->hide();
        break;
    case GlobalEnumatedAndExtern::btAI3:
        ui->AI3->hide();
        break;
    case GlobalEnumatedAndExtern::btAI4:
        ui->AI4->hide();
        break;
    default :
        break;
    }
}

void DisplayWindows::setupStyle()
{
    _palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());
    this->setPalette(_palette);
}

void DisplayWindows::addNewDataFrame(QVector<DataFrame> newDataFrameVector)
{
//    qDebug() << objectName() << " nb frame recieved size" << newDataFrameVector.size();
    quint8 valueDI1_9 = 0;
    quint8 valueDI10_18 = 0;

    for(int i = 0; i < newDataFrameVector.size(); i++)
    {
        valueDI1_9 = newDataFrameVector[i].DI1_8();
        valueDI10_18 = newDataFrameVector[i].DI9_16();

        //qDebug() << objectName() << "value DI1" << (value);
        ui->DI1->addYValue((valueDI1_9 & 0x01) >> 0);
        ui->DI2->addYValue((valueDI1_9 & 0x02) >> 1);
        ui->DI3->addYValue((valueDI1_9 & 0x04) >> 2);
        ui->DI4->addYValue((valueDI1_9 & 0x08) >> 3);
        ui->DI5->addYValue((valueDI1_9 & 0x10) >> 4);
        ui->DI6->addYValue((valueDI1_9 & 0x20) >> 5);
        ui->DI7->addYValue((valueDI1_9 & 0x40) >> 6);
        ui->DI8->addYValue((valueDI1_9 & 0x80) >> 7);

        ui->DI9->addYValue(valueDI10_18 & 0x01);
        ui->DI10->addYValue((valueDI10_18 & 0x02) >> 1);
        ui->DI11->addYValue((valueDI10_18 & 0x01) >> 0);
        ui->DI12->addYValue((valueDI10_18 & 0x02) >> 1);
        ui->DI13->addYValue((valueDI10_18 & 0x04) >> 2);
        ui->DI14->addYValue((valueDI10_18 & 0x08) >> 3);
        ui->DI15->addYValue((valueDI10_18 & 0x10) >> 4);
        ui->DI16->addYValue((valueDI10_18 & 0x20) >> 5);

        ui->AI1->addYValue(newDataFrameVector[i].AI1());
        ui->AI2->addYValue(newDataFrameVector[i].AI2());
        ui->AI3->addYValue(newDataFrameVector[i].AI3());
        ui->AI4->addYValue(newDataFrameVector[i].AI4());
    }
    // qDebug() << objectName() << "replot";
    // updatePlot();
}

void DisplayWindows::addValueDI1_8(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    ui->DI1->addYValue((value & 0x01) >> 0);
    ui->DI2->addYValue((value & 0x02) >> 1);
    ui->DI3->addYValue((value & 0x04) >> 2);
    //    ui->DI4->addYValue((value & 0x08) >> 3);
    //    ui->DI5->addYValue((value & 0x10) >> 4);
    //    ui->DI6->addYValue((value & 0x20) >> 5);
    //    ui->DI7->addYValue((value & 0x40) >> 6);
    //    ui->DI8->addYValue((value & 0x80) >> 7);
}

void DisplayWindows::addValueDI9_16(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
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
    //qDebug() << objectName() << " Data recieved " << value;
    ui->AI1->addYValue(value);
}

void DisplayWindows::addValueAI2(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    ui->AI2->addYValue(value);
}

void DisplayWindows::addValueAI3(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    ui->AI3->addYValue(value);
}

void DisplayWindows::addValueAI4(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    ui->AI4->addYValue(value);
}

void DisplayWindows::_setAllTraceName()
{
    ui->DI1->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI1]);
    ui->DI2->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI2]);
    ui->DI3->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI3]);
    ui->DI4->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI4]);
    ui->DI5->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI5]);
    ui->DI6->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI6]);
    ui->DI7->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI7]);
    ui->DI8->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI8]);
    ui->DI9->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI9]);
    ui->DI10->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI10]);
    ui->DI11->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI11]);
    ui->DI12->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI12]);
    ui->DI13->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI13]);
    ui->DI14->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI14]);
    ui->DI15->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI15]);
    ui->DI16->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI16]);

    ui->AI1->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI1]);
    ui->AI2->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI2]);
    ui->AI3->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI3]);
    ui->AI4->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI4]);


}

void DisplayWindows::_hideAllTrace()
{
    ui->DI1->hide();
    ui->DI2->hide();
    ui->DI3->hide();
    ui->DI4->hide();
    ui->DI5->hide();
    ui->DI6->hide();
    ui->DI7->hide();
    ui->DI8->hide();
    ui->DI9->hide();
    ui->DI10->hide();
    ui->DI11->hide();
    ui->DI12->hide();
    ui->DI13->hide();
    ui->DI14->hide();
    ui->DI15->hide();
    ui->DI16->hide();

    ui->AI1->hide();
    ui->AI2->hide();
    ui->AI3->hide();
    ui->AI4->hide();
}

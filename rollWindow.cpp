#include "rollWindow.h"
#include "ui_rollWindow.h"

RollWindow::RollWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RollWindow),
    _memoDataFrame(new DataFrame)
{
    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    ui->setupUi(this);
    //this->setupStyle();

    //setup title name of all trace
    this->_setAllTraceName();

    //hide all trace
    this->_hideAllTrace();
}


RollWindow::~RollWindow()
{
    delete ui;
}

void RollWindow::setDrawRightToLeft(bool drawRightToLeft)
{
    ui->DI1->setDrawRightToLeft(drawRightToLeft);
    ui->DI2->setDrawRightToLeft(drawRightToLeft);
    ui->DI3->setDrawRightToLeft(drawRightToLeft);
    ui->DI4->setDrawRightToLeft(drawRightToLeft);
    ui->DI5->setDrawRightToLeft(drawRightToLeft);
    ui->DI6->setDrawRightToLeft(drawRightToLeft);
    ui->DI7->setDrawRightToLeft(drawRightToLeft);
    ui->DI8->setDrawRightToLeft(drawRightToLeft);
    ui->DI9->setDrawRightToLeft(drawRightToLeft);
    ui->DI10->setDrawRightToLeft(drawRightToLeft);
    ui->DI11->setDrawRightToLeft(drawRightToLeft);
    ui->DI12->setDrawRightToLeft(drawRightToLeft);
    ui->DI13->setDrawRightToLeft(drawRightToLeft);
    ui->DI14->setDrawRightToLeft(drawRightToLeft);
    ui->DI15->setDrawRightToLeft(drawRightToLeft);
    ui->DI16->setDrawRightToLeft(drawRightToLeft);

    ui->AI1->setDrawRightToLeft(drawRightToLeft);
    ui->AI2->setDrawRightToLeft(drawRightToLeft);
    ui->AI3->setDrawRightToLeft(drawRightToLeft);
    ui->AI4->setDrawRightToLeft(drawRightToLeft);
}

void RollWindow::setSizeOfPlot(int valuePixels)
{
    ui->DI1->setNbPixels(valuePixels);
    ui->DI2->setNbPixels(valuePixels);
    ui->DI3->setNbPixels(valuePixels);
    ui->DI4->setNbPixels(valuePixels);
    ui->DI5->setNbPixels(valuePixels);
    ui->DI6->setNbPixels(valuePixels);
    ui->DI7->setNbPixels(valuePixels);
    ui->DI8->setNbPixels(valuePixels);
    ui->DI9->setNbPixels(valuePixels);
    ui->DI10->setNbPixels(valuePixels);
    ui->DI11->setNbPixels(valuePixels);
    ui->DI12->setNbPixels(valuePixels);
    ui->DI13->setNbPixels(valuePixels);
    ui->DI14->setNbPixels(valuePixels);
    ui->DI15->setNbPixels(valuePixels);
    ui->DI16->setNbPixels(valuePixels);

    ui->AI1->setNbPixels(valuePixels);
    ui->AI2->setNbPixels(valuePixels);
    ui->AI3->setNbPixels(valuePixels);
    ui->AI4->setNbPixels(valuePixels);
}

void RollWindow::refreshPlot()
{
    //this->changeBrackgroudColorLabelTrace();

    if(this->isVisible())
    {
        if(ui->DI1->isVisible())
        {
 //           ui->DI1->updatePlot();
           ui->DI1->replot();
        }
        if(ui->DI2->isVisible())
        {
//            ui->DI2->updatePlot();
            ui->DI2->replot();
        }
        if(ui->DI3->isVisible())
        {
 //           ui->DI3->updatePlot();
            ui->DI3->replot();
        }
        if(ui->DI4->isVisible())
        {
//            ui->DI4->updatePlot();
            ui->DI4->replot();
        }
        if(ui->DI5->isVisible())
        {
 //           ui->DI5->updatePlot();
            ui->DI5->replot();
        }
        if(ui->DI6->isVisible())
        {
//           ui->DI6->updatePlot();
            ui->DI6->replot();
        }
        if(ui->DI7->isVisible())
        {
//            ui->DI7->updatePlot();
            ui->DI7->replot();
        }
        if(ui->DI8->isVisible())
        {
//            ui->DI8->updatePlot();
            ui->DI8->replot();
        }
        if(ui->DI9->isVisible())
        {
 //           ui->DI9->updatePlot();
            ui->DI9->replot();
        }
        if(ui->DI10->isVisible())
        {
 //           ui->DI10->updatePlot();
            ui->DI10->replot();
        }
        if(ui->DI11->isVisible())
        {
//            ui->DI11->updatePlot();
            ui->DI11->replot();
        }
        if(ui->DI12->isVisible())
        {
//            ui->DI12->updatePlot();
            ui->DI12->replot();
        }
        if(ui->DI13->isVisible())
        {
//            ui->DI13->updatePlot();
            ui->DI13->replot();
        }
        if(ui->DI14->isVisible())
        {
 //           ui->DI14->updatePlot();
            ui->DI14->replot();
        }
        if(ui->DI15->isVisible())
        {
 //           ui->DI15->updatePlot();
            ui->DI15->replot();
        }
        if(ui->DI16->isVisible())
        {
 //           ui->DI16->updatePlot();
            ui->DI16->replot();
        }
        if(ui->AI1->isVisible())
        {
 //          ui->AI1->updatePlot();
            ui->AI1->replot();
        }
        if(ui->AI2->isVisible())
        {
 //           ui->AI2->updatePlot();
            ui->AI2->replot();
        }
        if(ui->AI3->isVisible())
        {
 //           ui->AI3->updatePlot();
            ui->AI3->replot();
        }
        if(ui->AI4->isVisible())
        {
//            ui->AI4->updatePlot();
            ui->AI4->replot();
        }
        //qDebug() << objectName() << "took" << timerElapse.elapsed() << "miliseconds" << " for refresh";
        //timerElapse.restart();
    }
}

void RollWindow::updateAllPlot()
{
    if(this->isVisible())
    {
        if(ui->DI1->isVisible())
        {
            ui->DI1->updatePlot();
        }
        if(ui->DI2->isVisible())
        {
            ui->DI2->updatePlot();
        }
        if(ui->DI3->isVisible())
        {
            ui->DI3->updatePlot();
        }
        if(ui->DI4->isVisible())
        {
            ui->DI4->updatePlot();
        }
        if(ui->DI5->isVisible())
        {
            ui->DI5->updatePlot();
        }
        if(ui->DI6->isVisible())
        {
           ui->DI6->updatePlot();
        }
        if(ui->DI7->isVisible())
        {
            ui->DI7->updatePlot();
        }
        if(ui->DI8->isVisible())
        {
            ui->DI8->updatePlot();
        }
        if(ui->DI9->isVisible())
        {
            ui->DI9->updatePlot();
        }
        if(ui->DI10->isVisible())
        {
            ui->DI10->updatePlot();
        }
        if(ui->DI11->isVisible())
        {
            ui->DI11->updatePlot();
        }
        if(ui->DI12->isVisible())
        {
            ui->DI12->updatePlot();
        }
        if(ui->DI13->isVisible())
        {
            ui->DI13->updatePlot();
        }
        if(ui->DI14->isVisible())
        {
            ui->DI14->updatePlot();
        }
        if(ui->DI15->isVisible())
        {
            ui->DI15->updatePlot();
        }
        if(ui->DI16->isVisible())
        {
            ui->DI16->updatePlot();
        }
        if(ui->AI1->isVisible())
        {
           ui->AI1->updatePlot();
        }
        if(ui->AI2->isVisible())
        {
            ui->AI2->updatePlot();
        }
        if(ui->AI3->isVisible())
        {
            ui->AI3->updatePlot();
        }
        if(ui->AI4->isVisible())
        {
            ui->AI4->updatePlot();
        }
        //qDebug() << objectName() << "took" << timerElapse.elapsed() << "miliseconds" << " for refresh";
        //timerElapse.restart();
    }
}
void RollWindow::addTrace(quint8 enumTrace)
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

void RollWindow::hideTrace(quint8 enumTrace)
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

//void RollWindow::setupStyle()
//{
//    _palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());
//    this->setPalette(_palette);
//}

void RollWindow::addNewDataFrame(DataFrame *newDataFrame)
{
    //    qDebug() << objectName() << " nb frame recieved size" << newDataFrameVector.size();
    quint8 valueDI1_9 = 0;
    quint8 valueDI10_18 = 0;

    _memoDataFrame = newDataFrame;
//    for(int i = 0; i < newDataFrame.size(); i++)
//    {
        valueDI1_9 = newDataFrame->DI1_8();
        valueDI10_18 = newDataFrame->DI9_16();

        //qDebug() << objectName() << "value DI1" << (value);
        if(ui->DI1->isVisible())
        ui->DI1->addYValue((valueDI1_9 & 0x01) >> 0);
        if(ui->DI2->isVisible())
        ui->DI2->addYValue((valueDI1_9 & 0x02) >> 1);
        if(ui->DI3->isVisible())
        ui->DI3->addYValue((valueDI1_9 & 0x04) >> 2);
        if(ui->DI4->isVisible())
        ui->DI4->addYValue((valueDI1_9 & 0x08) >> 3);
        if(ui->DI5->isVisible())
        ui->DI5->addYValue((valueDI1_9 & 0x10) >> 4);
        if(ui->DI6->isVisible())
        ui->DI6->addYValue((valueDI1_9 & 0x20) >> 5);
        if(ui->DI7->isVisible())
        ui->DI7->addYValue((valueDI1_9 & 0x40) >> 6);
        if(ui->DI8->isVisible())
        ui->DI8->addYValue((valueDI1_9 & 0x80) >> 7);

        if(ui->DI9->isVisible())
        ui->DI9->addYValue(valueDI10_18 & 0x01);
        if(ui->DI10->isVisible())
        ui->DI10->addYValue((valueDI10_18 & 0x02) >> 1);
        if(ui->DI11->isVisible())
        ui->DI11->addYValue((valueDI10_18 & 0x01) >> 0);
        if(ui->DI12->isVisible())
        ui->DI12->addYValue((valueDI10_18 & 0x02) >> 1);
        if(ui->DI13->isVisible())
        ui->DI13->addYValue((valueDI10_18 & 0x04) >> 2);
        if(ui->DI14->isVisible())
        ui->DI14->addYValue((valueDI10_18 & 0x08) >> 3);
        if(ui->DI15->isVisible())
        ui->DI15->addYValue((valueDI10_18 & 0x10) >> 4);
        if(ui->DI16->isVisible())
        ui->DI16->addYValue((valueDI10_18 & 0x20) >> 5);

        if(ui->AI1->isVisible())
        ui->AI1->addYValue(_memoDataFrame->AI1(), _memoDataFrame->TR_AI1());
        if(ui->AI2->isVisible())
        ui->AI2->addYValue(_memoDataFrame->AI2(), _memoDataFrame->TR_AI2());
        if(ui->AI3->isVisible())
        ui->AI3->addYValue(_memoDataFrame->AI3(), 0);
        if(ui->AI4->isVisible())
        ui->AI4->addYValue(_memoDataFrame->AI4(), 0);
//    }
    // qDebug() << objectName() << "replot";
    //updatePlot();
    //this->refreshPlot();
    //this->updateAllPlot();
}

void RollWindow::addValueDI1_8(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    ui->DI1->addYValue((value & 0x01) >> 0);
    ui->DI2->addYValue((value & 0x02) >> 1);
    ui->DI3->addYValue((value & 0x04) >> 2);
    ui->DI4->addYValue((value & 0x08) >> 3);
    ui->DI5->addYValue((value & 0x10) >> 4);
    ui->DI6->addYValue((value & 0x20) >> 5);
    ui->DI7->addYValue((value & 0x40) >> 6);
    ui->DI8->addYValue((value & 0x80) >> 7);
}

void RollWindow::addValueDI9_16(quint8 value)
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

void RollWindow::addValueAI1(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
 //   ui->AI1->addYValue(value);
}

void RollWindow::addValueAI2(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    //ui->AI2->addYValue(value);
}

void RollWindow::addValueAI3(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    //ui->AI3->addYValue(value);
}

void RollWindow::addValueAI4(quint8 value)
{
    //qDebug() << objectName() << " Data recieved " << value;
    //ui->AI4->addYValue(value);
}

void RollWindow::_setAllTraceName()
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

void RollWindow::_hideAllTrace()
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


#include "triggerWindow.h"
#include "ui_triggerWindow.h"

extern qint8 minRange0;
extern qint8 maxRange0_24;
extern qint8 maxRange0_30;
extern qint8 minRange_15_15;
extern qint8 maxRange_15_15;

TriggerWindow::TriggerWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TriggerWindow),
    _AI1SettingTriggerValue(0),
    _AI2SettingTriggerValue(0),
    _AI1TriggerRange((quint8)GlobalEnumatedAndExtern::range0_30),
    _AI2TriggerRange((quint8)GlobalEnumatedAndExtern::range0_30)
{
    ui->setupUi(this);

    this->_triggerFunctionEnable = false;

    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    //setup title name of all trace
    this->_setAllTraceName();

    //hide all trace
    this->_hideAllTrace();

    //setup signal and slot
    this->_setupSignalAndSlot();

    // force the trigger trace to be on bottom
    ui->verticalLayout->setAlignment(ui->widgetFunction,Qt::AlignBottom);

    // set the color of trigger trcae to red
    ui->widgetFunction->setTraceColorRed();
}

TriggerWindow::~TriggerWindow()
{
    delete ui;
}

void TriggerWindow::setDrawRightToLeft(bool drawRightToLeft)
{
    ui->widgetDI1->setDrawRightToLeft(!drawRightToLeft);
    ui->widgetDI2->setDrawRightToLeft(!drawRightToLeft);
    ui->widgetDI3->setDrawRightToLeft(!drawRightToLeft);
    ui->widgetDI4->setDrawRightToLeft(!drawRightToLeft);

    ui->widgetAI1->setDrawRightToLeft(!drawRightToLeft);
    ui->widgetAI2->setDrawRightToLeft(!drawRightToLeft);
}

void TriggerWindow::setSizeOfPlot(int valuePixels)
{
    ui->widgetDI1->setNbPixels(valuePixels);
    ui->widgetDI2->setNbPixels(valuePixels);
    ui->widgetDI3->setNbPixels(valuePixels);
    ui->widgetDI4->setNbPixels(valuePixels);
    ui->widgetAI1->setNbPixels(valuePixels);
    ui->widgetAI2->setNbPixels(valuePixels);
    ui->widgetFunction->setNbPixels(valuePixels);
}

void TriggerWindow::refreshPlot()
{
    this->_triggerFunctionEnable = ui->widgetTriggerFunctionT->areSomeTraceSelected();

    if(this->isVisible())
    {
        if(ui->widgetDI1->isVisible())
        {
            //            ui->widgetDI1->updatePlot();
            ui->widgetDI1->replot();
        }
        if(ui->widgetDI2->isVisible())
        {
            //            ui->widgetDI2->updatePlot();
            ui->widgetDI2->replot();
        }
        if(ui->widgetDI3->isVisible())
        {
            //            ui->widgetDI3->updatePlot();
            ui->widgetDI3->replot();
        }
        if(ui->widgetDI4->isVisible())
        {
            //            ui->widgetDI4->updatePlot();
            ui->widgetDI4->replot();
        }
        if(ui->widgetAI1->isVisible())
        {
            //            ui->widgetAI1->updatePlot();
            ui->widgetAI1->replot();
        }
        if(ui->widgetAI2->isVisible())
        {
            //            ui->widgetAI2->updatePlot();
            ui->widgetAI2->replot();
        }

        if(this->_triggerFunctionEnable)
        {
            //            ui->widgetFunction->updatePlot();
            ui->widgetFunction->replot();
        }
    }
}

void TriggerWindow::_setAllTraceName()
{
    ui->widgetDI1->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI1]);
    ui->widgetDI2->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI2]);
    ui->widgetDI3->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI3]);
    ui->widgetDI4->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btDI4]);
    ui->widgetAI1->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI1]);
    ui->widgetAI2->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::btAI2]);
    ui->widgetFunction->setTitleName(TriggerTracePossible[GlobalEnumatedAndExtern::functionResult]);
}

void TriggerWindow::_hideAllTrace()
{
    ui->widgetDI1->hide();
    ui->widgetDI2->hide();
    ui->widgetDI3->hide();
    ui->widgetDI4->hide();
    ui->widgetAI1->hide();
    ui->widgetAI2->hide();
}

void TriggerWindow::_setupSignalAndSlot()
{
    //connect all slots and signals from trigger menu and emit signal to outside
    //manage range
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonRangeAI1WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI1Changed()));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonRangeAI2WasChanged()),
                     this, SLOT(_recieved_pushButtonRangeAI2Changed()));

    //manage eEdge
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI1WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeDI1Changed(quint8)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI2WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeDI2Changed(quint8)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI3WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeDI3Changed(quint8)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI4WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeDI4Changed(quint8)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeAI1WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeAI1Changed(quint8)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeAI2WasChanged(quint8)),
                     this, SLOT(_recieved_pushButtonEdgeAI2Changed(quint8)));

    //manage doubleSpinBox value
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxDI1_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxDI2_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI2_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxDI3_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI3_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxDI4_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxDI4_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxAI1_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxAI1_valueChanged(double)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_doubleSpinBoxAI2_valueWasChanged(double)),
                     this, SLOT(_recieved_doubleSpinBoxAI2_valueChanged(double)));

    //manage trigger function selection
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxTopLeft_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxTopRight_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxBottomLeft_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxBottomRight_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxTopMiddle_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxMiddle_currentIndexChanged(quint8)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(quint8)),
                     this, SLOT(_recieved_ComboBoxBottomMiddle_currentIndexChanged(quint8)));

    //error management
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_errorWrongEquation(quint8,bool)),
                     this, SLOT(_received_errorWrongEquation(quint8,bool)));
}

quint8 TriggerWindow::_doubleToQuint8(double value, GlobalEnumatedAndExtern::eRangeValue range)
{
    qint8 minRangeValue = 0;
    qint8 maxRangeValue = 0;

    double result;

    switch (range)
    {
    case GlobalEnumatedAndExtern::range0_24:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_24;
        break;
    case GlobalEnumatedAndExtern::range0_30:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_30;
        break;
    case GlobalEnumatedAndExtern::range15_15:
        minRangeValue = minRange_15_15;
        maxRangeValue = maxRange_15_15;
        break;
    default:
        break;
    }
    result = ((value - minRangeValue)*255)/(maxRangeValue-minRangeValue);

    //    qDebug() << "double value  : " << value;
    //    qDebug() << "double result : " << minRangeValue << result;
    quint8 resultInt = (quint8)result;
    return resultInt;
}

void TriggerWindow::updateAllPlot()
{
    if(this->isVisible())
    {
        if(ui->widgetDI1->isVisible())
        {
            ui->widgetDI1->updatePlot();
        }
        if(ui->widgetDI2->isVisible())
        {
            ui->widgetDI2->updatePlot();
        }
        if(ui->widgetDI3->isVisible())
        {
            ui->widgetDI3->updatePlot();
        }
        if(ui->widgetDI4->isVisible())
        {
            ui->widgetDI4->updatePlot();
        }
        if(ui->widgetAI1->isVisible())
        {
            ui->widgetAI1->updatePlot();
        }
        if(ui->widgetAI2->isVisible())
        {
            ui->widgetAI2->updatePlot();
        }

        if(ui->widgetFunction->isVisible())
        {
            ui->widgetFunction->updatePlot();
        }
        //qDebug() << objectName() << "took" << timerElapse.elapsed() << "miliseconds" << " for refresh";
        //timerElapse.restart();
    }


}

void TriggerWindow::addTrace(quint8 enumTrace)
{
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->widgetDI1->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI1, true);
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->widgetDI2->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI2, true);
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->widgetDI3->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI3, true);
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->widgetDI4->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI4, true);
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->widgetAI1->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btAI1, true);
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->widgetAI2->show();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btAI2, true);
        break;
    default :
        break;
    }

    //add trace in combox in trigger function
    ui->widgetTriggerFunctionT->comboboxAddItem(enumTrace);
}

void TriggerWindow::hideTrace(quint8 enumTrace)
{
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->widgetDI1->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI1, false);
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->widgetDI2->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI2, false);
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->widgetDI3->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI3, false);
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->widgetDI4->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btDI4, false);
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->widgetAI1->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btAI1, false);
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->widgetAI2->hide();
        ui->widgetTriggerSettingT->_btSelected(GlobalEnumatedAndExtern::btAI2, false);
        break;
    default :
        break;
    }

    //remove trace in combox in trigger function
    ui->widgetTriggerFunctionT->comboboxRevmoveItem(enumTrace);
}

void TriggerWindow::pushButtonRangeAI1_changeRange()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI1_ChangeRange();
}

void TriggerWindow::pushButtonRangeAI2_changeRange()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI2_ChangeRange();
}

void TriggerWindow::pushButtonEdgeDI1_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI1_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI2_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI2_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI3_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI3_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI4_changeEdge(quint8 eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI4_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeAI1_changeEdge(quint8 eEdge)
{
    this->_AI1TriggerRange = eEdge;
    ui->widgetTriggerSettingT->pushButtonEdgeAI1_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeAI2_changeEdge(quint8 eEdge)
{
    this->_AI2TriggerRange = eEdge;
    ui->widgetTriggerSettingT->pushButtonEdgeAI2_changeEdge(eEdge);
}

void TriggerWindow::doubleSpinBoxDI1_changeValue(double value)
{
    ui->widgetTriggerSettingT->doubleSpinBoxDI1_changeValue(value);
}

void TriggerWindow::doubleSpinBoxDI2_changeValue(double value)
{
    ui->widgetTriggerSettingT->doubleSpinBoxDI2_changeValue(value);
}

void TriggerWindow::doubleSpinBoxDI3_changeValue(double value)
{
    ui->widgetTriggerSettingT->doubleSpinBoxDI3_changeValue(value);
}

void TriggerWindow::doubleSpinBoxDI4_changeValue(double value)
{
    ui->widgetTriggerSettingT->doubleSpinBoxDI4_changeValue(value);
}

void TriggerWindow::doubleSpinBoxAI1_changeValue(double value)
{
    quint8 valueInt = this->_doubleToQuint8(value, (GlobalEnumatedAndExtern::eRangeValue) this->_AI1TriggerRange);
    this->_AI1SettingTriggerValue = valueInt;
    ui->widgetTriggerSettingT->doubleSpinBoxAI1_changeValue(value);
    ui->widgetAI1->setSettingTriggerValue(valueInt);
}

void TriggerWindow::doubleSpinBoxAI2_changeValue(double value)
{
    quint8 valueInt = this->_doubleToQuint8(value, (GlobalEnumatedAndExtern::eRangeValue) this->_AI2TriggerRange);
    this->_AI2SettingTriggerValue = valueInt;
    ui->widgetTriggerSettingT->doubleSpinBoxAI2_changeValue(value);
    ui->widgetAI2->setSettingTriggerValue(valueInt);
}

void TriggerWindow::comboBoxTopLeft_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxTopLeft_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxTopRight_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxTopRight_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxBottomLeft_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxBottomLeft_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxBottomRight_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxBottomRight_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxTopMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxTopMiddle_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxMiddle_changeCurrentIndex(index);
}

void TriggerWindow::comboBoxBottomMiddle_changeCurrentIndex(quint8 index)
{
    ui->widgetTriggerFunctionT->comboBoxBottomMiddle_changeCurrentIndex(index);
}

void TriggerWindow::addNewDataFrame(DataFrame *newDataFrame)
{
    //    qDebug() << objectName() << " nb frame recieved size" << newDataFrameVector.size();
    quint8 valueDI1_8 = 0;

    //_memoDataFrame = newDataFrame;

    //    for(int i = 0; i < newDataFrameVector.size(); i++)
    //    {
    valueDI1_8 = newDataFrame->DI1_8();

    //qDebug() << objectName() << "value DI1" << (value);
    if(ui->widgetDI1->isVisible())
        ui->widgetDI1->addYValue((valueDI1_8 & 0x01) >> 0);
    if(ui->widgetDI2->isVisible())
        ui->widgetDI2->addYValue((valueDI1_8 & 0x02) >> 1);
    if(ui->widgetDI3->isVisible())
        ui->widgetDI3->addYValue((valueDI1_8 & 0x04) >> 2);
    if(ui->widgetDI4->isVisible())
        ui->widgetDI4->addYValue((valueDI1_8 & 0x08) >> 3);

    if(ui->widgetAI1->isVisible())
        ui->widgetAI1->addYValue(newDataFrame->AI1(), _AI1SettingTriggerValue);
    if(ui->widgetAI2->isVisible())
        ui->widgetAI2->addYValue(newDataFrame->AI2(), _AI2SettingTriggerValue);

    if(ui->widgetFunction->isVisible())
        ui->widgetFunction->addYValue(newDataFrame->TR1());
    //    }
    //qDebug() << objectName() << "updateAllPlot";
    // updatePlot();
    // refreshPlot();
    // this->updateAllPlot();
}

void TriggerWindow::_recieved_pushButtonRangeAI1Changed()
{
    emit _pushButtonRangeAI1WasChanged();
}

void TriggerWindow::_recieved_pushButtonRangeAI2Changed()
{
    emit _pushButtonRangeAI2WasChanged();
}

void TriggerWindow::_recieved_pushButtonEdgeDI1Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI1WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI2Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI2WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI3Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI3WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI4Changed(quint8 eEdge)
{
    emit _pushButtonEdgeDI4WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeAI1Changed(quint8 eEdge)
{
    emit _pushButtonEdgeAI1WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeAI2Changed(quint8 eEdge)
{
    emit _pushButtonEdgeAI2WasChanged(eEdge);
}

void TriggerWindow::_recieved_doubleSpinBoxDI1_valueChanged(double value)
{
    emit _doubleSpinBoxDI1_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_doubleSpinBoxDI2_valueChanged(double value)
{
    emit _doubleSpinBoxDI2_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_doubleSpinBoxDI3_valueChanged(double value)
{
    emit _doubleSpinBoxDI3_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_doubleSpinBoxDI4_valueChanged(double value)
{
    emit _doubleSpinBoxDI4_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_doubleSpinBoxAI1_valueChanged(double value)
{
    emit _doubleSpinBoxAI1_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_doubleSpinBoxAI2_valueChanged(double value)
{
    emit _doubleSpinBoxAI2_valueWasChangedFromTriggerMenu(value);
}

void TriggerWindow::_recieved_ComboBoxTopLeft_currentIndexChanged(quint8 index)
{
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxTopRight_currentIndexChanged(quint8 index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomLeft_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomRight_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxTopMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomMiddle_currentIndexChanged(quint8 index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

void TriggerWindow::_received_errorWrongEquation(quint8 errorNumber, bool active)
{
    emit _errorWrongEquation(errorNumber, active);
}

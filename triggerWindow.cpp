#include "triggerWindow.h"
#include "ui_triggerWindow.h"

TriggerWindow::TriggerWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TriggerWindow)
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

void TriggerWindow::setDrawLeftToRight(bool drawLeftToRight)
{
    ui->widgetDI1->setDrawLeftToRight(drawLeftToRight);
    ui->widgetDI2->setDrawLeftToRight(drawLeftToRight);
    ui->widgetDI3->setDrawLeftToRight(drawLeftToRight);
    ui->widgetDI4->setDrawLeftToRight(drawLeftToRight);

    ui->widgetAI1->setDrawLeftToRight(drawLeftToRight);
    ui->widgetAI2->setDrawLeftToRight(drawLeftToRight);
}

void TriggerWindow::refreshPlot()
{
    this->_triggerFunctionEnable = ui->widgetTriggerFunctionT->areSomeTraceSelected();

    if(this->isVisible() && this->_triggerFunctionEnable)
    {
        if(ui->widgetDI1->isVisible())
        {
            ui->widgetDI1->updatePlot();
            ui->widgetDI1->replot();
        }
        if(ui->widgetDI2->isVisible())
        {
            ui->widgetDI2->updatePlot();
            ui->widgetDI2->replot();
        }
        if(ui->widgetDI3->isVisible())
        {
            ui->widgetDI3->updatePlot();
            ui->widgetDI3->replot();
        }
        if(ui->widgetDI4->isVisible())
        {
            ui->widgetDI4->updatePlot();
            ui->widgetDI4->replot();
        }
        if(ui->widgetAI1->isVisible())
        {
            ui->widgetAI1->updatePlot();
            ui->widgetAI1->replot();
        }
        if(ui->widgetAI2->isVisible())
        {
            ui->widgetAI2->updatePlot();
            ui->widgetAI2->replot();
        }

        ui->widgetFunction->updatePlot();
        ui->widgetFunction->replot();
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
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI1WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI1Changed(int)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI2WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI2Changed(int)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI3WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI3Changed(int)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeDI4WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeDI4Changed(int)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeAI1WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeAI1Changed(int)));
    QObject::connect(ui->widgetTriggerSettingT, SIGNAL(_pushButtonEdgeAI2WasChanged(int)),
                     this, SLOT(_recieved_pushButtonEdgeAI2Changed(int)));

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
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopRight_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomLeft_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomLeft_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomRight_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomRight_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxTopMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxTopMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxMiddle_currentIndexChanged(int)));
    QObject::connect(ui->widgetTriggerFunctionT, SIGNAL(_comboBoxBottomMiddle_currentIndexWasChanged(int)),
                     this, SLOT(_recieved_ComboBoxBottomMiddle_currentIndexChanged(int)));
}

void TriggerWindow::addTrace(int enumTrace)
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
    ui->widgetTriggerFunctionT->_comboboxAddItem(enumTrace);
}

void TriggerWindow::hideTrace(int enumTrace)
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
    ui->widgetTriggerFunctionT->_comboboxRevmoveItem(enumTrace);
}

void TriggerWindow::pushButtonRangeAI1_changeRange()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI1_ChangeRange();
}

void TriggerWindow::pushButtonRangeAI2_changeRange()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI2_ChangeRange();
}

void TriggerWindow::pushButtonEdgeDI1_changeEdge(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI1_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI2_changeEdge(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI2_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI3_changeEdge(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI3_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeDI4_changeEdge(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI4_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeAI1_changeEdge(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeAI1_changeEdge(eEdge);
}

void TriggerWindow::pushButtonEdgeAI2_changeEdge(int eEdge)
{
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
    ui->widgetTriggerSettingT->doubleSpinBoxAI1_changeValue(value);
}

void TriggerWindow::doubleSpinBoxAI2_changeValue(double value)
{
    ui->widgetTriggerSettingT->doubleSpinBoxAI2_changeValue(value);
}

void TriggerWindow::comboBoxTopLeft_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxTopLeft_currentIndexChanged(index);
}

void TriggerWindow::comboBoxTopRight_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxTopRight_currentIndexChanged(index);
}

void TriggerWindow::comboBoxBottomLeft_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxBottomLeft_currentIndexChanged(index);
}

void TriggerWindow::comboBoxBottomRight_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxBottomRight_currentIndexChanged(index);
}

void TriggerWindow::comboBoxTopMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxTopMiddle_currentIndexChanged(index);
}

void TriggerWindow::comboBoxMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxMiddle_currentIndexChanged(index);
}

void TriggerWindow::comboBoxBottomMiddle_changeCurrentIndex(int index)
{
    ui->widgetTriggerFunctionT->_comboBoxBottomMiddle_currentIndexChanged(index);
}

void TriggerWindow::addNewDataFrame(QVector<DataFrame> newDataFrameVector)
{
    //    qDebug() << objectName() << " nb frame recieved size" << newDataFrameVector.size();
    quint8 valueDI1_9 = 0;

    for(int i = 0; i < newDataFrameVector.size(); i++)
    {
        valueDI1_9 = newDataFrameVector[i].DI1_8();

        //qDebug() << objectName() << "value DI1" << (value);
        ui->widgetDI1->addYValue((valueDI1_9 & 0x01) >> 0);
        ui->widgetDI2->addYValue((valueDI1_9 & 0x02) >> 1);
        ui->widgetDI3->addYValue((valueDI1_9 & 0x04) >> 2);
        ui->widgetDI4->addYValue((valueDI1_9 & 0x08) >> 3);

        ui->widgetAI1->addYValue(newDataFrameVector[i].AI1());
        ui->widgetAI2->addYValue(newDataFrameVector[i].AI2());

        ui->widgetFunction->addYValue(newDataFrameVector[i].TR1());
     }
    // qDebug() << objectName() << "replot";
    // updatePlot();
}

void TriggerWindow::_recieved_pushButtonRangeAI1Changed()
{
    emit _pushButtonRangeAI1WasChanged();
}

void TriggerWindow::_recieved_pushButtonRangeAI2Changed()
{
    emit _pushButtonRangeAI2WasChanged();
}

void TriggerWindow::_recieved_pushButtonEdgeDI1Changed(int eEdge)
{
    emit _pushButtonEdgeDI1WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI2Changed(int eEdge)
{
    emit _pushButtonEdgeDI2WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI3Changed(int eEdge)
{
    emit _pushButtonEdgeDI3WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeDI4Changed(int eEdge)
{
    emit _pushButtonEdgeDI4WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeAI1Changed(int eEdge)
{
    emit _pushButtonEdgeAI1WasChanged(eEdge);
}

void TriggerWindow::_recieved_pushButtonEdgeAI2Changed(int eEdge)
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

void TriggerWindow::_recieved_ComboBoxTopLeft_currentIndexChanged(int index)
{
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxTopRight_currentIndexChanged(int index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomLeft_currentIndexChanged(int index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomRight_currentIndexChanged(int index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxTopMiddle_currentIndexChanged(int index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxMiddle_currentIndexChanged(int index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void TriggerWindow::_recieved_ComboBoxBottomMiddle_currentIndexChanged(int index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

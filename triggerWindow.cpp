#include "triggerWindow.h"
#include "ui_triggerWindow.h"

TriggerWindow::TriggerWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TriggerWindow)
{
    ui->setupUi(this);

    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    //setup title name of all trace
    this->_setAllTraceName();

    //hide all trace
    this->_hideAllTrace();

    //setup signal and slot
    this->setupSignalAndSlot();

    // force the trigger trace to be on bottom
    ui->verticalLayout->setAlignment(ui->widgetFunction,Qt::AlignBottom);
}

TriggerWindow::~TriggerWindow()
{
    delete ui;
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

void TriggerWindow::setupSignalAndSlot()
{
    //connect all signals from trigger menu to outside
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
}

void TriggerWindow::_addTrace(int enumTrace)
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
    ui->widgetTriggerFunction->_comboboxAddItem(enumTrace);
}

void TriggerWindow::_hideTrace(int enumTrace)
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
    ui->widgetTriggerFunction->_comboboxRevmoveItem(enumTrace);
}

void TriggerWindow::_pushButtonRangeAI1Changed()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI1Changed();
}

void TriggerWindow::_pushButtonRangeAI2Changed()
{
    ui->widgetTriggerSettingT->pushButtonRangeAI2Changed();
}

void TriggerWindow::_pushButtonEdgeDI1Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI1Changed(eEdge);
}

void TriggerWindow::_pushButtonEdgeDI2Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI2Changed(eEdge);
}

void TriggerWindow::_pushButtonEdgeDI3Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI3Changed(eEdge);
}

void TriggerWindow::_pushButtonEdgeDI4Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeDI4Changed(eEdge);
}

void TriggerWindow::_pushButtonEdgeAI1Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeAI1Changed(eEdge);
}

void TriggerWindow::_pushButtonEdgeAI2Changed(int eEdge)
{
    ui->widgetTriggerSettingT->pushButtonEdgeAI2Changed(eEdge);
}

void TriggerWindow::_comboBoxTopLeft_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopLeft_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxTopRight_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopRight_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxBottomLeft_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomLeft_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxBottomRight_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomRight_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxTopMiddle_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxTopMiddle_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxMiddle_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxMiddle_currentIndexChanged(index);
}

void TriggerWindow::_comboBoxBottomMiddle_currentIndexChanged(int index)
{
    ui->widgetTriggerFunction->_comboBoxBottomMiddle_currentIndexChanged(index);
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

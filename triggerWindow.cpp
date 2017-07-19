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

void TriggerWindow::_addTrace(int enumTrace)
{
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->widgetDI1->show();
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->widgetDI2->show();
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->widgetDI3->show();
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->widgetDI4->show();
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->widgetAI1->show();
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->widgetAI2->show();
        break;
    default :
        break;
    }

}

void TriggerWindow::_hideTrace(int enumTrace)
{
    switch(enumTrace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->widgetDI1->hide();
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->widgetDI2->hide();
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->widgetDI3->hide();
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->widgetDI4->hide();
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->widgetAI1->hide();
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->widgetAI2->hide();
        break;
    default :
        break;
    }
}

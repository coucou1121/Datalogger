#include "triggerWindow.h"
#include "ui_triggerWindow.h"

TriggerWindow::TriggerWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TriggerWindow)
{
    ui->setupUi(this);
    ui->widgetTriggerSetting->setMinimumWidth(30);
 //   ui->widgetTriggerFunction->setMinimumWidth(30);
}

TriggerWindow::~TriggerWindow()
{
    delete ui;
}

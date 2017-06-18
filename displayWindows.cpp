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

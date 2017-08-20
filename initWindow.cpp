#include "initWindow.h"
#include "ui_initWindow.h"

InitWindow::InitWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::InitWindow)
{
    ui->setupUi(this);
}

InitWindow::~InitWindow()
{
    delete ui;
}

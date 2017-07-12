#include "errorFrame.h"
#include "ui_errorFrame.h"

ErrorFrame::ErrorFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorFrame)
{
    ui->setupUi(this);
}

ErrorFrame::~ErrorFrame()
{
    delete ui;
}

void ErrorFrame::setBackgroundColor(QColor colorBackGround, QColor colorTopLine)
{
    ui->labelError->setStyleSheet("background-color:" + colorBackGround.name() + ";");
    ui->line->setStyleSheet("background-color:" + colorTopLine.name() + ";");
}

#include "stateFrame.h"
#include "ui_stateFrame.h"

StateFrame::StateFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateFrame)
{
    ui->setupUi(this);
    setStateStop();
}

StateFrame::~StateFrame()
{
    delete ui;
}

void StateFrame::setStateStop()
{
    QPixmap pix(":/images/StateStop.png");
    //ui->label->setStyleSheet("border-image:url(:/2.png);");
    ui->labelLogoState->setPixmap(pix);
    ui->labelState->setText("Stop");
}


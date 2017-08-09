#include "stateFrame.h"
#include "ui_stateFrame.h"

StateFrame::StateFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateFrame)
{
    ui->setupUi(this);

    //initialise the Key - Value for main state possible
    _mainStatePossible = GlobalEnumatedAndExtern::initMainStatePossibleTxt();

    //set logo
    _pixStateStop = new QPixmap(":/images/StateStop.png");
    _pixStatePause = new QPixmap(":/images/StatePause.png");
    _pixStateRunTrig = new QPixmap(":/images/StateRunTrig.png");
    _pixStateOnTrig = new QPixmap(":/images/StateOnTrig.png");
    _pixStateRollOn = new QPixmap(":/images/StateRollOn.png");

    //init the default value
    setMainState(GlobalEnumatedAndExtern::mainStateStop);
}

StateFrame::~StateFrame()
{
    delete ui;
}

void StateFrame::setMainState(GlobalEnumatedAndExtern::eMainState stateApp)
{
    ui->labelState->setText(_mainStatePossible[stateApp]);

    switch (stateApp)
    {
    case GlobalEnumatedAndExtern::mainStateStop:
        ui->labelLogoState->setPixmap(*_pixStateStop);
        break;
    case GlobalEnumatedAndExtern::mainStatePause:
        ui->labelLogoState->setPixmap(*_pixStatePause);
        break;
    case GlobalEnumatedAndExtern::mainStateRunTrig:
        ui->labelLogoState->setPixmap(*_pixStateRunTrig);
        break;
    case GlobalEnumatedAndExtern::mainStateOnTrig:
        ui->labelLogoState->setPixmap(*_pixStateOnTrig);
        break;
    case GlobalEnumatedAndExtern::mainStateRollOn:
        ui->labelLogoState->setPixmap(*_pixStateRollOn);
        break;
    default:
        break;
    }
    //QPixmap pix(":/images/StateStop.png");
    //ui->labelLogoState->setPixmap(pix);
    //ui->labelState->setText(mainStateStopTxt);
}


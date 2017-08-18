#include "stateFrame.h"
#include "ui_stateFrame.h"

StateFrame::StateFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateFrame)
{
    ui->setupUi(this);

    //initialise the Key - Value for main state possible
    _mainStatePossible = GlobalEnumatedAndExtern::initMainStateDisplayPossibleTxt();

    //set logo
    _pixStateStop = new QPixmap(":/images/StateStop.png");
    _pixStatePause = new QPixmap(":/images/StatePause.png");
    _pixStateRunTrig = new QPixmap(":/images/StateRunTrig.png");
    _pixStateOnTrig = new QPixmap(":/images/StateOnTrig.png");
    _pixStateRollOn = new QPixmap(":/images/StateRollOn.png");

    //init the default value
    setDisplayState(GlobalEnumatedAndExtern::init);
}

StateFrame::~StateFrame()
{
    delete ui;
}

void StateFrame::setDisplayState(GlobalEnumatedAndExtern::eMainStateDisplay stateToDisplay)
{
    ui->labelState->setText(_mainStatePossible[stateToDisplay]);

    switch (stateToDisplay)
    {
    case GlobalEnumatedAndExtern::init:
        //ui->labelLogoState->setPixmap(*_pixStateStop);
        break;
    case GlobalEnumatedAndExtern::stopped:
        ui->labelLogoState->setPixmap(*_pixStateStop);
        break;
    case GlobalEnumatedAndExtern::ready:
        //ui->labelLogoState->setPixmap(*_pixStatePause);
        break;
    case GlobalEnumatedAndExtern::runTrig:
        ui->labelLogoState->setPixmap(*_pixStateRunTrig);
        break;
    case GlobalEnumatedAndExtern::trigged:
        ui->labelLogoState->setPixmap(*_pixStateOnTrig);
        break;
    case GlobalEnumatedAndExtern::rollOn:
        ui->labelLogoState->setPixmap(*_pixStateRollOn);
        break;
    case GlobalEnumatedAndExtern::paused:
        ui->labelLogoState->setPixmap(*_pixStateRollOn);
        break;
    default:
        break;
    }
}


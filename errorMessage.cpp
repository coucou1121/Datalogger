#include "errorMessage.h"
#include "ui_errorMessage.h"

ErrorMessage::ErrorMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorMessage)
{
    ui->setupUi(this);

    //initialise the Key - Value for error
    _errorListPossible = GlobalEnumatedAndExtern::initErrorPossible();
}

ErrorMessage::~ErrorMessage()
{
    delete ui;
}

void ErrorMessage::_setColor(bool inTrouble)
{
    if(inTrouble)
    {
        //setup sample / second frame
        ui->label->setStyleSheet("background-color:" + _myStyle.getBackGroundColorErrorFrame().name()+ ";");
        ui->line->setStyleSheet("background-color:" + _myStyle.getErrorLineInTrouble().name()+ ";");
    }
    else
    {
        //setup sample / second frame
        ui->label->setStyleSheet("background-color:" + _myStyle.getBackGroundColor().name()+ ";");
        ui->line->setStyleSheet("background-color:" + _myStyle.getBackGroundColorBottomBar().name()+ ";");
    }
}

void ErrorMessage::_reveivedError(int errorNumber, bool active)
{
    qDebug() << objectName() << "recievedError :" << errorNumber << ", " << active;

    if(active)
    {
        _errorListNow.insert(errorNumber,_errorListPossible[errorNumber]);
    }
    else
    {
        _errorListNow.remove(errorNumber);
    }
    this->_displayMessage();
}

void ErrorMessage::_displayMessage()
{
    qDebug() << "nb error :" << _errorListNow.size();

    if(_errorListNow.isEmpty())
    {
        this->_setColor(false);
        ui->label->setText(_errorListPossible[GlobalEnumatedAndExtern::noError]);
    }
    else
    {
        this->_setColor(true);
        //update all traces
        for(auto e : _errorListNow.keys())
        {
            ui->label->setText(_errorListNow[e]);
        }
    }
}
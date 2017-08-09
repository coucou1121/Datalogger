#include "settingTriggerFunction.h"
#include "ui_settingTriggerFunction.h"

extern QString opNoneTxt;
extern QString opOrTxt;
extern QString opAndTxt;
extern QString opNotOrTxt;
extern QString opNoTAnd;

SettingTriggerFunction::SettingTriggerFunction(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingTriggerFunction)
{
    ui->setupUi(this);

    //initialise the Key - Value for combobx
    TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    // setup the style
    this->setupStyle();

    // add all logical operator in all comboboxes
    this->setupLogicalCombobox(ui->comboBoxTopMiddle);
    this->setupLogicalCombobox(ui->comboBoxMiddle);
    this->setupLogicalCombobox(ui->comboBoxBottomMiddle);

    // add "none" of all trace comboboxes
    this->setupTraceCombobox();

    //set no trace selected
    this->_areSomeTraceSelected = false;

}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
}

bool SettingTriggerFunction::areSomeTraceSelected() const
{
    return _areSomeTraceSelected;
}

void SettingTriggerFunction::setupStyle()
{
    ui->labelTitleTriggerFunction->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                 "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");
}

void SettingTriggerFunction::setupTraceCombobox()
{
    ui->comboBoxTopLeft->addItem(TriggerTracePossible[0]);
    ui->comboBoxTopRight->addItem(TriggerTracePossible[0]);
    ui->comboBoxBottomLeft->addItem(TriggerTracePossible[0]);
    ui->comboBoxBottomRight->addItem(TriggerTracePossible[0]);
}

void SettingTriggerFunction::setupLogicalCombobox(QComboBox *combobox)
{
    combobox->addItem(opNoneTxt);
    combobox->addItem(opOrTxt);
    combobox->addItem(opAndTxt);
    combobox->addItem(opNotOrTxt);
    combobox->addItem(opNoTAnd);
}

void SettingTriggerFunction::updateCombobox()
{
    int nbItem = 0;
    //empty the combobox
    ui->comboBoxTopLeft->clear();
    ui->comboBoxTopRight->clear();
    ui->comboBoxBottomLeft->clear();
    ui->comboBoxBottomRight->clear();

    //add "none"
    this->setupTraceCombobox();

    //update all traces
    for(auto e : TriggerTraceSelected.keys())
    {
        ui->comboBoxTopLeft->addItem(TriggerTraceSelected[e], e);
        ui->comboBoxTopRight->addItem(TriggerTraceSelected[e], e);
        ui->comboBoxBottomLeft->addItem(TriggerTraceSelected[e], e);
        ui->comboBoxBottomRight->addItem(TriggerTraceSelected[e], e);
        nbItem++;
    }
    //set if are some selected trace
    _areSomeTraceSelected = nbItem == 0 ? false : true;

    qDebug() << objectName() << "areSomeTraceSelected" << _areSomeTraceSelected;
}

void SettingTriggerFunction::_comboboxAddItem(int buttonNumber)
{
    //if its DI1 -> DI4, AI1 and AI2
    if(     buttonNumber < GlobalEnumatedAndExtern::btDI5 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI1 ||
            buttonNumber == GlobalEnumatedAndExtern::btAI2)
    {
        TriggerTraceSelected[buttonNumber] = TriggerTracePossible[buttonNumber];
        this->updateCombobox();
    }

}

void SettingTriggerFunction::_comboboxRevmoveItem(int buttonNumber)
{
    TriggerTraceSelected.remove(buttonNumber);
    this->updateCombobox();
}

void SettingTriggerFunction::_comboBoxTopLeft_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopLeft received index changed : " << index;
    ui->comboBoxTopLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxTopRight_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopRight received index changed : " << index;
    ui->comboBoxTopRight->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomLeft_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomLeft received index changed : " << index;
    ui->comboBoxBottomLeft->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomRight_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomRight received index changed : " << index;
    ui->comboBoxBottomRight->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxTopMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxTopMiddle received index changed : " << index;
    ui->comboBoxTopMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxMiddle received index changed : " << index;
    ui->comboBoxMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::_comboBoxBottomMiddle_currentIndexChanged(int index)
{
    //    qDebug()<< objectName() << " comboBoxBottomMiddle received index changed : " << index;
    ui->comboBoxBottomMiddle->setCurrentIndex(index);
}

void SettingTriggerFunction::on_comboBoxTopLeft_currentIndexChanged(int index)
{
    emit _comboBoxTopLeft_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxTopRight_currentIndexChanged(int index)
{
    emit _comboBoxTopRight_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomLeft_currentIndexChanged(int index)
{
    emit _comboBoxBottomLeft_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomRight_currentIndexChanged(int index)
{
    emit _comboBoxBottomRight_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxTopMiddle_currentIndexChanged(int index)
{
    emit _comboBoxTopMiddle_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxMiddle_currentIndexChanged(int index)
{
    emit _comboBoxMiddle_currentIndexWasChanged(index);
}

void SettingTriggerFunction::on_comboBoxBottomMiddle_currentIndexChanged(int index)
{
    emit _comboBoxBottomMiddle_currentIndexWasChanged(index);
}

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
    TriggerTracePossible = GlobalEnumated::initTriggerTracePossible();

    // setup the style
    this->setupStyle();

    // add all logical operator in all comboboxes
    this->setupLogicalCombobox(ui->comboBoxTopMiddle);
    this->setupLogicalCombobox(ui->comboBoxMiddle);
    this->setupLogicalCombobox(ui->comboBottomMiddle);

    // add "none" of all trace comboboxes
    this->setupTraceCombobox();

}

SettingTriggerFunction::~SettingTriggerFunction()
{
    delete ui;
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
    }
}

void SettingTriggerFunction::_comboboxAddItem(int buttonNummer)
{
    TriggerTraceSelected[buttonNummer] = TriggerTracePossible[buttonNummer];
    this->updateCombobox();
}

void SettingTriggerFunction::_comboboxRevmoveItem(int buttonNummer)
{
    TriggerTraceSelected.remove(buttonNummer);
    this->updateCombobox();
}

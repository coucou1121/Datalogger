#include "settingTriggerSetting.h"
#include "ui_settingTriggerSetting.h"

extern QString range0_24Txt;
extern QString range0_30Txt;
extern QString range15_15Txt;

SettingTriggerSetting::SettingTriggerSetting(QWidget *parent) :
    QFrame(parent),
    _pixmapFallingEdge(":/images/FollingEdge.png"),
    _pixmapRisingEdge(":/images/RisingEdge.png"),
    ui(new Ui::SettingTriggerSetting)
{
    ui->setupUi(this);
    setupStyle();
}

void SettingTriggerSetting::setupStyle()
{
    ui->labelTitleTriggerSetting->setStyleSheet("background-color:" + _myStyle.getBackGroundColorButtonStatusbarSelected().name() +
                                                "; color:" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() + ";");


    //set defaut value for trigger setting
    ui->pushButtonRangeDI1->setText(range0_24Txt);
    ui->pushButtonRangeDI2->setText(range0_24Txt);
    ui->pushButtonRangeDI3->setText(range0_24Txt);
    ui->pushButtonRangeDI4->setText(range0_24Txt);
    ui->pushButtonRangeAI1->setText(range0_30Txt);
    ui->pushButtonRangeAI2->setText(range0_30Txt);
    ui->pushButtonRangeAI3->setText(range0_30Txt);
    ui->pushButtonRangeAI4->setText(range0_30Txt);

    //set backgroud of all buttom
    ui->pushButtonRangeDI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeDI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeDI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeDI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeAI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeAI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeAI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonRangeAI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                          "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                          ", stop: 0 #ffffff);");
    ui->pushButtonEdgeDI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");
    ui->pushButtonEdgeDI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");
    ui->pushButtonEdgeDI3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");
    ui->pushButtonEdgeDI4->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");
    ui->pushButtonEdgeAI1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");
    ui->pushButtonEdgeAI2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                         "stop: 1" + _myStyle.getBackGroundColorButtonStatusbarUnselected().name() +
                                         ", stop: 0 #ffffff);");

    //set default edge value
    _btDI1Edge = GlobalEnumated::risingEdge;
    _btDI2Edge = GlobalEnumated::risingEdge;
    _btDI3Edge = GlobalEnumated::risingEdge;
    _btDI4Edge = GlobalEnumated::risingEdge;
    _btAI1Edge = GlobalEnumated::risingEdge;
    _btAI2Edge = GlobalEnumated::risingEdge;

    //set the picure on push button egge
    this->setEdgeIcon(ui->pushButtonEdgeDI1, _btDI1Edge);
    this->setEdgeIcon(ui->pushButtonEdgeDI2, _btDI2Edge);
    this->setEdgeIcon(ui->pushButtonEdgeDI3, _btDI3Edge);
    this->setEdgeIcon(ui->pushButtonEdgeDI4, _btDI4Edge);
    this->setEdgeIcon(ui->pushButtonEdgeAI1, _btAI1Edge);
    this->setEdgeIcon(ui->pushButtonEdgeAI2, _btAI2Edge);

    //set doublespinbox shape
    //setup style all spinbox
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI1);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI2);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI3);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI4);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxAI1);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxAI2);
}

SettingTriggerSetting::~SettingTriggerSetting()
{
    delete ui;
}

void SettingTriggerSetting::on_pushButtonRangeDI1_released()
{

    static GlobalEnumated::eRangeValue selection;

    selection = selection == GlobalEnumated::range0_24 ? GlobalEnumated::range0_24 : GlobalEnumated::range0_24;

    if(selection == GlobalEnumated::range0_24)
    {
        ui->pushButtonRangeDI1->setText(range0_24Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeDI2_released()
{
    static GlobalEnumated::eRangeValue selection;

    selection = selection == GlobalEnumated::range0_24 ? GlobalEnumated::range0_24 : GlobalEnumated::range0_24;

    if(selection == GlobalEnumated::range0_24)
    {
        ui->pushButtonRangeDI2->setText(range0_24Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeDI3_released()
{
    static GlobalEnumated::eRangeValue selection;

    selection = selection == GlobalEnumated::range0_24 ? GlobalEnumated::range0_24 : GlobalEnumated::range0_24;

    if(selection == GlobalEnumated::range0_24)
    {
        ui->pushButtonRangeDI3->setText(range0_24Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeDI4_released()
{
    static GlobalEnumated::eRangeValue selection;

    selection = selection == GlobalEnumated::range0_24 ? GlobalEnumated::range0_24 : GlobalEnumated::range0_24;

    if(selection == GlobalEnumated::range0_24)
    {
        ui->pushButtonRangeDI4->setText(range0_24Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeAI1_released()
{
    static GlobalEnumated::eRangeValue selection;

    if(ui->pushButtonRangeAI1->text() == range0_30Txt)
    {
        selection = GlobalEnumated::range0_30;
    }
    else
    {
        selection = GlobalEnumated::range15_15;
    }

    selection = selection == GlobalEnumated::range0_30 ? GlobalEnumated::range15_15 : GlobalEnumated::range0_30;

    if(selection == GlobalEnumated::range0_30)
    {
        ui->pushButtonRangeAI1->setText(range0_30Txt);
    }
    if(selection == GlobalEnumated::range15_15)
    {
        ui->pushButtonRangeAI1->setText(range15_15Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeAI2_released()
{
    GlobalEnumated::eRangeValue selection;

    //check the state
    if(ui->pushButtonRangeAI2->text() == range0_30Txt)
    {
        selection = GlobalEnumated::range0_30;
    }
    else
    {
        selection = GlobalEnumated::range15_15;
    }

    selection = selection == GlobalEnumated::range0_30 ? GlobalEnumated::range15_15 : GlobalEnumated::range0_30;

    //swap the state
    if(selection == GlobalEnumated::range0_30)
    {
        ui->pushButtonRangeAI2->setText(range0_30Txt);
    }
    if(selection == GlobalEnumated::range15_15)
    {
        ui->pushButtonRangeAI2->setText(range15_15Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeAI3_released()
{
    GlobalEnumated::eRangeValue selection;

    //check the state
    if(ui->pushButtonRangeAI3->text() == range0_30Txt)
    {
        selection = GlobalEnumated::range0_30;
    }
    else
    {
        selection = GlobalEnumated::range15_15;
    }

    selection = selection == GlobalEnumated::range0_30 ? GlobalEnumated::range15_15 : GlobalEnumated::range0_30;

    //swap the state
    if(selection == GlobalEnumated::range0_30)
    {
        ui->pushButtonRangeAI3->setText(range0_30Txt);
    }
    if(selection == GlobalEnumated::range15_15)
    {
        ui->pushButtonRangeAI3->setText(range15_15Txt);
    }
}

void SettingTriggerSetting::on_pushButtonRangeAI4_released()
{
    GlobalEnumated::eRangeValue selection;

    //check the state
    if(ui->pushButtonRangeAI4->text() == range0_30Txt)
    {
        selection = GlobalEnumated::range0_30;
    }
    else
    {
        selection = GlobalEnumated::range15_15;
    }

    selection = selection == GlobalEnumated::range0_30 ? GlobalEnumated::range15_15 : GlobalEnumated::range0_30;

    //swap the state
    if(selection == GlobalEnumated::range0_30)
    {
        ui->pushButtonRangeAI4->setText(range0_30Txt);
    }
    if(selection == GlobalEnumated::range15_15)
    {
        ui->pushButtonRangeAI4->setText(range15_15Txt);
    }
}

void SettingTriggerSetting::on_pushButtonEdgeDI1_released()
{
    _btDI1Edge = _btDI1Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeDI1, _btDI1Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI2_released()
{
    _btDI2Edge = _btDI2Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeDI2, _btDI2Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI3_released()
{
    _btDI3Edge = _btDI3Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeDI3, _btDI3Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI4_released()
{
    _btDI4Edge = _btDI4Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeDI4, _btDI4Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeAI1_released()
{
    _btAI1Edge = _btAI1Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeAI1, _btAI1Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeAI2_released()
{
    _btAI2Edge = _btAI2Edge == GlobalEnumated::risingEdge ? GlobalEnumated::fallingEdge : GlobalEnumated::risingEdge;
    this->setEdgeIcon(ui->pushButtonEdgeAI2, _btAI2Edge);
}

void SettingTriggerSetting::setEdgeIcon(QPushButton *pushbutton, GlobalEnumated::eEdge edgeType)
{
    if(edgeType == GlobalEnumated::fallingEdge)
    {
        pushbutton->setIcon(_pixmapFallingEdge);
    }
    if(edgeType == GlobalEnumated::risingEdge)
    {
        pushbutton->setIcon(_pixmapRisingEdge);
    }
    pushbutton->setIconSize(QSize(40,40));
}

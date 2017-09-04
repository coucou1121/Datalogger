#include "settingTriggerSetting.h"
#include "ui_settingTriggerSetting.h"

extern QString range0_24Txt;
extern QString range0_30Txt;
extern QString range15_15Txt;

extern qint8 minRange0;
extern qint8 maxRange0_24;
extern qint8 maxRange0_30;
extern qint8 minRange_15_15;
extern qint8 maxRange_15_15;

SettingTriggerSetting::SettingTriggerSetting(QWidget *parent) :
    QFrame(parent),
    _pixmapFallingEdge(":/images/FollingEdge.png"),
    _pixmapRisingEdge(":/images/RisingEdge.png"),
    _pixmapNoEdge(":/images/StateStop.png"),
    ui(new Ui::SettingTriggerSetting)
{
    ui->setupUi(this);

    //set value of the trigger funtion to 0
    _triggerSetting = new TriggerFunctions();

    //initialise the Key - Value for combobx
    _triggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

    //setup style
    setupStyle();

    //unselect all trace
    this->_DI1select(false);
    this->_DI2select(false);
    this->_DI3select(false);
    this->_DI4select(false);
    this->_AI1select(false);
    this->_AI2select(false);
    this->_AI3select(false);
    this->_AI4select(false);
}

void SettingTriggerSetting::setupStyle()
{
    CommonStyle::setbackGroundColorLabel(ui->labelTitleTriggerSetting);

    //set label text
    ui->labelDI1->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI1]);
    ui->labelDI2->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI2]);
    ui->labelDI3->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI3]);
    ui->labelDI4->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btDI4]);
    ui->labelAI1->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI1]);
    ui->labelAI2->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI2]);
    ui->labelAI3->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI3]);
    ui->labelAI4->setText(_triggerTracePossible[GlobalEnumatedAndExtern::btAI4]);

    //set defaut value for trigger setting
    ui->pushButtonRangeDI1->setText(range0_24Txt);
    ui->pushButtonRangeDI2->setText(range0_24Txt);
    ui->pushButtonRangeDI3->setText(range0_24Txt);
    ui->pushButtonRangeDI4->setText(range0_24Txt);
    ui->pushButtonRangeAI1->setText(range0_30Txt);
    ui->pushButtonRangeAI2->setText(range0_30Txt);
    ui->pushButtonRangeAI3->setText(range0_30Txt);
    ui->pushButtonRangeAI4->setText(range0_30Txt);

    this->_rangeDI1 = GlobalEnumatedAndExtern::range0_24;
    this->_rangeDI2 = GlobalEnumatedAndExtern::range0_24;
    this->_rangeDI3 = GlobalEnumatedAndExtern::range0_24;
    this->_rangeDI4 = GlobalEnumatedAndExtern::range0_24;
    this->_rangeAI1 = GlobalEnumatedAndExtern::range0_30;
    this->_rangeAI2 = GlobalEnumatedAndExtern::range0_30;
    this->_rangeAI3 = GlobalEnumatedAndExtern::range0_30;
    this->_rangeAI4 = GlobalEnumatedAndExtern::range0_30;

    //set backgroud of all buttom
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI1);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI2);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI3);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI4);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI1);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI2);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI3);
    CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI4);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI1);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI2);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI3);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI4);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeAI1);
    CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeAI2);

    //set default edge value
    _btDI1Edge = GlobalEnumatedAndExtern::risingEdge;
    _btDI2Edge = GlobalEnumatedAndExtern::risingEdge;
    _btDI3Edge = GlobalEnumatedAndExtern::risingEdge;
    _btDI4Edge = GlobalEnumatedAndExtern::risingEdge;
    _btAI1Edge = GlobalEnumatedAndExtern::risingEdge;
    _btAI2Edge = GlobalEnumatedAndExtern::risingEdge;

    //set the picure on push button egge
    this->_setEdgeIcon(ui->pushButtonEdgeDI1, _btDI1Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI2, _btDI2Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI3, _btDI3Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI4, _btDI4Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeAI1, _btAI1Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeAI2, _btAI2Edge);

    //set doublespinbox shape
    //setup style all spinbox
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI1);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI2);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI3);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxDI4);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxAI1);
    _myStyle.setDoublespinBoxShape(ui->doubleSpinBoxAI2);
}

TriggerFunctions *SettingTriggerSetting::triggerSetting() const
{
    return _triggerSetting;
}

SettingTriggerSetting::~SettingTriggerSetting()
{
    delete ui;
}

void SettingTriggerSetting::on_pushButtonRangeDI1_released()
{

}

void SettingTriggerSetting::on_pushButtonRangeDI2_released()
{

}

void SettingTriggerSetting::on_pushButtonRangeDI3_released()
{

}

void SettingTriggerSetting::on_pushButtonRangeDI4_released()
{

}

void SettingTriggerSetting::on_pushButtonRangeAI1_released()
{
    GlobalEnumatedAndExtern::eRangeValue selection;
    //swap range
    selection = ui->pushButtonRangeAI1->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;

    //configur widget
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI1, selection);

    //memorise the range
    this->_rangeAI1 = selection;

    emit _pushButtonRangeAI1WasChanged();
    emit _pushButtonRangeAI1TXTWasChanged(ui->pushButtonRangeAI1->text());
}

void SettingTriggerSetting::on_pushButtonRangeAI2_released()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap range
    selection = ui->pushButtonRangeAI2->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;

    //configure widget
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI2, selection);

    emit _pushButtonRangeAI2WasChanged();
    emit _pushButtonRangeAI2TXTWasChanged(ui->pushButtonRangeAI2->text());
}

void SettingTriggerSetting::on_pushButtonRangeAI3_released()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap range
    selection = ui->pushButtonRangeAI3->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;

    //configur widget
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI3, selection);

    emit _pushButtonRangeAI3WasChanged();
    emit _pushButtonRangeAI3TXTWasChanged(ui->pushButtonRangeAI3->text());
}

void SettingTriggerSetting::on_pushButtonRangeAI4_released()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap range
    selection = ui->pushButtonRangeAI4->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;

    //configur widget
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI4, selection);

    emit _pushButtonRangeAI4WasChanged();
    emit _pushButtonRangeAI4TXTWasChanged(ui->pushButtonRangeAI4->text());
}

void SettingTriggerSetting::on_pushButtonEdgeDI1_released()
{
    switch (_btDI1Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btDI1Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btDI1Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btDI1Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeDI1, _btDI1Edge);
    this->_triggerSetting->setBtDI1Edge(_btDI1Edge);
    emit _pushButtonEdgeDI1WasChanged((int)_btDI1Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI2_released()
{
    switch (_btDI2Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btDI2Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btDI2Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btDI2Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeDI2, _btDI2Edge);
    this->_triggerSetting->setBtDI2Edge(_btDI2Edge);
    emit _pushButtonEdgeDI2WasChanged((int)_btDI2Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI3_released()
{
    switch (_btDI3Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btDI3Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btDI3Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btDI3Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeDI3, _btDI3Edge);
    this->_triggerSetting->setBtDI3Edge(_btDI3Edge);
    emit _pushButtonEdgeDI3WasChanged((int)_btDI3Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeDI4_released()
{
    switch (_btDI4Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btDI4Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btDI4Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btDI4Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeDI4, _btDI4Edge);
    this->_triggerSetting->setBtDI4Edge(_btDI4Edge);
    emit _pushButtonEdgeDI4WasChanged((int)_btDI4Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeAI1_released()
{
    switch (_btAI1Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btAI1Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btAI1Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btAI1Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeAI1, _btAI1Edge);
    this->_triggerSetting->setBtAI1Edge(_btAI1Edge);
    emit _pushButtonEdgeAI1WasChanged((int)_btAI1Edge);
}

void SettingTriggerSetting::on_pushButtonEdgeAI2_released()
{
    switch (_btAI2Edge)
    {
    case GlobalEnumatedAndExtern::risingEdge:
        _btAI2Edge = GlobalEnumatedAndExtern::fallingEdge;
        break;
    case GlobalEnumatedAndExtern::fallingEdge:
        _btAI2Edge = GlobalEnumatedAndExtern::noEdge;
        break;
    case GlobalEnumatedAndExtern::noEdge:
        _btAI2Edge = GlobalEnumatedAndExtern::risingEdge;
        break;
    default:
        break;
    }
    this->_setEdgeIcon(ui->pushButtonEdgeAI2, _btAI2Edge);
    this->_triggerSetting->setBtAI2Edge(_btAI2Edge);
    emit _pushButtonEdgeAI2WasChanged((int)_btAI2Edge);
}

void SettingTriggerSetting::_DI1select(bool btselected)
{
    ui->pushButtonRangeDI1->setEnabled(btselected);
    ui->doubleSpinBoxDI1->setEnabled(btselected);
    ui->pushButtonEdgeDI1->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeDI1);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeDI1);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI1);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI1);
    }
}

void SettingTriggerSetting::_DI2select(bool btselected)
{
    ui->pushButtonRangeDI2->setEnabled(btselected);
    ui->doubleSpinBoxDI2->setEnabled(btselected);
    ui->pushButtonEdgeDI2->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeDI2);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeDI2);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI2);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI2);
    }
}

void SettingTriggerSetting::_DI3select(bool btselected)
{
    ui->pushButtonRangeDI3->setEnabled(btselected);
    ui->doubleSpinBoxDI3->setEnabled(btselected);
    ui->pushButtonEdgeDI3->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeDI3);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeDI3);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI3);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI3);
    }
}

void SettingTriggerSetting::_DI4select(bool btselected)
{
    ui->pushButtonRangeDI4->setEnabled(btselected);
    ui->doubleSpinBoxDI4->setEnabled(btselected);
    ui->pushButtonEdgeDI4->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeDI4);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeDI4);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeDI4);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeDI4);
    }
}

void SettingTriggerSetting::_AI1select(bool btselected)
{
    ui->pushButtonRangeAI1->setEnabled(btselected);
    ui->doubleSpinBoxAI1->setEnabled(btselected);
    ui->pushButtonEdgeAI1->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeAI1);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeAI1);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI1);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeAI1);
    }
}

void SettingTriggerSetting::_AI2select(bool btselected)
{
    ui->pushButtonRangeAI2->setEnabled(btselected);
    ui->doubleSpinBoxAI2->setEnabled(btselected);
    ui->pushButtonEdgeAI2->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeAI2);
        CommonStyle::setBackGroundColor(ui->pushButtonEdgeAI2);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI2);
        CommonStyle::setPushButtonBlocked(ui->pushButtonEdgeAI2);
    }
}

void SettingTriggerSetting::_AI3select(bool btselected)
{
    ui->pushButtonRangeAI3->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeAI3);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI3);
    }
}

void SettingTriggerSetting::_AI4select(bool btselected)
{
    ui->pushButtonRangeAI4->setEnabled(btselected);

    if(btselected)
    {
        CommonStyle::setBackGroundColor(ui->pushButtonRangeAI4);
    }
    else
    {
        CommonStyle::setPushButtonBlocked(ui->pushButtonRangeAI4);
    }
}

void SettingTriggerSetting::setRangeAndTextTrace(GlobalEnumatedAndExtern::eTracePossible trace, GlobalEnumatedAndExtern::eRangeValue range)
{
    double minRangeValue = 0;
    double maxRangeValue = 0;
    QString rangeTxt = "";

    switch (range)
    {
    case GlobalEnumatedAndExtern::range0_24:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_24;
        rangeTxt = range0_24Txt;
        break;
    case GlobalEnumatedAndExtern::range0_30:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_30;
        rangeTxt = range0_30Txt;
        break;
    case GlobalEnumatedAndExtern::range15_15:
        minRangeValue = minRange_15_15;
        maxRangeValue = maxRange_15_15;
        rangeTxt = range15_15Txt;
        break;
    default:
        break;
    }

    switch (trace)
    {
    case GlobalEnumatedAndExtern::btDI1:
        ui->doubleSpinBoxDI1->setMinimum(minRangeValue);
        ui->doubleSpinBoxDI1->setMaximum(maxRangeValue);
        ui->pushButtonRangeDI1->setText(rangeTxt);
        this->_rangeDI1 = range;
        this->_triggerSetting->setDoubleSpinBoxDI4(_doubleToQuint8(ui->doubleSpinBoxDI1->value(), range));
        break;
    case GlobalEnumatedAndExtern::btDI2:
        ui->doubleSpinBoxDI2->setMinimum(minRangeValue);
        ui->doubleSpinBoxDI2->setMaximum(maxRangeValue);
        ui->pushButtonRangeDI2->setText(rangeTxt);
        this->_rangeDI2 = range;
        this->_triggerSetting->setDoubleSpinBoxDI4(_doubleToQuint8(ui->doubleSpinBoxDI2->value(), range));
        break;
    case GlobalEnumatedAndExtern::btDI3:
        ui->doubleSpinBoxDI3->setMinimum(minRangeValue);
        ui->doubleSpinBoxDI3->setMaximum(maxRangeValue);
        ui->pushButtonRangeDI3->setText(rangeTxt);
        this->_rangeDI3 = range;
        this->_triggerSetting->setDoubleSpinBoxDI4(_doubleToQuint8(ui->doubleSpinBoxDI3->value(), range));
        break;
    case GlobalEnumatedAndExtern::btDI4:
        ui->doubleSpinBoxDI4->setMinimum(minRangeValue);
        ui->doubleSpinBoxDI4->setMaximum(maxRangeValue);
        ui->pushButtonRangeDI4->setText(rangeTxt);
        this->_rangeDI4 = range;
        this->_triggerSetting->setDoubleSpinBoxDI4(_doubleToQuint8(ui->doubleSpinBoxDI4->value(), range));
        break;
    case GlobalEnumatedAndExtern::btAI1:
        ui->doubleSpinBoxAI1->setMinimum(minRangeValue);
        ui->doubleSpinBoxAI1->setMaximum(maxRangeValue);
        ui->pushButtonRangeAI1->setText(rangeTxt);
        this->_rangeAI1 = range;
        this->_triggerSetting->setDoubleSpinBoxAI1(_doubleToQuint8(ui->doubleSpinBoxAI1->value(), range));
        break;
    case GlobalEnumatedAndExtern::btAI2:
        ui->doubleSpinBoxAI2->setMinimum(minRangeValue);
        ui->doubleSpinBoxAI2->setMaximum(maxRangeValue);
        ui->pushButtonRangeAI2->setText(rangeTxt);
        this->_rangeAI2 = range;
        this->_triggerSetting->setDoubleSpinBoxAI2(_doubleToQuint8(ui->doubleSpinBoxAI2->value(), range));
        break;
    case GlobalEnumatedAndExtern::btAI3:
        ui->pushButtonRangeAI3->setText(rangeTxt);
        break;
    case GlobalEnumatedAndExtern::btAI4:
        ui->pushButtonRangeAI4->setText(rangeTxt);
        break;
    default:
        break;
    }
}

double SettingTriggerSetting::triggerValueAI2() const
{
    return _triggerValueAI2;
}

double SettingTriggerSetting::triggerValueAI1() const
{
    return _triggerValueAI1;
}

quint8 SettingTriggerSetting::_doubleToQuint8(double value, GlobalEnumatedAndExtern::eRangeValue range)
{
    qint8 minRangeValue = 0;
    qint8 maxRangeValue = 0;

    double result;

    switch (range)
    {
    case GlobalEnumatedAndExtern::range0_24:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_24;
        break;
    case GlobalEnumatedAndExtern::range0_30:
        minRangeValue = minRange0;
        maxRangeValue = maxRange0_30;
        break;
    case GlobalEnumatedAndExtern::range15_15:
        minRangeValue = minRange_15_15;
        maxRangeValue = maxRange_15_15;
         break;
    default:
        break;
    }
    result = ((value - minRangeValue)*255)/(maxRangeValue-minRangeValue);

//    qDebug() << "double value  : " << value;
//    qDebug() << "double result : " << minRangeValue << result;
    quint8 resultInt = (quint8)result;
    return resultInt;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeAI4() const
{
    return _rangeAI4;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeAI3() const
{
    return _rangeAI3;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeAI2() const
{
    return _rangeAI2;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeAI1() const
{
    return _rangeAI1;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeDI4() const
{
    return _rangeDI4;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeDI2() const
{
    return _rangeDI2;
}

GlobalEnumatedAndExtern::eRangeValue SettingTriggerSetting::rangeDI1() const
{
    return _rangeDI1;
}

void SettingTriggerSetting::_btSelected(quint8 buttonNumber, bool btSelected)
{
    switch(buttonNumber)
    {
    case GlobalEnumatedAndExtern::btDI1 :
        this->_DI1select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btDI2 :
        this->_DI2select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btDI3 :
        this->_DI3select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btDI4 :
        this->_DI4select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btAI1 :
        this->_AI1select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btAI2 :
        this->_AI2select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btAI3 :
        this->_AI3select(btSelected);
        break;
    case GlobalEnumatedAndExtern::btAI4 :
        this->_AI4select(btSelected);
        break;
    default:
        break;
    }
}

void SettingTriggerSetting::pushButtonRangeAI1_ChangeRange()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap the range
    selection = ui->pushButtonRangeAI1->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI1, selection);
}

void SettingTriggerSetting::pushButtonRangeAI2_ChangeRange()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap the range
    selection = ui->pushButtonRangeAI2->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI2, selection);
}

void SettingTriggerSetting::pushButtonRangeAI3_ChangeRange()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap the range
    selection = ui->pushButtonRangeAI3->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI3, selection);
}

void SettingTriggerSetting::pushButtonRangeAI4_ChangeRange()
{
    GlobalEnumatedAndExtern::eRangeValue selection;

    //swap the range
    selection = ui->pushButtonRangeAI4->text() == range0_30Txt ? GlobalEnumatedAndExtern::range15_15 : GlobalEnumatedAndExtern::range0_30;
    setRangeAndTextTrace(GlobalEnumatedAndExtern::btAI4, selection);
}

void SettingTriggerSetting::pushButtonEdgeDI1_changeEdge(quint8 eEdge)
{
    _btDI1Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtDI1Edge(_btDI1Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI1, _btDI1Edge);
}

void SettingTriggerSetting::pushButtonEdgeDI2_changeEdge(quint8 eEdge)
{
    _btDI2Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtDI2Edge(_btDI2Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI2, _btDI2Edge);
}

void SettingTriggerSetting::pushButtonEdgeDI3_changeEdge(quint8 eEdge)
{
    _btDI3Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtDI3Edge(_btDI3Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI3, _btDI3Edge);
}

void SettingTriggerSetting::pushButtonEdgeDI4_changeEdge(quint8 eEdge)
{
    _btDI4Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtDI4Edge(_btDI4Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeDI4, _btDI4Edge);
}

void SettingTriggerSetting::pushButtonEdgeAI1_changeEdge(quint8 eEdge)
{
    _btAI1Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtAI1Edge(_btAI1Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeAI1, _btAI1Edge);
}

void SettingTriggerSetting::pushButtonEdgeAI2_changeEdge(quint8 eEdge)
{
    _btAI2Edge = (GlobalEnumatedAndExtern::eEdge)eEdge;
    this->_triggerSetting->setBtAI2Edge(_btAI2Edge);
    this->_setEdgeIcon(ui->pushButtonEdgeAI2, _btAI2Edge);
}

void SettingTriggerSetting::doubleSpinBoxDI1_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxDI1(_doubleToQuint8(value, _rangeDI1));
    ui->doubleSpinBoxDI1->setValue(value);
}

void SettingTriggerSetting::doubleSpinBoxDI2_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxDI2(_doubleToQuint8(value, _rangeDI2));
    ui->doubleSpinBoxDI2->setValue(value);
}

void SettingTriggerSetting::doubleSpinBoxDI3_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxDI3(_doubleToQuint8(value, _rangeDI3));
    ui->doubleSpinBoxDI3->setValue(value);
}

void SettingTriggerSetting::doubleSpinBoxDI4_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxDI4(_doubleToQuint8(value, _rangeDI4));
    ui->doubleSpinBoxDI4->setValue(value);
}

void SettingTriggerSetting::doubleSpinBoxAI1_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxAI1(_doubleToQuint8(value, _rangeAI1));
    this->_triggerValueAI1 = ui->doubleSpinBoxAI1->value();
    ui->doubleSpinBoxAI1->setValue(value);
}

void SettingTriggerSetting::doubleSpinBoxAI2_changeValue(double value)
{
    this->_triggerSetting->setDoubleSpinBoxAI2(_doubleToQuint8(value, _rangeAI2));
    this->_triggerValueAI2 = ui->doubleSpinBoxAI2->value();
    ui->doubleSpinBoxAI2->setValue(value);
}

void SettingTriggerSetting::_setEdgeIcon(QPushButton *pushbutton, GlobalEnumatedAndExtern::eEdge edgeType)
{
    if(edgeType == GlobalEnumatedAndExtern::fallingEdge)
    {
        pushbutton->setIcon(_pixmapFallingEdge);
    }
    if(edgeType == GlobalEnumatedAndExtern::risingEdge)
    {
        pushbutton->setIcon(_pixmapRisingEdge);
    }
    if(edgeType == GlobalEnumatedAndExtern::noEdge)
    {
        pushbutton->setIcon(_pixmapNoEdge);
    }
    pushbutton->setIconSize(QSize(30,30));
}

void SettingTriggerSetting::on_doubleSpinBoxDI1_valueChanged(double value)
{
    emit _doubleSpinBoxDI1_valueWasChanged(value);
}

void SettingTriggerSetting::on_doubleSpinBoxDI2_valueChanged(double value)
{
    emit _doubleSpinBoxDI2_valueWasChanged(value);
}

void SettingTriggerSetting::on_doubleSpinBoxDI3_valueChanged(double value)
{
    emit _doubleSpinBoxDI3_valueWasChanged(value);
}

void SettingTriggerSetting::on_doubleSpinBoxDI4_valueChanged(double value)
{
    emit _doubleSpinBoxDI4_valueWasChanged(value);
}

void SettingTriggerSetting::on_doubleSpinBoxAI1_valueChanged(double value)
{
    emit _doubleSpinBoxAI1_valueWasChanged(value);
}

void SettingTriggerSetting::on_doubleSpinBoxAI2_valueChanged(double value)
{
    emit _doubleSpinBoxAI2_valueWasChanged(value);
}

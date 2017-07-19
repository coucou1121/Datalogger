#ifndef SETTINGCHANNELSELECTION_H
#define SETTINGCHANNELSELECTION_H

#include <QDebug>
#include <QFrame>
#include <QPushButton>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class SettingChannelSelection;
}

class SettingChannelSelection : public QFrame
{
    Q_OBJECT

public:
    explicit SettingChannelSelection(QWidget *parent = 0);
    ~SettingChannelSelection();

private:
    Ui::SettingChannelSelection *ui;

    //variable for commum style for getting acces of all color and shape
    CommonStyle _myStyle;

    //set the color and shape of this windows
    void setupStyle();

    //set the background color of all push button on UI
    void setupUILayout();

    //set the label of all push button on UI
    void setupLabel();

    //setup shap and background of the push button
    void setupButton(QPushButton *pushbutton, QColor btColor);

    //setup background color of the push button
    void setupButtonBackGround(QPushButton *pushbutton, QColor btSelectedColor, bool btSelected);

    //key value for pushbutton name
    QMap<int, QString> TriggerTracePossible;

    //generic emit signal for all button
    void emitBtdSignal(int buttonNumber, bool btSelected);

private slots:
    void on_btDI1_released();
    void on_btDI2_released();
    void on_btDI3_released();
    void on_btDI4_released();
    void on_btDI5_released();
    void on_btDI6_released();
    void on_btDI7_released();
    void on_btDI8_released();
    void on_btDI9_released();
    void on_btDI10_released();
    void on_btDI11_released();
    void on_btDI12_released();
    void on_btDI13_released();
    void on_btDI14_released();
    void on_btDI15_released();
    void on_btDI16_released();
    void on_btAI1_released();
    void on_btAI2_released();
    void on_btAI3_released();
    void on_btAI4_released();

signals:

    //send if button is seleced or not
    void _btSeleccted(int buttonNumber, bool btSelected);

    void _btDI1Selected(bool btSelected);
    void _btDI2Selected(bool btSelected);
    void _btDI3Selected(bool btSelected);
    void _btDI4Selected(bool btSelected);
    void _btDI5Selected(bool btSelected);
    void _btDI6Selected(bool btSelected);
    void _btDI7Selected(bool btSelected);
    void _btDI8Selected(bool btSelected);
    void _btDI9Selected(bool btSelected);
    void _btDI10Selected(bool btSelected);
    void _btDI11Selected(bool btSelected);
    void _btDI12Selected(bool btSelected);
    void _btDI13Selected(bool btSelected);
    void _btDI14Selected(bool btSelected);
    void _btDI15Selected(bool btSelected);
    void _btDI16Selected(bool btSelected);

    void _btAI1Selected(bool btSelected);
    void _btAI2Selected(bool btSelected);
    void _btAI3Selected(bool btSelected);
    void _btAI4Selected(bool btSelected);

    //add button in all trigger function combobox
    void _btAddList(int buttonNummer);
    void _btDI2AddList(int buttonNummer);
    void _btDI3AddList(int buttonNummer);
    void _btDI4AddList(int buttonNummer);
    void _btAI1AddList(int buttonNummer);
    void _btAI2AddList(int buttonNummer);

    //remove button in all trigger function combobox
    void _btRemoveList(int buttonNummer);
    void _btDI2RemoveList(int buttonNummer);
    void _btDI3RemoveList(int buttonNummer);
    void _btDI4RemoveList(int buttonNummer);
    void _btAI1RemoveList(int buttonNummer);
    void _btAI2RemoveList(int buttonNummer);

    //add trace in trigger setting
    void _addTrace(int enumTrace);

    //remove trace in trigger setting
    void _removeTrace(int enumTrace);
};

#endif // SETTINGCHANNELSELECTION_H

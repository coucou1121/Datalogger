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

    //check if there is minimum one selected trace
    void _checkIfAreSelectedTrace();

private:
    Ui::SettingChannelSelection *ui;

    //variable for commum style for getting acces of all color and shape
    CommonStyle _myStyle;

    //quantity of selected trace
    quint8 _sumOfSelectedTrace;

    //quantity of trigger selected trace
    quint8 _sumOfTriggerSelectedTrace;

    //set the color and shape of this windows
    void _setupStyle();

    //set the background color of all push button on UI
    void _setupUILayout();

    //set the label of all push button on UI
    void _setupLabel();

    //setup background color of the push button
    void _setupButtonBackGround(QPushButton *pushbutton, GlobalEnumatedAndExtern::eTracePossible trace , bool btSelected);

    //key value for pushbutton name
    QMap<int, QString> _triggerTracePossible;

    //generic emit signal for all button
    void emitBtSignal(int buttonNumber, bool btSelected);



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

    //button pushed
    void _btSeleccted(quint8 buttonNumber, bool btSelected);

    //add button in all trigger function combobox
    void _btAddList(quint8 buttonNummer);

    //remove button in all trigger function combobox
    void _btRemoveList(quint8 buttonNummer);

    //add trace in trigger setting
    void _addTrace(quint8 enumTrace);

    //remove trace in trigger setting
    void _removeTrace(quint8 enumTrace);

    //error no selected trace
    void _errorNoSelectedTrace(quint8 errorNumber, bool noSelecetTrace);

    //error no selected trigger trace
    void _errorNoSelectedTriggerTrace(quint8 errorNumber, bool noSelectedTriggerTrace);
};

#endif // SETTINGCHANNELSELECTION_H

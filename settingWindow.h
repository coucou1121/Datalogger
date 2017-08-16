#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "commonStyle.h"
#include "triggerFunctions.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();

    bool triggerFunctionEnable() const;

    TriggerFunctions *getTriggerFuntion();

private:
    Ui::SettingWindow *ui;
    CommonStyle _myStyle;

    //setup signal and slot
    void _setupSignalAndSlot();

    //trigger function enable
    bool _triggerFunctionEnable;

    //trigger function setting
    TriggerFunctions *_triggerFunction;

    //trigger setting
    TriggerFunctions *_triggerSetting;

    //double to int converter
    quint8 doubleToQint8(double value, GlobalEnumatedAndExtern::eRangeValue range);

public slots:
    void _recievedNbFrameSavedChanged(quint64 nbFrameChanged);
    void _recievedSizeFrameChange(int frameSize);
    void _recievedFTDIBaudrateChange(int FTDIBaudrate);

    void enableWindows(bool enableState);

    void pushButtonRangeAI1_changeRange();
    void pushButtonRangeAI2_changeRange();

    void pushButtonEdgeDI1_changeEdge(int eEdge);
    void pushButtonEdgeDI2_changeEdge(int eEdge);
    void pushButtonEdgeDI3_changeEdge(int eEdge);
    void pushButtonEdgeDI4_changeEdge(int eEdge);
    void pushButtonEdgeAI1_changeEdge(int eEdge);
    void pushButtonEdgeAI2_changeEdge(int eEdge);

    void doubleSpinBoxDI1_changeValue(double value);
    void doubleSpinBoxDI2_changeValue(double value);
    void doubleSpinBoxDI3_changeValue(double value);
    void doubleSpinBoxDI4_changeValue(double value);
    void doubleSpinBoxAI1_changeValue(double value);
    void doubleSpinBoxAI2_changeValue(double value);

    void comboBoxTopLeft_changeCurrentIndex(int index);
    void comboBoxTopRight_changeCurrentIndex(int index);
    void comboBoxBottomLeft_changeCurrentIndex(int index);
    void comboBoxBottomRight_changeCurrentIndex(int index);
    void comboBoxTopMiddle_changeCurrentIndex(int index);
    void comboBoxMiddle_changeCurrentIndex(int index);
    void comboBoxBottomMiddle_changeCurrentIndex(int index);

private slots:
    void _recievedAddTraceFromChannelSelection(int traceNumber);
    void _recievedRemoveTraceFromChannelSelection(int traceNumber);
    void _recieved_errorFrequencyToLow(int errorNumber, bool active);
    void _received_errorWrongEquation(int errorNumber,bool active);

    void _recieved_pushButtonRangeAI1Changed();
    void _recieved_pushButtonRangeAI2Changed();

    void _recieved_pushButtonEdgeDI1Changed(int eEdge);
    void _recieved_pushButtonEdgeDI2Changed(int eEdge);
    void _recieved_pushButtonEdgeDI3Changed(int eEdge);
    void _recieved_pushButtonEdgeDI4Changed(int eEdge);
    void _recieved_pushButtonEdgeAI1Changed(int eEdge);
    void _recieved_pushButtonEdgeAI2Changed(int eEdge);

    void _recieved_doubleSpinBoxDI1_valueChanged(double value);
    void _recieved_doubleSpinBoxDI2_valueChanged(double value);
    void _recieved_doubleSpinBoxDI3_valueChanged(double value);
    void _recieved_doubleSpinBoxDI4_valueChanged(double value);
    void _recieved_doubleSpinBoxAI1_valueChanged(double value);
    void _recieved_doubleSpinBoxAI2_valueChanged(double value);

    void _recieved_ComboBoxTopLeft_currentIndexChanged(int index);
    void _recieved_ComboBoxTopRight_currentIndexChanged(int index);
    void _recieved_ComboBoxBottomLeft_currentIndexChanged(int index);
    void _recieved_ComboBoxBottomRight_currentIndexChanged(int index);
    void _recieved_ComboBoxTopMiddle_currentIndexChanged(int index);
    void _recieved_ComboBoxMiddle_currentIndexChanged(int index);
    void _recieved_ComboBoxBottomMiddle_currentIndexChanged(int index);

signals:
    void _addTraceInTriggerMenu(int traceNumber);
    void _removeTraceInTriggerMenu(int traceNumber);
    void _addTraceInDisplayMenu(int traceNumber);
    void _removeTraceInDisplayMenu(int traceNumber);
    void _nbFrameSavedChange(quint64 nbFrameChanges);
    void _sizeFrameChange(int frameSize);
    void _FTDIBaudrateChange(int FTDIBaudrate);
    void _errorFrequencyToLow(int errorNumber,bool active);
    void _errorWrongEquation(int errorNumber,bool active);

    void _pushButtonRangeAI1WasChangedFromSettingMenu();
    void _pushButtonRangeAI2WasChangedFromSettingMenu();

    void _pushButtonEdgeDI1WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI2WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI3WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI4WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeAI1WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeAI2WasChangedFromSettingMenu(int eEdge);

    void _doubleSpinBoxDI1_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI2_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI3_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI4_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxAI1_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxAI2_valueWasChangedFromSettingMenu(double value);

    void _comboBoxTopLeft_currentIndexWasChanged(int index);
    void _comboBoxTopRight_currentIndexWasChanged(int index);
    void _comboBoxBottomLeft_currentIndexWasChanged(int index);
    void _comboBoxBottomRight_currentIndexWasChanged(int index);
    void _comboBoxTopMiddle_currentIndexWasChanged(int index);
    void _comboBoxMiddle_currentIndexWasChanged(int index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(int index);

};

#endif // SETTINGWINDOW_H

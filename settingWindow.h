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

    //check if there is minimum one selected trace
    void checkIfAreSelectedTrace();

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
    void _received_NbFrameSavedChanged(quint64 nbFrameChanged);
    void _received_SizeFrameChange(int frameSize);
    void _received_FTDIBaudrateChange(int FTDIBaudrate);
    void _received_percentPreTriggerChanged(quint8 percent);

//    void enableWindows(bool enableState);

    void pushButtonRangeAI1_changeRange();
    void pushButtonRangeAI2_changeRange();

    void pushButtonEdgeDI1_changeEdge(quint8 eEdge);
    void pushButtonEdgeDI2_changeEdge(quint8 eEdge);
    void pushButtonEdgeDI3_changeEdge(quint8 eEdge);
    void pushButtonEdgeDI4_changeEdge(quint8 eEdge);
    void pushButtonEdgeAI1_changeEdge(quint8 eEdge);
    void pushButtonEdgeAI2_changeEdge(quint8 eEdge);

    void doubleSpinBoxDI1_changeValue(double value);
    void doubleSpinBoxDI2_changeValue(double value);
    void doubleSpinBoxDI3_changeValue(double value);
    void doubleSpinBoxDI4_changeValue(double value);
    void doubleSpinBoxAI1_changeValue(double value);
    void doubleSpinBoxAI2_changeValue(double value);

    void comboBoxTopLeft_changeCurrentIndex(quint8 index);
    void comboBoxTopRight_changeCurrentIndex(quint8 index);
    void comboBoxBottomLeft_changeCurrentIndex(quint8 index);
    void comboBoxBottomRight_changeCurrentIndex(quint8 index);
    void comboBoxTopMiddle_changeCurrentIndex(quint8 index);
    void comboBoxMiddle_changeCurrentIndex(quint8 index);
    void comboBoxBottomMiddle_changeCurrentIndex(quint8 index);

private slots:
    void _received_AddTraceFromChannelSelection(quint8 traceNumber);
    void _received_RemoveTraceFromChannelSelection(quint8 traceNumber);

    void _received_errorNoSelectedTrace(quint8 errorNumber, bool active);
    void _received_errorNoSectedTriggerTrace(quint8 errorNumber,bool active);
    void _received_errorFrequencyToLow(quint8 errorNumber, bool active);
    void _received_errorWrongEquation(quint8 errorNumber,bool active);

    void _received_pushButtonRangeAI1Changed();
    void _received_pushButtonRangeAI2Changed();

    void _received_pushButtonEdgeDI1Changed(quint8 eEdge);
    void _received_pushButtonEdgeDI2Changed(quint8 eEdge);
    void _received_pushButtonEdgeDI3Changed(quint8 eEdge);
    void _received_pushButtonEdgeDI4Changed(quint8 eEdge);
    void _received_pushButtonEdgeAI1Changed(quint8 eEdge);
    void _received_pushButtonEdgeAI2Changed(quint8 eEdge);

    void _received_doubleSpinBoxDI1_valueChanged(double value);
    void _received_doubleSpinBoxDI2_valueChanged(double value);
    void _received_doubleSpinBoxDI3_valueChanged(double value);
    void _received_doubleSpinBoxDI4_valueChanged(double value);
    void _received_doubleSpinBoxAI1_valueChanged(double value);
    void _received_doubleSpinBoxAI2_valueChanged(double value);

    void _received_ComboBoxTopLeft_currentIndexChanged(quint8 index);
    void _received_ComboBoxTopRight_currentIndexChanged(quint8 index);
    void _received_ComboBoxBottomLeft_currentIndexChanged(quint8 index);
    void _received_ComboBoxBottomRight_currentIndexChanged(quint8 index);
    void _received_ComboBoxTopMiddle_currentIndexChanged(quint8 index);
    void _received_ComboBoxMiddle_currentIndexChanged(quint8 index);
    void _received_ComboBoxBottomMiddle_currentIndexChanged(quint8 index);

signals:
    void _addTraceInTriggerMenu(quint8 traceNumber);
    void _removeTraceInTriggerMenu(quint8 traceNumber);
    void _addTraceInDisplayMenu(quint8 traceNumber);
    void _removeTraceInDisplayMenu(quint8 traceNumber);
    void _nbFrameSavedChange(quint64 nbFrameChanges);
    void _sizeFrameChange(int frameSize);
    void _FTDIBaudrateChange(int FTDIBaudrate);
    void _percentPreTriggerWasChanged(quint8 percent);

    void _errorNoSelectedTrace(quint8 errorNumber, bool active);
    void _errorNoSelectedTriggerTrace(quint8 errorNumber, bool active);
    void _errorFrequencyToLow(quint8 errorNumber,bool active);
    void _errorWrongEquation(quint8 errorNumber,bool active);

    void _pushButtonRangeAI1WasChangedFromSettingMenu();
    void _pushButtonRangeAI2WasChangedFromSettingMenu();

    void _pushButtonEdgeDI1WasChangedFromSettingMenu(quint8 eEdge);
    void _pushButtonEdgeDI2WasChangedFromSettingMenu(quint8 eEdge);
    void _pushButtonEdgeDI3WasChangedFromSettingMenu(quint8 eEdge);
    void _pushButtonEdgeDI4WasChangedFromSettingMenu(quint8 eEdge);
    void _pushButtonEdgeAI1WasChangedFromSettingMenu(quint8 eEdge);
    void _pushButtonEdgeAI2WasChangedFromSettingMenu(quint8 eEdge);

    void _doubleSpinBoxDI1_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI2_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI3_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxDI4_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxAI1_valueWasChangedFromSettingMenu(double value);
    void _doubleSpinBoxAI2_valueWasChangedFromSettingMenu(double value);

    void _comboBoxTopLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxTopRight_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomRight_currentIndexWasChanged(quint8 index);
    void _comboBoxTopMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(quint8 index);

};

#endif // SETTINGWINDOW_H

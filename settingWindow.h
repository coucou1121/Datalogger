#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "commonStyle.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();

private:
    Ui::SettingWindow *ui;
    CommonStyle _myStyle;

    //setup signal and slot
    void setupSignalAndSlot();

public slots:
    void _recievedNbFrameSavedChanged(quint64 nbFrameChanged);
    void _recievedSizeFrameChange(int frameSize);
    void _recievedFTDIBaudrateChange(int FTDIBaudrate);

private slots:
    void _recievedAddTraceFromChannelSelection(int traceNumber);
    void _recievedRemoveTraceFromChannelSelection(int traceNumber);
    void _recievedErrorFrequencyToLow(int errorNumber, bool active);

    void _recieved_pushButtonRangeAI1ChangedFromSettingMenu();
    void _recieved_pushButtonRangeAI2ChangedFromSettingMenu();
    void _recieved_pushButtonRangeAI1ChangedFromTriggerMenu();
    void _recieved_pushButtonRangeAI2ChangedFromTriggerMenu();

    void _recieved_pushButtonEdgeDI1ChangedFromSettingMenu(int eEdge);
    void _recieved_pushButtonEdgeDI2ChangedFromSettingMenu(int eEdge);
    void _recieved_pushButtonEdgeDI3ChangedFromSettingMenu(int eEdge);
    void _recieved_pushButtonEdgeDI4ChangedFromSettingMenu(int eEdge);
    void _recieved_pushButtonEdgeAI1ChangedFromSettingMenu(int eEdge);
    void _recieved_pushButtonEdgeAI2ChangedFromSettingMenu(int eEdge);

    void _recieved_pushButtonEdgeDI1ChangedFromTriggerMenu(int eEdge);
    void _recieved_pushButtonEdgeDI2ChangedFromTriggerMenu(int eEdge);
    void _recieved_pushButtonEdgeDI3ChangedFromTriggerMenu(int eEdge);
    void _recieved_pushButtonEdgeDI4ChangedFromTriggerMenu(int eEdge);
    void _recieved_pushButtonEdgeAI1ChangedFromTriggerMenu(int eEdge);
    void _recieved_pushButtonEdgeAI2ChangedFromTriggerMenu(int eEdge);

    void _recievedComboBoxTopLeft_currentIndexChanged(int index);
    void _recievedComboBoxTopRight_currentIndexChanged(int index);
    void _recievedComboBoxBottomLeft_currentIndexChanged(int index);
    void _recievedComboBoxBottomRight_currentIndexChanged(int index);
    void _recievedComboBoxTopMiddle_currentIndexChanged(int index);
    void _recievedComboBoxMiddle_currentIndexChanged(int index);
    void _recievedComboBoxBottomMiddle_currentIndexChanged(int index);

signals:
    void _addTraceInTriggerMenu(int traceNumber);
    void _removeTraceInTriggerMenu(int traceNumber);
    void _addTraceInDisplayMenu(int traceNumber);
    void _removeTraceInDisplayMenu(int traceNumber);
    void _nbFrameSavedChange(quint64 nbFrameChanges);
    void _sizeFrameChange(int frameSize);
    void _FTDIBaudrateChange(int FTDIBaudrate);
    void _errorFrequencyToLow(int errorNumber,bool active);

    void _pushButtonRangeAI1WasChangedFromSettingMenu();
    void _pushButtonRangeAI2WasChangedFromSettingMenu();

    void _pushButtonEdgeDI1WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI2WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI3WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeDI4WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeAI1WasChangedFromSettingMenu(int eEdge);
    void _pushButtonEdgeAI2WasChangedFromSettingMenu(int eEdge);

    void _comboBoxTopLeft_currentIndexWasChanged(int index);
    void _comboBoxTopRight_currentIndexWasChanged(int index);
    void _comboBoxBottomLeft_currentIndexWasChanged(int index);
    void _comboBoxBottomRight_currentIndexWasChanged(int index);
    void _comboBoxTopMiddle_currentIndexWasChanged(int index);
    void _comboBoxMiddle_currentIndexWasChanged(int index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(int index);
};

#endif // SETTINGWINDOW_H

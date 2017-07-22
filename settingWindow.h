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

signals:
    void _addTraceInTriggerMenu(int traceNumber);
    void _removeTraceInTriggerMenu(int traceNumber);
    void _addTraceInDisplayMenu(int traceNumber);
    void _removeTraceInDisplayMenu(int traceNumber);
    void _nbFrameSavedChange(quint64 nbFrameChanges);
    void _sizeFrameChange(int frameSize);
    void _FTDIBaudrateChange(int FTDIBaudrate);
    void _errorFrequencyToLow(int errorNumber,bool active);
};

#endif // SETTINGWINDOW_H

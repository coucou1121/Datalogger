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

private slots:
    void _recievedAddTraceFromChannelSelection(int traceNumber);
    void _recievedRemoveTraceFromChannelSelection(int traceNumber);

signals:
    void _addTraceInTriggerMenu(int traceNumber);
    void _removeTraceInTriggerMenu(int traceNumber);
};

#endif // SETTINGWINDOW_H

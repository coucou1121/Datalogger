#ifndef TRIGGERWINDOW_H
#define TRIGGERWINDOW_H

#include <QFrame>
#include "globalEnumatedAndExtern.h"

namespace Ui {
class TriggerWindow;
}

class TriggerWindow : public QFrame
{
    Q_OBJECT

public:
    explicit TriggerWindow(QWidget *parent = 0);
    ~TriggerWindow();

private:
    Ui::TriggerWindow *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

    //setup signal and slot
    void setupSignalAndSlot();

public slots:
    void _addTrace(int enumTrace);
    void _hideTrace(int enumTrace);
    void _comboBoxTopLeft_currentIndexChanged(int index);
    void _comboBoxTopRight_currentIndexChanged(int index);
    void _comboBoxBottomLeft_currentIndexChanged(int index);
    void _comboBoxBottomRight_currentIndexChanged(int index);
    void _comboBoxTopMiddle_currentIndexChanged(int index);
    void _comboBoxMiddle_currentIndexChanged(int index);
    void _comboBoxBottomMiddle_currentIndexChanged(int index);
    void _pushButtonRangeAI1Changed();
    void _pushButtonRangeAI2Changed();

private slots:
    void _recieved_pushButtonRangeAI1Changed();
    void _recieved_pushButtonRangeAI2Changed();

signals:
    void _pushButtonRangeAI1WasChanged();
    void _pushButtonRangeAI2WasChanged();
};

#endif // TRIGGERWINDOW_H

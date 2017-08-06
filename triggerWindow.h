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

    void _pushButtonRangeAI1Changed();
    void _pushButtonRangeAI2Changed();

    void _pushButtonEdgeDI1Changed(int eEdge);
    void _pushButtonEdgeDI2Changed(int eEdge);
    void _pushButtonEdgeDI3Changed(int eEdge);
    void _pushButtonEdgeDI4Changed(int eEdge);
    void _pushButtonEdgeAI1Changed(int eEdge);
    void _pushButtonEdgeAI2Changed(int eEdge);

    void _comboBoxTopLeft_currentIndexChanged(int index);
    void _comboBoxTopRight_currentIndexChanged(int index);
    void _comboBoxBottomLeft_currentIndexChanged(int index);
    void _comboBoxBottomRight_currentIndexChanged(int index);
    void _comboBoxTopMiddle_currentIndexChanged(int index);
    void _comboBoxMiddle_currentIndexChanged(int index);
    void _comboBoxBottomMiddle_currentIndexChanged(int index);

private slots:
    void _recieved_pushButtonRangeAI1Changed();
    void _recieved_pushButtonRangeAI2Changed();

    void _recieved_pushButtonEdgeDI1Changed(int eEdge);
    void _recieved_pushButtonEdgeDI2Changed(int eEdge);
    void _recieved_pushButtonEdgeDI3Changed(int eEdge);
    void _recieved_pushButtonEdgeDI4Changed(int eEdge);
    void _recieved_pushButtonEdgeAI1Changed(int eEdge);
    void _recieved_pushButtonEdgeAI2Changed(int eEdge);

signals:
    void _pushButtonRangeAI1WasChanged();
    void _pushButtonRangeAI2WasChanged();

    void _pushButtonEdgeDI1WasChanged(int eEdge);
    void _pushButtonEdgeDI2WasChanged(int eEdge);
    void _pushButtonEdgeDI3WasChanged(int eEdge);
    void _pushButtonEdgeDI4WasChanged(int eEdge);
    void _pushButtonEdgeAI1WasChanged(int eEdge);
    void _pushButtonEdgeAI2WasChanged(int eEdge);
};

#endif // TRIGGERWINDOW_H

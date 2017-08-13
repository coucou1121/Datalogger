#ifndef TRIGGERWINDOW_H
#define TRIGGERWINDOW_H

#include <QFrame>
#include "globalEnumatedAndExtern.h"
#include "dataFrame.h"

namespace Ui {
class TriggerWindow;
}

class TriggerWindow : public QFrame
{
    Q_OBJECT

public:
    explicit TriggerWindow(QWidget *parent = 0);
    ~TriggerWindow();

    //direction du draw
    // if true, draw left to right, mode roll on
    // if flase, draw right to left, mode trig
    void setDrawLeftToRight(bool drawLeftToRight);

    // update the plot
    void refreshPlot();


private:
    Ui::TriggerWindow *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

    //setup signal and slot
    void _setupSignalAndSlot();

    //trigger function enable
    bool _triggerFunctionEnable;

public slots:
    void addTrace(int enumTrace);
    void hideTrace(int enumTrace);

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

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);

private slots:
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
    void _pushButtonRangeAI1WasChanged();
    void _pushButtonRangeAI2WasChanged();

    void _pushButtonEdgeDI1WasChanged(int eEdge);
    void _pushButtonEdgeDI2WasChanged(int eEdge);
    void _pushButtonEdgeDI3WasChanged(int eEdge);
    void _pushButtonEdgeDI4WasChanged(int eEdge);
    void _pushButtonEdgeAI1WasChanged(int eEdge);
    void _pushButtonEdgeAI2WasChanged(int eEdge);

    void _comboBoxTopLeft_currentIndexWasChanged(int index);
    void _comboBoxTopRight_currentIndexWasChanged(int index);
    void _comboBoxBottomLeft_currentIndexWasChanged(int index);
    void _comboBoxBottomRight_currentIndexWasChanged(int index);
    void _comboBoxTopMiddle_currentIndexWasChanged(int index);
    void _comboBoxMiddle_currentIndexWasChanged(int index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(int index);

    void _doubleSpinBoxDI1_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI2_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI3_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI4_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxAI1_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxAI2_valueWasChangedFromTriggerMenu(double value);
};

#endif // TRIGGERWINDOW_H

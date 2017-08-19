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
    void setDrawRightToLeft(bool drawRightToLeft);

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
    void addTrace(quint8 enumTrace);
    void hideTrace(quint8 enumTrace);

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

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);

private slots:
    void _recieved_pushButtonRangeAI1Changed();
    void _recieved_pushButtonRangeAI2Changed();

    void _recieved_pushButtonEdgeDI1Changed(quint8 eEdge);
    void _recieved_pushButtonEdgeDI2Changed(quint8 eEdge);
    void _recieved_pushButtonEdgeDI3Changed(quint8 eEdge);
    void _recieved_pushButtonEdgeDI4Changed(quint8 eEdge);
    void _recieved_pushButtonEdgeAI1Changed(quint8 eEdge);
    void _recieved_pushButtonEdgeAI2Changed(quint8 eEdge);

    void _recieved_doubleSpinBoxDI1_valueChanged(double value);
    void _recieved_doubleSpinBoxDI2_valueChanged(double value);
    void _recieved_doubleSpinBoxDI3_valueChanged(double value);
    void _recieved_doubleSpinBoxDI4_valueChanged(double value);
    void _recieved_doubleSpinBoxAI1_valueChanged(double value);
    void _recieved_doubleSpinBoxAI2_valueChanged(double value);

    void _recieved_ComboBoxTopLeft_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxTopRight_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxBottomLeft_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxBottomRight_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxTopMiddle_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxMiddle_currentIndexChanged(quint8 index);
    void _recieved_ComboBoxBottomMiddle_currentIndexChanged(quint8 index);

    void _received_errorWrongEquation(quint8 errorNumber,bool active);

signals:
    void _pushButtonRangeAI1WasChanged();
    void _pushButtonRangeAI2WasChanged();

    void _pushButtonEdgeDI1WasChanged(quint8 eEdge);
    void _pushButtonEdgeDI2WasChanged(quint8 eEdge);
    void _pushButtonEdgeDI3WasChanged(quint8 eEdge);
    void _pushButtonEdgeDI4WasChanged(quint8 eEdge);
    void _pushButtonEdgeAI1WasChanged(quint8 eEdge);
    void _pushButtonEdgeAI2WasChanged(quint8 eEdge);

    void _doubleSpinBoxDI1_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI2_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI3_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxDI4_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxAI1_valueWasChangedFromTriggerMenu(double value);
    void _doubleSpinBoxAI2_valueWasChangedFromTriggerMenu(double value);

    void _comboBoxTopLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxTopRight_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomRight_currentIndexWasChanged(quint8 index);
    void _comboBoxTopMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(quint8 index);

    void _errorWrongEquation(quint8 errorNumber,bool active);
};

#endif // TRIGGERWINDOW_H

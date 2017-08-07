#ifndef SETTINGTRIGGERSETTING_H
#define SETTINGTRIGGERSETTING_H

#include <QDebug>
#include <QFrame>
#include <QPushButton>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class SettingTriggerSetting;
}

class SettingTriggerSetting : public QFrame
{
    Q_OBJECT

public:
    explicit SettingTriggerSetting(QWidget *parent = 0);
    ~SettingTriggerSetting();

    //change range selection
    void pushButtonRangeAI1_ChangeRange();
    void pushButtonRangeAI2_ChangeRange();

    //change edge selection
    void pushButtonEdgeDI1_changeEdge(int eEdge);
    void pushButtonEdgeDI2_changeEdge(int eEdge);
    void pushButtonEdgeDI3_changeEdge(int eEdge);
    void pushButtonEdgeDI4_changeEdge(int eEdge);
    void pushButtonEdgeAI1_changeEdge(int eEdge);
    void pushButtonEdgeAI2_changeEdge(int eEdge);

    //change value in doubleSpinBox
    void doubleSpinBoxDI1_changeValue(double value);
    void doubleSpinBoxDI2_changeValue(double value);
    void doubleSpinBoxDI3_changeValue(double value);
    void doubleSpinBoxDI4_changeValue(double value);
    void doubleSpinBoxAI1_changeValue(double value);
    void doubleSpinBoxAI2_changeValue(double value);

private:
    Ui::SettingTriggerSetting *ui;

    CommonStyle _myStyle;
    void setupStyle();

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    //state of edge
    GlobalEnumatedAndExtern::eEdge _btDI1Edge;
    GlobalEnumatedAndExtern::eEdge _btDI2Edge;
    GlobalEnumatedAndExtern::eEdge _btDI3Edge;
    GlobalEnumatedAndExtern::eEdge _btDI4Edge;
    GlobalEnumatedAndExtern::eEdge _btAI1Edge;
    GlobalEnumatedAndExtern::eEdge _btAI2Edge;

    void setEdgeIcon(QPushButton *pushbutton, GlobalEnumatedAndExtern::eEdge edgeType);
    void setRangeValue();

    //picture on button
    QPixmap _pixmapFallingEdge;
    QPixmap _pixmapRisingEdge;

    //select or unselect the button
    void _DI1select(bool btselected);
    void _DI2select(bool btselected);
    void _DI3select(bool btselected);
    void _DI4select(bool btselected);
    void _AI1select(bool btselected);
    void _AI2select(bool btselected);
    void _AI3select(bool btselected);
    void _AI4select(bool btselected);

public slots:
    void _btSelected(int buttonNumber, bool btSelected);

private slots:
    void on_pushButtonRangeDI1_released();
    void on_pushButtonRangeDI2_released();
    void on_pushButtonRangeDI3_released();
    void on_pushButtonRangeDI4_released();
    void on_pushButtonRangeAI1_released();
    void on_pushButtonRangeAI2_released();
    void on_pushButtonRangeAI3_released();
    void on_pushButtonRangeAI4_released();

    void on_pushButtonEdgeDI1_released();
    void on_pushButtonEdgeDI2_released();
    void on_pushButtonEdgeDI3_released();
    void on_pushButtonEdgeDI4_released();
    void on_pushButtonEdgeAI1_released();
    void on_pushButtonEdgeAI2_released();

    void on_doubleSpinBoxDI1_valueChanged(double value);
    void on_doubleSpinBoxDI2_valueChanged(double value);
    void on_doubleSpinBoxDI3_valueChanged(double value);
    void on_doubleSpinBoxDI4_valueChanged(double value);
    void on_doubleSpinBoxAI1_valueChanged(double value);
    void on_doubleSpinBoxAI2_valueChanged(double value);

signals:
    void _pushButtonRangeAI1WasChanged();
    void _pushButtonRangeAI2WasChanged();

    void _pushButtonEdgeDI1WasChanged(int eEdge);
    void _pushButtonEdgeDI2WasChanged(int eEdge);
    void _pushButtonEdgeDI3WasChanged(int eEdge);
    void _pushButtonEdgeDI4WasChanged(int eEdge);
    void _pushButtonEdgeAI1WasChanged(int eEdge);
    void _pushButtonEdgeAI2WasChanged(int eEdge);

    void _doubleSpinBoxDI1_valueWasChanged(double value);
    void _doubleSpinBoxDI2_valueWasChanged(double value);
    void _doubleSpinBoxDI3_valueWasChanged(double value);
    void _doubleSpinBoxDI4_valueWasChanged(double value);
    void _doubleSpinBoxAI1_valueWasChanged(double value);
    void _doubleSpinBoxAI2_valueWasChanged(double value);
};

#endif // SETTINGTRIGGERSETTING_H

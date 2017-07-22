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


};

#endif // SETTINGTRIGGERSETTING_H

#ifndef SETTINGPRETRIGGERPERCENTAGE_H
#define SETTINGPRETRIGGERPERCENTAGE_H

#include <QFrame>
#include "commonStyle.h"


namespace Ui {
class SettingPreTriggerPercentage;
}

class SettingPreTriggerPercentage : public QFrame
{
    Q_OBJECT

public:
    explicit SettingPreTriggerPercentage(QWidget *parent = 0);
    ~SettingPreTriggerPercentage();

    void setMaximumRange(const quint16 &maximumRange);
    void setStepOnClick(const quint8 &stepOnClick);

private:
    Ui::SettingPreTriggerPercentage *ui;

    CommonStyle _myStyle;
    void setupStyle();

    //maximum reccord time
    quint16 _maximumRange;

    //step for one click
    quint8 _stepOnClick;

private slots:
    void on_spinBoxTimeBeforeTrig_valueChanged(int arg1);
    void on_spinBoxTimeAfterTrig_valueChanged(int arg1);
};

#endif // SETTINGPRETRIGGERPERCENTAGE_H

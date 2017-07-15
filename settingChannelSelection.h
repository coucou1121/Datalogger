#ifndef SETTINGCHANNELSELECTION_H
#define SETTINGCHANNELSELECTION_H

#include <QDebug>
#include <QFrame>
#include <QPushButton>
#include "commonStyle.h"

namespace Ui {
class SettingChannelSelection;
}

class SettingChannelSelection : public QFrame
{
    Q_OBJECT

public:
    explicit SettingChannelSelection(QWidget *parent = 0);
    ~SettingChannelSelection();

private:
    Ui::SettingChannelSelection *ui;

    CommonStyle _myStyle;
    void setupStyle();

    void setupUILayout();
    void setupButton(QPushButton *pushbutton, QColor btColor);

private slots:
    void on_btDI1_released();
    void on_btDI2_released();
    void on_btDI3_released();
    void on_btDI4_released();
    void on_btDI5_released();
    void on_btDI6_released();
    void on_btDI7_released();
    void on_btDI8_released();
    void on_btDI9_released();
    void on_btDI10_released();
    void on_btDI11_released();
    void on_btDI12_released();
    void on_btDI13_released();
    void on_btDI14_released();
    void on_btDI15_released();
    void on_btDI16_released();
    void on_btAI1_released();
    void on_btAI2_released();
    void on_btAI3_released();
    void on_btAI4_released();

signals:
    void _btDI1Selected(bool btSelected);
    void _btDI2Selected(bool btSelected);
    void _btDI3Selected(bool btSelected);
    void _btDI4Selected(bool btSelected);
    void _btDI5Selected(bool btSelected);
    void _btDI6Selected(bool btSelected);
    void _btDI7Selected(bool btSelected);
    void _btDI8Selected(bool btSelected);
    void _btDI9Selected(bool btSelected);
    void _btDI10Selected(bool btSelected);
    void _btDI11Selected(bool btSelected);
    void _btDI12Selected(bool btSelected);
    void _btDI13Selected(bool btSelected);
    void _btDI14Selected(bool btSelected);
    void _btDI15Selected(bool btSelected);
    void _btDI16Selected(bool btSelected);

    void _btAI1Selected(bool btSelected);
    void _btAI2Selected(bool btSelected);
    void _btAI3Selected(bool btSelected);
    void _btAI4Selected(bool btSelected);

};

#endif // SETTINGCHANNELSELECTION_H

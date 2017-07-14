#ifndef SETTINGCHANNELSELECTION_H
#define SETTINGCHANNELSELECTION_H

#include <QWidget>
#include <QPushButton>
#include "commonStyle.h"

namespace Ui {
class SettingChannelSelection;
}

class SettingChannelSelection : public QWidget
{
    Q_OBJECT

public:
    explicit SettingChannelSelection(QWidget *parent = 0);
    ~SettingChannelSelection();

private:
    Ui::SettingChannelSelection *ui;

    CommonStyle _myStyle;
    bool _btSelected;

    void setupUILayout();
    void setupButton(QPushButton *pushbutton, QColor btColor);

    QPushButton *_btDI1;
    QPushButton *_btDI2;
    QPushButton *_btDI3;
    QPushButton *_btDI4;
    QPushButton *_btDI5;
    QPushButton *_btDI6;
    QPushButton *_btDI7;
    QPushButton *_btDI8;
    QPushButton *_btDI9;
    QPushButton *_btDI10;
    QPushButton *_btDI11;
    QPushButton *_btDI12;
    QPushButton *_btDI13;
    QPushButton *_btDI14;
    QPushButton *_btDI15;
    QPushButton *_btDI16;

    QPushButton *_btAI1;
    QPushButton *_btAI2;
    QPushButton *_btAI3;
    QPushButton *_btAI4;

private slots:

    void _btDI1_released();
    void _btDI2_released();
    void _btDI3_released();
    void _btDI4_released();
    void _btDI5_released();
    void _btDI6_released();
    void _btDI7_released();
    void _btDI8_released();
    void _btDI9_released();
    void _btDI10_released();
    void _btDI11_released();
    void _btDI12_released();
    void _btDI13_released();
    void _btDI14_released();
    void _btDI15_released();
    void _btDI16_released();
    void _btAI1_released();
    void _btAI2_released();
    void _btAI3_released();
    void _btAI4_released();

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

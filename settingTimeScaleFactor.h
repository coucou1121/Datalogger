#ifndef SETTINGTIMESCALEFACTOR_H
#define SETTINGTIMESCALEFACTOR_H

#include <QFrame>
#include "commonStyle.h"

namespace Ui {
class SettingTimeScaleFactor;
}

class SettingTimeScaleFactor : public QFrame
{
    Q_OBJECT

public:
    explicit SettingTimeScaleFactor(QWidget *parent = 0);
    ~SettingTimeScaleFactor();

private:
    Ui::SettingTimeScaleFactor *ui;

    CommonStyle _myStyle;
    void setupStyle();
};

#endif // SETTINGTIMESCALEFACTOR_H

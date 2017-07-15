#ifndef SETTINGTRIGGERFUNCTION_H
#define SETTINGTRIGGERFUNCTION_H

#include <QFrame>
#include "commonStyle.h"

namespace Ui {
class SettingTriggerFunction;
}

class SettingTriggerFunction : public QFrame
{
    Q_OBJECT

public:
    explicit SettingTriggerFunction(QWidget *parent = 0);
    ~SettingTriggerFunction();

private:
    Ui::SettingTriggerFunction *ui;

    CommonStyle _myStyle;
    void setupStyle();
};

#endif // SETTINGTRIGGERFUNCTION_H

#ifndef SETTINGTRIGGERFUNCTION_H
#define SETTINGTRIGGERFUNCTION_H

#include <QWidget>

namespace Ui {
class SettingTriggerFunction;
}

class SettingTriggerFunction : public QWidget
{
    Q_OBJECT

public:
    explicit SettingTriggerFunction(QWidget *parent = 0);
    ~SettingTriggerFunction();

private:
    Ui::SettingTriggerFunction *ui;
};

#endif // SETTINGTRIGGERFUNCTION_H

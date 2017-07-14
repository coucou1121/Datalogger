#ifndef SETTINGPRETRIGGERPERCENTAGE_H
#define SETTINGPRETRIGGERPERCENTAGE_H

#include <QWidget>

namespace Ui {
class SettingPreTriggerPercentage;
}

class SettingPreTriggerPercentage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPreTriggerPercentage(QWidget *parent = 0);
    ~SettingPreTriggerPercentage();

private:
    Ui::SettingPreTriggerPercentage *ui;
};

#endif // SETTINGPRETRIGGERPERCENTAGE_H

#ifndef SETTINGTRIGGERSETTING_H
#define SETTINGTRIGGERSETTING_H

#include <QWidget>

namespace Ui {
class SettingTriggerSetting;
}

class SettingTriggerSetting : public QWidget
{
    Q_OBJECT

public:
    explicit SettingTriggerSetting(QWidget *parent = 0);
    ~SettingTriggerSetting();

private:
    Ui::SettingTriggerSetting *ui;
};

#endif // SETTINGTRIGGERSETTING_H

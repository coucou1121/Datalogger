#ifndef SETTINGTIMESCALEFACTOR_H
#define SETTINGTIMESCALEFACTOR_H

#include <QWidget>

namespace Ui {
class SettingTimeScaleFactor;
}

class SettingTimeScaleFactor : public QWidget
{
    Q_OBJECT

public:
    explicit SettingTimeScaleFactor(QWidget *parent = 0);
    ~SettingTimeScaleFactor();

private:
    Ui::SettingTimeScaleFactor *ui;
};

#endif // SETTINGTIMESCALEFACTOR_H

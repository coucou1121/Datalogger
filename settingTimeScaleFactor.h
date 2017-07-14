#ifndef SETTINGTIMESCALEFACTOR_H
#define SETTINGTIMESCALEFACTOR_H

#include <QFrame>

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
};

#endif // SETTINGTIMESCALEFACTOR_H

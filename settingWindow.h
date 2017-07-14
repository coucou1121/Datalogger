#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "commonStyle.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();

private:
    Ui::SettingWindow *ui;
    CommonStyle _myStyle;
};

#endif // SETTINGWINDOW_H

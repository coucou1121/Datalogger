#ifndef SETTINGTRIGGERFUNCTION_H
#define SETTINGTRIGGERFUNCTION_H

#include <QFrame>
#include <QDebug>
#include <QComboBox>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

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

    void setupTraceCombobox();
    void setupLogicalCombobox(QComboBox *combobox);

    // key - value for insert the text in comboboxe according mithe the button number selected in channel selection
    // base is define in GlobalEnumated class
    QMap<int, QString> TriggerTraceSelected;
    QMap<int, QString> TriggerTracePossible;
    void updateCombobox();

public slots:
    void _comboboxAddItem(int buttonNummer);
    void _comboboxRevmoveItem(int buttonNummer);
};

#endif // SETTINGTRIGGERFUNCTION_H

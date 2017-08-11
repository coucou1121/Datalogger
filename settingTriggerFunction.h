#ifndef SETTINGTRIGGERFUNCTION_H
#define SETTINGTRIGGERFUNCTION_H

#include <QFrame>
#include <QDebug>
#include <QComboBox>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"
#include "triggerFunctions.h"

namespace Ui {
class SettingTriggerFunction;
}

class SettingTriggerFunction : public QFrame
{
    Q_OBJECT

public:
    explicit SettingTriggerFunction(QWidget *parent = 0);
    ~SettingTriggerFunction();

    bool areSomeTraceSelected() const;

private:
    Ui::SettingTriggerFunction *ui;

    //value of the selected trigger function
    TriggerFunctions *_triggerFuntion;

    //check if trig trace is selected
    bool _areSomeTraceSelected;

    //not none state
    bool _comboBoxTopLeftNotNone;
    bool _comboBoxTopMiddleNotNone;
    bool _comboBoxTopRightNotNone;
    bool _comboBoxMiddleNotNone;
    bool _comboBoxBottomLeftNotNone;
    bool _comboBoxBottomRightNotNone;
    bool _comboBoxBottomMiddleNotNone;

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
    void _comboboxAddItem(int buttonNumber);
    void _comboboxRevmoveItem(int buttonNumber);

    // received when the trace was changed from an other trigger function menu.
    void _comboBoxTopLeft_currentIndexChanged(int index);
    void _comboBoxTopRight_currentIndexChanged(int index);
    void _comboBoxBottomLeft_currentIndexChanged(int index);
    void _comboBoxBottomRight_currentIndexChanged(int index);
    void _comboBoxTopMiddle_currentIndexChanged(int index);
    void _comboBoxMiddle_currentIndexChanged(int index);
    void _comboBoxBottomMiddle_currentIndexChanged(int index);


private slots:
    // recieved when other trace was selected on this windows
    void on_comboBoxTopLeft_currentIndexChanged(int index);
    void on_comboBoxTopRight_currentIndexChanged(int index);
    void on_comboBoxBottomLeft_currentIndexChanged(int index);
    void on_comboBoxBottomRight_currentIndexChanged(int index);
    void on_comboBoxTopMiddle_currentIndexChanged(int index);
    void on_comboBoxMiddle_currentIndexChanged(int index);
    void on_comboBoxBottomMiddle_currentIndexChanged(int index);

    //received error
    void _received_errorWrongEquation(int errorNumber,bool active);

signals:
    // send for change the sychronize the selection in the other trigger function menu
    void _comboBoxTopLeft_currentIndexWasChanged(int index);
    void _comboBoxTopRight_currentIndexWasChanged(int index);
    void _comboBoxBottomLeft_currentIndexWasChanged(int index);
    void _comboBoxBottomRight_currentIndexWasChanged(int index);
    void _comboBoxTopMiddle_currentIndexWasChanged(int index);
    void _comboBoxMiddle_currentIndexWasChanged(int index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(int index);

    //error
    void _errorWrongEquation(int errorNumber,bool active);

};

#endif // SETTINGTRIGGERFUNCTION_H

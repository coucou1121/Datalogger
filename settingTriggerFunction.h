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

    TriggerFunctions *triggerFuntion() const;

    // change current index in the combobox, use to sychronise wiht the other same object.
    void comboBoxTopLeft_changeCurrentIndex(quint8 index);
    void comboBoxTopRight_changeCurrentIndex(quint8 index);
    void comboBoxBottomLeft_changeCurrentIndex(quint8 index);
    void comboBoxBottomRight_changeCurrentIndex(quint8 index);
    void comboBoxTopMiddle_changeCurrentIndex(quint8 index);
    void comboBoxMiddle_changeCurrentIndex(quint8 index);
    void comboBoxBottomMiddle_changeCurrentIndex(quint8 index);

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
    void _setupStyle();

    void _setupTraceCombobox();
    void _setupLogicalCombobox(QComboBox *combobox);

    // key - value for insert the text in comboboxe according mithe the button number selected in channel selection
    // base is define in GlobalEnumated class
    QMap<int, QString> _triggerTraceSelected;
    QMap<int, QString> _triggerTracePossible;

    void _updateCombobox();

public slots:
    void comboboxAddItem(quint8 buttonNumber);
    void comboboxRevmoveItem(quint8 buttonNumber);

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
    void _received_errorWrongEquation(quint8 errorNumber,bool active);

signals:

    // send for sychronize the selection in the other trigger function menu
    void _comboBoxTopLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxTopRight_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomLeft_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomRight_currentIndexWasChanged(quint8 index);
    void _comboBoxTopMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxMiddle_currentIndexWasChanged(quint8 index);
    void _comboBoxBottomMiddle_currentIndexWasChanged(quint8 index);

    //error
    void _errorWrongEquation(quint8 errorNumber,bool active);
};

#endif // SETTINGTRIGGERFUNCTION_H

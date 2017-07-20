#ifndef SETTINGTIMESCALEFACTOR_H
#define SETTINGTIMESCALEFACTOR_H

#include <QFrame>
#include <QDebug>
#include <QString>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

#define UNIT_SECONDES " [s]"
#define UNIT_MILLI_SECONDES " [ms]"
#define TRAME_VALUE 65536

namespace Ui {
class SettingTimeScaleFactor;
}

class SettingTimeScaleFactor : public QFrame
{
    Q_OBJECT

public:
    explicit SettingTimeScaleFactor(QWidget *parent = 0);
    ~SettingTimeScaleFactor();

private slots:
    void on_comboBoxPeriod_currentTextChanged(const QString &arg1);

    void on_comboBoxPeriod_currentIndexChanged(int index);

private:
    Ui::SettingTimeScaleFactor *ui;


    //key value for periode possible
    QMap<int, double> _peridePossible;

    //key value for text periode possible
    QMap<int, QString> _peridePossibleTxt;

    CommonStyle _myStyle;
    void setupStyle();

    void _initPeriode();
    void _initDuration(int index);
    void _initSampleSeconde();
};

#endif // SETTINGTIMESCALEFACTOR_H

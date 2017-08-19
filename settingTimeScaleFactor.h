#ifndef SETTINGTIMESCALEFACTOR_H
#define SETTINGTIMESCALEFACTOR_H

#include <QFrame>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

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

    // _frequancy
    int _frequency;

    //nombre of saved frame
    quint64 _nbFrameSaved;

    //size of frame
    int _frameSize;

    //FTDI baudrate
    int _FTDIbaudrate;

    //key value for periode possible
    QMap<int, double> _peridePossible;

    //key value for text periode possible
    QMap<int, QString> _peridePossibleTxt;

    CommonStyle _myStyle;
    void setupStyle();

    void _initPeriode();
    void _initDuration();
    void _initSampleRate(int index);

private slots:

    void on_comboBoxPeriod_currentTextChanged(const QString &arg1);
    void on_comboBoxPeriod_currentIndexChanged(int index);

    void _nbFrameSavedWasChanged(quint64 nbFrameChanged);
    void _sizeFrameWasChanged(int frameSize);
    void _FTDIBaudrateWasChanged(int FTDIBaudrate);

signals:
    void _errorFrequencyToLow(quint8 errorNumber, bool active);
};

#endif // SETTINGTIMESCALEFACTOR_H

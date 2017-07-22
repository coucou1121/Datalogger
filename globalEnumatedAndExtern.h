#ifndef GLOBALENUMATEDANDEXTERN_H
#define GLOBALENUMATEDANDEXTERN_H

#include <QString>
#include <QMap>

class GlobalEnumatedAndExtern
{

private:

public:
    GlobalEnumatedAndExtern();


    //ErrorPossible
    typedef enum
    {
        noError = 0,
        ErrorSamplingFrequencyToHigh
    }eError;


    static QMap<int, QString> initErrorPossible();

    //trace range
    typedef enum
    {
        range0_24 = 0,
        range0_30,
        range15_15
    }eRangeValue;

    QString range0_24Txt;
    QString range0_30Txt;
    QString range15_15Txt;

    //edge type
    typedef enum
    {
        fallingEdge = 0,
        risingEdge
    }eEdge;

    //Equation operator possible
    typedef enum
    {
        opNone = 0,
        opOr,
        opAnd,
        opNotOr,
        opNotAnd
    }eLogicOperator;

    QString opNoneTxt;
    QString opOrTxt;
    QString opAndTxt;
    QString opNotOrTxt;
    QString opNoTAnd;

    //button in trigger function
    typedef enum
    {
        btNone = 0,
        btDI1,
        btDI2,
        btDI3,
        btDI4,
        btDI5,
        btDI6,
        btDI7,
        btDI8,
        btDI9,
        btDI10,
        btDI11,
        btDI12,
        btDI13,
        btDI14,
        btDI15,
        btDI16,
        btAI1,
        btAI2,
        btAI3,
        btAI4,
        functionResult
    }eTracePossible;

    //button in trigger function
    typedef enum
    {
        periode0_5_microsec = 0,
        periode1_microsec,
        periode50_microsec,
        periode100_microsec,
        periode1_ms,
        periode5_ms,
        periode10_ms,
        periode50_ms,
        periode100_ms,
        periode500_ms,
        periode1_s,
        periode5_s,
        periode10_s
    }ePeriodePossible;

    static QMap<int, QString> TriggerTracePossible;

    static QMap<int, QString> initTriggerTracePossible();
    static QMap<int, double> initPeridePossible();
    static QMap<int, QString> initPeridePossibleTxt();

};

#endif // GLOBALENUMATEDANDEXTERN_H
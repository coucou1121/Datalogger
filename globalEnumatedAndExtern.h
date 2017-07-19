#ifndef GLOBALENUMATEDANDEXTERN_H
#define GLOBALENUMATEDANDEXTERN_H

#include <QString>
#include <QMap>

class GlobalEnumatedAndExtern
{

private:

public:
    GlobalEnumatedAndExtern();

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

    static QMap<int, QString> initTriggerTracePossible();

    static QMap<int, QString> TriggerTracePossible;

};

#endif // GLOBALENUMATEDANDEXTERN_H

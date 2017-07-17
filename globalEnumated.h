#ifndef GLOBALENUMATED_H
#define GLOBALENUMATED_H

#include <QString>
#include <QMap>

class GlobalEnumated
{

private:

public:
    GlobalEnumated();

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
        btAI1,
        btAI2
    }eTriggerTracePossible;

    static QMap<int, QString> initTriggerTracePossible();

};

#endif // GLOBALENUMATED_H

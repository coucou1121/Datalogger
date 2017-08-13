#ifndef TRIGGERFUNCTIONS_H
#define TRIGGERFUNCTIONS_H

#include <QDebug>
#include "globalEnumatedAndExtern.h"

class TriggerFunctions : public QObject
{
    Q_OBJECT

public:
    TriggerFunctions();

    void displayValue();

    GlobalEnumatedAndExtern::eTracePossible traceA() const;
    void setTraceA(const GlobalEnumatedAndExtern::eTracePossible &traceA);

    GlobalEnumatedAndExtern::eTracePossible traceB() const;
    void setTraceB(const GlobalEnumatedAndExtern::eTracePossible &traceB);

    GlobalEnumatedAndExtern::eTracePossible traceC() const;
    void setTraceC(const GlobalEnumatedAndExtern::eTracePossible &traceC);

    GlobalEnumatedAndExtern::eTracePossible traceD() const;
    void setTraceD(const GlobalEnumatedAndExtern::eTracePossible &traceD);

    GlobalEnumatedAndExtern::eLogicOperator logicalOperator_Top() const;
    void setLogicalOperator_Top(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Top);

    GlobalEnumatedAndExtern::eLogicOperator logicalOperator_Middle() const;
    void setLogicalOperator_Middle(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Middle);

    GlobalEnumatedAndExtern::eLogicOperator logicalOperator_Bottom() const;
    void setLogicalOperator_Bottom(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Bottom);

    bool onTrig(quint8 valueA, quint8 valueB = 0, quint8 valueC = 0, quint8 valueD = 0);

private:

    bool _onTrigStatus;

    quint16 _valueFunction;

    void _setValueFunction();

    bool _checkValideEquation();

    GlobalEnumatedAndExtern::eTracePossible _traceA;
    GlobalEnumatedAndExtern::eTracePossible _traceB;
    GlobalEnumatedAndExtern::eTracePossible _traceC;
    GlobalEnumatedAndExtern::eTracePossible _traceD;

    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Top;
    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Middle;
    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Bottom;

signals:
   void _errorWrongEquation(int errorNumber,bool active);
};

#endif // TRIGGERFUNCTIONS_H

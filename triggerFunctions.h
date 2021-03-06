#ifndef TRIGGERFUNCTIONS_H
#define TRIGGERFUNCTIONS_H

#include <QDebug>
#include "globalEnumatedAndExtern.h"
#include "dataFrame.h"

#define DIGITAL_MIN_VALUE 0
#define DIGITAL_MAX_VALUE 1
#define ANALOG_MIN_VALUE 0
#define ANALOG_MAX_VALUE 255

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

    bool onTrig(DataFrame *data);

    void setBtDI1Edge(const GlobalEnumatedAndExtern::eEdge &btDI1Edge);
    GlobalEnumatedAndExtern::eEdge btDI1Edge() const;

    GlobalEnumatedAndExtern::eEdge btDI2Edge() const;
    void setBtDI2Edge(const GlobalEnumatedAndExtern::eEdge &btDI2Edge);

    GlobalEnumatedAndExtern::eEdge btDI3Edge() const;
    void setBtDI3Edge(const GlobalEnumatedAndExtern::eEdge &btDI3Edge);

    GlobalEnumatedAndExtern::eEdge btDI4Edge() const;
    void setBtDI4Edge(const GlobalEnumatedAndExtern::eEdge &btDI4Edge);

    GlobalEnumatedAndExtern::eEdge btAI1Edge() const;
    void setBtAI1Edge(const GlobalEnumatedAndExtern::eEdge &btAI1Edge);

    GlobalEnumatedAndExtern::eEdge btAI2Edge() const;
    void setBtAI2Edge(const GlobalEnumatedAndExtern::eEdge &btAI2Edge);

    quint8 doubleSpinBoxDI1() const;
    void setDoubleSpinBoxDI1(quint8 doubleSpinBoxDI1);

    quint8 doubleSpinBoxDI2() const;
    void setDoubleSpinBoxDI2(quint8 doubleSpinBoxDI2);

    quint8 doubleSpinBoxDI3() const;
    void setDoubleSpinBoxDI3(quint8 doubleSpinBoxDI3);

    quint8 doubleSpinBoxDI4() const;
    void setDoubleSpinBoxDI4(quint8 doubleSpinBoxDI4);

    quint8 doubleSpinBoxAI1() const;
    void setDoubleSpinBoxAI1(quint8 doubleSpinBoxAI1);

    quint8 doubleSpinBoxAI2() const;
    void setDoubleSpinBoxAI2(quint8 doubleSpinBoxAI2);

    bool onTrigStatus() const;

private:

    bool _onTrigStatus;

    quint16 _valueFunction;

    void _setValueFunction();

    bool _checkValideEquation();

    quint8 _checkOnTrigTrace(quint8 trace, quint8 memoTrace, GlobalEnumatedAndExtern::eEdge edge, quint8 minValue, quint8 maxValue, quint8 trigValue);

    GlobalEnumatedAndExtern::eTracePossible _traceA;
    GlobalEnumatedAndExtern::eTracePossible _traceB;
    GlobalEnumatedAndExtern::eTracePossible _traceC;
    GlobalEnumatedAndExtern::eTracePossible _traceD;

    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Top;
    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Middle;
    GlobalEnumatedAndExtern::eLogicOperator _logicalOperator_Bottom;

    //state of edge
    GlobalEnumatedAndExtern::eEdge _btDI1Edge;
    GlobalEnumatedAndExtern::eEdge _btDI2Edge;
    GlobalEnumatedAndExtern::eEdge _btDI3Edge;
    GlobalEnumatedAndExtern::eEdge _btDI4Edge;
    GlobalEnumatedAndExtern::eEdge _btAI1Edge;
    GlobalEnumatedAndExtern::eEdge _btAI2Edge;

    //doubleSpinBox value
    quint8 _doubleSpinBoxDI1;
    quint8 _doubleSpinBoxDI2;
    quint8 _doubleSpinBoxDI3;
    quint8 _doubleSpinBoxDI4;
    quint8 _doubleSpinBoxAI1;
    quint8 _doubleSpinBoxAI2;

    //minimum Value of trace in pulse
    quint8 _minValueTraceA;
    quint8 _minValueTraceB;
    quint8 _minValueTraceC;
    quint8 _minValueTraceD;

    //maximum Value of trace in pulse
    quint8 _maxValueTraceA;
    quint8 _maxValueTraceB;
    quint8 _maxValueTraceC;
    quint8 _maxValueTraceD;

    //trig value
    quint8 _trigValueTraceA;
    quint8 _trigValueTraceB;
    quint8 _trigValueTraceC;
    quint8 _trigValueTraceD;

    //analysed frame
    DataFrame *_newFrame;
    DataFrame *_memoFrame;

signals:
   void _errorWrongEquation(quint8 errorNumber,bool active);
};

#endif // TRIGGERFUNCTIONS_H

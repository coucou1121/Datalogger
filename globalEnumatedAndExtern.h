#ifndef GLOBALENUMATEDANDEXTERN_H
#define GLOBALENUMATEDANDEXTERN_H

#include <QString>
#include <QMap>

class GlobalEnumatedAndExtern
{

private:

public:
    GlobalEnumatedAndExtern();

    //application main state possible
    typedef enum
    {
        mainStateInit = 0,
        mainStateStop,
        mainStateReady,
        mainStateSet,
        mainStateTrig,
        mainStateRoll,
        mainStateDebug
    }eMainStateApplication;

    //application trig state possible
    typedef enum
    {
        trigNotReady = 0,
        trigReady,
        trigRunTrig,
        trigTrigged,
    }eTrigState;

    //application trig state possible
    typedef enum
    {
        rollNotReady = 0,
        rollReady,
        rollRollOn,
        rollPaused,
    }eRollState;

    //display state possible
    typedef enum
    {
        init = 0,
        stopped,
        ready,
        runTrig,
        trigged,
        rollOn,
        paused
    }eMainStateDisplay;

    QString BPMenuHomeTxt;
    QString BPMenuSetTxt;
    QString BPMenuTrigTxt;
    QString BPMenuRollTxt;
    QString BPMenuDebugTxt;

//    QString mainStateInitTxt;
//    QString mainStateReadyTxt;
//    QString mainStatePauseTxt;
//    QString mainStateRunTrigTxt;
//    QString mainStateOnTrigTxt;
//    QString mainStateRollOnTxt;

    //startStop button state possible
    typedef enum
    {
        stop,
        start,
        hold
    }eBPStartStopState;

    QString BPStartStopStateBlockTxt;
    QString BPStartStopStateStartTxt;
    QString BPStartStopStateStopTxt;

    //Error Possible
    // from the Highest priority is at the top after noError
    typedef enum
    {
        noError = 0,
        errorSamplingFrequencyToHigh,
        errorNoSelectedTrace,
        errorNoSelectedTriggerTrace,
        errorWrongEquation
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
        noEdge = 0,
        fallingEdge,
        risingEdge
    }eEdge;

    //Equation operator possible
    typedef enum
    {
        opNone = 0,
        opAnd,
        opOr,
        opAndNot,
        opOrNot
    }eLogicOperator;

    QString opNoneTxt;
    QString opOrTxt;
    QString opAndTxt;
    QString opNotOrTxt;
    QString opNoTAnd;

    //button in setting windows
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

    typedef enum
    {
        endOfTransmission = 0x04,
        transmissionEnquiry = 0x05,
        positiveAcknoledge = 0x06,
        negativeAcknoledge = 0x15
    }eFTDIReturnValue;

    //all static variables
    static QMap<int, QString> TriggerTracePossible;
    static QMap<int, QString> FTDIReturnValuePossible;

    //init array for external use
    static QMap<int, QString> initTriggerTracePossible();
    static QMap<int, QString> initFTDIReturnValuePossibleTxt();


    static QMap<int, double> initPeridePossible();
    static QMap<int, QString> initPeridePossibleTxt();

    static QMap<int, QString> initMainStateDisplayPossibleTxt();

};

#endif // GLOBALENUMATEDANDEXTERN_H

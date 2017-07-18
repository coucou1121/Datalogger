#include "globalEnumatedAndExtern.h"

GlobalEnumatedAndExtern::GlobalEnumatedAndExtern()
{

}

QMap<int, QString> GlobalEnumatedAndExtern::initTriggerTracePossible()
{

    QMap<int, QString> ret;
    ret.insert(btNone, "none");
    ret.insert(btDI1, "DI 1");
    ret.insert(btDI2, "DI 2");
    ret.insert(btDI3, "DI 3");
    ret.insert(btDI4, "DI 4");
    ret.insert(btDI5, "DI 5");
    ret.insert(btDI6, "DI 6");
    ret.insert(btDI7, "DI 7");
    ret.insert(btDI8, "DI 8");
    ret.insert(btDI9, "DI 9");
    ret.insert(btDI10, "DI 10");
    ret.insert(btDI11, "DI 11");
    ret.insert(btDI12, "DI 12");
    ret.insert(btDI13, "DI 13");
    ret.insert(btDI14, "DI 14");
    ret.insert(btDI15, "DI 15");
    ret.insert(btDI16, "DI 16");
    ret.insert(btAI1, "AI 1");
    ret.insert(btAI2, "AI 2");
    ret.insert(btAI3, "AI 3");
    ret.insert(btAI4, "AI 4");
    return ret;
}


//initialise the Key - Value for combobx
extern QMap<int, QString> TriggerTracePossible = GlobalEnumatedAndExtern::initTriggerTracePossible();

extern QString range0_24Txt = "0/24";
extern QString range0_30Txt = "0/30";
extern QString range15_15Txt = "-15/+15";


extern QString opNoneTxt = "NONE";
extern QString opOrTxt = "OR";
extern QString opAndTxt = "AND";
extern QString opNotOrTxt = "/ OR";
extern QString opNoTAnd = "/ AND";


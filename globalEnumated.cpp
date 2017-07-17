#include "globalEnumated.h"

GlobalEnumated::GlobalEnumated()
{

}

QMap<int, QString> GlobalEnumated::initTriggerTracePossible()
{

    QMap<int, QString> ret;
    ret.insert(btNone, "none");
    ret.insert(btDI1, "DI 1");
    ret.insert(btDI2, "DI 2");
    ret.insert(btDI3, "DI 3");
    ret.insert(btDI4, "DI 4");
    ret.insert(btAI1, "AI 1");
    ret.insert(btAI1, "AI 2");
    return ret;
}

extern QString range0_24Txt = "0 / 24";
extern QString range0_30Txt = "0 / 30";
extern QString range15_15Txt = "-15 / +15";


extern QString opNoneTxt = "NONE";
extern QString opOrTxt = "OR";
extern QString opAndTxt = "AND";
extern QString opNotOrTxt = "/ OR";
extern QString opNoTAnd = "/ AND";


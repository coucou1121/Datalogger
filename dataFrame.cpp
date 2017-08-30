#include "dataFrame.h"

DataFrame::DataFrame()
{
    _msbCPT = _lsbCPT = _DI1_8 = _DI9_16 = 0;
    _AI1 = _AI2 = _AI3 = _AI4 = 0;
    _TR1 = _TR_AI1 = _TR_AI2 = 0;
}

quint8 DataFrame::msbCPT() const
{
    return _msbCPT;
}

void DataFrame::setMsbCPT(const quint8 &msbCPT)
{
    _msbCPT = msbCPT;
}

quint8 DataFrame::lsbCPT() const
{
    return _lsbCPT;
}

void DataFrame::setLsbCPT(const quint8 &lsbCPT)
{
    _lsbCPT = lsbCPT;
}

quint8 DataFrame::DI1_8() const
{
    return _DI1_8;
}

void DataFrame::setDI1_8(const quint8 &DI1_8)
{
    _DI1_8 = DI1_8;
}

quint8 DataFrame::DI9_16() const
{
    return _DI9_16;
}

void DataFrame::setDI9_16(const quint8 &DI9_16)
{
    _DI9_16 = DI9_16;
}

quint8 DataFrame::AI1() const
{
    return _AI1;
}

void DataFrame::setAI1(const quint8 &AI1)
{
    _AI1 = AI1;
}

quint8 DataFrame::AI2() const
{
    return _AI2;
}

void DataFrame::setAI2(const quint8 &AI2)
{
    _AI2 = AI2;
}

quint8 DataFrame::AI3() const
{
    return _AI3;
}

void DataFrame::setAI3(const quint8 &AI3)
{
    _AI3 = AI3;
}

quint8 DataFrame::AI4() const
{
    return _AI4;
}

void DataFrame::setAI4(const quint8 &AI4)
{
    _AI4 = AI4;
}

void DataFrame::setTR1(const quint8 &TR1)
{
    _TR1 = TR1;
}

void DataFrame::displayValue()
{
    qDebug() << "CPT" << '\t' << _msbCPT << _lsbCPT << _DI1_8 << _DI9_16
             << _AI1 << _AI2 << _AI3 << _AI4 << _TR1;
}

quint8 DataFrame::TR_AI1() const
{
    return _TR_AI1;
}

void DataFrame::setTR_AI1(const quint8 &TR_AI1)
{
    _TR_AI1 = TR_AI1;
}

quint8 DataFrame::TR_AI2() const
{
    return _TR_AI2;
}

void DataFrame::setTR_AI2(const quint8 &TR_AI2)
{
    _TR_AI2 = TR_AI2;
}

quint8 DataFrame::TR1() const
{
    return _TR1;
}

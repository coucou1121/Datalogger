#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <QDebug>

class DataFrame
{
public:
    DataFrame();

    quint8 msbCPT() const;
    void setMsbCPT(const quint8 &msbCPT);

    quint8 lsbCPT() const;
    void setLsbCPT(const quint8 &lsbCPT);

    quint8 DI1_8() const;
    void setDI1_8(const quint8 &DI1_8);

    quint8 DI9_16() const;
    void setDI9_16(const quint8 &DI9_16);

    quint8 AI1() const;
    void setAI1(const quint8 &AI1);

    quint8 AI2() const;
    void setAI2(const quint8 &AI2);

    quint8 AI3() const;
    void setAI3(const quint8 &AI3);

    quint8 AI4() const;
    void setAI4(const quint8 &AI4);

    quint8 TR1() const;
    void setTR1(const quint8 &TR1);

    void displayValue();

private:

    //frame structure
    quint8 _msbCPT;
    quint8 _lsbCPT;
    quint8 _DI1_8;
    quint8 _DI9_16;
    quint8 _AI1;
    quint8 _AI2;
    quint8 _AI3;
    quint8 _AI4;
    quint8 _TR1;
};

#endif // DATAFRAME_H

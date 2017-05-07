#ifndef FRAMESIMULATOR_H
#define FRAMESIMULATOR_H

#include <QtCore/qglobal.h>
#include <iostream>
#include <iomanip>
#include <QtDebug>

#include "frameThread.h"

class FrameSimulator : public QObject
{
public:
    FrameSimulator();
    quint8 getMsbCPT() const;
    void setMsbCPT(const quint8 &value);

    quint8 getLsbCPT() const;
    void setLsbCPT(const quint8 &value);

    quint16 getAllDI() const;
    void setAllDI(const quint16 &value);

    quint8 getAI1() const;
    void setAI1(const quint8 &value);

    quint8 getAI2() const;
    void setAI2(const quint8 &value);

    quint8 getAI3() const;
    void setAI3(const quint8 &value);

    quint8 getAI4() const;
    void setAI4(const quint8 &value);


    quint64 getCPT() const;
    void setCPT(const quint64 &CPT);

public slots:
    void onValueChanged(int);
    void updateCount();
    void resetCPT();
    void displayValue();
    void incValue();

private:
    quint64 _CPT;
    quint8 _msbCPT;
    quint8 _lsbCPT;
    quint16 _allDI;
    quint8 _AI1;
    quint8 _AI2;
    quint8 _AI3;
    quint8 _AI4;

private slots:

};

#endif // FRAMESIMULATOR_H

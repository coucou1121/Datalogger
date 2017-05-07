#include "frameSimulator.h"

FrameSimulator::FrameSimulator()
{
    this->resetCPT();
}

quint8 FrameSimulator::getMsbCPT() const
{
    return _msbCPT;
}

void FrameSimulator::setMsbCPT(const quint8 &value)
{
    _msbCPT = value;
}

quint8 FrameSimulator::getLsbCPT() const
{
    return _lsbCPT;
}

void FrameSimulator::setLsbCPT(const quint8 &value)
{
    _lsbCPT = value;
}

quint16 FrameSimulator::getAllDI() const
{
    return _allDI;
}

void FrameSimulator::setAllDI(const quint16 &value)
{
    _allDI = value;
}

quint8 FrameSimulator::getAI1() const
{
    return _AI1;
}

void FrameSimulator::setAI1(const quint8 &value)
{
    _AI1 = value;
}

quint8 FrameSimulator::getAI2() const
{
    return _AI2;
}

void FrameSimulator::setAI2(const quint8 &value)
{
    _AI2 = value;
}

quint8 FrameSimulator::getAI3() const
{
    return _AI3;
}

void FrameSimulator::setAI3(const quint8 &value)
{
    _AI3 = value;
}

quint8 FrameSimulator::getAI4() const
{
    return _AI4;
}

void FrameSimulator::setAI4(const quint8 &value)
{
    _AI4 = value;
}

void FrameSimulator::displayValue()
{
    qDebug() << "CPT" << '\t' << _CPT  << _msbCPT
             << _lsbCPT << _allDI << _AI1
             << _AI2 << _AI3 << _AI4;
}

void FrameSimulator::incValue()
{
    _CPT = (_msbCPT << 8) | _lsbCPT;
    _CPT++;
    setLsbCPT(_CPT & 0xFF);
    setMsbCPT(_CPT >> 8);
    _allDI = _allDI < 255 ? _allDI+1 : 0;
    _AI1 = _AI1 < 255 ? _AI1+1 : 0;
    _AI2 = _AI1 >> 1;
    _AI3 = _AI1 >> 2;
    _AI4 = _AI1 >> 3;
}

quint64 FrameSimulator::getCPT() const
{
    return _CPT;
}

void FrameSimulator::setCPT(const quint64 &CPT)
{
    _CPT = CPT;
}

void FrameSimulator::resetCPT()
{
    _CPT = 0;
    _msbCPT = 0;
    _lsbCPT = 0;
    _allDI  = 0;
    _AI1 = 0;
    _AI2 = 0;
    _AI3 = 0;
    _AI4 = 0;
}

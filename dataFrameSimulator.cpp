#include "dataFrameSimulator.h"

DataFrameSimulator::DataFrameSimulator(QString name, QObject *parent) :
QObject(parent)
{
    this->setObjectName(name);
    this->resetFrame();
}

quint64 DataFrameSimulator::CPT() const
{
    return _CPT;
}

void DataFrameSimulator::setCPT(const quint64 &CPT)
{
    _CPT = CPT;
}

void DataFrameSimulator::resetFrame()
{
    _CPT = 0;
    _dataFrame.setDI1_8(0);
    _dataFrame.setDI9_16(0);
    _dataFrame.setAI1(0);
    _dataFrame.setAI2(0);
    _dataFrame.setAI3(0);
    _dataFrame.setAI4(0);
}

void DataFrameSimulator::incValue()
{
    quint8 lsbCPT;
    quint8 msbCPT;
    quint8 DI_1_8;
    quint8 DI_9_16;
    quint8 AI1, AI2, AI3, AI4;

    _CPT++;
    lsbCPT = (_CPT & 0xFF);
    msbCPT = (_CPT >> 8);
    DI_1_8 = lsbCPT;
    DI_9_16 = msbCPT;
    AI1 = lsbCPT;
    AI2 = AI1 >> 1;
    AI3 = AI1 >> 2;
    AI4 = AI1 >> 3;

    _dataFrame.setLsbCPT(lsbCPT);
    _dataFrame.setMsbCPT(msbCPT);
    _dataFrame.setDI1_8(DI_1_8);
    _dataFrame.setDI9_16(DI_9_16);
    _dataFrame.setAI1(AI1);
    _dataFrame.setAI2(AI2);
    _dataFrame.setAI3(AI3);
    _dataFrame.setAI4(AI4);

    qDebug() << objectName() << " Data increased " << _CPT;
    qDebug() << objectName() << " emit lsbCPT " << lsbCPT;
    emit valueUpdated(lsbCPT);
}

DataFrame DataFrameSimulator::dataFrame() const
{
    return _dataFrame;
}

void DataFrameSimulator::setDataFrame(const DataFrame &dataFrame)
{
    _dataFrame = dataFrame;
}

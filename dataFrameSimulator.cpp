#include "dataFrameSimulator.h"

DataFrameSimulator::DataFrameSimulator(QString name, QObject *parent) :
    QObject(parent),
    _dataFrame(new DataFrame())
{
    this->setObjectName(name);
    this->_resetFrame();
    _triggerFunction = new TriggerFunctions();
}

quint64 DataFrameSimulator::CPT() const
{
    return _CPT;
}

void DataFrameSimulator::setCPT(const quint64 &CPT)
{
    _CPT = CPT;
}

void DataFrameSimulator::_resetFrame()
{
    _CPT = 0;
    _dataFrame->setDI1_8(0);
    _dataFrame->setDI9_16(0);
    _dataFrame->setAI1(0);
    _dataFrame->setAI2(0);
    _dataFrame->setAI3(0);
    _dataFrame->setAI4(0);
    _dataFrame->setTR1(0);
}

void DataFrameSimulator::_incValue()
{
    quint8 lsbCPT;
    quint8 msbCPT;
    quint8 DI_1_8;
    quint8 DI_9_16;
    quint8 AI1, AI2, AI3, AI4;
    quint8 TR1;

    _CPT++;
    lsbCPT = (_CPT & 0xFF);
    msbCPT = (_CPT >> 8);
    DI_1_8 = lsbCPT;
    DI_9_16 = msbCPT;
    AI1 = lsbCPT;
    AI2 = (_CPT >> 1) & 0xFF;
    AI3 = (_CPT >> 2) & 0xFF;
    AI4 = (_CPT >> 3) & 0xFF;

    _dataFrame->setLsbCPT(lsbCPT);
    _dataFrame->setMsbCPT(msbCPT);
    _dataFrame->setDI1_8(DI_1_8);
    _dataFrame->setDI9_16(DI_9_16);
    _dataFrame->setAI1(AI1);
    _dataFrame->setAI2(AI2);
    _dataFrame->setAI3(AI3);
    _dataFrame->setAI4(AI4);
    _dataFrame->setTR1(TR1);
}

void DataFrameSimulator::setItConsumerAdress(const QVector<DataFrame>::iterator &itConsumerAdress)
{
    _itConsumerAdress = itConsumerAdress;
}

void DataFrameSimulator::setItProducer(const QVector<DataFrame>::iterator &itProducer)
{
    _itProducer = itProducer;
}

DataFrame *DataFrameSimulator::dataFrame() const
{
    return _dataFrame;
}

void DataFrameSimulator::setDataFrame(DataFrame *dataFrame)
{
    _dataFrame = dataFrame;
}

void DataFrameSimulator::setDataFrameVectorReccorder(QVector<DataFrame> *dataFrameVectorReccorder)
{
    _dataFrameVectorReccorder = dataFrameVectorReccorder;
}

void DataFrameSimulator::createDataFrame()
{
    //    qDebug() << objectName() << "received " << "createDataFrame";
    timerElapse.restart();
    //int itProducteurAdress = (int)&(_itProducer);
    quint16 i = 0;
//    qDebug() << objectName();
//    qDebug() << "adress Cosumer  : " << _itConsumerAdress;
//    qDebug() << "adress Producer : " << _itProducer;
//    qDebug() << "adress Producer : " << (int)_itProducer;

    for(i=0; i<NB_FRAME_CREATE_AT_EVERY_TICK; i++)
    {
        //if data creation arrive on reading thread
        //stop for the rest of creation and wait the next tick
         if(_itConsumerAdress != _itProducer)
         {
             _incValue();
             *this->_itProducer = *this->_dataFrame;
             this->_itProducer++;
             this->_itProducer = this->_itProducer < _dataFrameVectorReccorder->end() ? this->_itProducer : this->_dataFrameVectorReccorder->begin();
//             _itProducer->displayValue();
         }
        //create new frame
        //put in circular buffer
//        qDebug() << "\nnew value";
//        _dataFrame->displayValue();
//        qDebug() << "\narray";
//        qDebug() << objectName();
//        for(QVector<DataFrame>::iterator it = _dataFrameVectorReccorder->begin(); it != _dataFrameVectorReccorder->end(); it++)
//        {
//            it->displayValue();
//        }
 //       qDebug() << (int)&(*_itProducer);

    }
    emit dataFrameWasSent((int)this->_itProducer);

    //qDebug() << "createDataFrame took" << timerElapse.nsecsElapsed()/1000 << "micro oseconds" << " for " << i << " values.";
    //    emit dataFrameWasSent(_dataFrameVector);
    //    qDebug() << objectName() << "newDataFrameSent size : " << _dataFrameVector.size();
//    _dataFrameVector.clear();
}

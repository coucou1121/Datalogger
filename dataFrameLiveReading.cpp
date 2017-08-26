#include "dataFrameLiveReading.h"

DataFrameLiveReading::DataFrameLiveReading(QString name, int nbFrameReadEveryCycle, QObject *parent) :
    QObject(parent),
    _nbFrameReadEveryCycle(nbFrameReadEveryCycle),
    _dataFrameTraceBuffer(nbFrameReadEveryCycle),
    _inReadingProcess(false),
    _FTDIdevice(new FTDIFunction("FTDI Device"))
{
    this->setObjectName(name);
}

void DataFrameLiveReading::setDataFrameVectorReccorder(QVector<DataFrame> *dataFrameVectorReccorder)
{
    _dataFrameVectorReccorder = dataFrameVectorReccorder;
}

void DataFrameLiveReading::setItProducer(const QVector<DataFrame>::iterator &itProducer)
{
    _itProducer = itProducer;
}

void DataFrameLiveReading::setItConsumerAdress(const QVector<DataFrame>::iterator &itConsumerAdress)
{
    _itConsumerAdress = itConsumerAdress;
}

void DataFrameLiveReading::runReading()
{
    static bool wasRunning = false;

    qDebug() << this->objectName() << "ask for starting";
    this->startReading();


  //  while(true)
 //   {
        if(_inReadingProcess && !wasRunning)
        {
            qDebug() << this->objectName() << "thread start reading";
            wasRunning = true;
            this->startReading();

        }

        if(!_inReadingProcess && wasRunning)
        {
            qDebug() << this->objectName() << "thread stop reading";
            wasRunning = false;
            this->stopReading();
        }
 //   }
}

void DataFrameLiveReading::startReading()
{
    this->_inReadingProcess = true;
    int dataToWrite = (int)GlobalEnumatedAndExtern::transmissionEnquiry;
    int dataReceived = 0;

    this->_FTDIdevice->liveReading(&dataToWrite);
}

void DataFrameLiveReading::stopReading()
{
    this->_inReadingProcess = false;
    this->_FTDIdevice->sendStop();
}


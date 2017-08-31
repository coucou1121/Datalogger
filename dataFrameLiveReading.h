#ifndef DATAFRAMELIVEREADING_H
#define DATAFRAMELIVEREADING_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QTime>
#include "FTDIFunction.h"
#include "globalEnumatedAndExtern.h"

class DataFrameLiveReading : public QObject
{
    Q_OBJECT

public:
    explicit DataFrameLiveReading(QString name, int nbFrameReadEveryCycle, QObject *parent = 0);


    void setDataFrameVectorReccorder(QVector<DataFrame> *dataFrameVectorReccorder);
    void setItProducer(const QVector<DataFrame>::iterator &itProducer);
    void setItConsumerAdress(const QVector<DataFrame>::iterator &itConsumerAdress);

    //start real time reading
    void startReading();
    void stopReading();

private:

    bool _inReadingProcess;
    //FTDI connection and functions
    FTDIFunction *_FTDIdevice;

    quint32 _baudRateSpeed2M;
    quint16 _baudRateSpeed9600;

    //actif wait delay
    void _waitDelay(int delayInSeconde);

    //circular buffer
    QVector<DataFrame> *_dataFrameVectorReccorder;
    QVector<DataFrame>::iterator _itProducer;
    QVector<DataFrame>::iterator _itConsumerAdress;

    //number of frame reading every cycle
    int _nbFrameReadEveryCycle;

    //temporary buffer for new Datas
    QVector<DataFrame> _dataFrameTraceBuffer;
    QVector<DataFrame>::iterator _itdataFrameTrace;

public slots:
     void runReading();

signals:
    void dataFrameWasSent(int itProducerAdress);
    void _startRealTimeDataReadieng();
};

#endif // DATAFRAMELIVEREADING_H

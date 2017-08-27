#ifndef DATAFRAMESIMULATOR_H
#define DATAFRAMESIMULATOR_H

#define NB_FRAME_CREATE_AT_EVERY_TICK 1000

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include "dataFrame.h"
#include "triggerFunctions.h"

class DataFrameSimulator : public QObject
{
    Q_OBJECT

public:
    DataFrameSimulator(QString name, QObject *parent = 0);

    quint64 CPT() const;
    void setCPT(const quint64 &CPT);


    void setDataFrameVectorReccorder(QVector<DataFrame> *dataFrameVectorReccorder);

    DataFrame *dataFrame() const;
    void setDataFrame(DataFrame *dataFrame);

    void setItProducer(const QVector<DataFrame>::iterator &itProducer);
    void setItConsumerAdress(const QVector<DataFrame>::iterator &itConsumerAdress);

private:
    DataFrame *_dataFrame;
    quint64 _CPT;
    QElapsedTimer timerElapse;
    QVector<DataFrame> _dataFrameVector;
    TriggerFunctions *_triggerFunction;
    void _resetFrame();
    void _incValue();

    QVector<DataFrame> *_dataFrameVectorReccorder;
    QVector<DataFrame>::iterator _itProducer;
    QVector<DataFrame>::iterator _itConsumerAdress;

public slots:
    void createDataFrame();

signals:
    // void dataFrameWasSent(QVector<DataFrame> newDataFrameVector);
    void dataFrameWasSent(int itProducerAdress);
};

#endif // DATAFRAMESIMULATOR_H

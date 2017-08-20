#ifndef DATAFRAMESIMULATOR_H
#define DATAFRAMESIMULATOR_H

#define NB_FRAME_CREATE_AT_EVERY_TICK 2

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

    DataFrame dataFrame() const;
    void setDataFrame(const DataFrame &dataFrame);

private:
    DataFrame _dataFrame;
    quint64 _CPT;
    QElapsedTimer timerElapse;
    QVector<DataFrame> _dataFrameVector;
    TriggerFunctions *_triggerFunction;
    void _resetFrame();
    void _incValue();

public slots:
    void createDataFrame();

signals:
    void dataFrameWasSent(QVector<DataFrame> newDataFrameVector);
};

#endif // DATAFRAMESIMULATOR_H

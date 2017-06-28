#ifndef DATAFRAMESIMULATOR_H
#define DATAFRAMESIMULATOR_H

#define NB_FRAME_CREATE_AT_EVERY_TICK 100
#include <QObject>
#include <QDebug>
#include "dataFrame.h"

class DataFrameSimulator : public QObject
{
    Q_OBJECT

public:
    DataFrameSimulator(QString name, QObject *parent = 0);

    quint64 CPT() const;
    void setCPT(const quint64 &CPT);

    DataFrame dataFrame() const;
    void setDataFrame(const DataFrame &dataFrame);

signals:
    void dataFramUpdate(QVector<DataFrame> newDataFrameVector);
    void valueDI1_8Updated(quint8 value);
    void valueDI9_16Updated(quint8 value);
    void valueAI1Updated(quint8 value);
    void valueAI2Updated(quint8 value);
    void valueAI3Updated(quint8 value);
    void valueAI4Updated(quint8 value);


public slots:
    void resetFrame();
    void incValue();
    void createDataFrame();

private:
    DataFrame _dataFrame;
    quint64 _CPT;
    QVector<DataFrame> _dataFrameVector;
};

#endif // DATAFRAMESIMULATOR_H

#ifndef DATAFRAMESIMULATOR_H
#define DATAFRAMESIMULATOR_H

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
    void valueAI1Updated(quint8 value);
    void valueAI2Updated(quint8 value);
    void valueAI3Updated(quint8 value);
    void valueAI4Updated(quint8 value);


public slots:
    void resetFrame();
    void incValue();

private:
    DataFrame _dataFrame;
    quint64 _CPT;
};

#endif // DATAFRAMESIMULATOR_H

#ifndef DATAANALYSER_H
#define DATAANALYSER_H

#include <QDebug>

class DataAnalyser
{
public:
    DataAnalyser();

public slots:
    void frameReceived();
};

#endif // DATAANALYSER_H

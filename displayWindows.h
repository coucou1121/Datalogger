#ifndef DISPLAYWINDOWS_H
#define DISPLAYWINDOWS_H

#include <QWidget>
#include <QElapsedTimer>

#include "commonStyle.h"
#include "dataFrameSimulator.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class DisplayWindows;
}

class DisplayWindows : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindows(QWidget *parent = 0);
    ~DisplayWindows();

public slots:

private:
    Ui::DisplayWindows *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

    //style
    QPalette _palette;
    CommonStyle _myStyle;
    QElapsedTimer timerElapse;
    void setupStyle();

public slots:
    void _addTrace(int enumTrace);
    void _hideTrace(int enumTrace);

    void updatePlot();

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);
    void addValueDI1_8(quint8 value);
    void addValueDI9_16(quint8 value);

    void addValueAI1(quint8 value);
    void addValueAI2(quint8 value);
    void addValueAI3(quint8 value);
    void addValueAI4(quint8 value);

};

#endif // DISPLAYWINDOWS_H

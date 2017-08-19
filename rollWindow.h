#ifndef ROLLWINDOW_H
#define ROLLWINDOW_H

#include <QWidget>
#include <QElapsedTimer>

#include "commonStyle.h"
#include "dataFrameSimulator.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class RollWindow;
}

class RollWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RollWindow(QWidget *parent = 0);
    ~RollWindow();

    //direction du draw
    // if true, draw left to right, mode roll on
    // if flase, draw right to left, mode trig
    void setDrawRightToLeft(bool drawRightToLeft);

    // update the plot
    void refreshPlot();

private:
    Ui::RollWindow *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

    //style
    //QPalette _palette;
    //CommonStyle _myStyle;
    QElapsedTimer timerElapse;
    //void setupStyle();

    void addValueDI1_8(quint8 value);
    void addValueDI9_16(quint8 value);

    void addValueAI1(quint8 value);
    void addValueAI2(quint8 value);
    void addValueAI3(quint8 value);
    void addValueAI4(quint8 value);

public slots:
    void addTrace(quint8 enumTrace);
    void hideTrace(quint8 enumTrace);

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);


};

#endif // ROLLWINDOW_H

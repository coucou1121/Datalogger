#ifndef DisplayWindow_H
#define DisplayWindow_H

#include <QWidget>
#include <QElapsedTimer>

#include "commonStyle.h"
#include "dataFrameSimulator.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = 0);
    ~DisplayWindow();

    //direction du draw
    // if true, draw left to right, mode roll on
    // if flase, draw right to left, mode trig
    void setDrawLeftToRight(bool drawLeftToRight);

    // update the plot
    void refreshPlot();

private:
    Ui::DisplayWindow *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

    //style
    //QPalette _palette;
    //CommonStyle _myStyle;
    QElapsedTimer timerElapse;
    //void setupStyle();

public slots:
    void _addTrace(int enumTrace);
    void _hideTrace(int enumTrace);

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);
    void addValueDI1_8(quint8 value);
    void addValueDI9_16(quint8 value);

    void addValueAI1(quint8 value);
    void addValueAI2(quint8 value);
    void addValueAI3(quint8 value);
    void addValueAI4(quint8 value);

};

#endif // DisplayWindow_H

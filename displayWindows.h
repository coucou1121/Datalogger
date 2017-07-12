#ifndef DISPLAYWINDOWS_H
#define DISPLAYWINDOWS_H

#include <QWidget>
#include <QElapsedTimer>

#include "commonStyle.h"
#include "dataFrameSimulator.h"

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
    void updatePlot();

    void addNewDataFrame(QVector<DataFrame> newDataFrameVector);
    void addValueDI1_8(quint8 value);
    void addValueDI9_16(quint8 value);

    void addValueAI1(quint8 value);
    void addValueAI2(quint8 value);
    void addValueAI3(quint8 value);
    void addValueAI4(quint8 value);

private:
    Ui::DisplayWindows *ui;

    //style
    QPalette _palette;
    CommonStyle _myStyle;
    QElapsedTimer timerElapse;
    void setupStyle();
};

#endif // DISPLAYWINDOWS_H

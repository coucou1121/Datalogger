#ifndef PLOTSETTING_H
#define PLOTSETTING_H

#include <QFrame>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

namespace Ui {
class PlotSetting;
}

class PlotSetting : public QFrame
{
    Q_OBJECT

public:
    explicit PlotSetting(QWidget *parent = 0);
    ~PlotSetting();


    void setSizeOfPlots(int nbPixels);
    void setTitle(QString nameTxt);
    void setStartValue(double startValue);
    void setMinimum(double valueMin);
    void setMaximum(double valueMin);
    void setStep(double stepValue);

private:
    Ui::PlotSetting *ui;

    CommonStyle _myStyle;
    void setupStyle();

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

signals:
     void _settingSizeOfPlotWasChanged(int nbPixels);
};

#endif // PLOTSETTING_H

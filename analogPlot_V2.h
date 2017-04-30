#ifndef ANALOGPLOT_V2_H
#define ANALOGPLOT_V2_H

#include <QWidget>

namespace Ui {
class AnalogPlot_V2;
}

class AnalogPlot_V2 : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogPlot_V2(QWidget *parent = 0);
    ~AnalogPlot_V2();

private:
    Ui::AnalogPlot_V2 *ui;
};

#endif // ANALOGPLOT_V2_H

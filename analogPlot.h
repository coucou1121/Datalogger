#ifndef ANALOGPLOT_H
#define ANALOGPLOT_H

#include <QWidget>

namespace Ui {
class AnalogPlot;
}

class AnalogPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogPlot(QWidget *parent = 0);
    ~AnalogPlot();

private:
    Ui::AnalogPlot *ui;
};

#endif // ANALOGPLOT_H

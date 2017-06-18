#ifndef DISPLAYWINDOWS_H
#define DISPLAYWINDOWS_H

#include <QWidget>

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
    void replot();
    void addValueAI1(quint8 value);
    void addValueAI2(quint8 value);
    void addValueAI3(quint8 value);
    void addValueAI4(quint8 value);

private:
    Ui::DisplayWindows *ui;
};

#endif // DISPLAYWINDOWS_H

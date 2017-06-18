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

private:
    Ui::DisplayWindows *ui;
};

#endif // DISPLAYWINDOWS_H

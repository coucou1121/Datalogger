#ifndef STATEFRAME_H
#define STATEFRAME_H

#include <QWidget>

namespace Ui {
class StateFrame;
}

class StateFrame : public QWidget
{
    Q_OBJECT

public:
    explicit StateFrame(QWidget *parent = 0);
    ~StateFrame();

    void setStateStop();

private:
    Ui::StateFrame *ui;
};

#endif // STATEFRAME_H

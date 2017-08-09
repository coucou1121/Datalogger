#ifndef STATEFRAME_H
#define STATEFRAME_H

#include <QWidget>
#include <QDebug>
#include "globalEnumatedAndExtern.h"

namespace Ui {
class StateFrame;
}

class StateFrame : public QWidget
{
    Q_OBJECT

public:
    explicit StateFrame(QWidget *parent = 0);
    ~StateFrame();

    void setMainState(GlobalEnumatedAndExtern::eMainState stateApp);

private:
    Ui::StateFrame *ui;

    GlobalEnumatedAndExtern::eMainState _mainsStateActualy;

    //key value for main state of application
    QMap<int, QString> _mainStatePossible;

    //logo
    QPixmap *_pixStateStop;
    QPixmap *_pixStatePause;
    QPixmap *_pixStateRunTrig;
    QPixmap *_pixStateOnTrig;
    QPixmap *_pixStateRollOn;
};

#endif // STATEFRAME_H

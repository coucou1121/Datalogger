#ifndef TRIGGERWINDOW_H
#define TRIGGERWINDOW_H

#include <QFrame>
#include "globalEnumatedAndExtern.h"

namespace Ui {
class TriggerWindow;
}

class TriggerWindow : public QFrame
{
    Q_OBJECT

public:
    explicit TriggerWindow(QWidget *parent = 0);
    ~TriggerWindow();

private:
    Ui::TriggerWindow *ui;

    //key value for Trace label name
    QMap<int, QString> TriggerTracePossible;

    void _setAllTraceName();
    void _hideAllTrace();

public slots:
    void _addTrace(int enumTrace);
    void _hideTrace(int enumTrace);
};

#endif // TRIGGERWINDOW_H

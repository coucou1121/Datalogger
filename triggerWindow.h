#ifndef TRIGGERWINDOW_H
#define TRIGGERWINDOW_H

#include <QFrame>

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
};

#endif // TRIGGERWINDOW_H

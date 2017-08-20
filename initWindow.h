#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QFrame>

namespace Ui {
class InitWindow;
}

class InitWindow : public QFrame
{
    Q_OBJECT

public:
    explicit InitWindow(QWidget *parent = 0);
    ~InitWindow();

    void addTextInLabel(QString text);

private:
    Ui::InitWindow *ui;
};

#endif // INITWINDOW_H

#ifndef ERRORFRAME_H
#define ERRORFRAME_H

#include <QWidget>

namespace Ui {
class ErrorFrame;
}

class ErrorFrame : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorFrame(QWidget *parent = 0);
    ~ErrorFrame();

    void setBackgroundColor(QColor colorBackGround, QColor colorTopLine);

private:
    Ui::ErrorFrame *ui;
};

#endif // ERRORFRAME_H

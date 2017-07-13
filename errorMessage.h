#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QWidget>

namespace Ui {
class ErrorMessage;
}

class ErrorMessage : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorMessage(QWidget *parent = 0);
    ~ErrorMessage();

private:
    Ui::ErrorMessage *ui;
};

#endif // ERRORMESSAGE_H

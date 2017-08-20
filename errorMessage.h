#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QWidget>
#include <QDebug>
#include "commonStyle.h"
#include "globalEnumatedAndExtern.h"

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

    //Style
    CommonStyle _myStyle;

    QMap<int, QString> _errorListPossible;
    QMap<int, QString> _errorListNow;

    void _setColor(bool inTrouble);
    void _displayMessage();

private slots:
    void _reveived_Error(quint8 errorNumber, bool active);

};

#endif // ERRORMESSAGE_H

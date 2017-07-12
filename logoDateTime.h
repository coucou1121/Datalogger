#ifndef LOGODATETIME_H
#define LOGODATETIME_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include "commonStyle.h"

namespace Ui {
class LogoDateTime;
}

class LogoDateTime : public QWidget
{
    Q_OBJECT

public:
    explicit LogoDateTime(QWidget *parent = 0);
    ~LogoDateTime();

private:  
    Ui::LogoDateTime *ui;
    QTimer *timer;
    QDate dateToDay;
    QTime TimeToDay;
    QDateTime today;

    //style
    CommonStyle _myStyle;

private slots:
    void showTime();

};

#endif // LOGODATETIME_H

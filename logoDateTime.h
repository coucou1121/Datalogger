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
    QTimer *_timer;
    QDate _dateToDay;
    QTime _timeToDay;
    QDateTime _dateTimeToDay;

    //style
    CommonStyle _myStyle;

private slots:
    void _showTime();

};

#endif // LOGODATETIME_H

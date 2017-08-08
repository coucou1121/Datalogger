#ifndef REFRESHTIMER_H
#define REFRESHTIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <Windows.h>
#include <QElapsedTimer>

class refreshTimer : public QObject
{
    Q_OBJECT

public:
    explicit refreshTimer(bool isCounting, QString name, int timeInterval, QObject *parent = 0);
    void startTimer();
    void stopTimer();

public slots:
    void updateCount();

signals:
    void error(QString err);
    void tickFinished();

private:
    QTimer *timer;
    quint64 count = 0;
    bool _isCounting;
    int _timeInterval;

    QElapsedTimer timerElapse;     
};

#endif // REFRESHTIMER_H

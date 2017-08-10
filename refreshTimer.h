#ifndef REFRESHTIMER_H
#define REFRESHTIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>

class refreshTimer : public QObject
{
    Q_OBJECT

public:
    explicit refreshTimer(bool isCounting, QString name, int timeInterval, QObject *parent = 0);
    void startTimer();
    void stopTimer();

private:
    QTimer *_timer;
    quint64 _count;
    bool _isCounting;
    int _timeInterval;
    QElapsedTimer _timerElapse;

private slots:
    void _updateCount();

signals:
    void _tickFinished();

};

#endif // REFRESHTIMER_H

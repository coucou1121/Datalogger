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
    explicit refreshTimer(bool wantToSleep, QString name, int timeInterval, QObject *parent = 0);

public slots:
    void updateCount();

signals:
    void error(QString err);
    void tickFinished();

private:
    QTimer *timer;
    quint64 count = 0;
    bool m_wantToSleep;

    QElapsedTimer timerElapse;     
};

#endif // REFRESHTIMER_H

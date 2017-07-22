#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QFrame>
#include <QDebug>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QFrame
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

    //setter
    void setNbSavedFrame(quint64 nbSavedFrame);
    void setFrameSize(int frameSize);
    void setBaudRateFTDI(const quint32 &baudRateFTDI);

private:
    Ui::DebugWindow *ui;

    quint64 _nbSavedFrame;
    int _frameSize;
    quint32 _baudRateFTDI;

private slots:
    void on_lineEditNbSavedFrame_textChanged(const QString &arg1);
    void on_lineEditFrameSize_textChanged(const QString &arg1);
    void on_lineEditBaudrate_textChanged(const QString &arg1);

signals:

    //send value if the saved frame number changed
    void _nbFrameSavedChanged(quint64 _nbSavedFrame);

    //send value if the size of frame was changed
    void _frameSizeChanged(int _frameSize);

    //send value if FTDI baudrate was changed
    void _FTDIBaudrateChanged(int _frameSize);
};

#endif // DEBUGWINDOW_H

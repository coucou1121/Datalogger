#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QFrame>
#include <QDebug>
#include <QTextBlock>
//#include "FTDIFunction.h"
#include "globalEnumatedAndExtern.h"
#include "dataFrame.h"

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
//    void setFTDI_Device(FTDIFunction *FTDI_Device);
//    void setFTDIdevice(FTDIFunction *FTDIdevice);

    //received data
    void receivedNewData(DataFrame *newDataFrame);

private:
    Ui::DebugWindow *ui;

    quint64 _nbSavedFrame;
    int _frameSize;
    quint32 _baudRateFTDI;

//    FTDIFunction *_FTDI_Device;

    //create the FTDI object
//    FTDIFunction *_FTDIdevice;

    //creat message possible
    QMap<int, QString> _FTDIReturnMessagePossibleTxt;

    //check if FTDI device was found
//    bool _FTDIDeviceFound();

    //read FTDI device info and display in text windows on debug menu
//    void _FTDIReadInfo();

    //add text in text widget on debug windows
    void _addTextInLabel(QString text);

private slots:
    void on_lineEditNbSavedFrame_textChanged(const QString &arg1);
    void on_lineEditFrameSize_textChanged(const QString &arg1);
    void on_lineEditBaudrate_textChanged(const QString &arg1);

    void on_pushButtonFTDIInfo_released();
    void on_pushButtonSendStart_released();
    void on_pushButtonFTDIStopRead_released();

    void on_checkBoxEmulationMode_toggled(bool checked);

    void on_pushButtonSendChar_released();

    void on_pushButtonFTDIStartReadData_released();

    void on_pushButtonFTDIStopReadData_released();

    void on_pushButtonCleanText_released();

signals:

    //send value if the saved frame number changed
    void _nbFrameSavedChanged(quint64 _nbSavedFrame);

    //send value if the size of frame was changed
    void _frameSizeChanged(int _frameSize);

    //send value if FTDI baudrate was changed
    void _FTDIBaudrateChanged(int _frameSize);

    //reset the error in case of emulation
    void _checkBoxEmulationModeStatusWasChanged(bool checked);
};

#endif // DEBUGWINDOW_H

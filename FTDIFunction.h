#ifndef FTDIFUNCTION_H
#define FTDIFUNCTION_H

#include <QObject>
#include <QDebug>
#include "FTDI/ftd2xx.h"
#include <QtGlobal>
#include "dataFrame.h"
#include "globalEnumatedAndExtern.h"

#define BAUD_RATE_9600  9600   //  speed of the USB port transfer at 9600 bits/sec
#define BAUD_RATE_2M  2000000  //  speed of the USB port transfer at 2'000'000 bits/sec

#define NB_LIVE_READING_DATA 1000
#define FRAME_SIZE    8                 //bytes
#define BUFFER_SIZE   FRAME_SIZE*NB_LIVE_READING_DATA   //bytes

class FTDIFunction : public QObject
{
    Q_OBJECT

public:
    FTDIFunction(QString name, QObject *parent = 0);
    int open();
    void ReadDeviceInfo();
    int setUSBparameter();
    int setBaudRate(quint64 baudRateSpeed);
    int setFlowControl();
    int setDataCaracteristique();
    int setRTS();
    int resetRTS();
    int resetdevice();
    int freeTxRxBuffer();
    int readDataOneChar(DWORD dwRxSize);
    int writeDataOneChar(int *data);
    void liveReading(int *dataStart);
    quint8 sendStop();

    void realTimeAcquisitionStart();

    FT_STATUS ftStatus() const;
    DWORD numDevs() const;
    DWORD Flags() const;
    DWORD ID() const;
    DWORD Type() const;
    DWORD LocId() const;
    QString SerialNumber();
    QString Description();

    QVector<DataFrame>::iterator itDataFrameBufferArray() const;
    void setItDataFrameBufferArray(const QVector<DataFrame>::iterator &itDataFrameBufferArray);

    bool FTDI_OK() const;

    GlobalEnumatedAndExtern::eFTDIStatePossible FTDIState() const;

    void setDataFrameVectorReccorder(QVector<DataFrame> *dataFrameVectorReccorder);

    DataFrame *newDataFrame() const;
    void setNewDataFrame(DataFrame *newDataFrame);

    void setItConsumerAdress(const QVector<DataFrame>::iterator &itConsumerAdress);
    void setItProducer(const QVector<DataFrame>::iterator &itProducer);

private:

    //FTDI value from chip
    FT_HANDLE _ftHandle;
    FT_DEVICE _ftDevice;
    FT_STATUS _ftStatus;
    DWORD _numDevs;
    DWORD _Flags;
    DWORD _ID;
    DWORD _Type;
    DWORD _LocId;
    char _SerialNumber[16];
    char _Description[64];
    int _iport;
    int _dataSend;
    int _dataReceved;
    int _dataStart;
    int _dataStop;
    DWORD 	_dwBytesWritten;
    DWORD _dwBytesRead;

    //connection
    bool _FTDIconnection();
    bool _FTDI_OK;
    quint32 _baudRateSpeed2M;
    quint16 _baudRateSpeed9600;

    //state of FTDI connection
    GlobalEnumatedAndExtern::eFTDIStatePossible _FTDIState;

    void initVariable();

    //read flow data from chips and save in buf
    unsigned char buf[BUFFER_SIZE];

    //counter for check the data is
    char counterValueHigh, counterValueLow;

    //application
    unsigned long i,j,k,l,m;
    long int counterValue, memoCounterValue, counterError, counterValueFind;
    unsigned long int trameNumberRead;
    FT_HANDLE ftHandle() const;
    void setFtHandle(const FT_HANDLE &ftHandle);

    //temporary buffer for new Datas
    DataFrame *_newDataFrame;
    QVector<DataFrame> *_dataFrameVectorReccorder;
    QVector<DataFrame>::iterator _itProducer;
    QVector<DataFrame>::iterator _itConsumerAdress;

//    QVector<DataFrame> _newData;
//    QVector<DataFrame>::iterator _itDataFrameBufferArray;

public slots:
    void received_connectFTDIDevice();
//    void received_readRealTimeData();

signals:
    void dataFrameWasSent(int itProducerAdress);
//    void _startReading();

};

#endif // FTDIFUNCTION_H

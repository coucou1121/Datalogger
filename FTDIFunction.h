#ifndef FTDIFUNCTION_H
#define FTDIFUNCTION_H

//#include "FTDI/ftd2xx.h"
//#include "FTDI/static/ftd2xx.h"
#include "CDM v2.12.26 WHQL Certified/ftd2xx.h"
#include <QtGlobal>


#define BAUD_RATE_9600  9600   //  speed of the USB port transfer at 9600 bits/sec
#define BAUD_RATE_2M  2000000  //  speed of the USB port transfer at 2'000'000 bits/sec

#define FRAME_SIZE    8                 //bytes
#define BUFFER_SIZE   FRAME_SIZE*16     //bytes

class FTDIFunction
{
public:
    FTDIFunction();
    int open();
    void ReadDeviceInfo();
    int setUSBparameter();
    int setBaudRate(quint16 baudRateSpeed);
    int setFlowControl();
    int setDataCaracteristique();
    int setRTS();
    int resetRTS();
    int resetdevice();
    int freeTxRxBuffer();
    int readDataOneChar(DWORD dwRxSize);
    int writeDataOneChar(int *data);
    void liveReading(int *dataStart);

// private:
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


    void initVariable();
    //read data
    unsigned char buf[BUFFER_SIZE];
    char counterValueHigh, counterValueLow;

    //application
    unsigned long i,j,k,l,m;
    long int counterValue, memoCounterValue, counterError, counterValueFind;
    unsigned long int trameNumberRead;
};

#endif // FTDIFUNCTION_H

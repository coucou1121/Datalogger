#include "FTDIFunction.h"
#include <QDebug>

FTDIFunction::FTDIFunction()
{
    _ftStatus = FT_CreateDeviceInfoList(&_numDevs);
    qDebug() << "Number of devices is " << _numDevs;
    _ftStatus = FT_GetDeviceInfoDetail(0, &_Flags, &_Type, &_ID, &_LocId, _SerialNumber,
                                       _Description,          &_ftHandle);
    if(_ftStatus == FT_OK)
    {
        qDebug() << "Device created";
    }
    else
    {
        qDebug() << "Deviced not created" << _numDevs;
    }
}

int FTDIFunction::open()
{
    _ftStatus = FT_Open(_iport, &_ftHandle);

    if(_ftStatus != FT_OK)
    {
        qDebug() << "Error: FT_Open returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "FTDI opened";
    }
    return((int)_ftStatus);

}

void FTDIFunction::ReadDeviceInfo()
{
    if (_numDevs > 0)
    {
        if (_ftStatus == FT_OK)
        {
            qDebug() << "Dev founded";
            qDebug() << "Flags = 0x" << _Flags;
            qDebug() << "Type  = 0x" << _Type;
            qDebug() << "ID    = 0x" << _ID;
            qDebug() << "LocId = 0x" << _LocId;
            qDebug() << "SerialNumber = " << _SerialNumber;
            qDebug() << "Description  = " << _Description;
            qDebug() << "ftHandle     = " << _ftHandle;
        }
    }
}

int FTDIFunction::setUSBparameter()
{
    // the USB request transfer siye
    //param@1: fthandle Handle of the device
    //param@2: DWORD    Transfer siye for USB IN request
    //param@3: DWORD    Transfer siye for USB OUT request

    _ftStatus = FT_SetUSBParameters(_ftHandle, 256, 128);
    if(_ftStatus != FT_OK)
    {
        qDebug() << "Error: FT_SetUSBParameters returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "USB :\t\tset";
    }
    return((int)_ftStatus);
}

int FTDIFunction::setBaudRate(quint16 baudRateSpeed)
{
    //set the baud rate for the device
    //param@1: fthandle      Handle of the device
    //param@2: dwBaudRate    Baud rate
    _ftStatus = FT_SetBaudRate(_ftHandle, baudRateSpeed);
    //    _ftStatus = FT_SetBaudRate(_ftHandle, BAUD_RATE_9600);
    if(_ftStatus != FT_OK)
    {
        qDebug() << "Error: FT_SetBaudRate returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "Baud rate :\t\t" << baudRateSpeed;
        //        qDebug() << "Baud rate :\t\t" << BAUD_RATE_9600;
    }
    return((int)_ftStatus);
}

int FTDIFunction::setFlowControl()
{
    //set the flow contole for the device
    //param@1: Handle of the device
    //param@2 : FT_FLOW_NONE       no control
    //          FT_FLOW_RTS_CTS    hardware conrol
    //          FT_FLOW_DTR_DSR    ... conrol
    //          FT_FLOW_XON_XOFF   caracter conrol
    _ftStatus = FT_SetFlowControl(_ftHandle, FT_FLOW_RTS_CTS, 0, 0);

    if (_ftStatus != FT_OK)
    {
        qDebug() << "Error: FT_SetFlowControl returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "Flow Controle:\tFT_FLOW_RTS_CTS";
    }
    return((int)_ftStatus);
}

int FTDIFunction::setDataCaracteristique()
{
    // Set the data caract[riatique for the device
    //param@1: fthandle     Handle of the device
    //param@2: uWordLenght  Number of bits per word,  must be FT_BITS_8 or FT_BITS_7
    //param@3: uStopBits    Number of stop bits, muste be FT_STOP_BITS_1 or FT_STOP_BITS_2
    //param@4: uParitz      Paritz, muste be FT_PARTIY_NONE, FT_PARITY_ODD, FT_PARITY_EVEN or FT_PARITY_SPACE
    _ftStatus= FT_SetDataCharacteristics(_ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);

    if (_ftStatus != FT_OK)
    {
        // FT_SetRts failed
        qDebug() << "Error: setDataCaracteristique returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "data cara:\tset";
    }
    return((int)_ftStatus);
}

int FTDIFunction::setRTS()
{
    //sets the Request To Send (RTS) control signal
    //param@1: Handle of the device
    _ftStatus = FT_SetRts(_ftHandle);
    if (_ftStatus != FT_OK)
    {
        // FT_SetRts failed
        qDebug() << "Error: FT_SetRts returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "RTS: set";
    }
    return((int)_ftStatus);
}

int FTDIFunction::resetRTS()
{
    //This function clears the Request To Send (RTS) control signal.
    //param@1: Handle of the device
    _ftStatus = FT_ClrRts(_ftHandle);
    if (_ftStatus != FT_OK)
    {
        // FT_SetRts failed
        qDebug() << "Error: FT_ClrRts returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "RTS: reset";
    }
    return((int)_ftStatus);
}

int FTDIFunction::resetdevice()
{
    //sends a reset command to the device.
    //param@1: fthandle      Handle of the device
    // FT_ResetDevice(ftHandle);
    _ftStatus = FT_ResetDevice(_ftHandle);
    if ((_ftStatus = FT_ResetDevice(_ftHandle)) != FT_OK)
    {
        // FT_ResetDevice failed
        qDebug() << "Error: FT_ResetDevice returned" << (int)_ftStatus;
    }
    else
    {
        // FT_ResetDevice  OK
        qDebug() << "Reset device : ok";
    }
    return((int)_ftStatus);
}

int FTDIFunction::freeTxRxBuffer()
{
    //This function purges receive and transmit buffers in the device.
    // Purge both Rx and Tx buffers
    //param@1: fthandle       Handle of the device
    _ftStatus = FT_Purge(_ftHandle, FT_PURGE_RX | FT_PURGE_TX);
    if (_ftStatus != FT_OK)
    {
        // FT_ResetDevice failed
        qDebug() << "Error: freeTxRxBuffer returned" << (int)_ftStatus;
    }
    else
    {
        // FT_ResetDevice  OK
        qDebug() << ("Rx,Tx buffer: clean");
    }
    return((int)_ftStatus);
}

int FTDIFunction::writeDataOneChar(int *data)
{
    //  do
    //    {
    //      setRTS();
    //    }
    //  while(ftStatus != FT_OK);

    _ftStatus = FT_Write(_ftHandle, data, 1, &_dwBytesWritten);

    /* Write */
    if(_ftStatus != FT_OK)
    {
        qDebug() << "Error: FT_Write returned" << (int)_ftStatus;
        // break;
    }
    else
    {
        qDebug() << "data Write : " << (void *)*data;
    }

    //resetRTS();
    return((int)_ftStatus);
}


int FTDIFunction::readDataOneChar(DWORD dwRxSize)
{
    /*Read*/
    //DWORD dwRxSize = 1;

    //  if(_ftStatus == FT_OK)
    //    {

    _ftStatus = FT_Read(_ftHandle, &_dataReceved, dwRxSize, &_dwBytesRead);
    //     pcBufRead = (char*)realloc(pcBufRead, dwRxSize);
    qDebug() << "recieved char :" << dwRxSize;

    if(_ftStatus != FT_OK)
    {
        qDebug() << "Error: readDataOneChar returned" << (int)_ftStatus;
    }
    else
    {
        qDebug() << "data read : " << (void *)_dataReceved;
    }
    //   }
    //  else
    //    {
    //      qDebug() << "Error: readDataOneChar returned" << (int)_ftStatus;
    //   }
    return((int)_ftStatus);
}

void FTDIFunction::liveReading(int *dataStart)
{
    initVariable();
    counterError = 0;
    //start live reading
    _ftStatus = writeDataOneChar(dataStart);

    //_ftStatus = resetRTS();
    //read the ack
    _ftStatus = readDataOneChar(1);

    qDebug() << "start reading";
    do
    {
        _ftStatus = FT_Read(_ftHandle, buf, BUFFER_SIZE, &_dwBytesRead);

        //qDebug() << "dwByteRead : " << _dwBytesRead;

        for(j=0;j<sizeof(buf);j++)
        {
            if(j%8 == 0)
            {
                counterValue=0;
                counterValueHigh =  buf[j];
                counterValueLow = buf[j+1];

                counterValue = counterValueHigh << 8 | counterValueLow;

                qDebug() << "counter Value" << counterValue;
                qDebug("value: %02x %02x %02x %02x %02x %02x %02x %02x \n",
                       buf[j], buf[j+1], buf[j+2], buf[j+3],
                        buf[j+4], buf[j+5], buf[j+6], buf[j+7]);
                if(memoCounterValue == 65535)
                {
                    counterError += counterValue == 0 ? 0 : 1;
                }
                else
                {
                    if(memoCounterValue != counterValue-1)
                    {
                        counterError++;
                    }
                }

                if(counterError)
                {
                    qDebug("cpt error : %ld", counterError);
                }
                memoCounterValue = counterValue;
                trameNumberRead++;

                if(counterValue == 0)
                {
                    qDebug("value: %02x %02x %02x %02x %02x %02x %02x %02x \n",
                           buf[j], buf[j+1], buf[j+2], buf[j+3],
                            buf[j+4], buf[j+5], buf[j+6], buf[j+7]);
                    qDebug("Nb trame read : %ld \n", trameNumberRead);

                }

            }
        }

    }
    while(!counterError);//trameNumberRead<(NB_TRAME_READ*1000));
    _ftStatus = writeDataOneChar(&_dataStop);
    /* Write */
    if(_ftStatus != FT_OK)
    {
        qDebug("Error: FT_Write returned : %d", _ftStatus);
        // break;
    }
    else
    {
        qDebug("data Write : %x\n", _dataStop);
    }
}

void FTDIFunction::initVariable()
{
    _iport = 0;
    _dataSend = 0xff;
    _dataReceved = 0x00;
    _dataStart = 0x05;
    _dataStop = 0x04;

    counterValue = 0;
    memoCounterValue = -1;
    counterError = 0;
    counterValueFind = 0;
}

#include "debugWindow.h"
#include "ui_debugWindow.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DebugWindow),
//    _FTDIdevice(new FTDIFunction()),
    _FTDIReturnMessagePossibleTxt(GlobalEnumatedAndExtern::initFTDIReturnCharPossibleTxt())
{
    ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::setFrameSize(int frameSize)
{
    _frameSize = frameSize;
    ui->lineEditFrameSize->setText(QString::number(_frameSize));
}

void DebugWindow::setBaudRateFTDI(const quint32 &baudRateFTDI)
{
    _baudRateFTDI = baudRateFTDI;
    ui->lineEditBaudrate->setText(QString::number(baudRateFTDI));
}

void DebugWindow::setFTDIdevice(FTDIFunction *FTDIdevice)
{
    _FTDIdevice = FTDIdevice;
}

void DebugWindow::receivedNewData(DataFrame *newDataFrame)
{

}

bool DebugWindow::_FTDIDeviceFound()
{
    return ((bool)this->_FTDIdevice->numDevs());
}

//#if LINUX

void DebugWindow::_addTextInLabel(QString text)
{
    QTextCursor cursor = ui->textEditDebug->textCursor();
    static quint8 lineCPT = 0;
    quint8 maxLine = 29;

    const quint8 lineToDelete = 1;

    QTextBlock b = ui->textEditDebug->document()->findBlockByLineNumber(lineToDelete);

    if(b.isValid() && lineCPT > maxLine)
    {
        //remove line
        QTextCursor cursor2(b);
        cursor2.select(QTextCursor::BlockUnderCursor);
        cursor2.removeSelectedText();

        //make empty the fist line
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar();
    }
    else
    {
        lineCPT++;
    }

    ui->textEditDebug->append(text);
}

void DebugWindow::_FTDIReadInfo()
{
    //display device information
    if(this->_FTDIDeviceFound())
    {
        this->_addTextInLabel("number of device : " + QString::number(this->_FTDIdevice->numDevs()));
        this->_addTextInLabel("Flags = \t0x" + QString::number(this->_FTDIdevice->Flags()));
        this->_addTextInLabel("Type  = \t0x" + QString::number(this->_FTDIdevice->Type()));
        this->_addTextInLabel("ID    = \t0x" + QString::number(this->_FTDIdevice->ID()));
        this->_addTextInLabel("LocId = \t0x" + QString::number(this->_FTDIdevice->LocId()));
        this->_addTextInLabel("SerialNumber\t: " + (QString)this->_FTDIdevice->SerialNumber());
        this->_addTextInLabel("Description\t: " + (QString)this->_FTDIdevice->Description());
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }
}
//#endif

void DebugWindow::setNbSavedFrame(quint64 nbSavedFrame)
{
    _nbSavedFrame = nbSavedFrame;
    ui->lineEditNbSavedFrame->setText(QString::number(_nbSavedFrame));
}

void DebugWindow::on_lineEditNbSavedFrame_textChanged(const QString &arg1)
{
    // qDebug() << objectName() << arg1;
    //   qDebug() << objectName() << arg1.toLongLong();
    emit _nbFrameSavedChanged(arg1.toInt());
}

void DebugWindow::on_lineEditFrameSize_textChanged(const QString &arg1)
{
    //   qDebug() << objectName() << arg1;
    //   qDebug() << objectName() << arg1.toInt();
    emit _frameSizeChanged(arg1.toInt());
}

void DebugWindow::on_lineEditBaudrate_textChanged(const QString &arg1)
{
    //   qDebug() << objectName() << arg1;
    //    qDebug() << objectName() << arg1.toUInt();
    emit _FTDIBaudrateChanged(arg1.toUInt());
}

void DebugWindow::on_pushButtonFTDIInfo_released()
{
    this->_FTDIReadInfo();
}

void DebugWindow::on_pushButtonSendStart_released()
{
    static quint8 cpt = 0;
    cpt++;
    this->_addTextInLabel("Test : " + QString::number(cpt));
}

void DebugWindow::on_pushButtonFTDIStopRead_released()
{

}

void DebugWindow::on_checkBoxEmulationMode_toggled(bool checked)
{
    emit _checkBoxEmulationModeStatusWasChanged(checked);
}

void DebugWindow::on_pushButtonSendChar_released()
{
    int dataToWrite = (int)ui->doubleSpinBoxFTDICharToSend->value();

    //display device information
    if(this->_FTDIDeviceFound())
    {
        //write data
        this->_FTDIdevice->writeDataOneChar(&dataToWrite);

        //check if ok
        if(this->_FTDIdevice->ftStatus() == FT_OK)
        {
            this->_addTextInLabel("Write char 0x"
                                  + QString::number(dataToWrite, 10) + ", "
                                  + _FTDIReturnMessagePossibleTxt[dataToWrite]);

            //read the ack
            dataToWrite = this->_FTDIdevice->readDataOneChar(1);
            this->_addTextInLabel("Write char 0x"
                                  + QString::number(dataToWrite, 10) + ", "
                                  + _FTDIReturnMessagePossibleTxt[dataToWrite]);
        }
        else
        {
            this->_addTextInLabel("Write error");
        }
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }
}

void DebugWindow::on_pushButtonFTDIStartReadData_released()
{
    int dataToWrite = (int)GlobalEnumatedAndExtern::transmissionEnquiry;
    int dataReceived = 0;

    if(this->_FTDIDeviceFound())
    {
        this->_addTextInLabel("Start reading...");
        _FTDIdevice->liveReading(&dataToWrite);
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }

}

void DebugWindow::on_pushButtonFTDIStopReadData_released()
{
    quint8 dataRecieved = 0;

    if(this->_FTDIDeviceFound())
    {
        this->_addTextInLabel("Send stop...");
        dataRecieved = this->_FTDIdevice->sendStop();
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }
}

void DebugWindow::on_pushButtonCleanText_released()
{
    ui->textEditDebug->clear();
}

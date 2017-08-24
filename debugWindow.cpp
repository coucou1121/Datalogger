#include "debugWindow.h"
#include "ui_debugWindow.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DebugWindow),
    _FTDIdevice(new FTDIFunction()),
    _FTDIReturnMessagePossibleTxt(GlobalEnumatedAndExtern::initFTDIReturnValuePossibleTxt())
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

bool DebugWindow::_FTDIDeviceFound()
{
    return ((bool)this->_FTDIdevice->_numDevs);
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
        this->_addTextInLabel("number of device : " + QString::number(this->_FTDIdevice->_numDevs));
        this->_addTextInLabel("Flags = \t0x" + QString::number(this->_FTDIdevice->_Flags));
        this->_addTextInLabel("Type  = \t0x" + QString::number(this->_FTDIdevice->_Type));
        this->_addTextInLabel("ID    = \t0x" + QString::number(this->_FTDIdevice->_ID));
        this->_addTextInLabel("LocId = \t0x" + QString::number(this->_FTDIdevice->_LocId));
        this->_addTextInLabel("SerialNumber\t: " + (QString)this->_FTDIdevice->_SerialNumber);
        this->_addTextInLabel("Description\t: " + (QString)this->_FTDIdevice->_Description);
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

#if LINUX
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
#endif

void DebugWindow::on_checkBoxEmulationMode_toggled(bool checked)
{
    emit _checkBoxEmulationModeStatusWasChanged(checked);
}

void DebugWindow::on_pushButtonSendChar_released()
{
    //display device information
    if(this->_FTDIDeviceFound())
    {
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }
}

void DebugWindow::on_pushButtonFTDIStartReadData_released()
{
    if(this->_FTDIDeviceFound())
    {
        _FTDIdevice->liveReading(&_FTDIdevice->_dataStart);
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
        //        this->_addTextInLabel("received : 0x" + QString::number(dataRecieved, 16) + ", " +
        //                             _FTDIReturnMessagePossibleTxt[dataRecieved]);
    }
    else
    {
        this->_addTextInLabel("Device FTDI not found");
    }

    // ui->label->setText(_errorListPossible[GlobalEnumatedAndExtern::noError]);
}

void DebugWindow::on_pushButtonCleanText_released()
{
    ui->textEditDebug->clear();
}

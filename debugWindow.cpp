#include "debugWindow.h"
#include "ui_debugWindow.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DebugWindow)
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

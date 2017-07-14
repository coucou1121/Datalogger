#include "baseWindow.h"
#include "ui_baseWindow.h"

BaseWindow::BaseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
    ui->LabelTitle->setStyleSheet("qproperty-alignment: 'AlignBottom | AlignRight';");
    ui->labelVersion->setStyleSheet("qproperty-alignment: 'AlignTop | AlignRight';");
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::setTitle(const QString &title)
{
    _title = title;
    ui->LabelTitle->setText(title);
}

void BaseWindow::setVersion(const QString &version)
{
    _version = version;
    ui->labelVersion->setText(version);
}

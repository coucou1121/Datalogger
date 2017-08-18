#include "homeWindow.h"
#include "ui_HomeWindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    ui->LabelTitle->setStyleSheet("qproperty-alignment: 'AlignBottom | AlignRight';");
    ui->labelVersion->setStyleSheet("qproperty-alignment: 'AlignTop | AlignRight';");
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::setTitle(const QString &title)
{
    _title = title;
    ui->LabelTitle->setText(title);
}

void HomeWindow::setVersion(const QString &version)
{
    _version = version;
    ui->labelVersion->setText(version);
}

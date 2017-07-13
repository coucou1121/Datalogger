#include "errorMessage.h"
#include "ui_errorMessage.h"

ErrorMessage::ErrorMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorMessage)
{
    ui->setupUi(this);
}

ErrorMessage::~ErrorMessage()
{
    delete ui;
}

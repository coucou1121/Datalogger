#include "initWindow.h"
#include "ui_initWindow.h"

InitWindow::InitWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::InitWindow)
{
    ui->setupUi(this);
}

InitWindow::~InitWindow()
{
    delete ui;
}

void InitWindow::addTextInLabel(QString text)
{
    QString temp = ui->initLabel->text();
    temp.append(text + "\n");
    ui->initLabel->setText(temp);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

//ready for work
//just to be sure
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(MINIMUM_WIDTH_SIZE, MINIMUM_HEIGHT_SIZE);
    this->setupStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStyle()
{
    QPalette palette;
    palette.setColor(backgroundRole(), _myStyle.getBackGroundColor());

    this->setPalette(palette);
}

void MainWindow::setTitle(const QString &title)
{
    _title = title;
    ui->LabelTitle->setText(_title);
}

void MainWindow::setVersion(const QString &version)
{
    _version = version;
    ui->labelVersion->setText(_version);
}

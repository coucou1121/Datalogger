#include "mainwindow.h"
#include "ui_mainwindow.h"

//ready for work
//jsut to be sure
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStyle()
{
    QPalette palette;
    palette.setColor(backgroundRole(), QColor::fromRgb( 82, 82, 82 ));
    this->setPalette(palette);
}

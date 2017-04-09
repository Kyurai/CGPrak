#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(sbxRotationZ,SIGNAL(clicked()),this,SLOT(receiveRotationZ(5)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

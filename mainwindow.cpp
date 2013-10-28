#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QtWidgets>
#include <QtGui/QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->btnDownBtn, SIGNAL(clicked()), this, SLOT(pageDown()));
    QObject::connect(ui->btnUpBtn, SIGNAL(clicked()), this, SLOT(pageUp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pageDown()
{
    ui->textEdit->verticalScrollBar()->triggerAction(QSlider::SliderPageStepAdd);
}

void MainWindow::pageUp()
{
    ui->textEdit->verticalScrollBar()->triggerAction(QSlider::SliderPageStepSub);
}

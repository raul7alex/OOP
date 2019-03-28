#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setStyleSheet("QLabel {border:2 solid red;background:yellow;font-size:32px;color:yellow}" );

    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    state = false;
    timer = new QTimer(this);
    progress = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateLabel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateLabel()
{
    if ( !state )
    {
        ui->label->setStyleSheet("QLabel {border:2 solid red;background:yellow;font-size:32px;color:red}" );
        state = true;
    }
    else
    {
        ui->label->setStyleSheet("QLabel {border:2 solid red;background:yellow;font-size:32px;color:yellow}" );
        state = false;
    }
    progress += 5;
    ui->progressBar->setValue(progress);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text() == "Start")
    {
        ui->progressBar->setValue(0);
        progress = 0;
        ui->pushButton->setText("Stop");
        timer->start(600);
    }
    else
    {
        ui->pushButton->setText("Stop");
        progress = 0;
        timer->stop();
        ui->pushButton->setText("Start");
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("border: 2 solid green;background:yellow;font-size:20px;color:red;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

     if ( ui->label->underMouse() )
     {
         Qt::MouseButton btn = event->button();
         if ( btn == Qt::LeftButton )
            ui->label->setText("Click butonul stanga pa label !");
         if ( btn == Qt::RightButton )
            ui->label->setText("Click butonul dreapta pa label !");
         if ( btn == Qt::MiddleButton )
            ui->label->setText("<p style ='background:b;font-size:20px;color:red'>Click butonul mijloc pa label !</p>");
     }
     else
         ui->label->setText("Click in afara label-ului !");
}

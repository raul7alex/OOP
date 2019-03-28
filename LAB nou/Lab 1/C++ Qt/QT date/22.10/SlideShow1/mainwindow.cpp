#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QList>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setGeometry(80, 80, 400, 300);
    ui->label->setStyleSheet("border:2px solid gray");
    i = -1;

  //  ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    ui->label->setScaledContents(true);
    ui->label->setAlignment(Qt::AlignCenter);

    GetImages();
    SetImage();
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(SetImage()));
  //  showMaximized();
    setStyleSheet("QLabel { background-color:rgb(179,180,28); padding: 7px ; color:rgb(255,255,255)}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if ( !timer->isActive())
        timer->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    if ( timer->isActive() )
        timer->stop();
}

void MainWindow::GetImages()
{
    path = /*QDir::currentPath()*/ "./Images/";
    qDebug() << path;
    QDir dir(path);
    QStringList filters;
    filters << "*.jpeg";
    dir.setNameFilters(filters);
    files = dir.entryList();
}

void MainWindow::SetImage()
{
    QPixmap pix(path + files[++i % files.count()]);
  //  ui->label->setPixmap(pix);
    ui->label->setPixmap(pix.scaled(ui->label->contentsRect().size(),Qt::KeepAspectRatio));
    qDebug() << ui->label->contentsRect().size().width()
             << ui->label->contentsRect().size().height() ;
}


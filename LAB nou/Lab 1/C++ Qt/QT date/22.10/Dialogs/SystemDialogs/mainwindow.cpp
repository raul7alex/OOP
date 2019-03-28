#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


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

void MainWindow::on_pushButton_clicked()
{
 //   QString fileName = QFileDialog::getOpenFileName(this);
    QString fileName = QFileDialog::getSaveFileName(this);
    QFileDialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.exec();
//    QStringList files = dialog.selectedFiles();

//    if (files.isEmpty())
//        return false;
//    if (!fileName.isEmpty())
 //       loadFile(fileName);
}

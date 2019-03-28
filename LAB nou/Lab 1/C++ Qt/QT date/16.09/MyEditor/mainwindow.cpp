#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>

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

void MainWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                      tr("Open File"),
                      "/home",tr("Images (*.png *.xpm *.jpg);;Text Files (*.txt *.rtf)"));
    std::ifstream fin(fileName.toStdString().c_str());
    char text[100000];
    fin.getline(text, 100000, EOF);
    fin.close();

    ui->textEdit->setText(QString::fromUtf8(text));
}

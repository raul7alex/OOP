#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 9; i++)
    {
    ui->listWidget->addItem(QString::number(i) + " Item ");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // listWidget creaza clase
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("Fuzzy bunny of doom");
    itm->setTextColor(Qt::red);
    itm->setBackgroundColor(Qt::black);
}

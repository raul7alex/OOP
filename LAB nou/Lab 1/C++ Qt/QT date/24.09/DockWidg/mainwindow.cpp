#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineEdit* le = new QLineEdit(this);
    ui->mainToolBar->addWidget(le);

    QComboBox* combo = new QComboBox(this);
    combo->addItems(QStringList() << "Ala" << "Bala" << "Portocala");
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(combo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

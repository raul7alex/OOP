#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ResetUi();

    OpenDB();

 //   ui->comboBox->setCurrentIndex(0);
    //SelectNames();
}

void MainWindow::OpenDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("Users");
    if ( !db.open())
        QMessageBox::critical(this, "Eroare!", "Nu s-a realizat conexiunea la baza de date!\n" + db.lastError().text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

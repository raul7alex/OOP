#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

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

void MainWindow::ResetUi()
{
    setWindowTitle("Save Image into Database");
    ui->gridLayout->setColumnStretch(0, 0);
    ui->gridLayout->setColumnStretch(1, 0);
    ui->gridLayout->setColumnStretch(2, 2);
   /* ui->gridLayout->setRowStretch(0, 1);
    ui->gridLayout->setRowStretch(1, 1);
    ui->gridLayout->setRowStretch(2, 1);
    ui->gridLayout->setRowStretch(3, 1);
    ui->gridLayout->setRowStretch(4, 0);
*/
    // ui->lblShowImage->setScaledContents(true);
    ui->lblShowImage->setAlignment(Qt::AlignCenter);
    ui->lblShowImage->setStyleSheet("QLabel{border: 2px solid green; background-color:rgb(229,205,204); padding: 7px ; }");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ResetUi();

    OpenDB();

 //   ui->comboBox->setCurrentIndex(0);
    SelectNames();
}

MainWindow::~MainWindow()
{
    if ( db.isOpen())
        db.close();
    delete ui;
}

void MainWindow::InsertPerson()
{
    QByteArray ba;
    QFile f(fileName);
    if(f.open(QIODevice::ReadOnly))
    {
        ba = f.readAll();
        f.close();
    }

    if ( db.isOpen())
    {
        QSqlDatabase::database().transaction();

        QSqlQuery query;
        query.prepare( "INSERT INTO Persons ( Name, Age, Image ) VALUES (:name, :age, :img)" );
        query.bindValue(":name", ui->txtName->text());
        query.bindValue(":age", ui->txtAge->text());
       // query.bindValue(":img", ba.toBase64());
        query.bindValue(":img", ba);
        query.exec();

        if( query.lastError().isValid())
        {
            qDebug() << query.lastError().text();
            ui->lblResult->setText("Image not Saved! " +  query.lastError().text());
            QSqlDatabase::database().rollback();
        }
        else
        {

            QSqlDatabase::database().commit();
            ui->lblResult->setText(tr("Image saved into Database!"));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->lblResult->setText("");
    fileName = QFileDialog::getOpenFileName(this,
                     "Select an Image", QDir::currentPath(), "Image Files (*.jpg *.jpeg *.bmp *.gif)");

    // Afiseaza imaginea in label
    QImage image(fileName);
    ui->lblShowImage->setPixmap(
      QPixmap::fromImage(image).scaled(ui->lblShowImage->contentsRect().size(), Qt::KeepAspectRatio));
}

void MainWindow::on_btnSaveImage_clicked()
{ // Insereaza imaginea in baza de date

     InsertPerson();
     SelectNames();
     ui->txtName->setText("");
     ui->txtAge->setText("");
}

void MainWindow::ShowImageByName(QString nume)
{
    if ( nume == "Selectati o imagine")
    {
        ui->lblShowImage->setPixmap(QPixmap()); // sterg imaginea
        ui->txtAge->setText("");
        ui->txtName->setText("");
        return;
    }
    if ( db.isOpen())
    {
        QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.prepare("SELECT * FROM Persons WHERE Name=:name");
        query.bindValue(":name", nume);

        query.exec();
        query.next();

        if( query.lastError().isValid())
        {
            ui->lblResult->setText("Image not found!");
            qDebug() << query.lastError().text();
            QSqlDatabase::database().rollback();
        }
        else
        {
            QByteArray ba = query.value(3).toByteArray();
            QPixmap pix;
            //pix.loadFromData(QByteArray::fromBase64(ba));
            pix.loadFromData(ba);

            // Arata imaginea in label
            ui->lblShowImage->setPixmap(pix.scaled(ui->lblShowImage->contentsRect().size(), Qt::KeepAspectRatio));

            // Completeaza campurile in line edit
            ui->txtName->setText(query.value(1).toString());
            ui->txtAge->setText(query.value(2).toString());

            QSqlDatabase::database().commit();
        }
    }
}

void MainWindow::SelectNames()
{
    ui->comboBox->clear();


    if ( db.isOpen())
    {
     //   QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.prepare("SELECT Name FROM Persons");

        query.exec();

        if( query.lastError().isValid())
        {
            ui->lblResult->setText("Records not found !");
            qDebug() << query.lastError().text();
    //        QSqlDatabase::database().rollback();
        }
        else
        {
            for (int i = 0; query.next(); ++i )
                ui->comboBox->insertItem(i, query.value(0).toString());
     //       QSqlDatabase::database().commit();
        }
    }

    ui->comboBox->insertItem(0, "Selectati o imagine");
    ui->comboBox->setCurrentIndex(0);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
  //  QString txt = ui->comboBox->currentText();
    ShowImageByName(arg1);
}



void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{


}

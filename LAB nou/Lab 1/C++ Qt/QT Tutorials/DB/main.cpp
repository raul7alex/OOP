#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString serverName ="LOCALHOST\\SQLEXPRESS";
    QString dbName="Users";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

    QString dsn =QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;TrustedConnection=Yes;").arg(serverName).arg(dbName);

    db.setDatabaseName(dsn);

    if(db.open())
    {
        qDebug()<<"Opened!";
        db.close();
    }
    else
    {
        qDebug()<<"Error = "<<db.lastError().text();
    }

    return a.exec();

}




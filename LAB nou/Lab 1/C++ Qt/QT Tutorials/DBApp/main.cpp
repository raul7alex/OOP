#include <QtCore/QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString serverName ="LOCALHOST\\SQLEXPRESS";
    //QString serverName ="LOCALHOST\\MySQL";
    QString dbName="Users";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

   // QString dsn =QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;TrustedConnection=Yes;").arg(serverName).arg(dbName);
    QString dsn =QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;UID=root;PDW=""").arg(serverName).arg(dbName);

    db.setDatabaseName(dsn);
    qDebug()<<"\n da";

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




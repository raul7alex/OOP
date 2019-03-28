#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Read(QString Filename)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open file for reading";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.flush();
    mFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Read(":/MyFiles/Files.pro");


    return a.exec();
}

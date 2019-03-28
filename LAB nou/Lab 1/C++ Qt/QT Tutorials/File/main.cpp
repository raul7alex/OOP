#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Write(QString Filename)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "could not open file for writing";
        return;
    }

    QTextStream out(&mFile);
    out << "Hello world i am the best programmer";

    mFile.flush();
    mFile.close();
}

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
int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    QString mFilename ="/Users/levitchi_dan2001/Documents/Text.txt";

    Write(mFilename);
    Read(mFilename);

    return app.exec();
}

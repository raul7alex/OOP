#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QDir mDir("/Users/levitchi_dan2001/Documents/C++/QT Tutorials");

    //afiseaza toate folderele / fisierele  aflate in directorul mDir cu adresa data
   foreach (QFileInfo mItem, mDir.entryInfoList()) {
      if(mItem.isDir()) qDebug()<<"Dir:   " << mItem.absoluteFilePath();
      if(mItem.isFile()) qDebug()<<"Dir:   " << mItem.absoluteFilePath();
   }

    /*
     * Verifica daca calea exista(daca nu o creeaza )
    QString mPath = "/Users/levitchi_dan2001/Documents/C++/QT Tutorials/zzz";
    if(mDir.exists())
    {
        mDir.mkpath(mPath);
        qDebug() <<"Created";
    }
    else
    {
        qDebug() <<"Already exists";
    }
    */

    /*
     * Afiseaza toate hardurile din pc (de exemplu E/, F/ ...
    foreach (QFileInfo mItem,mDir.drives()) {
        qDebug() << mItem.absoluteFilePath();
    }
    */
    return a.exec();
}

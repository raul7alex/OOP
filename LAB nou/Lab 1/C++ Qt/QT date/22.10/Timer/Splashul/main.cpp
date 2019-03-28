#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
   /*
    QPixmap pm(":/images/austria.jpg");  //

    splash->setPixmap(pm);
    */

    QPixmap p(":/images/austria.jpg");
    int width = 600, height = 400;
    splash->setPixmap(p.scaled(width, height, Qt::KeepAspectRatio));
    splash->show();

    MainWindow w;
    int x, y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;

    w.setGeometry(x, y, width, height);
    QTimer::singleShot(2500, splash, SLOT(close()));
    QTimer::singleShot(2500, &w, SLOT(show()));



    return a.exec();
}

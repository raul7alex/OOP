#include <QApplication>
#include "myclass.h"
#include <QSplashScreen>
#include <QTimer>
#include <QDesktopWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QSplashScreen *splash = new QSplashScreen;

    QPixmap p(":/images/lightroom.png");
    int width = 800, height = 600;
    splash->setPixmap(p.scaled(QSize(width, height), Qt::KeepAspectRatio));
    splash->show();

    MyClass w;
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

    return app.exec();
}


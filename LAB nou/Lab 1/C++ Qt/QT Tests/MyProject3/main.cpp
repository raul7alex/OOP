#include <QApplication>
#include "myclass.h"
#include <QDesktopWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyClass w;
/*
    int width = 600, height =400, x, y,
        screenWidth, screenHeight;

    QDesktopWidget *desktop =QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;


    w.setGeometry(x, y, width, height);
*/
     w.show();


    return app.exec();
}

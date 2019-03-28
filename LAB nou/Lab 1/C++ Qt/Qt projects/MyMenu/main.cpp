#include <QApplication>
#include "mymenu.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyMenu w;
    w.show();

    return app.exec();
}

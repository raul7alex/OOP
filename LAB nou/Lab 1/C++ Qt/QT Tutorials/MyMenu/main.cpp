#include <QApplication>
#include "myclass.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyClass w;
    w.show();

    return app.exec();
}

#include <QApplication>
#include "testsignals2.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TestSignals2 w;
    w.show();

    return app.exec();
}

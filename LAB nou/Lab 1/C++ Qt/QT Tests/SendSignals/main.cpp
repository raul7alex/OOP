#include<QApplication>
#include "testsignals.h"

int main(int argc, char * argv [])
{
    QApplication app(argc, argv);
    TestSignals w;
    w.show();

    return app.exec();
}

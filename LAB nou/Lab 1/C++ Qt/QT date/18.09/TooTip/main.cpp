#include <QApplication>
#include "testtooltip.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    TestToolTip w;
    w.show();

    return app.exec();
}

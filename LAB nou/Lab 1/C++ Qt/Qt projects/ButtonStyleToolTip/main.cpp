#include <QApplication>
#include "tooltip.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ToolTip w;
    w.show();

    return app.exec();
}

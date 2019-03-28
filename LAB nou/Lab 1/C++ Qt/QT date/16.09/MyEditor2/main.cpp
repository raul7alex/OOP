#include <QApplication>
#include "myeditor.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyEditor myEditor;
    myEditor.show();

    return app.exec();
}


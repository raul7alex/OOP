#include <QApplication>
#include "mylabel.h"
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow window;
    window.setWindowTitle(QString::fromUtf8("QT - QWheelEvent Delta Value"));
    window.resize(300, 250);
    QWidget *centralWidget = new QWidget(&window);

    QHBoxLayout * layout = new QHBoxLayout(centralWidget);
    MyLabel *label = new MyLabel;
    layout->addWidget(label);

    window.setCentralWidget(centralWidget);

    window.show();

    return app.exec();
}

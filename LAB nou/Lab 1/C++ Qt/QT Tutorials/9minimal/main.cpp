#include <QApplication>

int main(int argc, char*argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    window->show();
    return app.exec();
}

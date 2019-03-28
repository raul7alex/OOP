#include <QApplication>
#include <QMenuBar>
#include <QMainWindow>
#include <QDesktopWidget>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow();

    int WIDTH = 350; // pt fereastra
    int HEIGHT = 250;

    int screenWidth;
    int screenHeight;

    int x, y;
    // centrarea ferestrei
    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    window->resize(WIDTH, HEIGHT);
    window->move( x, y );

    QWidget* centralWidget = new QWidget(window);
    QMenuBar* mb = new QMenuBar(centralWidget);
    QMenu* m1 = new QMenu("Meniu 1");
    QMenu* sub1 = new QMenu("Submeniu 1");
    QMenu* sub2 = new QMenu("Submeniu 2");

    m1->addMenu(sub1);
    m1->addMenu(sub2);
    mb->addMenu(m1);
    window->setCentralWidget(centralWidget);
    window->show();
    return app.exec();
}

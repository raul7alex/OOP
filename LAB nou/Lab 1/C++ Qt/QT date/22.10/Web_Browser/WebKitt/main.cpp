#include <QApplication>
#include <QWebView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebView view;
    view.move(300, 200);
    view.show();
    view.load(QUrl("http://google.com"));

    return a.exec();
}

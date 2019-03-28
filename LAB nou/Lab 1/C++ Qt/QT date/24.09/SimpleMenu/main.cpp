#include "simplemenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  SimpleMenu window;

  window.resize(350, 250);
  window.move(350, 350);
  window.setWindowTitle("Simple menu");
  window.show();

  return app.exec();
}

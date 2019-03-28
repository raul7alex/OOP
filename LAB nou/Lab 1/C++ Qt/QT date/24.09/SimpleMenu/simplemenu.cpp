#include "simplemenu.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent)
{
  QAction *actQuit = new QAction("&Quit", this);

  QMenu *file;
  file = menuBar()->addMenu("&File");
  file->addAction(actQuit);

  connect(actQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

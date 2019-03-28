#include "menu.h"
#include <QMenu>
#include <QHBoxLayout>
#include <QAction>
#include <QContextMenuEvent>
#include <QApplication>

void Menu::contextMenuEvent(QContextMenuEvent *event)
 {
     QMenu menu;
     QAction *setupAction = new QAction("Setupul", this);
     QAction *monitorAction = new QAction("Monitorul", this);

    // connect(setupAction,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
     menu.addAction(setupAction);
     menu.addAction(monitorAction);
     menu.exec(event->globalPos());
 }

Menu::Menu(QWidget *parent ):
    QMainWindow{ parent },
    centralWidget {new QWidget },
    layout { new QHBoxLayout (centralWidget)}
{
    setCentralWidget(centralWidget);

}

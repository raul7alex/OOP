#include "myclass.h"
#include <QMenuBar>
#include <QMenu>

MyClass::MyClass(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

     menuBar = new QMenuBar(centralWidget);
     setMenuBar(menuBar);

     fileMenu = new QMenu("&File", this);
     editMenu = new QMenu("&Edit", this);

     subMenu1 = new QMenu("Submenu1",fileMenu);
     subMenu2 = new QMenu("Submenu2",editMenu);

     lastMenu1 = new QMenu("LastMenu1",subMenu1);
     lastMenu2 = new QMenu("LastMenu2",subMenu2);

     menuBar->addMenu(fileMenu);
     menuBar->addMenu(editMenu);

     fileMenu->addMenu(subMenu1);
     editMenu->addMenu(subMenu2);

     subMenu1->addMenu(lastMenu1);
     subMenu2->addMenu(lastMenu2);

}

#include "myclass.h"
#include <QToolBar>

MyClass::MyClass(QWidget *parent):
    QMainWindow (parent)
{
   toolBar = new QToolBar(this);
   addToolBar(toolBar);
}

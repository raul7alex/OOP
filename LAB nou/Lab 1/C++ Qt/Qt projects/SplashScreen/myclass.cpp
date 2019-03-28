#include "myclass.h"

MyClass::MyClass(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget (parent);
    setCentralWidget(centralWidget);
}

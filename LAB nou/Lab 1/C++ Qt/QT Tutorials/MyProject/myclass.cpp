#include "myclass.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>

MyClass::MyClass(QWidget *parent):
    QMainWindow {parent }
{
    QWidget *centralWidget = new QWidget (this);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout(centralWidget);
    pushButton = new QPushButton("close");

    connect(pushButton, SIGNAL(clicked(bool)), qApp, SLOT(exit());
    layout -> addWidget(pushButton);

}

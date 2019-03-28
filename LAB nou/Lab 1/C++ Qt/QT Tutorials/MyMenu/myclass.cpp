#include "myclass.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>

MyClass::MyClass(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget(parent);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout (centralWidget);
    button = new QPushButton;
    layout->addWidget(button);
    button->setText("exit");

    textEdit = new QTextEdit;
    layout->addWidget(textEdit);

    connect(button, SIGNAL(clicked(bool)) ,qApp, SLOT(quit()));
}

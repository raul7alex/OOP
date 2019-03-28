#include "dialog.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QApplication>

void Dialog::on_push_button()
{
    QMessageBox::information(this, "MyMessage", lineEdit->text());
}

Dialog::Dialog(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget (this);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout(centralWidget);
    pushButton = new QPushButton("Click me");
    lineEdit = new QLineEdit;

    layout->addWidget(lineEdit);
    layout->addWidget(pushButton);
     connect(pushButton, SIGNAL (released()), this, SLOT (on_push_button()));
}

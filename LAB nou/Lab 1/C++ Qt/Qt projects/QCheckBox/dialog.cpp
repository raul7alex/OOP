#include "dialog.h"
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>

void Dialog::on_push_button()
{
    if(checkBox->isChecked())
    {
        QMessageBox::information(this, "MyWindow"," You like cats");
    }
    else
    {
        QMessageBox::information(this, "MyWindow"," You don't like cats");
    }
}
Dialog::Dialog(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget (this);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout(centralWidget);
    checkBox = new QCheckBox("I like cats");
    pushButton = new QPushButton("Click me");

    layout->addWidget(checkBox);
    layout->addWidget(pushButton);

    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(on_push_button()));

}

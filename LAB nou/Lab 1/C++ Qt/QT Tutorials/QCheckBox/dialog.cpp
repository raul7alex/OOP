#include "dialog.h"
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>

Dialog::Dialog(QWidget *parent):
    QMainWindow { parent }
{
    QWidget *centralWidget = new QWidget (this);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout (centralWidget);
    checkBox = new QCheckBox;
    pushButton = new QPushButton;

    layout->addWidget(checkBox);
    layout->addWidget(pushButton);
}

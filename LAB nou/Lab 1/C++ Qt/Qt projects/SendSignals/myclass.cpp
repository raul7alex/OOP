#include "myclass.h"
#include <QHBoxLayout>
#include <QDial>
#include <QSlider>
#include <QSpinBox>

void MyClass::SetupGui()
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QHBoxLayout(centralWidget);

    dial = new QDial;
    slider = new QSlider;
    spinBox = new QSpinBox;

    dial->setRange(0,100);
    slider->setRange(0,100);
    spinBox->setRange(0,100);

    slider->setOrientation(Qt::Horizontal);
    layout->addWidget(dial);
    layout->addWidget(slider);
    layout->addWidget(spinBox);
}

void MyClass::SetupConnections()
{
    connect(dial, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
}

MyClass::MyClass(QWidget *parent):
    QMainWindow { parent },
{
    SetupGui();
    SetupConnections();

}

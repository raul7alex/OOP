#include "testsignals.h"
#include <QVBoxLayout>
#include <QSlider>
#include <QDial>
#include <QSpinBox>

void TestSignals::SetupGui()
{
    setLayout(layout);
    layout->addWidget(slider);
    layout->addWidget(spin);
    layout->addWidget(dial);
    slider->setOrientation(Qt::Horizontal);
    setGeometry(400, 400, 200, 350);

}

TestSignals::TestSignals(QWidget *parent) :
    QWidget(parent),
    layout { new QVBoxLayout },
    dial   { new QDial },
    slider { new QSlider },
    spin   { new QSpinBox }

{
    SetupGui();

    connect(slider, SIGNAL(valueChanged(int)),
            spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),
            dial,SLOT(setValue(int)));
    connect(dial,SIGNAL(valueChanged(int)),
            slider,SLOT(setValue(int)));
}

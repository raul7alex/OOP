#include "testsignals2.h"
#include <QVBoxLayout>
#include <QSlider>
#include <QDial>
#include <QSpinBox>

void TestSignals2::SetupGUI()
{
    layout->addWidget(slider);
    layout->addWidget(spin);
    layout->addWidget(dial);
    slider->setOrientation(Qt::Horizontal);
    setGeometry(800, 400, 200, 350);
    setLayout(layout);
}

TestSignals2::TestSignals2(QWidget *parent) :
    QWidget(parent),
    layout { new QVBoxLayout },
    slider { new QSlider },
    spin { new QSpinBox },
    dial { new QDial }

{
    SetupGUI();

    connect(slider, SIGNAL(valueChanged(int)),
            spin, SLOT(setValue(int)));

    connect(spin,SIGNAL(valueChanged(int)),
            dial, SLOT(setValue(int)));

    connect(dial,SIGNAL(valueChanged(int)),
            slider,SLOT(setValue(int)));

}

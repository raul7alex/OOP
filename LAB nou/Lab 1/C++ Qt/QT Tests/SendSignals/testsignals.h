#ifndef TESTSIGNALS_H
#define TESTSIGNALS_H

#include <QWidget>

#include <QVBoxLayout>
#include <QDial>
#include <QSlider>
#include <QSpinBox>

class TestSignals : public QWidget
{
    Q_OBJECT
public:
    explicit TestSignals(QWidget *parent = 0);
    void SetupGui();



signals:

public slots:

   private:
    QVBoxLayout * layout;
    QDial       * dial;
    QSlider     * slider;
    QSpinBox    * spin;
};

#endif // TESTSIGNALS_H

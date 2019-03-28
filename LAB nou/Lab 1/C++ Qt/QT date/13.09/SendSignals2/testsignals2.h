#ifndef TESTSIGNALS2_H
#define TESTSIGNALS2_H

#include <QWidget>

class QVBoxLayout;   // declarari forward
class QDial;
class QSlider;
class QSpinBox;

class TestSignals2 : public QWidget
{
    Q_OBJECT
public:
    explicit TestSignals2(QWidget *parent = 0);

    void SetupGUI();
signals:

public slots:

private:
    QVBoxLayout *layout;
    QSlider *slider;
    QSpinBox *spin;
    QDial *dial;
};

#endif // TESTSIGNALS2_H

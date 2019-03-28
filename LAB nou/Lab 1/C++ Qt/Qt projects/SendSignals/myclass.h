#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include<QMainWindow>

class QHBoxLayout;
class QDial;
class QSlider;
class QSpinBox;

class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyClass(QWidget *parent = 0);
    void SetupGui();

    void SetupConnections();

protected slots:

private:
    QHBoxLayout *layout;
    QDial *dial;
    QSlider *slider;
    QSpinBox *spinBox;
};

#endif // MYCLASS_H

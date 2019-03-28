#include "mybutton.h"
#include <QMouseEvent>
#include <QLineEdit>


MyButton::MyButton(QWidget *parent, QLineEdit *parentWidg) :
    QPushButton(parent)
{
    ple = parentWidg;
}

void MyButton::mousePressEvent(QMouseEvent *)
{
    Qt::MouseButton button = ev->button();
    switch (button)
    {
        case Qt::LeftButton: ple->setText("Butonul stang!");
            break;
        case Qt::RightButton: ple->setText("Butonul drept!");
            break;
        case Qt::MiddleButton: ple->setText("Butonul din mijloc!");
            break;
    default: QPushButton::mousePressEvent(ev);
    }

}

void MyButton::mouseDoubleClickEvent(QMouseEvent *)
{

}

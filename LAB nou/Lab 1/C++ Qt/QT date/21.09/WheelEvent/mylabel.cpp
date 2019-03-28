#include "mylabel.h"

MyLabel::MyLabel(QLabel *parent) :
    QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    x = 0;
}

void MyLabel::wheelEvent(QWheelEvent *event)
{
    x += event->delta()/120;
    if ( event->delta() > 0 )
        setText("UP " + QString::number(x));//event->delta()));
    else
        setText("DOWN " + QString::number(x));//event->delta()));


    /* nu stiu ce-i cu scrollWithPixels
    QPoint numPixels = event->pixelDelta();
       QPoint numDegrees = event->angleDelta() / 8;

       if (!numPixels.isNull()) {
           scrollWithPixels(numPixels);
       } else if (!numDegrees.isNull()) {
           QPoint numSteps = numDegrees / 15;
           scrollWithDegrees(numSteps);
       }
       */
}

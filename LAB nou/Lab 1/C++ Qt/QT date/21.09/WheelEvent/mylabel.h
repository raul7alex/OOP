#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWheelEvent>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QLabel *parent = 0);
    void wheelEvent(QWheelEvent *event);


signals:

public slots:
private:
    int x;
};

#endif // MYLABEL_H

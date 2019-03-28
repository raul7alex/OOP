#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
class QMouseEvent;
class QWidget;
class QLineEdit;


class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0, QLineEdit* parentWidg = 0);

signals:

public slots:
protected:
    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *);
private:
    QLineEdit* ple;
};

#endif // MYBUTTON_H

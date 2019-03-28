#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QMainWindow>

class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyClass(QWidget *parent = 0);
protected slots:

private:
};

#endif // MYCLASS_H

#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QMainWindow>

class QToolBar;

class MyClass :public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyClass(QWidget *parent = 0);

private:
    QToolBar *toolBar;
};

#endif // MYCLASS_H

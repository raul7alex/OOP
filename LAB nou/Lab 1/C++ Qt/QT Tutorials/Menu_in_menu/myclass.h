#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>

class QMenuBar;
class QMenu;


class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyClass(QWidget *parent = 0);
private:
    QMenuBar *menuBar;
    QMenu *fileMenu, *editMenu, *subMenu1, *subMenu2, *lastMenu1, *lastMenu2;
};

#endif // MYCLASS_H

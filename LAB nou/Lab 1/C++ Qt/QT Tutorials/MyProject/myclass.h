#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
class QHBoxLayout;
class QPushButton;

class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyClass(QWidget *parent = 0);
protected slots:

private:
    QHBoxLayout *layout;
    QPushButton *pushButton;
};

#endif // MYCLASS_H

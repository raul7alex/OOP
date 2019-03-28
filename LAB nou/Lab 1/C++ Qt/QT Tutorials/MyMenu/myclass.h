#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>

class QHBoxLayout;
class QPushButton;
class QTextEdit;

class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
   explicit MyClass(QWidget *parent = 0);
protected slots:

private:
    QHBoxLayout *layout;
    QPushButton *button;
    QTextEdit *textEdit;
};

#endif // MYCLASS_H

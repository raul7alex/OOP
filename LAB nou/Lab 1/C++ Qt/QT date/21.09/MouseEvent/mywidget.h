#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "mybutton.h"

#include <QWidget>
#include <QWidget>
class QLineEdit;
class QHBoxLayout;


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QLineEdit *le;
    MyButton* btn;
    QHBoxLayout* hb;
};

#endif // MYWIDGET_H

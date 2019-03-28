#include "mywidget.h"
#include <QLineEdit>
#include <QHBoxLayout>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    le = new QLineEdit;
    btn = new MyButton(this, le);
    hb = new QHBoxLayout;
    hb->addWidget(le);
    hb->addWidget(btn);
    setLayout(hb);
}

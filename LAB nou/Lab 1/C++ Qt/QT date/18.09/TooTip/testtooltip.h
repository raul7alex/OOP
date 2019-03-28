#ifndef TESTTOOLTIP_H
#define TESTTOOLTIP_H

#include <QMainWindow>

class QHBoxLayout;
class QPushButton;

class TestToolTip : public QMainWindow
{
    Q_OBJECT
public:
    explicit TestToolTip(QWidget *parent = 0);

signals:

public slots:

private:
    QWidget* centralWidget;
    QHBoxLayout *layout;
    QPushButton *sendPushButton, *namePushButton;

};

#endif // TESTTOOLTIP_H

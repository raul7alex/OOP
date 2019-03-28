#ifndef TOOLTIP_H
#define TOOLTIP_H

#include <QMainWindow>

class QHBoxLayout;
class QPushButton;

class ToolTip : public QMainWindow
{
    Q_OBJECT;
public:
    explicit ToolTip(QWidget *parent = 0);
protected slots:
private:
    QHBoxLayout *layout;
    QPushButton *okButton, *exitButton;
};

#endif // TOOLTIP_H

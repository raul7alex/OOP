#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

class QHBoxLayout;
class QDialog;
class QAction;
class QContextMenuEvent;

class Menu : public QMainWindow
{
   Q_OBJECT;
public:
    explicit Menu(QWidget *parent = 0);
virtual void contextMenuEvent(QContextMenuEvent *event);
protected slots:

private:
    QWidget *centralWidget;
    QHBoxLayout *layout;
    QAction *setupAction, *monitorAction;
    QContextMenuEvent *event;
};

#endif // MENU_H

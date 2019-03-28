#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>
#include <QMainWindow>

class QMenu;
class QMenuBar;
class QAction;


class MyMenu : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MyMenu(QWidget *parent = 0);
    void CreateActions();


protected slots:

private:
    QMenuBar *menuBar;
    QMenu *fileMenu, *editMenu;
    QAction *newAction, *openAction, *saveAction, *printAction,
            *exitAction, *copyAction, *cutAction, *pasteAction;
};

#endif // MYMENU_H

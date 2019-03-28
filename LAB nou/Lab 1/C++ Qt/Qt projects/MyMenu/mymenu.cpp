#include "mymenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

void MyMenu::CreateActions()
{
    newAction = new QAction(QIcon(":/Icons/new.png"), tr("&New File"), this);
    openAction = new QAction(QIcon(":/Icons/open.png"), tr("&Open File"), this);
    saveAction = new QAction(QIcon(":/Icons/save.png"), tr("&Save File"), this);
    printAction = new QAction(QIcon(":/Icons/print.png"), tr("&Print File"), this);
    copyAction = new QAction(QIcon(":/Icons/copy.png"), tr("&Copy"), this);
    cutAction = new QAction(QIcon(":/Icons/cut.png"), tr("&Cut File"), this);
    pasteAction = new QAction(QIcon(":/Icons/paste.png"), tr("&Paste"), this);
    exitAction = new QAction(QIcon(":/Icons/exit.png"), tr("&Exit"), this);
}

MyMenu::MyMenu(QWidget *parent):
    QMainWindow { parent }
{
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    fileMenu = new QMenu("&File", this);
    editMenu = new QMenu("&Edit", this);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);

    CreateActions();

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    fileMenu->addAction(newAction);





}

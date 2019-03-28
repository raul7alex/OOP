#include "editor.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QVBoxLayout>


void Editor::CreateMenus()
{
    menuBar = new QMenuBar(this);
    fileMenu = new QMenu(tr("&File"), this);
    windowMenu = new QMenu(tr("&Window"), this);
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(windowMenu);
    this->setMenuBar(menuBar);

    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    windowMenu->addAction(exitAct);
}

void Editor::CreateActions()
{
    newAct = new QAction(QIcon(":/Icon/new.png"), tr("&New File"), this);
    openAct = new QAction(QIcon(":/Icon/open.png"), tr("&Open File"), this);
    saveAct = new QAction(QIcon(":/Icon/save.png"), tr("&Save As"), this);
    printAct = new QAction(QIcon(":/Icon/print.png"), tr("&Print"), this);
    exitAct = new QAction(QIcon(":/Icon/close.png"), tr("&Exit"), this);
}

void Editor::CreateToolBar()
{
    tBar = new QToolBar(this);
    tBar->addAction(newAct);
    tBar->addAction(openAct);
    tBar->addAction(saveAct);
    tBar->addSeparator();
    tBar->addAction(printAct);
    tBar->addSeparator();
    tBar->addAction(exitAct);
    this->addToolBar(tBar);
}

void Editor::OpenContextMenu(QPoint point)
{
    QPoint globalP = editor->mapToGlobal(point);
    QMenu contextMenu;
    contextMenu.addAction(newAct);
    contextMenu.addAction(openAct);
    contextMenu.addAction(saveAct);
    contextMenu.addAction(printAct);
    contextMenu.addSeparator();
    contextMenu.addAction(exitAct);

    QAction* act  = contextMenu.exec(globalP);

}

Editor::Editor(QWidget *parent) :
    QMainWindow(parent)
{
    setGeometry(300, 300, 550, 450);
    CreateActions();
    CreateMenus();
    CreateToolBar();

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    vbLay = new QVBoxLayout(centralWidget);
    editor = new QTextEdit(this);
    vbLay->addWidget(editor);
    editor->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(editor, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(OpenContextMenu(QPoint)));
}

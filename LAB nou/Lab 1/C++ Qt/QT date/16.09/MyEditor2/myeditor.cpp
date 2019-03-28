#include "myeditor.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QToolBar>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

void MyEditor::CreateCentralWidget()
{
    QWidget *centralWidget = new QWidget(this);

    setCentralWidget(centralWidget);
    textEdit = new QTextEdit;
    layout = new QVBoxLayout(centralWidget);
    layout->addWidget(textEdit);
}

void MyEditor::CreateMenus()
{
    menuBar = new QMenuBar(this);
    fileMenu = new QMenu("&File", this);
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = new QMenu("&Edit", this);
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);

}

void MyEditor::CreateActions()
{
    newAct = new QAction(QIcon(":/Icons/new.png"), tr("&New File"), this);
    openAct = new QAction(QIcon(":/Icons/open.png"), tr("&Open File"), this);
    saveAct = new QAction(QIcon(":/Icons/save.png"), tr("&Save File"), this);
    printAct = new QAction(QIcon(":/Icons/print.png"), tr("&Print File"), this);
    copyAct = new QAction(QIcon(":/Icons/copy.png"), tr("&Copy"), this);
    cutAct = new QAction(QIcon(":/Icons/cut.png"), tr("&Cut File"), this);
    pasteAct = new QAction(QIcon(":/Icons/paste.png"), tr("&Paste"), this);
    exitAct = new QAction(QIcon(":/Icons/exit.png"), tr("&Exit"), this);
}

void MyEditor::CreateToolBar()
{
    toolBar = new QToolBar(this);
    toolBar->addAction(newAct);
    toolBar->addAction(openAct);
    toolBar->addAction(saveAct);
    toolBar->addSeparator();
    toolBar->addAction(printAct);
    toolBar->addSeparator();
    toolBar->addAction(copyAct);
    toolBar->addAction(cutAct);
    toolBar->addAction(pasteAct);
    toolBar->addSeparator();
    toolBar->addAction(exitAct);
    addToolBar(Qt::TopToolBarArea,toolBar);

    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void MyEditor::OnOpenFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp);;Text Files (*.txt *.rtf)"));
    if ( fileName == "") return;

    QFileInfo fi(fileName);
    QString ext = fi.suffix();
    if ( ext == "txt")
    {
       QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

       QTextStream in(&file);
       while (!in.atEnd())
       {
           QString text = in.readAll();
           textEdit->setText(text);
       }
    }
}

void MyEditor::OnSaveFileButton()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home",
                               tr("Images (*.png *.xpm *.jpg);;Text Files (*.txt *.rtf)"));


    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;
     QTextStream out(&file);
        out << textEdit->document()->toPlainText();

}

MyEditor::MyEditor(QWidget* parent) :
    QMainWindow(parent)
{
    CreateCentralWidget();
    CreateActions();
    CreateMenus();

    CreateToolBar();
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(OnOpenFileDialog()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(OnSaveFileButton()));
    setMenuBar(menuBar);
    setGeometry(400, 400, 650, 450);
}

#include "myclass.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QPrinter>
#include <QPrintDialog>
#include <QDesktopWidget>

void MyClass::CreateGui()
{
    QWidget *centralWidget = new QWidget(this);

    setCentralWidget(centralWidget);
    textEdit = new QTextEdit;
    layout = new QHBoxLayout(centralWidget);
    layout->addWidget(textEdit);
}

void MyClass::CreateActions()
{
    newAction = new QAction(QIcon(":/Icons/new.png"), tr("&New File"), this);
    openAction = new QAction(QIcon(":/Icons/open.png"), tr("&Open File"), this);
    saveAction = new QAction(QIcon(":/Icons/save.png"), tr("&Save File"), this);
    printAction = new QAction(QIcon(":/Icons/print.png"), tr("&Print File"), this);
    exitAction = new QAction(QIcon(":Icons/exit.png"), tr("&Exit "), this);
    copyAction = new QAction(QIcon(":/Icons/copy.png"), tr("&Copy"), this);
    cutAction = new QAction(QIcon(":/Icons/cut.png"), tr("&Cut"), this);
    pasteAction =new QAction(QIcon(":/Icons/paste.png"), tr("&Paste"), this);

    newAction ->setToolTip(tr("<font color ='red'><b>Create a new file</b></font>< /br> "));
    openAction ->setToolTip(tr("<font color ='red'><b>Open a file</b></font>< /br> "));
    saveAction ->setToolTip(tr("<font color ='red'><b>Save a file</b></font>< /br> "));
    printAction ->setToolTip(tr("<font color ='red'><b>Print a file</b></font>< /br> "));
    exitAction ->setToolTip(tr("<font color ='red'><b>Close the program</b></font>< /br> "));
    copyAction ->setToolTip(tr("<font color ='red'><b>Copy selected files or text</b></font>< /br> "));
    cutAction ->setToolTip(tr("<font color ='red'><b>Cut selected files or text</b></font>< /br> "));
    pasteAction ->setToolTip(tr("<font color ='red'><b>Paste selected files or text</b></font>< /br> "));

}

void MyClass::CreateMenu()
{


    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    fileMenu = new QMenu("&File", this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = new QMenu("&Edit", this);
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
}

void MyClass::CreateToolBar()
{
    toolBar = new QToolBar(this);
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addSeparator();
    toolBar->addAction(printAction);
    toolBar->addSeparator();
    toolBar->addAction(copyAction);
    toolBar->addAction(cutAction);
    toolBar->addAction(pasteAction);
    toolBar->addSeparator();
    toolBar->addAction(exitAction);

    addToolBar(Qt::TopToolBarArea,toolBar);

    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);}

void MyClass::OnOpenFileButton()
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

void MyClass::OnSaveFileButton()
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

void MyClass::OnNewFileButton()
{

    if ( textEdit->document()->isModified())
    {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home",
                               tr("Images (*.png *.xpm *.jpg);;Text Files (*.txt *.rtf)"));
    QFile file(fileName);
       // Trying to open in WriteOnly and Text mode
       if(!file.open(QFile::WriteOnly |
                     QFile::Text))
           return;


       // To write text, we use operator<<(),
       // which is overloaded to take
       // a QTextStream on the left
       // and data types (including QString) on the right

       QTextStream out(&file);
       out<<textEdit->document()->toPlainText();
       file.flush();
       file.close();
    }

    textEdit->setText("");
}

void MyClass::OnPrintFileButton()
{
     QPrinter printer;
     printer.setPrinterName("Print Document");

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    if(dialog->exec() ==QDialog::Rejected) return;
    textEdit->print(&printer);
}

void MyClass::CreateAction()
{
    connect(exitAction, SIGNAL(triggered(bool)), qApp,SLOT(quit()));
    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(OnOpenFileButton()));
    connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(OnSaveFileButton()));
    connect(newAction, SIGNAL(triggered(bool)), this, SLOT(OnNewFileButton()));
    connect(printAction, SIGNAL(triggered(bool)), this, SLOT(OnPrintFileButton()));

    connect(copyAction, SIGNAL(triggered(bool)),textEdit,SLOT(copy()));
    connect(cutAction, SIGNAL(triggered(bool)),textEdit,SLOT(cut()));
    connect(pasteAction, SIGNAL(triggered(bool)),textEdit,SLOT(paste()));
}

MyClass::MyClass(QWidget *parent):
    QMainWindow { parent}
{
    CreateGui();
    CreateActions();
    CreateMenu();
    CreateToolBar();
    CreateAction();
    int width = 600, height =400, x, y,
        screenWidth, screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;


    setGeometry(x, y, width, height);
}


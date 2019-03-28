#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QMainWindow>

class QMenu;
class QMenuBar;
class QAction;
class QToolBar;
class QTextEdit;
class QHBoxLayout;

class MyClass : public QMainWindow
{
    Q_OBJECT;
public:
   explicit MyClass(QWidget *parent = 0);

    void CreateGui();
    void CreateMenu();
    void CreateActions();
    void CreateToolBar();
    void CreateAction();

protected slots:
    void OnOpenFileButton();
    void OnSaveFileButton();
    void OnNewFileButton();
    void OnPrintFileButton();

private:
    QMenuBar *menuBar;
    QMenu *fileMenu ,*editMenu;
    QAction *newAction, *openAction, *saveAction, *printAction,
            *exitAction, * copyAction, *cutAction, *pasteAction;
    QToolBar *toolBar;
    QTextEdit *textEdit;
    QHBoxLayout *layout;

};

#endif // MYCLASS_H

#ifndef MYEDITOR_H
#define MYEDITOR_H
#include <QMainWindow>
#include <QWidget>

class QMenu;
class QMenuBar;
class QToolBar;
class QAction;
class QTextEdit;
class QVBoxLayout;

class MyEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyEditor(QWidget* parent = 0);

    void CreateCentralWidget();
    void CreateMenus();
    void CreateEditor();
    void CreateActions();
    void CreateToolBar();
protected slots:
        void OnOpenFileDialog();
        void OnSaveFileButton();
private:
   QMenuBar *menuBar;
   QMenu *fileMenu, *editMenu;
   QAction *newAct, *openAct,
           *saveAct, *printAct,
           *cutAct, *copyAct, *pasteAct, *exitAct;

    QToolBar *toolBar;
    QTextEdit *textEdit;
    QVBoxLayout *layout;
};

#endif // MYEDITOR_H

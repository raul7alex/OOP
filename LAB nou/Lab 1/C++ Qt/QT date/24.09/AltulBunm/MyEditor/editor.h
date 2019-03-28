#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

class QMenuBar;
class QMenu;
class QToolBar;
class QAction;
class QTextEdit;
class QVBoxLayout;

class Editor : public QMainWindow
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = 0);

    void CreateMenus();
    void CreateActions();
    void CreateToolBar();
signals:

public slots:
    void OpenContextMenu(QPoint);
private:
    QMenuBar* menuBar;
    QMenu *fileMenu, *windowMenu;
    QToolBar* tBar;
    QAction *newAct, *openAct, *saveAct, *printAct, *exitAct;
    QVBoxLayout *vbLay;
    QTextEdit* editor;
};

#endif // EDITOR_H

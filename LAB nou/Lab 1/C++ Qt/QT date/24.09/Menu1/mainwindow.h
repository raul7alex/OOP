#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

virtual void contextMenuEvent(QContextMenuEvent *event);

private slots:

    void on_MainWindow_customContextMenuRequested(const QPoint &pos);

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
    QDialog* dlg;
};

#endif // MAINWINDOW_H

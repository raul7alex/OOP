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

    void AddItem();
private slots:
    void on_pushButton_clicked();

    void on_actionSterge_triggered();

protected:
    void keyPressEvent(QKeyEvent *);

    bool eventFilter(QObject*, QEvent*);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

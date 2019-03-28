#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlRecord>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
      void OpenDB();
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString fileName;
};

#endif // MAINWINDOW_H

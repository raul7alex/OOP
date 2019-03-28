#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void UpdateLabel();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool state;
    int progress;
    QTimer *timer;
};

#endif // MAINWINDOW_H

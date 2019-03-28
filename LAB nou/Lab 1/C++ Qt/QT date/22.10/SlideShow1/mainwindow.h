#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void GetImages();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void SetImage();

protected:
private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int i;
    QString path;
    QList<QString> files;
};

#endif // MAINWINDOW_H

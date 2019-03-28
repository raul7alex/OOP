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

    void InsertPerson();
    void OpenDB();
    void ResetUi();
    void ShowImageByName(QString name);
    void SelectNames();
private slots:
    void on_pushButton_clicked();

    void on_btnSaveImage_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString fileName;
};

#endif // MAINWINDOW_H

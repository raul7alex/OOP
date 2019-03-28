#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
class FileManager;
}

class FileManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileManager(QWidget *parent = 0);
    ~FileManager();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::FileManager *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
};

#endif // FILEMANAGER_H

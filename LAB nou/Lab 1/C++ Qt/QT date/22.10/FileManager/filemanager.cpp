#include "filemanager.h"
#include "ui_filemanager.h"

FileManager::FileManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileManager)
{
    ui->setupUi(this);

    QString mPath = QDir::currentPath();//QDir::rootPath();

    dirModel = new QFileSystemModel(this);
    // Set filter
    dirModel->setFilter(QDir::NoDotAndDotDot |
                        QDir::AllDirs);

    // QFileSystemModel requires root path
    dirModel->setRootPath(mPath);
    // Attach the dir model to the view
    ui->treeView->setModel(dirModel);


    // FILES

    fileModel = new QFileSystemModel(this);

 //   fileModel->setFilter(QDir::NoDotAndDotDot |
 //                        QDir::Files);

    fileModel->setRootPath(mPath);

    // Attach the file model to the view
    ui->listView->setModel(fileModel);
}

FileManager::~FileManager()
{
    delete ui;
}

void FileManager::on_treeView_clicked(const QModelIndex &index)
{
   // QString path = dirModel->fileInfo(index).absolutePath();
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->index(path));

}

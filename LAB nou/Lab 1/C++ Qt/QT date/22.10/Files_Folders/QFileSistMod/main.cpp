#include <QApplication>
#include <QFileSystemModel>
#include <QSplitter>
#include <QListView>
#include <QTreeView>

int main(int argc, char*argv[])
{
    QApplication app(argc, argv);
    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
 //   model->setRootPath(QString("D:"));
    model->setRootPath(QDir::rootPath());
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::rootPath()));
 //   tree->setRootIndex(model->index(QString("D:")));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Doua vederi cu acelasi File system model");
    splitter->show();
    return app.exec();
}

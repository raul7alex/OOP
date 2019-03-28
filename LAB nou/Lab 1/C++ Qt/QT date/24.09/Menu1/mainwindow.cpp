#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QContextMenuEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Trebuie ca MainWindow sa aiba COntextMenuPolicy setata pe Qt::DefaultContextMenu
// pot face asta si din designer (scrie in bibliografia pentru contextMenuEvent)
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
 {
 //   QMessageBox::about(this, "Titlu", "HAHAAHA");
     QMenu menu;
     QAction *setupAction = new QAction("Setupul", this);
     QAction *monitorAction = new QAction("Monitorul", this);

     menu.addAction(setupAction);
     menu.addAction(monitorAction);
     menu.exec(event->globalPos());//(QPoint(event->globalX(), event->globalY()));
 }

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{
 /*   QMenu *menu = new QMenu();
    QAction *setupAction = new QAction("Setupul", this);
    QAction *monitorAction = new QAction("Monitorul", this);

    menu->addAction(setupAction);
    menu->addAction(monitorAction);

    menu->addAction(ui->action_Open);

    menu->exec(QCursor::pos());      // ok
*/
    // for most widgets
   //    QPoint globalPos = centralWidget()->mapToGlobal(pos);
       // for QAbstractScrollArea and derived classes you would use:
     //  QPoint globalPos = ui->centralWidget->viewport()->mapToGlobal(pos);

    //menu->exec(globalPos);
}

void MainWindow::on_actionNew_triggered()
{
    dlg = new QDialog(this);
    dlg->setGeometry(50, 50, 300, 200);
    dlg->move(300, 300);
    dlg->setModal(false);
    dlg->show();
       // QDialog mDialog;
  //  mDialog.setModal(false);
   // mDialog.exec();        // OK !!!
   // mDialog.show();
}

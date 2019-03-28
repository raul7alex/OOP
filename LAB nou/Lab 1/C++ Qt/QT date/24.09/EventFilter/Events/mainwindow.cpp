#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->viewport()->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItem()
{
    if ( ui->lineEdit->text() != "")
    {
        // adauga in listWidget textul din lineEdit
        ui->listWidget->addItem(ui->lineEdit->text());

        // sterge textul din lineEdit
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_pushButton_clicked()
{
    AddItem();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   if ( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
       AddItem();
   else
       QMainWindow::keyPressEvent(event);
}



bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
        if (obj == ui->listWidget->viewport())
        {

            if (event->type() == QEvent::MouseButtonPress)
            {
             //   QMessageBox::information(this, "wsds", "DA");
                QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                if ( mouseEvent->button() == Qt::RightButton )
                {
                    int x = mouseEvent->x();
                    int y = mouseEvent->y();
                    QMenu menu;

                    menu.addAction(ui->actionSterge);

                    menu.exec(ui->listWidget->mapToGlobal(QPoint(x, y)));
                    return true;
                }

            }
            else {
                return false;
            }
        } else {
            // pass the event on to the parent class
            return QMainWindow::eventFilter(obj, event);
        }

}

void MainWindow::on_actionSterge_triggered()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

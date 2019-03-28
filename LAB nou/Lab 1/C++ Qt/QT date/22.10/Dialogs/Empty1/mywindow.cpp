#include "mywindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mydialog.h"
#include <QTextEdit>
#include <QDialogButtonBox>


void MyWindow::InitWidgets()
{
    textLabel = new QLabel(tr("Introduceti un text: "), this);
    textLineEdit = new QLineEdit;
    openPushButton = new QPushButton;
    openPushButton->setText(tr("Trimite"));
    openPushButton->setIcon(QIcon(":/Icons/open-icon.png"));
    textEdit1 = new QTextEdit;

    hLay1 = new QHBoxLayout;
    hLay1->addWidget(textLabel);
    hLay1->addWidget(textLineEdit, 2);
    hLay1->addWidget(openPushButton);

    vLay = new QVBoxLayout;
    vLay->addLayout(hLay1);

    hLay2 = new QHBoxLayout;
    hLay2->addWidget(textEdit1);
    vLay->addLayout(hLay2);
    setLayout(vLay);
}

void MyWindow::OpenDialog()
{
    /*          Merge si cu alocare dinamica a dialogului
    MyDialog* dlg = new MyDialog(this);
    QTextEdit * textEdit2 = new QTextEdit;
    QVBoxLayout* vbLay = new QVBoxLayout;
    vbLay->addWidget(textEdit2);
    QDialogButtonBox *dialButtons
                = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(dialButtons, SIGNAL(accepted()), dlg, SLOT(accept()));
    connect(dialButtons, SIGNAL(rejected()), dlg, SLOT(reject()));

    vbLay->addWidget(dialButtons);
    dlg->setLayout(vbLay);
    int x = dlg->exec();
*/
    // Merge si cu alocare statica
    MyDialog dlg;
    QTextEdit * textEdit2 = new QTextEdit;
    QVBoxLayout* vbLay = new QVBoxLayout;
    vbLay->addWidget(textEdit2);
    QDialogButtonBox *dialButtons
                = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(dialButtons, SIGNAL(accepted()), &dlg, SLOT(accept()));
    connect(dialButtons, SIGNAL(rejected()), &dlg, SLOT(reject()));

    vbLay->addWidget(dialButtons);
    dlg.setLayout(vbLay);

    int x = dlg.exec();
    if ( x == QDialog::Accepted)
    {
        textLineEdit->setText("Acceptat");
        textEdit1->setPlainText(textEdit2->toPlainText());
    }
    if ( x == QDialog::Rejected)
        textLineEdit->setText("Respins");
}

MyWindow::MyWindow(QWidget *parent) :
    QWidget(parent)
{
    InitWidgets();
    connect(openPushButton, SIGNAL(clicked()),
            this, SLOT(OpenDialog()));

}




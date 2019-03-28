#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnFwd_clicked()
{
    ui->webView->forward();
}

void Dialog::on_btnBack_clicked()
{
    ui->webView->back();
}


void Dialog::on_btnRefresh_clicked()
{
    ui->webView->reload();
}

void Dialog::on_btnGo_clicked()
{
    ui->webView->load("http://" + ui->urlEdit->text());
}

void Dialog::on_urlEdit_returnPressed()
{
    on_btnGo_clicked();
}

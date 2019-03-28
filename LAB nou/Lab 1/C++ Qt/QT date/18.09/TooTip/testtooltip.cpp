#include "testtooltip.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>

TestToolTip::TestToolTip(QWidget *parent) :
    QMainWindow(parent),
    centralWidget { new QWidget },
    layout {new QHBoxLayout(centralWidget)},
    sendPushButton {new QPushButton},
    namePushButton {new QPushButton}
{
    setCentralWidget(centralWidget);
    sendPushButton->setText("Send Button");
    sendPushButton->setStyleSheet(" background-color: yellow;"
                                  "border-style: outset;"
                                  "border-width: 15px;"
                                  "border-radius: 30px;"
                                  "border-color: blue;"
                                  "font: bold 16px;"
                                  "min-width: 10em;"
                                  "padding: 20px;");
    sendPushButton->setToolTip("<font color ='red'><b>Trimite un mesaj</b></font>< /br> <ol><li>Unu</li><li>Doi</li><li>Trei</li><ol>");

    namePushButton->setText("Name Button");
    namePushButton->setToolTip("<html><p>Se trimite numele persoanei</p>  <img src=panda.jpg width=100 height=80></html>");
    layout->addWidget(namePushButton);
    layout->addWidget(sendPushButton);



}

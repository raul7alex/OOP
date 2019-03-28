#include "tooltip.h"

#include <QHBoxLayout>
#include <QPushButton>

ToolTip::ToolTip(QWidget *parent):
    QMainWindow{ parent }
{
    QWidget *centralWidget = new QWidget (this);
    setCentralWidget(centralWidget);

    layout = new QHBoxLayout(centralWidget);

    okButton = new QPushButton("ok");
    exitButton = new QPushButton("close");

    layout ->addWidget(okButton);
    layout ->addWidget(exitButton);

    okButton->setToolTip("<b>Accepta conditiile </b>");
    exitButton->setToolTip("<b>Exit from the application</b>");

    okButton->setStyleSheet(" background-color: yellow;"
                                             "border-style: outset;"
                                             "border-width: 5px;"
                                             "border-radius: 10px;"
                                             "border-color: blue;"
                                             "font: bold 12px;"
                                             "min-width: 5em;"
                                             "padding: 5px;");

}

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save_As;
    QAction *actionPrint;
    QAction *action_Exit;
    QAction *action_Copy;
    QAction *actionC_ut;
    QAction *action_Paste;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(747, 471);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save_As = new QAction(MainWindow);
        action_Save_As->setObjectName(QStringLiteral("action_Save_As"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save_As->setIcon(icon2);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon4);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon5);
        actionC_ut = new QAction(MainWindow);
        actionC_ut->setObjectName(QStringLiteral("actionC_ut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionC_ut->setIcon(icon6);
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Paste->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save_As);
        menu_File->addSeparator();
        menu_File->addAction(actionPrint);
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menu_Edit->addAction(action_Copy);
        menu_Edit->addAction(actionC_ut);
        menu_Edit->addAction(action_Paste);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPrint);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(actionC_ut);
        mainToolBar->addAction(action_Paste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_New->setText(QApplication::translate("MainWindow", "&New", 0));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("MainWindow", "Create New File", 0));
#endif // QT_NO_TOOLTIP
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0));
#ifndef QT_NO_TOOLTIP
        action_Open->setToolTip(QApplication::translate("MainWindow", "Open File", 0));
#endif // QT_NO_TOOLTIP
        action_Save_As->setText(QApplication::translate("MainWindow", "&Save As", 0));
#ifndef QT_NO_TOOLTIP
        action_Save_As->setToolTip(QApplication::translate("MainWindow", "Save File As", 0));
#endif // QT_NO_TOOLTIP
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0));
#ifndef QT_NO_TOOLTIP
        actionPrint->setToolTip(QApplication::translate("MainWindow", "Print Current File", 0));
#endif // QT_NO_TOOLTIP
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", 0));
#ifndef QT_NO_TOOLTIP
        action_Exit->setToolTip(QApplication::translate("MainWindow", "Exit Application", 0));
#endif // QT_NO_TOOLTIP
        action_Copy->setText(QApplication::translate("MainWindow", "&Copy", 0));
#ifndef QT_NO_TOOLTIP
        action_Copy->setToolTip(QApplication::translate("MainWindow", "Copy Seletcted Text", 0));
#endif // QT_NO_TOOLTIP
        actionC_ut->setText(QApplication::translate("MainWindow", "C&ut", 0));
#ifndef QT_NO_TOOLTIP
        actionC_ut->setToolTip(QApplication::translate("MainWindow", "Cut Selected Text", 0));
#endif // QT_NO_TOOLTIP
        action_Paste->setText(QApplication::translate("MainWindow", "&Paste", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

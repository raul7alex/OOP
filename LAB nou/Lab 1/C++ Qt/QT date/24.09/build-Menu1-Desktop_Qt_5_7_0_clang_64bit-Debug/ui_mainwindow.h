/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_File;
    QAction *action_Document;
    QAction *actionNew;
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDial *dial;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_New;
    QMenu *menuWind;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(479, 593);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_File = new QAction(MainWindow);
        action_File->setObjectName(QStringLiteral("action_File"));
        action_Document = new QAction(MainWindow);
        action_Document->setObjectName(QStringLiteral("action_Document"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(80, 20, 251, 191));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(120, 260, 48, 27));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(140, 360, 69, 27));
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(140, 410, 118, 27));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(130, 450, 110, 27));
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(300, 280, 111, 161));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_New = new QMenu(menu_File);
        menu_New->setObjectName(QStringLiteral("menu_New"));
        menuWind = new QMenu(menuBar);
        menuWind->setObjectName(QStringLiteral("menuWind"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuWind->menuAction());
        menu_File->addAction(menu_New->menuAction());
        menu_File->addAction(action_Open);
        menuWind->addAction(actionNew);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", 0));
        action_File->setText(QApplication::translate("MainWindow", "&File", 0));
        action_Document->setText(QApplication::translate("MainWindow", "&Document", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_New->setTitle(QApplication::translate("MainWindow", "&New", 0));
        menuWind->setTitle(QApplication::translate("MainWindow", "Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

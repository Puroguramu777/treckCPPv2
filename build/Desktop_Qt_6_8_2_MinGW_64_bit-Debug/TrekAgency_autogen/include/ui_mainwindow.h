/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *addClientButton;
    QPushButton *updateClientButton;
    QPushButton *deleteClientButton;
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *telephoneLineEdit;
    QLineEdit *emailLineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(270, 180, 256, 192));
        addClientButton = new QPushButton(centralwidget);
        addClientButton->setObjectName("addClientButton");
        addClientButton->setGeometry(QRect(59, 110, 131, 24));
        updateClientButton = new QPushButton(centralwidget);
        updateClientButton->setObjectName("updateClientButton");
        updateClientButton->setGeometry(QRect(59, 160, 131, 24));
        deleteClientButton = new QPushButton(centralwidget);
        deleteClientButton->setObjectName("deleteClientButton");
        deleteClientButton->setGeometry(QRect(59, 220, 131, 24));
        nomLineEdit = new QLineEdit(centralwidget);
        nomLineEdit->setObjectName("nomLineEdit");
        nomLineEdit->setGeometry(QRect(120, 480, 113, 24));
        prenomLineEdit = new QLineEdit(centralwidget);
        prenomLineEdit->setObjectName("prenomLineEdit");
        prenomLineEdit->setGeometry(QRect(280, 480, 113, 24));
        telephoneLineEdit = new QLineEdit(centralwidget);
        telephoneLineEdit->setObjectName("telephoneLineEdit");
        telephoneLineEdit->setGeometry(QRect(430, 480, 113, 24));
        emailLineEdit = new QLineEdit(centralwidget);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(570, 480, 113, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addClientButton->setText(QCoreApplication::translate("MainWindow", "addClientButton", nullptr));
        updateClientButton->setText(QCoreApplication::translate("MainWindow", "updateClientButton", nullptr));
        deleteClientButton->setText(QCoreApplication::translate("MainWindow", "deleteClientButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

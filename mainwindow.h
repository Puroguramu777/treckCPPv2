#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QSqlTableModel>
#include "database_manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addClientButton_clicked();
    void on_updateClientButton_clicked();
    void on_deleteClientButton_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseManager dbManager;
    QSqlTableModel *model;  // Déclaration du modèle pour QTableView
    void loadClients();  // Fonction pour charger les clients
};

#endif // MAINWINDOW_H

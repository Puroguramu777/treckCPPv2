#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    model(new QSqlTableModel(this))  // Initialisation du modèle
{
    ui->setupUi(this);

    // Connexion à la base de données
    if (!dbManager.connect()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données a échoué !");
    }

    // Configurer le modèle
    model->setTable("clients");
    model->select();  // Charger toutes les données de la table clients
    ui->tableView->setModel(model);  // Associer le modèle au QTableView
    ui->tableView->resizeColumnsToContents();  // Ajuster la largeur des colonnes
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addClientButton_clicked()
{
    // Récupérer les informations du formulaire
    QString nom = ui->nomLineEdit->text();
    QString prenom = ui->prenomLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString telephone = ui->telephoneLineEdit->text();

    // Ajouter le client dans la base de données via le modèle
    dbManager.addClient(nom, prenom, email, telephone);

    // Rafraîchir les données dans le modèle
    model->select();
}

void MainWindow::on_updateClientButton_clicked()
{
    // Vérifier si une ligne est sélectionnée
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client à mettre à jour.");
        return;
    }

    // Récupérer les informations actuelles du client
    QString id = model->data(model->index(row, 0)).toString();  // ID du client
    QString nom = ui->nomLineEdit->text();
    QString prenom = ui->prenomLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString telephone = ui->telephoneLineEdit->text();

    // Mettre à jour les informations dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE clients SET nom = ?, prenom = ?, email = ?, telephone = ? WHERE id = ?");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(telephone);
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour du client:" << query.lastError().text();
        return;
    }

    // Rafraîchir les données dans le modèle
    model->select();
}

void MainWindow::on_deleteClientButton_clicked()
{
    // Vérifier si une ligne est sélectionnée
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    // Récupérer l'ID du client sélectionné
    QString id = model->data(model->index(row, 0)).toString();

    // Demander une confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce client ?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Supprimer le client de la base de données
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du client:" << query.lastError().text();
        return;
    }

    // Rafraîchir les données dans le modèle
    model->select();
}

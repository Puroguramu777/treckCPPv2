#include "database_manager.h"
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
    // Initialisation de l'objet DatabaseManager
    db = QSqlDatabase::addDatabase("QSQLITE");  // Utilisation de SQLite
    db.setDatabaseName("clients.db");            // Nom de la base de données
}

bool DatabaseManager::connect()
{
    if (db.open()) {
        qDebug() << "Connection à la base de données réussie.";
        return true;
    } else {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        return false;
    }
}

void DatabaseManager::addClient(const QString &nom, const QString &prenom, const QString &email, const QString &telephone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO clients (nom, prenom, email, telephone) VALUES (?, ?, ?, ?)");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(telephone);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du client:" << query.lastError().text();
    } else {
        qDebug() << "Client ajouté avec succès.";
    }
}

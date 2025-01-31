#include "database.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

bool DatabaseManager::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");  // Adresse du serveur MySQL
    db.setDatabaseName("trek_agency");  // Nom de la base de données
    db.setUserName("qtuser");  // Ton utilisateur MySQL
    db.setPassword("password123");  // Mot de passe défini dans MySQL Workbench
    db.setPort(3306);  // Le port MySQL par défaut

    if (!db.open()) {
        qDebug() << "❌ Erreur de connexion à MySQL :" << db.lastError().text();
        return false;
    }

    qDebug() << "✅ Connexion réussie à MySQL!";
    return true;
}

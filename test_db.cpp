#include "database_manager.h"
#include <QDebug>

void testDatabaseConnection() {
    DatabaseManager dbManager;  // Crée une instance de DatabaseManager

    if (!dbManager.connect()) {
        qDebug() << "Erreur de connexion à la base de données";
    } else {
        qDebug() << "Connexion réussie à la base de données";
    }
}

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class DatabaseManager
{
public:
    DatabaseManager();
    bool connect();  // Connexion à la base de données
    void addClient(const QString &nom, const QString &prenom, const QString &email, const QString &telephone);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H

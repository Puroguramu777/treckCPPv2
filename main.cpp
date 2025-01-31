#include "mainwindow.h"
#include <QApplication>
#include "database_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Démarrage de l'application...";  // Ajout du message pour confirmer l'exécution

    DatabaseManager dbManager;
    if (!dbManager.connect()) {
        qDebug() << "Impossible de se connecter à la base de données.";
        return -1;  // Si la connexion échoue, on arrête l'exécution
    }

    // Création de la fenêtre principale
    MainWindow w;
    w.show();

    return a.exec();
}

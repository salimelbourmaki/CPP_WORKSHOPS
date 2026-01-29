#include <iostream>
#include <string>
using namespace std;

// ===============================
// ======== Classe Client ========
// ===============================
class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    // Constructeur par défaut
    Client() : id(0), nom(""), prenom("") {
        cout << "Client vide créé." << endl;
    }

    // Constructeur avec paramètres
    Client(int i, string n, string p) : id(i), nom(n), prenom(p) {
        cout << "Client " << nom << " " << prenom << " créé." << endl;
    }

    // Constructeur de copie
    Client(const Client& c) {
        id = c.id;
        nom = c.nom;
        prenom = c.prenom;
        cout << "Client copié : " << nom << " " << prenom << endl;
    }

    // Destructeur
    ~Client() {
        cout << "Destruction du client : " << nom << " " << prenom << endl;
    }

    // Méthode d’affichage
    void afficher() const {
        cout << "Client [ID=" << id << ", Nom=" << nom << ", Prénom=" << prenom << "]" << endl;
    }
};

// ===============================
// ======== Classe Compte ========
// ===============================
class Compte {
private:
    int numero;
    float solde;
    Client* client;
    static int nbComptes; // attribut partagé entre tous les comptes

public:
    // Constructeur par défaut
    Compte() {
        numero = 0;
        solde = 0.0;
        client = nullptr;
        nbComptes++;
        cout << "Compte vide créé." << endl;
    }

    // Constructeur avec paramètres
    Compte(int num, float s, const Client& c) {
        numero = num;
        solde = s;
        client = new Client(c); // copie profonde
        nbComptes++;
        cout << "Compte " << numero << " créé avec client associé." << endl;
    }

    // Constructeur de copie
    Compte(const Compte& c) {
        numero = c.numero;
        solde = c.solde;
        if (c.client != nullptr)
            client = new Client(*c.client); // copie profonde du client
        else
            client = nullptr;
        nbComptes++;
        cout << "Compte copié : " << numero << endl;
    }

    // Destructeur
    ~Compte() {
        delete client;
        nbComptes--;
        cout << "Compte " << numero << " supprimé." << endl;
    }

    // Méthode d'affichage
    void afficher() const {
        cout << "Compte [Numéro=" << numero << ", Solde=" << solde << "]" << endl;
        if (client)
            client->afficher();
        else
            cout << "Aucun client associé." << endl;
    }

    // Accesseurs
    float getSolde() const { return solde; }
    void setSolde(float s) { solde = s; }

    // Méthode statique
    static void afficherNbComptes() {
        cout << "Nombre total de comptes existants : " << nbComptes << endl;
    }
};

// Initialisation de l'attribut statique
int Compte::nbComptes = 0;

// ===============================
// ===== Fonction utilitaire =====
// ===============================
inline float calculInteret(float solde, float taux) {
    return solde + solde * taux / 100.0;
}

// ===============================
// ========= Programme main ======
// ===============================
int main() {
    cout << "=== Début du programme bancaire ===" << endl;

    // Création de clients
    Client c1(1, "Dupont", "Jean");
    Client c2(2, "Martin", "Claire");

    // Création de comptes
    Compte::afficherNbComptes();
    Compte* compte1 = new Compte(1001, 5000.0, c1);
    Compte* compte2 = new Compte(1002, 12000.0, c2);
    Compte::afficherNbComptes();

    // Affichage des comptes
    cout << "\n--- Informations des comptes ---" << endl;
    compte1->afficher();
    compte2->afficher();

    // Copie d’un compte
    cout << "\n--- Copie d’un compte ---" << endl;
    Compte compte3 = *compte1;
    compte3.afficher();
    Compte::afficherNbComptes();

    // Application d’intérêts
    cout << "\n--- Application des intérêts ---" << endl;
    float nouveauSolde = calculInteret(compte1->getSolde(), 5.0);
    compte1->setSolde(nouveauSolde);
    cout << "Nouveau solde du compte 1001 après intérêts : " << compte1->getSolde() << endl;

    // Suppression d’un compte
    cout << "\n--- Suppression d’un compte ---" << endl;
    delete compte2;
    Compte::afficherNbComptes();

    // Suppression du dernier compte dynamique
    delete compte1;
    Compte::afficherNbComptes();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}

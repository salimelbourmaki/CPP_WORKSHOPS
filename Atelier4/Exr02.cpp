#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**************************************************************
 * Classe Client
 * Représente un client de la banque avec un nom, un CIN et un identifiant.
 **************************************************************/
class Client {
private:
    string nom;
    string CIN;
    int idClient;

public:
    // Constructeur
    Client(string n, string c, int id)
        : nom(n), CIN(c), idClient(id) {}

    // Méthode d’affichage (publique)
    void afficherInfos() const {
        cout << "Nom du client : " << nom << endl;
        cout << "CIN : " << CIN << endl;
        cout << "Identifiant client : " << idClient << endl;
    }

    // Méthode d’accès non sensible
    string getNom() const { return nom; }

    // Autorisation spéciale pour la Banque et l’Agent
    friend class Banque;
    friend class AgentBancaire;
};

/**************************************************************
 * Classe CompteBancaire
 * Représente un compte bancaire associé à un client.
 * Contient des informations sensibles : numéro, solde, code secret.
 **************************************************************/
class CompteBancaire {
private:
    string numeroCompte;
    double solde;
    string codeSecret;   // Donnée sensible, non accessible publiquement
    Client* proprietaire;

public:
    // Constructeur
    CompteBancaire(string num, double s, string code, Client* client)
        : numeroCompte(num), solde(s), codeSecret(code), proprietaire(client) {}

    // Méthodes publiques
    void deposer(double montant) {
        if (montant > 0)
            solde += montant;
    }

    void retirer(double montant) {
        if (montant > 0 && montant <= solde)
            solde -= montant;
        else
            cout << " Opération invalide ou solde insuffisant !" << endl;
    }

    // Méthode d’affichage non confidentielle
    void afficherInfosPubliques() const {
        cout << "Numéro de compte : " << numeroCompte << endl;
        cout << "Solde : " << solde << " DH" << endl;
        cout << "Titulaire : " << proprietaire->getNom() << endl;
    }

    // Relation d’amitié (accès restreint)
    friend class Banque;
    friend class AgentBancaire;
};

/**************************************************************
 * Classe AgentBancaire
 * Représente un employé autorisé à effectuer des opérations confidentielles.
 **************************************************************/
class AgentBancaire {
private:
    string nomAgent;
    string identifiant;

public:
    // Constructeur
    AgentBancaire(string n, string id)
        : nomAgent(n), identifiant(id) {}

    // Méthode : transfert entre deux comptes (accès direct via amitié)
    void effectuerTransfert(CompteBancaire& source, CompteBancaire& destination, double montant) {
        if (montant <= 0) {
            cout << "Montant invalide !" << endl;
            return;
        }
        if (montant > source.solde) {
            cout << "Solde insuffisant pour le transfert !" << endl;
            return;
        }
        source.solde -= montant;
        destination.solde += montant;

        cout << "Transfert de " << montant << " DH effectué par " << nomAgent
             << " du compte " << source.numeroCompte
             << " vers " << destination.numeroCompte << "." << endl;
    }

    // Méthode : consultation du code secret (accès réservé)
    void consulterCodeSecret(const CompteBancaire& compte) const {
        cout << "Consultation confidentielle du code secret par l’agent " << nomAgent << endl;
        cout << "Compte : " << compte.numeroCompte
             << " | Code secret : " << compte.codeSecret << endl;
    }

    friend class Banque;
};

/**************************************************************
 * Classe Banque
 * Centralise la gestion des clients et comptes.
 * Permet un audit interne et contrôle les opérations.
 **************************************************************/
class Banque {
private:
    string nomBanque;
    vector<Client*> clients;
    vector<CompteBancaire*> comptes;

public:
    // Constructeur
    Banque(string nom) : nomBanque(nom) {}

    // Ajout de clients et de comptes
    void ajouterClient(Client* c) {
        clients.push_back(c);
    }

    void ajouterCompte(CompteBancaire* c) {
        comptes.push_back(c);
    }

    // Affichage général
    void afficherClients() const {
        cout << "\n=== Liste des clients de " << nomBanque << " ===" << endl;
        for (auto c : clients)
            c->afficherInfos();
    }

    void afficherComptes() const {
        cout << "\n=== Liste des comptes ===" << endl;
        for (auto c : comptes)
            c->afficherInfosPubliques();
    }

    // Audit interne (accès complet)
    void auditInterne() const {
        cout << "\n===  Rapport d’audit interne de la banque " << nomBanque << " ===" << endl;
        for (auto compte : comptes) {
            cout << "Compte : " << compte->numeroCompte
                 << " | Solde : " << compte->solde
                 << " | Code secret : " << compte->codeSecret
                 << " | Titulaire : " << compte->proprietaire->getNom()
                 << " (" << compte->proprietaire->CIN << ")" << endl;
        }
    }

    friend class AgentBancaire;
};


int main() {
    // Création de la banque
    Banque banque("Banque Centrale du Maroc");

    // Création des clients
    Client c1("Mohamed El Khattabi", "AA123456", 1);
    Client c2("Salim El Bourmaki", "BB654321", 2);

    // Création des comptes
    CompteBancaire compte1("CPT001", 8000.0, "1234", &c1);
    CompteBancaire compte2("CPT002", 99965788980, "5678", &c2);

    // Enregistrement dans la banque
    banque.ajouterClient(&c1);
    banque.ajouterClient(&c2);
    banque.ajouterCompte(&compte1);
    banque.ajouterCompte(&compte2);

    // Création d’un agent bancaire
    AgentBancaire agent("Youssef Amrani", "AG001");

    // --- Simulations d’opérations ---
    cout << "\n=== DÉPÔTS & RETRAITS ===" << endl;
    compte1.deposer(1500);
    compte2.retirer(500);

    // Transfert confidentiel par l’agent
    cout << "\n=== TRANSFERT PAR AGENT ===" << endl;
    agent.effectuerTransfert(compte1, compte2, 1000);

    // Consultation confidentielle du code secret
    cout << "\n=== CONSULTATION CONFIDENTIELLE ===" << endl;
    agent.consulterCodeSecret(compte2);

    // Affichage général
    banque.afficherClients();
    banque.afficherComptes();

    // Audit interne complet
    banque.auditInterne();

    return 0;
}